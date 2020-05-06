# !/usr/bin/bash
# Скрипт запускает сборку и тестирование проекта
# Скрипт определяет месторасположение проекта для сборки исходя из собственного месторасположения в папке /sources/<project>/scripts

buildDirName=build-$(uname -s)
buildType=${1:-Release}
cd $(dirname "$0")/.. \
	&& mkdir -p "$buildDirName/$buildType" \
	&& cd "$buildDirName/$buildType" \
	&& cmake -DCMAKE_BUILD_TYPE="$buildType" ../.. \
	&& cmake --build . \
	&& ctest -VV -C "$buildType"
