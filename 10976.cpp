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

    int y, k;
    double x;

    while(cin >> k)
    {
        y = k+1;
        vector <pair <int, int>> myvec;
        vector <pair <int, int>>::iterator iter, END;
        for(; y <= 2*k; y++)
        {
            x = (double)(y*k)/(y-k);
            if((int)(x) == x)
            {
                myvec.pb( MP (x, y));
            }
        }

        END = myvec.end();
        cout << myvec.size()<<"\n";
        for(iter = myvec.begin(); iter!= END; ++iter)
        {
            cout << "1/"<<k<<" = 1/"<< iter->fi<<" + 1/"<< iter->se<<"\n";
        }
    }
}
