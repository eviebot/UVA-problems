#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    long long int storage[1415], d, k, i, test_cases, term, deg, bn, prod;
    vector <int> aN;

    for(i = 1; i<= 1415; i++)
    {
        storage[i-1] = i*(i+1)/2 ;
    }

    cin >> test_cases;

    for(int g = 0; g < test_cases; g++)
    {
        aN.clear();
        bn = 0;
        cin >> deg;
        for(i = 0; i<= deg; i++)
        {
            cin >> term;
            aN.pb(term);
        }

        cin >> d >> k;

        for(term = 0; term < 1415; term++)
        {
            if( d * storage[term] >= k)
            {
                term++;
                //cout << term <<"\n\n";
                break;
            }
        }
        prod = 1;
        for(i = 0; i<= deg; i++)
        {
            bn += prod * aN.at(i);
            prod *= term;
        }

        cout << bn << "\n";
    }
}
