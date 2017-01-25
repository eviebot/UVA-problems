#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back

void chutiyaap(int i, int j, vector<vector <char >> & vec, int m , int n)
{
    vector <vector <int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int t1, t2, k;
    for(k = 0; k<=7;k++)
    {
        t1 = i+ dir[k][0];
        t2 = j+ dir[k][1];
        if(t1 < 0 || t2 < 0 || t1 >= m || t2 >=n || vec[t1][t2]=='*')
            continue;
        else
            vec[t1][t2] ++;
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

    int m, n, i, j, counter= 1;
    char c;
    vector <vector <char >> myvec;
    vector <char> temp;
    while(true)
    {
        cin >> m >> n;
        if(m == 0 && n==0)
            break;
        myvec.clear();
        temp.clear();
        for(i = 1; i<= m;i++)
        {
            for(j = 1; j<=n;j++)
            {
                cin >> c;
                if(c=='.')
                    c='0';
                temp.pb(c);
            }
            myvec.pb(temp);
            temp.clear();
        }
        cout.flush();
        for(i = 0; i< m;i++)
        {
            for(j = 0; j<n;j++)
            {
                if(myvec[i][j]=='*')
                    chutiyaap(i, j, myvec, m, n);
            }
        }
        cout << "Field #"<< counter<<":\n";
        counter++;
        for(i = 0; i< m;i++)
        {
            for(j = 0; j< n;j++)
            {
                cout << myvec[i][j];
            }
            cout << '\n';
        }
        cout <<'\n';
    }
}
