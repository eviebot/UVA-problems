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

    int lel, B, SG, SB, i, j, k, s1, s2;
    cin >> lel;

    for(int wilie = 0; wilie < lel; wilie ++)
    {
        cin >> B >> SG >> SB;
        multiset <int> green, blue;
        multiset <int>::iterator gend, bend;

        for(i = 0; i< SG; i++)
        {
            cin>> k;
            green.insert(k);
        }

        for(i = 0; i< SB; i++)
        {
            cin >> k;
            blue.insert(k);
        }

        while(!green.empty() && !blue.empty())
        {
            j = 0;
            vector <int> g, b;
            while(j != B)
            {
                gend = green.end();--gend;
                bend = blue.end(); --bend;
                s1 = *gend;
                s2 = *bend;
                if( s1 > s2)
                {
                    g.pb(s1-s2);
                }
                else if(s1 < s2)
                {
                    b.pb(s2-s1);
                }

                green.erase(gend);
                blue.erase(bend);
                j++;
                if(green.empty() || blue.empty())
                    break;
            }

            green.insert(g.begin(), g.end());
            blue.insert(b.begin(), b.end());
        }

        if(green.empty() && blue.empty())
        {
            cout << "green and blue died\n";
        }
        else if(blue.empty())
        {
            cout << "green wins\n";
            gend = green.begin();
            bend = green.end();
            --bend;
            while(bend != gend)
            {
                cout << *bend<<"\n";
                --bend;
            }
            cout << *bend<<"\n";

        }
        else
        {
            cout << "blue wins\n";
            gend = blue.begin();
            bend = blue.end();
            --bend;
            while(bend != gend)
            {
                cout << *bend<<"\n";
                --bend;
            }
            cout << *bend<<"\n";
        }
        if(wilie != lel-1)
            cout<<"\n";
    }
}
