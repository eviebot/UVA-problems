#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;
ofstream outfile;
ifstream infile;

int n;
vector <int> temp;
vector <bool> visited(26), nodes(26);
int DPY[26][26][26], DPM[26][26][26];

int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);

    int i, j, k;
    char age, decision, city1, city2, pos1, pos2;
    int energy;
    while(cin >> n)
    {
        if( !n)
            break;

        for(i = 0; i < 26; ++i)
        {
            for(j = 0; j < 26; ++j)
            {
                DPY[i][j][0] = 999999;
                DPM[i][j][0] = 999999;
            }
        }
        for(i = 0; i < n; ++i)
        {
            cin >> age >> decision >> city1 >> city2 >> energy;
            if( age == 'Y')
            {
                DPY[city1-'A'][city2-'A'][0] = energy;

                if( decision == 'B')
                {
                    DPY[city2-'A'][city1-'A'][0] = energy;
                }
            }
            else
            {
                DPM[city1-'A'][city2-'A'][0] = energy;
                if( decision == 'B')
                {
                    DPM[city2-'A'][city1-'A'][0] = energy;
                }
            }
        }
        cin >> pos1 >> pos2;
        for(i = 0; i < 26; ++i)
        {
            for(j = 0; j < 26; ++j)
            {
                if( i == j)
                {
                    DPY[i][j][0] = 0;
                    DPM[i][j][0] = 0;
                }
            }
        }
        for(k = 1; k < 26; ++k)
        {
            for(i = 0; i < 26; ++i)
            {
                for(j = 0; j < 26; ++j)
                {
                    DPY[i][j][k] = min(DPY[i][j][k-1], DPY[i][k][k-1]+DPY[k][j][k-1]);
                    DPM[i][j][k] = min(DPM[i][j][k-1], DPM[i][k][k-1]+DPM[k][j][k-1]);
                }
            }
        }

        int minimum = 999999, temp;
        vector <char> CITY;
        for(i= 0; i < 26; ++i)
        {
            temp = (DPY[pos1-'A'][i][25] + DPM[pos2-'A'][i][25]);
            if( temp < minimum)
            {
                CITY.clear();
                CITY.pb(i+65);
                minimum = temp;
            }
            else if( temp == minimum)
            {
                CITY.pb(i+65);
            }
        }
        if( minimum == 999999)
        {
            cout << "You will never meet.\n";
        }
        else
        {
            cout << minimum;
            for(i = 0;i < CITY.size(); ++i)
            {
                cout << ' ' << CITY[i];
            }
            cout << '\n';
        }
    }
}
