#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front

int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    while(true)
    {
        getline(cin , s);
        if(s=="#")
            break;

        if(next_permutation(s.begin(), s.end()))
            cout << s<<"\n";
        else
            cout << "No Successor\n";
    }
}
