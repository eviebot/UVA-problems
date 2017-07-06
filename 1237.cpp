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

    string str;
    int test_cases, i, D, L, H, query, P;
    bool flag;
    cin >> test_cases;

    for(int lel = 0; lel < test_cases; ++lel)
    {
        cin >> D;
        unordered_map <string, pair <int, int>> lit;
        unordered_map <string, pair <int, int>>::iterator iter, END;
        for(i = 0; i< D; i++)
        {
            cin >> str >> L >> H;
            lit.insert( MP (str, MP( L, H ) ) );
        }

        END = lit.end();
        cin >> query;
        for(i = 0; i< query; i++)
        {
            cin >> P;
            flag = false;
            iter = lit.begin();
            for(; iter != END ; ++iter)
            {
                if( iter->se.fi <= P && iter->se.se >= P)
                {
                    if(flag)
                    {
                        flag = false;
                        break;
                    }
                    flag = true;
                    str = iter->fi;
                }
            }

            if(flag)
            {
                cout << str<<"\n";
            }
            else
            {
                cout << "UNDETERMINED\n";
            }
        }
        if(lel != test_cases-1)
            cout <<'\n';
    }
}
