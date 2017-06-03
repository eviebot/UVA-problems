#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

typedef long long int lli;
ofstream outfile;
ifstream infile;

int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);

    int n, i, j, tem, k, maxi, sum ;

    while( cin >> n)
    {
        vector <vector <int>> orig;
        vector <vector <vector <int>>> storage;
        vector <int> temp;
        maxi = 0;
        for(i = 0; i<= n; ++i)
        {
            temp.pb(0);
        }
        for(i = 0; i<= n; ++i)
        {
            orig.pb(temp);
        }
        for(i = 0; i<= n; ++i)
        {
            storage.pb(orig);
        }

        for(i = 1; i<= n; ++i)
        {
            for(j = 1; j<= n; ++j)
            {
                cin >> tem;
                orig[i][j] = tem;
                storage[j][j][i] = tem;
                maxi += tem;
            }
        }

        for(j = 1; j<= n; ++j)
        {
            for(k = j; k<= n; ++k)
            {
                sum = 0;
                if( j == k )
                {
                    for( i = 1; i<= n; ++i )
                    {
                        sum += storage[j][j][i];
                        if(sum > maxi)
                            maxi = sum;
                        if(sum < 0)
                            sum = 0;

                    }
                }
                else
                {
                    for(i = 1; i<= n; ++i)
                    {
                        storage[j][k][i] = storage[j][k-1][i] + orig[i][k];
                        sum += storage[j][k][i];
                        if(sum > maxi)
                            maxi = sum;
                        if(sum < 0)
                            sum = 0;
                    }
                }
            }
        }
        cout << maxi<<"\n";
    }
}
