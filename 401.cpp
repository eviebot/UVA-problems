#include <bits/stdc++.h>
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
bool mirror(string *x)
{
    char C;
    int len = (*x).length();
    len--;
    string s="";
    for(;len>=0;len--)
    {
        C = (*x)[len];
        if(C=='1'|| C=='8'||C=='A' || C=='H' || C=='I'|| C=='M'||C=='O'|| C=='T' || C=='U'|| C=='V'||C=='W'||C=='X'||C=='Y')
            s += C;
        else if(C=='E')
            s += '3';
        else if(C=='3')
            s += 'E';
        else if(C=='J')
            s += 'L';
        else if(C=='L')
            s += 'J';
        else if(C=='S')
            s += '2';
        else if(C=='2')
            s += 'S';
        else if(C=='Z')
            s += '5';
        else if(C=='5')
            s += 'Z';
        else
            return false;
    }
    if(s==(*x))
        return true;
    return false;
}
int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    bool WOW[2];
    while(getline(cin, s))
    {
        cout << s;
        WOW[0] = palindrome(&s);
        WOW[1] = mirror(&s);
        if(WOW[0]==false && WOW[1] == false)
            cout << " -- is not a palindrome.\n";
        else if(WOW[0] == true && WOW[1]==true)
            cout << " -- is a mirrored palindrome.\n";
        else if(WOW[0] == true)
            cout << " -- is a regular palindrome.\n";
        else
            cout << " -- is a mirrored string.\n";
        cout <<"\n";
    }
}
