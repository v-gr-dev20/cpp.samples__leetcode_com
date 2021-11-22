#!/bin/bash
# Скрипт запускает тестирование проекта
# Скрипт определяет месторасположение проекта для сборки исходя из собственного месторасположения в папке /sources/<project>/scripts

projectPath=$(dirname $(readlink -m $(dirname $(readlink -m "$0"))))
buildDirName=build-$(uname -s)
buildType=${1:-Release}
cd "$projectPath/$buildDirName/$buildType" \
	&& ctest -VV -C "$buildType"
