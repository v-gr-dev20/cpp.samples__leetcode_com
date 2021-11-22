# !Powershell
# Скрипт для запуска в Windows процесса тестирования проекта в среде windows-cmake-MSVS.
# Скрипт определяет месторасположение проекта для сборки исходя из собственного месторасположения.
# Скрипт должен находиться в дочерней папке проекта, например, <проект>/scripts.

function main( [Parameter( Position = 0 )][string] $thisScriptPath, [Parameter( Position = 1 )][string[]] $commandLineArgs )
{
	# Ожидается параметр: тип сборки Release | Debug
	$buildType = [string]$commandLineArgs[0]
	if( [string]::IsNullOrEmpty( $buildType ) ) {
		$buildType='Release'
	}
	<#assert#> if( [string]::IsNullOrEmpty( $buildType ) ) { throw }
	
	# Получаем путь и имя проекта - имя родительской папки скрипта на 2 уровня выше
	$thisScriptDirPath = $thisScriptPath |Split-Path -parent
	$projectPath = $thisScriptDirPath |Split-Path -parent
	$projectName = $projectPath |Split-Path -Leaf
	<#assert#> if( [string]::IsNullOrEmpty( $projectName ) ) { throw }
	<#assert#> if( [string]::IsNullOrEmpty( $projectPath ) ) { throw }

	# Получаем рабочую папку сборки
	$buildDirName="build-$(($PSVersionTable.OS -split ' ')[0])"
	$buildDirPath = Join-Path "$projectPath" "$buildDirName"
	if( -not ( Test-Path "$buildDirPath" ) ) {
		mkdir -p "$buildDirPath"
	}

	# Запускаем тестирование проекта
	&{
		Push-Location "$buildDirPath" `
		&& ctest -VV -C $buildType

		Pop-Location
	}
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
