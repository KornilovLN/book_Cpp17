#include "clFsmTable.h"
#include <iostream>

#include <stdio.h>
#include <string>

//-----------------------------------------------------------------------------------
//--- функции деятельности в некоторых состояниях
//-----------------------------------------------------------------------------------

void fnMill() {     //--- вертушка
    std::cout << "< fnMill(): in progress >" << std::endl;
}

void fnCounter() {  //--- счетчик
    std::cout << "< fnCounter(): in progress >" << std::endl;
}

void fnWaiter() {   //--- демонстрация ожидания (мигает ?)
    std::cout << "< fnWaiter(): in progress >" << std::endl;
}

void fnExit() {     //--- функция выхода автомата из работы
    std::cout << "< fnExit(): get out from FSM >" << std::endl;
}

//----------------------------------------------------------------------------------

clFsmTable::clFsmTable()
{
    std::cout << "\n<<< Простой пример FSM (реализация посредством table) >>>" << std::endl;
    std::cout << "<<< Стартует FSM методом init(), также может быть остановлена по standby() >>>" << std::endl;
    std::cout << "<<< Сигналы - нажатие клавиш 'I','W','F' и Enter >>>" << std::endl;
    std::cout << "<<< Состояние автомата будет меняться между: >>>" << std::endl;
    std::cout << "<<< st_init, st_work, st_final, st_exit >>>" << std::endl;
    std::cout << "<<< st_exit состояние приводит к выходу и остановке автомата >>>" << std::endl;

    //ctor
}

clFsmTable::~clFsmTable()
{
    //dtor
}

//-----------------------------------------------------------------------------------
//--- Методы класса
//-----------------------------------------------------------------------------------

eSignals1_t clFsmTable::getSignal()
{
    char ch = std::cin.get();

    switch (toupper(ch)) {
    case 'I': return signI;
    case 'W': return signW;
    case 'F': return signF;
    default: return  signErr;
    }
}

void clFsmTable::out()
{
    std::string st = "";
    std::string sg = "";

    switch (m_current_state) {
    case stinit: st = "stinit"; break;
    case stwork: st = "stwork"; break;
    case stfinal:st = "stfinal";break;
    case stexit: st = "stexit" ;break;
    }

    switch (m_current_signal) {
    case signI: sg = "signI";       break;
    case signW: sg = "signW";       break;
    case signF: sg = "signF";       break;
    case signErr: sg = "signErr";   break;
    case signFlush: sg ="signFlush";break;
    }

    //std::cout << "There was a <" << sg << "> SIGNAL, now the STATE is <" << st << ">" << std::endl;
    std::cout << "State: " << st << " , Signal: " << sg << std::endl;
}

void clFsmTable::ExitMessage()
{
    std::cout << "\n<<< ------------------------ >>>" << std::endl;
    std::cout << "<<< Полный выход из автомата >>>" << std::endl;
    std::cout << "<<< ------------------------ >>>" << std::endl;
}

//-----------------------------------------------------------------------------------
//--- Создание таблицы переходов;
//--- Инициализация работы автомата
//--- Методы остановки автомата и сброса переменной сигнала
//-----------------------------------------------------------------------------------

void clFsmTable::newState()
{
  FSM_table[(int)stinit][(int)signI] = stwork;
  FSM_table[(int)stinit][(int)signW] = stwork;
  FSM_table[(int)stinit][(int)signF] = stfinal;
  FSM_table[(int)stwork][(int)signI] = stinit;
  FSM_table[(int)stwork][(int)signW] = stwork;
  FSM_table[(int)stwork][(int)signF] = stfinal;
  FSM_table[(int)stfinal][(int)signI] = stinit;
  FSM_table[(int)stfinal][(int)signW] = stinit;
  FSM_table[(int)stfinal][(int)signF] = stexit;
}

void clFsmTable::newActivity()
{
  FSM_activity[stinit] = fnMill;
  FSM_activity[stwork] = fnCounter;
  FSM_activity[stfinal]= fnWaiter;
  FSM_activity[stexit] = fnExit;
}

void clFsmTable::init()
{
    //--- создали таблицу переходов
    newState();

    //--- и привязку функций деятельности к состояниям
    newActivity();

    //--- установили начальное состояние
    m_current_state = stinit;

    //--- В дальнейшем - отслеживать неудачную инициализацию
    m_enabled = true;   //--- а пока так.
}

void clFsmTable::standby()
{
    //--- добавить необходимый код правильной остановки

    m_enabled = false;
}

bool clFsmTable::isWorking()
{
    return m_enabled;
}

//--- Будет работать, когда организуем генерацию сигналов асинхронно
void clFsmTable::flushSignal()
{
    m_current_signal = signFlush;
}

//-----------------------------------------------------------------------------------
//--- Главный метод класса - автомат
//-----------------------------------------------------------------------------------

void clFsmTable::doFSM(eSignals1_t  tmp_signal)
{
    //while (m_enabled)
    if (m_enabled)
    {
        //--- получили сигнал во временный буфер
        //eSignals1_t  tmp_signal = getSignal();

        //---  и если сигнал правильный - сменили состояние по таблице
        if (tmp_signal != signErr) {
            m_current_signal = tmp_signal;
            m_current_state = FSM_table[(int)m_current_state][(int)m_current_signal];

            //--- вывели состояние и полученный сигнал
            out();

            //--- activity - Деятельность в текущем состоянии
            //--- отсюда можно принимать решение о прекращении работы автомата
            //--- или извне - задействуя метод ZB: standbyFSM()
            FSM_activity[m_current_state]();
        }

        //--- по состоянию выхода stexit завершаем работу
        if (m_current_state == stexit) {
            ExitMessage();
            standby();
            //break;
        }
    }
}



