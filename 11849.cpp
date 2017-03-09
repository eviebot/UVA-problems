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

    long long int N, M, i, j, t, common;

    while(true)
    {
        cin >> N >> M;
        if(N==0 && M==0)
            break;
        common = 0;

        unordered_set <long long int> myset;
        unordered_set <long long int>::iterator iter;

        for(i = 0; i< N; i++)
        {
            cin >> t;
            myset.insert(t);
        }
        iter = myset.end();
        for(j = 0; j< M; j++)
        {
            cin >> t;
            if(myset.find( t ) != myset.end())
            {
                ++common;
            }
        }

        cout << common<<"\n";
    }
}
