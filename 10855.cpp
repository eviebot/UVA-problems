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

    vector <string> larger;
    vector <string> smaller;
    int N_large, N_small, i, j, t, l, m, t1, t2, sum, qw, wq;
    int chicksum[4];
    string s;
    bool flag1, flag2, flag3, flag4;
    while(true)
    {
        for(i = 0; i< 4;i++)
            chicksum[i] = 0;
        larger.clear();
        smaller.clear();
        cin >> N_large >> N_small;
        t = N_large - N_small;
        if(N_large ==0)
            break;
        for(i = 0; i< N_large ; i++)
        {
            cin >> s;
            larger.pb(s);
        }
        for(i = 0; i< N_small; i++)
        {
            cin >> s;
            smaller.pb(s);
        }

        for(i = 0; i<= t; i++)
        {
            for(j = 0; j<= t; j++)
            {
                flag1 = flag2 = flag3 = flag4 = true;sum = 4;
                for(l = 0; l<N_small && sum; l++)
                {
                    t1 = N_small-l-1;
                    for(m = 0; m< N_small && sum; m++)
                    {
                        t2 = N_small-m-1;
                        qw = i+l;wq = j+m;
                        if(flag1 && !(smaller[l][m] == larger[qw][wq])){
                            flag1 = false;sum--;}
                        if(flag2 && !(smaller[t2][l] == larger[qw][wq])) {
                           flag2 = false;sum--;}
                        if(flag3 && !(smaller[t1][t2] == larger[qw][wq])){
                            flag3 = false;sum--;}
                        if(flag4 && !(smaller[m][t1] == larger[qw][wq])){
                            flag4 = false;sum--;}
                    }
                }
                if(flag1)
                    chicksum[0]++;
                if(flag2)
                    chicksum[1]++;
                if(flag3)
                    chicksum[2]++;
                if(flag4)
                    chicksum[3]++;
            }
        }
        cout << chicksum[0]<<" "<< chicksum[1]<<" "<< chicksum[2] <<" "<< chicksum[3]<<"\n";
    }
}
