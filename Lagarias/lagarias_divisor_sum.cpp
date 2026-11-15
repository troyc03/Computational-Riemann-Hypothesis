
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

using ull = unsigned long long;
using ld = long double;

class Lagarias
{
private:
    ull n;
    ull sigma_n;
    ld H_n;

public:

    // Constructor
    Lagarias(ull num)
        : n(num), sigma_n(0), H_n(0.0L)
    {
    }

    // Calculate the sum of positive divisors
    void calculate_sigma()
    {
        sigma_n = 0;

        for (ull i = 1; i <= n / i; ++i)
        {
            if (n % i == 0)
            {
                sigma_n += i;

                ull paired = n / i;

                if (paired != i)
                    sigma_n += paired;
            }
        }
    }

    // Calculate the harmonic number
    void calculate_harmonic()
    {
        H_n = 0.0L;

        for (ull i = 1; i <= n; ++i)
        {
            H_n += 1.0L / i;
        }
    }

    // Calculate the Lagarias upper bound
    ld calculate_bound() const
    {
        return H_n + exp(H_n) * log(H_n);
    }

    // Calculate the Lagarias residual
    ld calculate_residual() const
    {
        return calculate_bound() - static_cast<ld>(sigma_n);
    }

    // Display results
    void display_results() const
    {
        ld bound = calculate_bound();
        ld residual = calculate_residual();

        cout << scientific << setprecision(15);

        cout << "\n========== LAGARIAS CRITERION ==========\n";

        cout << "n = " << n << '\n';
        cout << "sigma(n) = " << sigma_n << '\n';
        cout << "H(n) = " << H_n << '\n';
        cout << "Upper bound = " << bound << '\n';
        cout << "Residual L(n) = " << residual << '\n';

        cout << "\nInequality:\n";

        cout << sigma_n << " <= " << bound << '\n';

        if (residual > 0)
        {
            cout << "Result: Inequality satisfied strictly.\n";
        }
        else if (residual == 0)
        {
            cout << "Result: Equality.\n";
        }
        else
        {
            cout << "Result: Apparent inequality violation.\n";
            cout << "Independent numerical verification required.\n";
        }

        cout << "========================================\n";
    }
};

int main()
{
    ull num;

    cout << "Enter an integer n >= 2: ";

    if (!(cin >> num) || num < 2)
    {
        cerr << "Invalid input. Enter an integer greater than or equal to 2.\n";
        return 1;
    }

    Lagarias calculation(num);

    calculation.calculate_sigma();
    calculation.calculate_harmonic();

    calculation.display_results();

    return 0;
}
