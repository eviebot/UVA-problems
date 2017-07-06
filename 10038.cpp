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

    int temp, n ,t, temp1, i;
    string s;
    while(cin >> n)
    {
        bool flags[n], fag = true;
        for(i = 0; i< n;i++)
        {
            flags[i]= true;
        }
        cin >> temp;
        if(n==1)
        {
            cout <<"Jolly\n";
            continue;
        }
        for(i = 0; i< n-1;i++)
        {
            cin >> temp1;
            t = abs(temp-temp1);
            temp = temp1;
            if(t==0 || t>= n)
            {
                fag = false;
            }
            else if(!flags[t])
            {
                fag= false;
            }
            else
            {
                flags[t] = false;
            }
        }
        if(!fag)
            cout <<"Not jolly\n";
        else
            cout <<"Jolly\n";
    }
}
