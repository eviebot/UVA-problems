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

    int spf, spb, i, j, teeth, len;
    double RATIO;
    cout << fixed << setprecision(2);
    while(true)
    {
        cin >> spf ;
        if(spf == 0)
            break;
        cin >> spb;
        RATIO = 1.0;
        vector <int> stor;
        set <double> myset;
        set <double>::iterator it, END, prev;
        for(i = 0; i< spf; ++i)
        {
            cin >> teeth;
            stor.pb(teeth);
        }
        len = stor.size();
        for(i = 0; i< spb; i++)
        {
            cin >> teeth;
            for(j = 0; j< len; ++j)
            {
                myset.insert( (double)(teeth) / stor[j] );
            }
        }

        END = myset.end();
        for(it = ++myset.begin(), prev = myset.begin() ; it != END; ++it, ++prev)
        {
            if( *it / *prev > RATIO)
                RATIO = *it / *prev;
        }

        cout << RATIO <<"\n";
    }
}
