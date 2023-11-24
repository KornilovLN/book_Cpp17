/*==================================================================================
//--- С++17 STL. Стандартная библиотека шаблонов. Галовиц Яцек
//----------------------------------------------------------------------------------

Компиляция и запуск примеров

Весь код из этой книги был разработан и протестирован в операционных систе-
мах Linux и MacOS с использованием компиляторов
    GNU C++,
    g++,
    LLVM C++,
    clang++.

Можно сгенерировать пример из командной оболочки
с помощью g++ следующей командой:

$ g++ -std=c++1z -o recipe_app recipe_code.cpp

Аналогичная команда с использованием clang++:

$ clang++ -std=c++1z –o recipe_app recipe_code.cpp

Оба примера командной строки предполагают, что recipe_code.cpp является
текстовым файлом, содержащим ваш код С++.
После компиляции программы исполняемый бинарный файл получит имя recipe_app,
его можно будет запустить следующим образом:

$ ./recipe_app

Во многих примерах мы считываем все содержимое файлов через стандартный
ввод.
В таких случаях мы используем стандартные каналы UNIX и команду cat,
чтобы направить содержимое файла в наше приложение:

$ cat file.txt | ./recipe_app

Это работает в ОС Linux и MacOS. В оболочке Microsoft Windows команда выглядит так:

> recipe_app.exe < file.txt

Если вы запускаете программы не из оболочки, а из интегрированной среды
разработки Microsoft Visual Studio,
то вам нужно открыть вкладку Configuration properties  Debugging
(Свойства конфигурацииОтладка)
и добавить фрагмент

< file.txt в командную строку приложения, которое запускает Visual Studio.

https://progtips.ru/instrumenty-programmista/codeblocks-v-voprosax-i-otvetax.html
==================================================================================*/

#include <iostream>
#include "clTutPair.h"
#include "clTutScope.h"
#include "clExplicit.h"
#include "clSwitchTest.h"
#include "clFsmTable.h"

using namespace std;

auto main() -> int
{
    //--- Создали класс 1-й работы с pair<int, int>
    //--- и выполнили  старым и новым C++17 методом
    clTutPair tutPair {17, 3};

    tutPair.fn_pair_old();
    tutPair.fn_pair_new();

    //--- Аналогично с tuple
    tutPair.fn_tuple();

    //--- Аналогично со struct
    tutPair.fn_struct();

    //--- Аналогично с map
    tutPair.fn_map();

    //--- область видимости переменных в if и switch
    //----------------------------------------------
    clTutScope scope {};
    scope.IfAndSwitch();

    //--- Explicit как это работает на примерах созд
    //--- экземпляров класса разными способами
    //----------------------------------------------
    clExplicit e1;
    clExplicit e2 = clExplicit(11);
    clExplicit e3(24);
    clExplicit e4 = clExplicit("StarmarkLN");
    clExplicit e5 = (clExplicit)5;
    clExplicit e6 = static_cast<clExplicit>(6);
    clExplicit* p = new clExplicit(1828);

    e1.out_Expl(1);
    e2.out_Expl(2);
    e3.out_Expl(3);
    e4.out_Expl(4);
    e5.out_Expl(5);
    e6.out_Expl(6);
    p->out_Expl(7);

    //--- Тест FSM switch технологии: --------------
    //--- https://habr.com/ru/articles/241941/
    //----------------------------------------------
    clSwitchTest swt{};
    swt.doFSM();


    //--- Тест FSM табличной технологии: -----------
    //--- https://ru.stackoverflow.com/questions/725062/%D0%A1%D0%B8-%D0%BC%D0%B0%D1%81%D1%81%D0%B8%D0%B2-%D1%83%D0%BA%D0%B0%D0%B7%D0%B0%D1%82%D0%B5%D0%BB%D0%B5%D0%B9-%D0%BD%D0%B0-%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%B8-%D1%81-%D1%80%D0%B0%D0%B7%D0%BD%D1%8B%D0%BC%D0%B8-%D1%82%D0%B8%D0%BF%D0%B0%D0%BC%D0%B8-%D0%B0%D1%80%D0%B3%D1%83%D0%BC%D0%B5%D0%BD%D1%82%D0%BE%D0%B2
    //----------------------------------------------
    //--- Тест FSM табличной технологии:
    //--- Инициализация init(); взводит внутренний m_enabled=true;
    //--- В самом автомате FSM сигнал signF 2-жды подряд пришедший переводит в stExit
    //--- а внутренняя activity функция данного статуса сбрасывает m_enabled=false;
    //--- и содержимое автомата становится недоступным.
    //--- Но сам автомат находится в состоянии standby и готов к рестарту.
    //--- Может быть запущен методом init();
    //--- При этом следует не выходить за пределы объемлющего цикла
    //--- по этой работе можно еще ознакомится с
    //----------------------------------------------

    //--- Создаем экземпляр автомата
    clFsmTable fsmt{};

    std::cout << "\n<<< Первый запуск автомата: init() >>>" << std::endl;
    fsmt.init();

    while(fsmt.isWorking())
    {
        eSignals1_t tmp_signal = fsmt.getSignal();
        fsmt.doFSM(tmp_signal);
    }

    std::cout << "\n<<< Восстановим работу автомата: init() >>>" << std::endl;
    fsmt.init();

    while(fsmt.isWorking())
    {
        eSignals1_t tmp_signal = fsmt.getSignal();
        fsmt.doFSM(tmp_signal);
    }

    //======================================================

    std::cout << "\n<<< Конец программы >>>\n" << std::endl;
    return 0;
}


