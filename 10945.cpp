#include <bits/stdc++.h>
#include <string>
using namespace std;

#define endl '\n'
#define pb push_back

bool palindrome(string *x)
{
    string a, b;
    int l = (*x).length();
    a = (*x).substr(0, l/2);
    b = (*x).substr((l/2)+l%2, l/2);
    reverse(b.begin(), b.end());
    if(a==b)
        return true;
    return false;
}
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

    string s, f;
    char c;
    int i;
    bool flag;
    while(true)
    {
        f = "";
        getline(cin, s);
        if(s=="DONE")
            break;
        for(i = 0; i< s.length();i++)
        {
            c = s[i];
            if(! (c=='.' || c==',' || c=='!' || c=='?' || c==' ') )
                f += c;
        }
        convert_to_lower(&f);
        flag = palindrome(&f);
        if(flag)
            cout <<"You won't be eaten!\n";
        else
            cout <<"Uh oh..\n";
    }
}
