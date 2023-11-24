#include "clTutPair.h"

#include <iostream>
#include <tuple>
#include <vector>
#include <map>

#include <chrono>

clTutPair::clTutPair(int dividend_, int divisor_)
{
    m_dividend = dividend_;
    m_divisor = divisor_;

    std::cout << "\n<<< Структурированные привязки ( композиция и декомпозиция переменных) >>>" << std::endl;
    std::cout << "    всегда применяются по одному шаблону:" << std::endl;
    std::cout << "    auto [var1, var2, ...] = <выражение пары, кортежа, структуры или массива>;\n" << std::endl;
    std::cout << "    Тип может иметь модификаторы auto , const auto , const auto& и даже auto&&\n" << std::endl;
    //ctor
}

clTutPair::~clTutPair()
{
    //dtor
}

//-----------------------------------------------------------------------------------------
//--- http://server.179.ru/tasks/cpp/theory/12-pair.html
//-----------------------------------------------------------------------------------------
std::pair<int, int> divide_remainder(int dividend, int divisor)
{
    std::pair<int, int> p;
    std::pair<int, int> res;

    p = std::make_pair(dividend, divisor);
    int dv = p.first / p.second;
    int rm = p.first % p.second;
    res = std::make_pair(dv,rm);

    return res;
}

void clTutPair::fn_pair_old()
{
    std::cout << "Старая версия работы с std::pair  void fn_pair_old()\n" << std::endl;
    std::pair<int, int> dt;
    dt = std::make_pair(m_dividend, m_divisor);

    const auto result (divide_remainder(dt.first, dt.second));

    std::cout << dt.first << " / " << dt.second << " = "
              << "( " << result.first << ", " << result.second << " )\n"
              << std::endl;
}

void clTutPair::fn_pair_new()
{
    std::cout << "C++17 Новая версия работы с std::pair  void fn_pair_new()\n" << std::endl;
    std::pair<int, int> dt;
    dt = std::make_pair(m_dividend, m_divisor);

    auto [fraction, remainder] = divide_remainder(dt.first, dt.second);

    std::cout << dt.first << " / " << dt.second << " = "
              << "( " << fraction << ", " << remainder << " )\n"
              << std::endl;
}

//-----------------------------------------------------------------------------------------
//--- https://www.educative.io/courses/cpp-standard-library-including-cpp-14-and-cpp-17/tuples
//-----------------------------------------------------------------------------------------

using std::get;

std::tuple< std::string, int, float>
stock_info()
{
    auto tp = std::make_tuple("Tuple example: ", -4321, 3.1415926);
    return tp;
}

void clTutPair::fn_tuple()
{
    std::cout << "Старая версия работы с std::tuple void fn_tuple()\n" << std::endl;
    auto tp1 = stock_info();
    std::cout << get<0>(tp1) << "\t" << get<1>(tp1) << "\t" << get<2>(tp1) << "\n" << std::endl;

    std::cout << "C++17 Новая версия работы с std::tuple void fn_tuple()\n" << std::endl;
    const auto [name, val_int, val_float] = stock_info();
    std::cout << name << "\t" << val_int << "\t" << val_float << "\n"  << std::endl;
}

//-----------------------------------------------------------------------------------------
//--- Декомпозицию можно применять и для пользовательских структур
//-----------------------------------------------------------------------------------------

void clTutPair::fn_struct()
{
    struct employee
    {
        unsigned id;
        std::string name;
        std::string role;
        unsigned salary;
    };

    std::vector<employee> employees {{1, "Ivan", "master", 1278},
        {2, "Alex", "ingener", 1050}};

    std::cout << "C++17 распаковка из вектора структур в цикле void fn_struct()\n" << std::endl;
    for (const auto &[id, name, role, salary] : employees)
    {
        std::cout << "ID: " << id
                  << "\tName: " << name
                  << "\tRole: " << role
                  << "\tSalary: " << salary << std::endl;
    }
}


//-----------------------------------------------------------------------------------------
//--- Декомпозицию можно применять и для контейнеров, например std::map
//-----------------------------------------------------------------------------------------

void clTutPair::fn_map()
{
    std::cout << "C++17 распаковка map в цикле void fn_map()\n" << std::endl;

std::map<std::string, size_t> animal_population {

    {"humans", 7000000000},
    {"chickens", 17863376000},
    {"camels", 24246291},
    {"sheep", 1086881528},
    /* ... */
    };

    for (const auto &[species, count] : animal_population)
    {
        std::cout << "На планете проживает\t" << count << "\t" << species << "\n" << std::endl;
    }
}
