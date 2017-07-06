#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

typedef long long int lli;

bool comp (int a, int b)
{
    return a > b;
}
int main()
{
    ofstream outfile;
    outfile.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int T, n, temp, i;

    cin >> T;

    for(int z = 0; z < T; ++z)
    {
        cin>> n >> temp;
        vector <int> vec;
        vector <int> diff;
        vector <int>:: iterator it, m;
        vec.pb(temp);
        diff.pb(temp);
        for(i = 1 ; i< n; ++i)
        {
            cin >> temp;
            vec.pb(temp);
            diff.pb(temp - vec[i-1]);
        }
        int maxi = 0;
        it = diff.begin();
        for( ; it != diff.end(); ++it)
        {
            if( *it > maxi)
            {
                m = it;
                maxi = *it;
            }
        }
        diff.erase(diff.begin(), m);

        int k = diff[0]-1, k_max = diff[0];

        for(i = 1; i< diff.size(); ++i)
        {
            if( k == diff[i])
            {
                --k;
            }
            else if( k < diff[i] )
            {
                ++k_max;
                break;
            }

        }

        cout << "Case "<< z+1<<": "<< k_max <<"\n";
    }
}
