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

    int i, temp, n;
    while(cin >> n)
    {
        if( !n)
        {
            break;
        }
        int maxi = 0, sum = 0;
        for(i = 0; i< n; ++i)
        {
            cin >> temp;
            sum += temp;
            if( sum < 0)
                sum = 0;
            else if( sum > maxi)
                maxi = sum;
        }
        if( maxi <= 0)
        {
            cout << "Losing streak.\n";
        }
        else
        {
            cout << "The maximum winning streak is "<< maxi <<".\n";
        }
    }
}
