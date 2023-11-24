#ifndef CLSWITCHTEST_H
#define CLSWITCHTEST_H

typedef enum states {
        st_init = 0,
        st_work,
        st_final,
        st_exit
}eStates_t;

typedef enum signals {
        sign_I,
        sign_W,
        sign_F,
        sign_Err
}eSignals_t;

class clSwitchTest
{
    public:
        clSwitchTest();
        virtual ~clSwitchTest();

        void doFSM();

    protected:

    private:
        void ExitMessage();
        eSignals_t getSignal();
        void out();

        eStates_t  m_current_state;
        eSignals_t m_current_signal;

        char m_key = '\0';
};

#endif // CLSWITCHTEST_H
