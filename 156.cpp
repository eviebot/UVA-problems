#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
void convert_to_lower(string *x)
{
    int len = (*x).length(), i;
    for(i = 0; i< len;i++)
    {
        (*x)[i] = tolower((*x)[i]);
    }
}
int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);
    int i, j;
    vector <vector <int> > vec;
    vector <int> temp;
    vector <string> storage;
    vector <string> finale;
    bool flag;
    for(i = 0; i< 26;i++)
        temp.pb(0);
    string s;
    while(true)
    {
        cin >> s;
        if(s=="#")
            break;
        storage.pb(s);
        vec.pb(temp);
    }

    for(i = 0; i< storage.size();i++)
    {
        s = storage[i];
        convert_to_lower(&s);
        for(j = 0; j< s.length();j++)
        {
            vec[i][(int)s[j]-97]  ++;
        }
    }

    for(i =0; i< storage.size();i++)
    {
        flag = true;
        for(j =0; j< storage.size();j++)
        {
            if(i!=j && vec[i] == vec[j])
            {
                flag = false;
            }
        }
        if(flag)
            finale.pb(storage[i]);
    }
    sort(finale.begin(), finale.end());
    for(i = 0; i< finale.size();i++)
        cout << finale[i]<<"\n";
}
