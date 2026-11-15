#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

using ull = unsigned long long;
using ld = long double;

class oper
{
    private:
        ull n;
        ull pos_sum;
        ld H_sum;
    
    public:
        oper() { n = 0; pos_sum = 0; H_sum = 0; }

        oper(ull num) // type
         { n = num; pos_sum = 0; H_sum = 0; }

         // member
         void KVal()
         {
            for (ull i = 1; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    pos_sum += i;
                }
            }
         }
         void H_sum_calc()
         {
            for (ull i = 1; i<= n; i++)
            {
                H_sum += (1.0L / i);
            }
         }
        
         void getn(ull num) { n = num; }
         ld getHn() { return H_sum; }
         ld getdiv() { return pos_sum; }
};

int main()
{
    oper devisor;
    ull num;
    cout << "what int n > 1? (1.84* 10^19 allowence): ";
    cin >> num;

    devisor.getn(num);
    devisor.KVal();

    oper Harmfunc(num);
    Harmfunc.H_sum_calc();

    ld div = devisor.getdiv();
    ld Hn = Harmfunc.getHn();
    ld expHn = exp(Hn);
    ld logHn = log(Hn);

    if (div <= Hn + expHn * logHn)
    {
        cout << "for n = " << num << '\n'
             << "the equation for the Lagarius inequality is: \n"
             << div << " <= " << Hn << " + " << expHn << " * " << logHn << '\n'
             << div << " <= " << Hn + expHn * logHn << '\n';
    }
    else { cout << "for n = " << num << '\n'
                << "The Lagarius inequality is wrong (something is wrong): \n"
                << div << " <= " << Hn << " + " << expHn << " * " << logHn << '\n'
                << div << " > " << Hn + expHn * logHn << '\n'; }
    return 0;

}