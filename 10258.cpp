#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second


bool cmp(pair<int, pair<int,int>>& a, pair<int, pair<int, int>>&b)
{
    if(a.se.fi > b.se.fi)
        return true;
    else if(a.se.fi < b.se.fi)
        return false;

    if(a.se.fi == b.se.fi && a.se.se < b.se.se)
        return true;
    else if(a.se.se > b.se.se)
        return false;

    if(a.se.se == b.se.se && a.fi < b.fi)
        return true;
    else
        return false;
}
int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);

    int testcases, contestant, problem, time, i, j, solved, penalty, k, t = 0;
    int log[101][11][2];
    bool participating[101];
    char verdict;
    string s;
    vector <pair<int, pair<int, int>>> myvec;
    cin >> testcases;
    for(i = 1; i<= testcases; i++)
    {
        for(i = 1; i< 101; i++)
        {
            participating[i] = false;
            for(j = 1; j < 11; j++){
                log[i][j][0] = 0;
                log[i][j][1] = 0;}
        }
        while(getline(cin, s))
        {
            if(s.length()==0)
            {
                for(j = 1; j< 101;j++)
                {
                    solved = 0;
                    penalty = 0;
                    for(k = 1; k< 11; k++)
                    {
                        if(log[j][k][0])
                        {
                            solved ++;
                            penalty += log[j][k][1];
                        }
                    }
                    if(participating[j]){
                        myvec.pb(make_pair(j, make_pair(solved, penalty)));}
                }
                sort(myvec.begin(), myvec.end(), cmp);
                for(auto x: myvec)
                    cout << x.first<<" "<< x.second.first << " "<< x.second.second<<"\n";
                if(t)
                    cout <<"\n";
                myvec.clear();
                for(i = 1; i< 101; i++)
                {
                    participating[i] = false;
                    for(j = 1; j < 11; j++){
                        log[i][j][0] = 0;
                        log[i][j][1] = 0;}
                }
                continue;
            }
            t++;
            stringstream ss(s);
            ss >> contestant >> problem >> time>> verdict;

            participating[contestant] = true;
            if(!log[contestant][problem][0])
            {
                if(verdict == 'C')
                {
                    log[contestant][problem][0] = 1;
                    log[contestant][problem][1] += time;
                }
                else if(verdict == 'I')
                {
                    log[contestant][problem][1] += 20;
                }
            }
        }
    }
    for(j = 1; j< 101;j++)
    {
        solved = 0;
        penalty = 0;
        for(k = 1; k< 11; k++)
        {
            if(log[j][k][0])
            {
                solved ++;
                penalty += log[j][k][1];
            }
        }
        if(participating[j]){
            myvec.pb(make_pair(j, make_pair(solved, penalty)));}
    }
    sort(myvec.begin(), myvec.end(), cmp);
    for(auto x: myvec)
        cout << x.first<<" "<< x.second.first << " "<< x.second.second<<"\n";
}

