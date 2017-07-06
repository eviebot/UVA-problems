#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

bool checker(queue <int> & x1, queue <int> & x2)
{
    if(x1.empty() && x2.empty())
        return false;
    return true;
}

int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int i, temp, max_frosh, j, k;
    while(true)
    {
        map <set <int> , int> mymap;
        map <set <int> , int>::iterator it, END;
        set <int> myset;
        max_frosh = 0;
        cin >> i;
        if(i==0)
            break;

        for(j = 0; j< i; j++)
        {
            myset.clear();
            for(k = 0; k< 5; k++)
            {
                cin >> temp;
                myset.insert(temp);
            }
            it = mymap.find(myset);
            if( it != mymap.end())
            {
                ++ it->se;
            }
            else
            {
                mymap.insert(make_pair(myset, 1));
            }
        }

        it = mymap.begin();
        END = mymap.end();
        for(; it!= END; it++)
        {
            if(it->se > max_frosh)
                max_frosh = it->se;
        }
        temp = 0;
        for(it = mymap.begin(); it!= END; it++)
        {
            if(it->se == max_frosh)
                temp += max_frosh;
        }
        cout<< temp<<"\n";
    }
}
