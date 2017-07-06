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

    int test_cases, tot;
    string str;
    cin >> test_cases;
    cin.ignore();
    getline(cin, str);
    cout << fixed << setprecision(4);         
    for(int lel = 1; lel <= test_cases; lel++)
    {
        map <string, int> mymap;
        map <string, int>::iterator it, END;
        tot =0;
        while(true)
        {
            getline(cin , str);
            if(str.length()==0)
                break;
            mymap[str]++;
            tot++;
        }

        it = mymap.begin();
        END = mymap.end();
        for(; it!= END; it++)
        {
            cout << it->fi <<" "<< (double)(it->se*100)/tot<<"\n";
        }
        if(lel!=test_cases)
            cout <<"\n";
    }
}

