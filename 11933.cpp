#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second


int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bitset <32> biter, calc;
    long long int n, a, b;
    bool flip_a;
    while(true)
    {
        cin >> n;
        if(n==0)
            break;
        biter = n;
        calc.reset();
        flip_a = true;
        for(int i = 0; i< 32; i++)
        {
            if(biter[i])
            {
                if(flip_a)
                {
                    flip_a =false;
                    calc.set(i);
                }
                else
                {
                    flip_a = true;
                    continue;
                }
            }
        }
        a = calc.to_ulong();
        b = n-a;
        cout << a<<" "<< b <<"\n";
    }
}


