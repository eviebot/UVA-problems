#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

int FIND(string a, char c, int start, int en)
{
    int i;
    for(i = start; i < en; ++i)
    {
        if(a[i] == c)
        {
            return i+1;
        }
    }
    return 0;
}
int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string s, query;
    cin >> s;
    int q, zz, len = s.length(), len_q, i, p, start;
    cin >> q;

    for(zz = 0; zz < q; ++zz)
    {
        cin >> query;
        len_q = query.length();

        start = FIND(s, query[0], 0, len);

        if(start)
        {
            p = start; i = 1;
            while(i != len_q && p)
            {
                p = FIND(s, query[i], p, len);
                ++i;
            }
            if(p)
            {
                cout << "Matched "<< start-1 << " "<< p-1 << "\n";
            }
            else
            {
                cout << "Not matched\n";
            }
        }
        else
        {
            cout << "Not matched\n";
        }
    }
    return 0;
}
