#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second


int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    char c;
    list <char> mylist;
    list <char>::iterator it, endlist;
    bool BEG = false;
    while(true)
    {
        c= cin.get();
        if(c==EOF)
            break;
        else if(c=='\n')
        {
            it = mylist.begin();
            endlist = mylist.end();
            for(; it!= endlist; it++)
                cout << *it;
            cout <<"\n";
            mylist.clear();
            BEG = false;
            //END = false;
            continue;
        }
        else if(c=='[')
        {
            BEG = true;
            it = mylist.begin();
        }
        else if(c==']')
        {
            //END = true;
            BEG = false;
        }
        else
        {
            if(BEG)
            {
                mylist.insert(it, c);
            }
            else
            {
                mylist.pb(c);
            }
        }
    }
}
