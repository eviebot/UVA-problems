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

    int n, i, r, c, t1, t2,sum;
    char ch;
    cin >> n;
    for(i = 1; i<= n;i++)
    {
        cin >> ch;
        cin >> r >> c;
        t1 = max(r, c);
        r = min(r, c);
        c = t1;
        if(ch=='r' || ch=='Q')
        {
            cout << r;
        }
        else if(ch =='K')
        {
            sum = 4;
            t1 = (r-3)/2;t2 = (c-3)/2;
            sum += t1*2 + t2*2 +t1*t2;
            cout << sum;
        }
        else
        {
            t1 = r*c;
            cout << t1/2 + t1%2;
        }
        cout << "\n";
    }
}
