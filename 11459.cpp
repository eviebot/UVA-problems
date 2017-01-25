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

    int testCASES, SL, players, rolls, z, i, t1, t2, c, k;
    bool flag;
    vector <vector <int> > boosters;
    vector <int> temp;
    cin >> testCASES;
    for(z = 1 ; z<= testCASES;z++)
    {
        boosters.clear();
        temp.clear();
        cin >> players>> SL >> rolls;
        int positions[players];
        for(i = 0; i<players;i++){
            positions[i] = 1;}
        for(i = 1; i<= SL;i++)
        {
            temp.clear();
            cin  >> t1 >> t2;
            temp.pb(t1);temp.pb(t2);
            boosters.pb(temp);
        }
        sort(boosters.begin(), boosters.end());
        c=0;
        flag = true;
        for(i = 1; i<=rolls;i++)
        {
            cin >> t1;
            if(flag){
            positions[c] += t1;

            for(k = 0; k <  SL;k++)
            {
                if(boosters[k][0]==positions[c])
                {
                    positions[c] = boosters[k][1];
                    break;
                }
            }
            if(positions[c]>=100)
            {
                positions[c]=100;
                flag = false;
            }
            c++;
            if(c==players)
                c=0;}
        }
        for(i = 0; i <players;i++)
        {
            cout<< "Position of player "<< (i+1)<< " is "<< positions[i]<<".\n";
        }
    }
}
