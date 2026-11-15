
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <stdexcept>

using namespace std;

using ull = unsigned long long;
using ld = long double;

class HarmonicNumber
{
private:
    ull n;
    ld H_n;

public:

    // Constructor
    explicit HarmonicNumber(ull num)
        : n(num), H_n(0.0L)
    {
    }

    // Calculate H_n using Kahan compensated summation
    ld calculate()
    {
        H_n = 0.0L;

        ld compensation = 0.0L;

        for (ull k = 1; k <= n; ++k)
        {
            ld term = 1.0L / static_cast<ld>(k);

            ld corrected_term = term - compensation;

            ld temporary_sum = H_n + corrected_term;

            compensation = (temporary_sum - H_n) - corrected_term;

            H_n = temporary_sum;
        }

        return H_n;
    }

    // Return the calculated harmonic number
    ld get_value() const
    {
        return H_n;
    }

    // Return the input integer
    ull get_n() const
    {
        return n;
    }
};

// Standalone test
int main()
{
    ull num;

    cout << "Enter an integer n >= 1: ";

    if (!(cin >> num) || num < 1)
    {
        cerr << "Invalid input. Enter a positive integer.\n";
        return 1;
    }

    HarmonicNumber harmonic(num);

    ld result = harmonic.calculate();

    cout << scientific << setprecision(18);

    cout << "\n========== HARMONIC NUMBER ==========\n";

    cout << "n = " << harmonic.get_n() << '\n';

    cout << "H_n = " << result << '\n';

    cout << "====================================\n";

    return 0;
}
