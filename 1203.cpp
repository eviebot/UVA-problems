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
    int q_num, period, k, i;
    unordered_map <int, int> mymap;
    set <pair <int, int> > myset;
    set <pair <int, int> >::iterator iter;
    pair <int, int> mypair;
    while(true)
    {
        cin >> str;
        if(str[0]=='#')
            break;
        cin >> q_num >> period;
        mypair = MP (period, q_num);
        mymap.insert( MP (q_num, period) );
        myset.insert( mypair );
    }
    cin >> k;

    for(i = 0; i< k ; i++)
    {
        iter = myset.begin();
        mypair.fi = iter->fi;
        mypair.se = iter->se;
        myset.erase(iter);
        cout << mypair.se<<"\n";
        mypair.fi += mymap.find(mypair.se)->se;
        myset.insert(mypair);
    }
}


