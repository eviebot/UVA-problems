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


    int i, j, sum, q, a, n, num1, tsum, lel = 0, i1;

    while(true)
    {
        cin >> a;
        ++lel;
        if(a==0)
            break;
        cout << "Case "<< lel <<":\n";
        int num[a];
        for(i = 0; i< a; i++)
        {
            cin >> num[i];
        }

        cin >> q;
        for(i1 = 0; i1< q; ++i1)
        {
            cin >> n;
            tsum = abs(num[0] + num[1] - n);
            sum = num[0] + num[1];
            for(i = 0; i < a; i++)
            {
                num1 = num[i];
                for(j = i+1; j< a; j++)
                {
                    if( abs(n - (num1 + num[j]) ) < tsum)
                    {
                        tsum = abs(n - (num1 + num[j]) );
                        sum = num1 + num[j];
                    }
                }
            }
            cout << "Closest sum to "<< n<<" is "<< sum <<".\n";
        }
    }
}
