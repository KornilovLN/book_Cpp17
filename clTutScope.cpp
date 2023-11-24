#include "clTutScope.h"

#include <iostream>
#include <tuple>
#include <vector>
#include <map>

clTutScope::clTutScope()
{
    std::cout << "\n<<< Ограничиваем область видимости переменных в выражениях if и switch >>>" << std::endl;
    std::cout << "    в С++17 была введена инициализация переменных в выражениях if и switch" << std::endl;
    //ctor
}

clTutScope::~clTutScope()
{
    //dtor
}

//--- https://codelessons.dev/ru/map-v-c-chto-eto-i-kak-s-etim-rabotat/

void clTutScope::IfAndSwitch()
{
    std::map <uint8_t, char> ch_map = { {0x0, '@'},
                                        {0x1, 'A'},{0x2, 'B'},{0x3, 'C'},
                                        {0x4, 'D'},{0x5, 'E'},{0x6, 'F'}};

    std::cout << "\n<<< Например: if (auto itr (ch_map.find(0x5)); itr != ch_map.end()) {...} >>>" << std::endl;
    if (auto itr (ch_map.find(0x5)); itr != ch_map.end()) {
        std::cout << "Iter: " << itr->first << ",   Val: " << itr->second << std::endl;
    } else {
        // itr является конечным итератором. Не разыменовываем.
    }

    if (auto itr (ch_map.find(0)); itr != ch_map.end()) {
        std::cout << "Iter: " << itr->first << ",   Val: " << itr->second << std::endl;
    } else {
        // itr является конечным итератором. Не разыменовываем.
    }

    std::cout << "\n<<< Например: switch (char ch (getchar()); ch) {...} >>>" << std::endl;

        switch (char ch (getchar()); ch) {
           case 'A': std::cout << "Был введен символ:" << "\t" << ch << '\n';  break;
           case 'B': std::cout << "Был введен символ:" << "\t" << ch << '\n';  break;
           case 'C': std::cout << "Был введен символ:" << "\t" << ch << '\n';  break;
           case '0'...'9':std::cout << "Была введена цифра:"  << "\t" << ch << '\n';  break;
           case 'Q': break;

           default: std::cout << "invalid input: " << ch << '\n';
        }

}
