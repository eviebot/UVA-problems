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

    int n, y, k, i, x, j;
    string s;
    char c;
    cin >> n;
    vector <string> myvec;
    vector <string>::iterator iter;
    vector <string>::iterator fin;
    for(i = 1; i<= n;i++)
    {
        y = 0;
        for(j = 1; j<=27;j++)
        {
            cin >> s;
            myvec.pb(s);
        }
        for(k = 1; k<=3;k++)
        {
            iter = myvec.end();
            iter--;
            c = (*iter)[0];
            if(c=='A'||c=='K'||c=='Q'||c=='J'||c=='T')
                x = 10;
            else
                x = (int)(c)-48;
            y+= x;
            myvec.erase(iter-10+x , iter+1);
            myvec.shrink_to_fit();
        }
        for(j = 28; j<=52;j++)
        {
            cin >> s;
            myvec.pb(s);
        }
        fin = myvec.begin();
        advance(fin, y-1);
        cout << "Case "<< i << ": "<< *fin<<"\n";
        myvec.clear();
    }
}
