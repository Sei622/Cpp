#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct prime_factor_info
{
    int prime;
    int index;
};

int main()
{
    int N;
    cin >> N;
    cout << N << " = ";
    vector<prime_factor_info> prime_factor;

    for (int i = 2; i <= (int)sqrt(N); i++)
    {
        bool only = true;
        while (N % i == 0)
        {
            if (only)
            {
                prime_factor.push_back({i, 1});
                only = false;
            }
            else
            {
                prime_factor.at(prime_factor.size() - 1).index++;
            }
            N /= i;
        }
    }
    if (N != 1)
    {
        prime_factor.push_back({N, 1});
    }

    for (int i = 0; i < prime_factor.size(); i++)
    {
        if (i != 0)
        {
            cout << " * ";
        }
        cout << prime_factor.at(i).prime << " ^ " << prime_factor.at(i).index;
    }

    cin >> N;
    return 0;
}