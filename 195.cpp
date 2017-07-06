#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, i;
    string s;
    cin >> n;
    for(i = 0; i< n;i++)
    {
        cin >> s;
        sort(s.begin(), s.end());
        do
        {
            cout << s<<"\n";
        }while(next_permutation(s.begin(), s.end()));
    }
}
