#include "clExplicit.h"
#include <iostream>



clExplicit::clExplicit()
{
    m_count += 1;
    //ctor
}

clExplicit::clExplicit(int n)
{
    m_count += 1;
    m_val_int = n;
    //ctor
}

clExplicit::clExplicit(const char* str_, int n)
{
    m_count += 1;
    m_str = str_;
    m_val_int = n;
    //ctor
}

clExplicit::~clExplicit()
{
    //dtor
}

void clExplicit::out_Expl(int n)
{
    if(n == 1){
        std::cout << "\n<<< Опыты исследования ключевого слова implicit >>>\n" << std::endl;
    }
    std::cout << "Опыт по порядку: " << n << std::endl;
    std::cout << "m_str:" << m_str << std::endl;
    std::cout << "m_val_int:" << m_val_int << std::endl;
    std::cout << "Всего создано экземпляров m_count: " << m_count << "\n" << std::endl;
}


