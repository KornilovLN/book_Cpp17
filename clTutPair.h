#ifndef CLTUTPAIR_H
#define CLTUTPAIR_H

class clTutPair
{
    public:
        clTutPair(int, int);
        virtual ~clTutPair();

        //-------------------------
        void fn_pair_old();
        void fn_pair_new();
        //-------------------------
        void fn_tuple();
        //-------------------------
        void fn_struct();
        //-------------------------
        void fn_map();

    protected:

    private:
        int m_dividend;
        int m_divisor;
};

#endif // CLTUTPAIR_H
