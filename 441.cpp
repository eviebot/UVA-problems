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

    int val, i, j, k, l, m, n;
    bool flag = false;
    while(true)
    {
        cin >> val;
        if(!val)
            break;
        if(flag)
            cout << "\n";
        flag = true;
        int arr[val];
        for( i = 0; i < val; i++)
        {
            cin >> arr[i];
        }

        for(i = 0; i < val - 5; ++i)
        {
            for( j = i+1; j < val-4;++j)
            {
                for( k = j+1; k < val-3 ; ++k)
                {
                    for(l = k+1; l< val-2; ++l)
                    {
                        for(m = l+1; m < val-1; ++m)
                        {
                            for( n= m+1; n < val; ++n)
                            {
                                cout << arr[i]<<' '<< arr[j]<<' '<< arr[k]<<' '<< arr[l]<<' '<< arr[m]<<' '<< arr[n]<<"\n";
                            }
                        }
                    }
                }
            }
        }
    }
}
