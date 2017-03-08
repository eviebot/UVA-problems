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

    int n, i, k, j, t, sum;

    while(true)
    {
        cin >> n;
        if(n==0)
            break;
        multiset <int> myset;
        multiset <int>::iterator BEG, END;
        sum = 0;
        for(i = 0; i< n; i++)
        {
            cin >> k;
            for( j = 0; j< k ; j++)
            {
                cin >> t;
                myset.insert(t);
            }
            BEG = myset.begin();
            END = myset.end();
            --END;

            sum += (*END - *BEG);
            myset.erase(BEG);
            myset.erase(END);
        }
        cout << sum <<"\n";
    }
}
