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

    int n, t, i, j, z, r, c, dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, pos[2], k;
    char tem;
    vector <vector <char>> myvec;
    vector <char> temp;
    cin >> t;
    for(z = 1; z<=t; z++)
    {
        cin >> r >> c >> n;
        myvec.clear();
        if(r==0 || c==0)
        {
            cout << "\n";
            continue;
        }
        else if(r==1&& c==1)
        {
            cin >> tem;
            cout << tem << "\n\n";
            continue;
        }
        for(i= 0; i< r;i++)
        {
            for(j = 0; j< c;j++)
            {
                cin >> tem;
                temp.pb(tem);
            }
            myvec.pb(temp);
            temp.clear();
        }
        vector <vector<char>> FINALTEMP;
        for(i = 0; i< c;i++)
            temp.pb('0');
        for(i = 0; i< r;i++)
        {
            FINALTEMP.pb(temp);
        }
        temp.clear();
        for(int jk = 1 ; jk<=n; jk++)
        {
            for(i = 0; i< r;i++)
            {
                for(j=0; j< c;j++)
                {
                    tem = myvec[i][j];
                    for(k = 0; k < 4;k++)
                    {
                        pos[0] = i + dir[k][0]; pos[1] = j + dir[k][1];
                        if(!(pos[0]< 0 || pos[0]==r || pos[1] < 0 || pos[1]==c))
                        {
                            if(tem=='R' && myvec[pos[0]][pos[1]] == 'P')
                                {FINALTEMP[i][j] = 'P';
                                    break;}
                            else if(tem=='S' && myvec[pos[0]][pos[1]]=='R')
                                {FINALTEMP[i][j] = 'R';
                                break;}
                            else if(tem=='P' && myvec[pos[0]][pos[1]]=='S')
                                {FINALTEMP[i][j] = 'S';
                                break;}
                            else
                                {FINALTEMP[i][j] = tem;}
                        }
                    }
                }
            }
            myvec =FINALTEMP;
        }
        for(i = 0; i< r;i++)
        {
            for(j = 0; j< c;j++)
            {
                cout<< myvec[i][j];
            }
            cout << "\n";
        }
        if(z!=t)
            cout << '\n';
    }
}
