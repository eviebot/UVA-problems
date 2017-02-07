#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front

int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, i, k, j, z, sum, n;
    vector <string> myvec;
    vector <string> temp = {"000", "000", "000"};
    string s;
    cin >> N;

    for(z = 0; z < N; z++)
    {
        myvec.clear();
        for(k = 0; k< 3;k++)
        {
            cin >> s;
            myvec.pb(s);
        }
        if(myvec[0] == "000" && myvec[1] =="000" && myvec[2]=="000")
        {
            cout << "-1\n";
            continue;
        }
        i = 0;
        while(true)
        {
            temp[0][0] = (myvec[1][0]+myvec[0][1])%2;
            temp[0][1] = (myvec[0][0]+myvec[0][2]+myvec[1][1])%2;
            temp[0][2] = (myvec[0][1]+myvec[1][2])%2;
            temp[1][0] = (myvec[0][0]+myvec[1][1]+myvec[2][0])%2;
            temp[1][1] = (myvec[1][0]+myvec[0][1]+myvec[2][1]+myvec[1][2])%2;
            temp[1][2] = (myvec[0][2]+myvec[2][2]+myvec[1][1])%2;
            temp[2][0] = (myvec[1][0]+myvec[2][1])%2;
            temp[2][1] = (myvec[1][1]+myvec[2][0]+myvec[2][2])%2;
            temp[2][2] = (myvec[2][1]+myvec[1][2])%2;
            sum = 0;

            for(j = 0; j< 3;j++)
            {
                for(n = 0; n< 3;n++)
                {
                    sum += temp[j][n];
                }
            }
            if(sum==0)
            {
                cout << i<<"\n";
                break;
            }
            i ++;
            myvec = temp;
        }
    }
}
