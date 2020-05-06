# !Powershell
# Скрипт-обертка для запуска в Windows процесса сборки проекта в среде wsl2-debian-docker-cmake-gcc.
# Скрипт определяет месторасположение проекта для сборки исходя из собственного месторасположения.
# Скрипт должен находиться в дочерней папке проекта, например, <проект>/scripts, рядом с одноименным bash-скриптом запуска сборки <скрипт>.sh

function main( [Parameter( Position = 0 )][string] $thisScriptPath, [Parameter( Position = 1 )][string[]] $commandLineArgs )
{
	clear
	
	# Получаем путь и имя проекта - имя родительской папки скрипта на 2 уровня выше
	$thisScriptDirPath = $thisScriptPath |Split-Path -parent
	$projectPath = $thisScriptDirPath |Split-Path -parent
	$projectName = $projectPath |Split-Path -Leaf
	<#assert#> if( [string]::IsNullOrEmpty( $projectName ) ) { throw }
	<#assert#> if( [string]::IsNullOrEmpty( $projectPath ) ) { throw }
	
	# Получаем источник точки монтирования проекта для системы сборки - родительский каталог проекта
	$projectParent = $projectPath |Split-Path -parent
	$projectMountPoint = convertPathToMountPoint $projectParent
	<#assert#> if( [string]::IsNullOrEmpty( $projectMountPoint ) ) { throw }

	# Получаем имя скрипта
	$thisScriptShortName = ( Get-ChildItem $thisScriptPath ).Basename
	$thisScriptDirName = $thisScriptDirPath |Split-Path -Leaf

	# формируем строку с параметрами командной строки
	$paramsToString = ( convertToStringWithQuotas $commandLineArgs )
	
	# Запускаем систему сборки для проекта
	bash -c "docker run --rm -t -v '${projectMountPoint}':/sources gtest bash -c '/sources/${projectName}/${thisScriptDirName}/${thisScriptShortName}.sh $paramsToString'"
}

# Преобразует путь вида "C:\Parent\Dir\file" в "/mnt/c/Parent/Dir/file"
function convertPathToMountPoint( [Parameter( Position = 0 )][string] $path )
{
	$fullPath = $path |Resolve-Path
	$driveName = ( ( $fullPath |Split-Path -Qualifier ) -replace '\:$', '' ).ToLower()
	$atRootPath = ( $fullPath -replace '^.*\:', '' ) -replace '\\', '/'
	-join( "/mnt/", $driveName, $atRootPath )
}

# Преобразует массив строк вида @("w1 w2", "w3", "w4") в строку вида '"w1 w2" w3 w4'
function convertToStringWithQuotas( [Parameter( Position = 0 )][string[]] $items )
{
	$result = ""
	foreach ( $item in $items ) {
		if( $item -match "\s" ) {
			$result = "${result} `\`"${item}`\`""
		} else {
			$result = "${result} ${item}"
		}
	}
	$result
}

# Выводит подсказку
function help( [Parameter( Position = 0 )][string] $thisScriptPath )
{
	$commandName = $thisScriptPath |Split-Path -Leaf
	"Usage:
		${commandName}
		${commandName} Release | Debug
		${commandName} -h | --help
	"
}

# Точка входа
if( -not [string]::IsNullOrEmpty( $Args[0] ) -and $Args[0].ToLower() -in @( "-h", "--help" ) ) {
	help $MyInvocation.MyCommand.Path
	exit
}

main $MyInvocation.MyCommand.Path $Args
