#ifndef CLEXPLICIT_H
#define CLEXPLICIT_H

//--- https://metanit.com/cpp/tutorial/5.7.php
class clExplicit
{
    public:
        explicit clExplicit();
        explicit clExplicit(int);
        explicit clExplicit(const char*, int n = 0);

        virtual ~clExplicit();

        void out_Expl(int n);

    protected:

    private:
        //--- Обратите внимание, после static идет ключевое слово inline.
        //--- Это ключевое слово в принципе необязательно для статических
        //--- переменных и необходимо конкретно в данном случае для
        //--- инициализации переменной count. В данном случае нулем.
        static inline unsigned m_count{};

        int m_val_int = 0;
        const char* m_str = "nul";
};

#endif // CLEXPLICIT_H
