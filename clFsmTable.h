#ifndef CLFSMTABLE_H
#define CLFSMTABLE_H


typedef enum states1{
        stinit = 0,
        stwork,
        stfinal,
        stexit
}eStates1_t;

typedef enum signals1{
        signI = 0,
        signW,
        signF,
        signErr,
        signFlush
}eSignals1_t;

class clFsmTable {

    public:
        clFsmTable();
        virtual ~clFsmTable();

        void init();
        void doFSM(eSignals1_t  tmp_signal);
        void standby();
        bool isWorking();

        eSignals1_t getSignal();//--- получает сигнал (извне: пока блокирует);

    protected:

    private:

        void newState();        //--- создает таблицу переходов
        void newActivity();     //--- создает таблицу функций активности
        void flushSignal();     //--- гасит принятый сигнал

        void out();             //--- выводит информацию о случившемся переходе
        void ExitMessage();     //--- выводит информацию о конце работы

        //--- главные переменные автомата
        eStates1_t  m_current_state;    //--- состояние автомата (из перечисления)
        eSignals1_t m_current_signal;   //--- переменная сигнала (из перечисления)

        char m_key = '\0';              //--- принимает сигнал от клавиатуры

        //--- массив указателей на функции активности типа void
        void (*FSM_activity[4])();

        //--- массив для таблицы переходов автомата
        eStates1_t FSM_table[4][4];

        bool m_enabled;                 //--- служит сигналом к остановке или разрешеия
};

#endif // CLFSMTABLE_H
