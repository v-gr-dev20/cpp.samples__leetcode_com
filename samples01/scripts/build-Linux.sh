#!/bin/bash
# Скрипт запускает сборку и тестирование проекта
# Скрипт определяет месторасположение проекта для сборки исходя из собственного месторасположения в папке /sources/<project>/scripts
# Скрипт выполняется в одной из трех конфигураций в порядке убывания приоритета:
#	- linux, git, gcc, cmake, gtest (не требуется доступ к внешним ресурсам),
#	- docker (требуется доступ в docker.io для получения готового образа gtest),
#	- git, docker (требуется доступ в github.com для получения Dockerfile'ов, необходимых для промежуточной сборки gtest).

assert() {
	eval "$*" || {
		echo Assertion failed: $*, $0: line $BASH_LINENO
		exit -1
	}
}

restartWithDocker() {
	assert isDockerInstalled
	docker pull vgrdev20/gtest:latest && docker image tag vgrdev20/gtest:latest gtest:latest \
	|| {
			assert 'isDockerInstalled && isGitInstalled'
			mkdir images \
			&& git clone --branch gtest-docker-images -- https://github.com/v-gr-dev20/gtest-docker-images.git images \
			&& bash images/scripts/build.sh gcc-gdb-locales \
			&& bash images/scripts/build.sh cmake \
			&& bash images/scripts/build.sh gtest
	   }
	assert [ "0" == "$?" ]
	local projectMountPoint=$(readlink -m $(dirname $(dirname $(dirname $(readlink -m "$0")))))
	local projectName=$(basename $(readlink -m $(dirname $(dirname $(readlink -m "$0")))))
	local thisScriptDirName=$(basename $(readlink -m $(dirname $(readlink -m "$0"))))
	local thisScriptShortName=$(basename "$0" |sed 's/.sh$//')
	docker run --rm -t -v "${projectMountPoint}":/sources gtest bash "/sources/${projectName}/${thisScriptDirName}/${thisScriptShortName}.sh" "$@"
	exit $?
}

isGccInstalled() {
	gcc --version > /dev/null 2>&1
}

isDockerInstalled() {
	docker --version > /dev/null 2>&1
}

isCmakeInstalled() {
	cmake --version > /dev/null 2>&1
}

isGitInstalled() {
	git --version > /dev/null 2>&1
}

isGtestInstalled() {
	test -f /usr/include/gtest/gtest.h \
	|| test -f /usr/local/include/gtest/gtest.h
}

isCalledFromContainer() {
	grep 'docker\|lxc' /proc/1/cgroup > /dev/null 2>&1
}

# Точка входа
if !( isGccInstalled && isCmakeInstalled && isGtestInstalled ) ;then
	assert isDockerInstalled 
	restartWithDocker "$@"
fi

assert 'isGccInstalled && isCmakeInstalled && isGtestInstalled'
buildDirName=build-$(uname -s)
buildType=${1:-Release}
cd $(dirname "$0")/.. \
	&& mkdir -p "$buildDirName/$buildType" \
	&& cd "$buildDirName/$buildType" \
	&& cmake -DCMAKE_BUILD_TYPE="$buildType" ../.. \
	&& cmake --build . \
	&& {
		if isCalledFromContainer ;then
			ctest -VV -C "$buildType"
		fi
	}
