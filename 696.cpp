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

    int r, c, t, fin;
    while(true)
    {
        cin >> r >> c;
        if(r==0 && c==0)
            break;
        if(r==1 || c==1)
            fin = max(r, c);
        else
        {
            t = r*c;
            fin = (t/2+t%2);
            if(r==2 || c==2)
            {
                t = max(r, c);
                if(t%4==1 || fin%4==3)
                    fin ++;
                else if(t%4==2)
                    fin += 2;
            }
        }
        cout << fin<<" knights may be placed on a "<<r<<" row "<<c<<" column board.\n";
    }
}
