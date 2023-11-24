#include "clSwitchTest.h"
#include <iostream>

#include <stdio.h>
#include <string>

clSwitchTest::clSwitchTest()
{
    std::cout << "\n<<< Простой пример FSM (реализация посредством switch) >>>" << std::endl;
    std::cout << "<<< Сигналы - нажатие клавиш 'I','W','F' и Enter >>>" << std::endl;
    std::cout << "<<< Состояние автомата будет меняться между: >>>" << std::endl;
    std::cout << "<<< st_init, st_work, st_final >>>" << std::endl;
    //ctor
}

clSwitchTest::~clSwitchTest()
{
    //dtor
}

eSignals_t clSwitchTest::getSignal()
{
    char ch = std::cin.get();

    switch (toupper(ch)) {
    case 'I': return sign_I;
    case 'W': return sign_W;
    case 'F': return sign_F;
    default: return  sign_Err;
    }

}

void clSwitchTest::out()
{
    std::string st = "";
    std::string sg = "";

    switch (m_current_state) {
    case st_init: st = "st_init"; break;
    case st_work: st = "st_work"; break;
    case st_final:st = "st_final";break;
    case st_exit: st = "st_exit" ;break;
    }

    switch (m_current_signal) {
    case sign_I: sg = "sign_I"; break;
    case sign_W: sg = "sign_W"; break;
    case sign_F: sg = "sign_F"; break;
    }

    std::cout << "State: " << st << " , Signal: " << sg << std::endl;
}

void clSwitchTest::ExitMessage()
{
    std::cout << "Полный выход из автомата" << std::endl;
}

void clSwitchTest::doFSM()
{
    m_current_state = st_init;

    while (1)
    {
        m_current_signal = getSignal();

        switch (m_current_state)
        {
            case st_init:
                switch (m_current_signal)
                {
                    case sign_I:
                        m_current_state = st_work;
                        break;
                    case sign_W:
                        m_current_state = st_work;
                        break;
                    case sign_F:
                        m_current_state = st_final;
                        break;
                }
                break;
            case st_work:
                switch (m_current_signal)
                {
                    case sign_I:
                        m_current_state = st_init;
                        break;
                    case sign_W:
                        m_current_state = st_work;
                        break;
                    case sign_F:
                        m_current_state = st_final;
                        break;
                }
                break;
            case st_final:
                switch (m_current_signal)
                {
                    case sign_I:
                        m_current_state = st_init;
                        break;
                    case sign_W:
                        m_current_state = st_init;
                        break;
                    case sign_F: //--- выйти из программы
                        m_current_state = st_exit;
                        break;
                }
                break;
        }

        out();

        if (m_current_state == st_exit) {
            ExitMessage();
            break;
        }
    }
}
