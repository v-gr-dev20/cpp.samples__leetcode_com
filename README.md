Это репозиторий с С++ решениями задач по программированию из списка [leetcode.com](https://leetcode.com/problemset/all/).
После сборки проекта получается консольная программа-монолит, выполняющая проверочные тесты gtest, которые демонстрируют работоспособность алгоритмов.

### Права
[MIT License](LICENSE)

### Содержание
[ Цели ](#goals)\
[ Кто автор ](#author)\
[ Из чего состоит ](#consist)\
[ Как воспроизвести результаты на leetcode.com ](#leetcode)\
[ Как развернуть и воспроизвести результаты в Windows ](#windows)\
[ Как развернуть и воспроизвести результаты в linux ](#linux)\
[ Как посмотреть на готовую сборку и результаты тестов ](#build)

<a id="goals"></a>
### Цели
Представленные в этом проекте решения задач из списка [leetcode.com](https://leetcode.com/problemset/all/) интересны сами по себе.\
Помимо этого достигаются еще четыре цели:\
	- хранение репозитория решенных задач, при этом должна быть возможность вручную скопировать решение "as-is" и проверить работоспособность на leetcode.com,\
	- создание и поддержание инфраструктуры программных модулей для разработки, отладки и тестирования решений задач с leetcode.com,\
	- демонстрация работоспособности алгоритмов решенных задач с выводом в консоли результатов работы проверочных тестов. После успешного решения очередной задачи демонстрационный набор тестов пополняется тестами для решенной задачи,\
	- проверка работоспособности на разных платформах.

<a id="author"></a>
### Кто автор
v.gr.dev20@gmail.com

<a id="consist"></a>
### Из чего состоит
Из однородных C++ модулей для каждой решенной задачи с leetcode.com и вспомогательных инфраструктурных модулей: ввод-вывод, обработка ошибок, запуск, тесты. Решения задач находятся в файлах [./src/\*_solution.cpp](samples01/src) внутри анонимного``` namespace{/*здесь*/}```. Тесты gtest размещены в [./test/tests.cpp](samples01/test/tests.cpp). Преднастройка gtest и запуск - в [./test/main.cpp](samples01/test/main.cpp). Вспомогательные программные модули - в [../common/\*.cpp,\*.h](common).\
Для добавления нового модуля задачи, например ```new_sample```, достаточно добавить в проект три файла:\
	- [./src/new_sample.h](samples01/src/new_sample.h) - определение ```class new_sample: public CBaseSample```, наследующего интерфейс [ISample](common/BaseSample.h#L13-L25),\
	- [./src/new_sample.cpp](samples01/src/new_sample.cpp) - реализация интерфейса ```ISample``` для нового класса ```new_sample``` с определением уникального идентификатора в конструкторе ```CBaseSample("```[new_sample](samples01/src/new_sample.cpp#:~:text=%3A%20CBaseSample(-,%22new_sample%22,-))```")```,\
	- [./src/new_sample_solution.cpp](samples01/src/new_sample_solution.cpp) - основной алгоритм решения в формате, который требуется на leetcode.com, и реализация интерфейса запуска решения [Run](samples01/src/new_sample_solution.cpp#L22-L25),\
 Еще следует добавить в [./test/tests.cpp](samples01/test/tests.cpp#L10-L19) набор тестов, соответствующих примерам ввода-вывода в заключительной части описания задачи на [leetcode.com/problems/*](https://leetcode.com/problems/4sum/). Добавляемые тесты и модули примеров с решениями будут скомпонованы в runtime посредством идентификатора [new_sample](samples01/test/tests.cpp#:~:text=TEST(-,new_sample,-%2C%20EXPECT_EQ01%20)%20%7B).

<a id="leetcode"></a>
### Как воспроизвести результаты на leetcode.com
1. Перейти по ссылке на задачу в одном из файлов с решениями [./src/*_solution.cpp](samples01/src), например в [./src/leetcode_com__4Sum__solution.cpp](samples01/src/leetcode_com__4Sum__solution.cpp#L1-L3) :
```
// 18. 4Sum
// Medium
// https://leetcode.com/problems/4sum/
```
2. Скопировать из файла [./src/*_solution.cpp](samples01/src/leetcode_com__4Sum__solution.cpp) код внутри ```namespace{```[/\*здесь\*/](samples01/src/leetcode_com__4Sum__solution.cpp#L33-L92)```}```
 и заменить им весь код ```class Solution``` на открывшейся странице [leetcode.com/problems/*](https://leetcode.com/problems/4sum/) .
3. Нажать ```[Run Code]``` внизу страницы [leetcode.com/problems/*](https://leetcode.com/problems/4sum/).

<a id="windows"></a>
### Как развернуть и воспроизвести результаты в Windows c Microsoft Visual Studio 2019 и gtest
1. Установить и настроить [git](https://git-scm.com/book/ru/v2/%D0%92%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D0%B5-%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0-Git), [Microsoft Visual Studio 2019](https://docs.microsoft.com/ru-ru/visualstudio/install/install-visual-studio?view=vs-2019) и [gtest](https://docs.microsoft.com/ru-ru/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2019).
2. Выполнить
```
mkdir demo `
&& git clone --branch dev -- https://github.com/v-gr-dev20/cpp.samples__leetcode_com.git demo `
&& demo/mssln/samples__leetcode_com.sln
```
3. В Visual Studio нажать ```[F5]``` для старта процесса сборки и запуска в отладчике целевой программы с выводом в консоли результатов тестов в формате gtest.

<a id="linux"></a>
### Как развернуть и воспроизвести результаты в linux с gcc, cmake и gtest
1. Установить и настроить [git](https://git-scm.com/book/ru/v2/%D0%92%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D0%B5-%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0-Git), [gcc](https://gcc.gnu.org/), [cmake](https://cmake.org/install/) и [gtest](https://github.com/google/googletest/tree/master/googletest#readme).
2. Выполнить
```
mkdir demo \
&& git clone --branch dev -- https://github.com/v-gr-dev20/cpp.samples__leetcode_com.git demo \
&& bash demo/samples01/scripts/build-Linux.sh \
&& bash demo/samples01/scripts/test-Linux.sh
```
При этом ожидается старт процесса сборки проекта, после чего следует выполнение целевой программы с выводом в консоли результатов тестов в формате gtest.

<a id="build"></a>
### Как посмотреть на готовую сборку и результаты тестов для разных платформ
[![Build status](https://ci.appveyor.com/api/projects/status/j1t6h0x4o1cywss7?svg=true)](https://ci.appveyor.com/project/v-gr-dev20/cpp-samples-leetcode-com)
