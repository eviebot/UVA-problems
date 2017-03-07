#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

bool checker(queue <int> & x1, queue <int> & x2)
{
    if(x1.empty() && x2.empty())
        return false;
    return true;
}

int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int lel, l, m, len, i, trips;
    string str;
    bool ferry_pos;
    cin >> lel;
    for(int willie = 1; willie <= lel; willie++)
    {
        queue <int> q[2];
        trips = 0;
        ferry_pos = false;

        cin >> l >> m;
        l*= 100;

        for(i = 1; i <= m; i++)
        {
            cin >> len >> str;
            if(str[0]=='l')
            {
                q[0].push(len);
            }
            else
            {
                q[1].push(len);
            }
        }

        while(checker(q[0], q[1]))
        {
            len = 0;
            if(q[1].empty())
            {
                if(ferry_pos)
                {
                    trips++;
                    ferry_pos = false;
                }
                while(!q[0].empty())
                {
                    if(len + q[0].front() <= l)
                    {
                        len+= q[0].front();
                        q[0].pop();
                    }
                    else
                    {
                        trips+=2;
                        len = 0;
                    }
                }
            }
            else if(q[0].empty())
            {
                if(!ferry_pos)
                {
                    trips++;
                    ferry_pos = true;
                }
                while(!q[1].empty())
                {
                    if(len + q[1].front() <= l)
                    {
                        len+= q[1].front();
                        q[1].pop();
                    }
                    else
                    {
                        trips+=2;
                        len = 0;
                    }
                }
            }
            else
            {
                while(!q[ferry_pos].empty())
                {
                    if(q[ferry_pos].front()+len <= l)
                    {
                        len += q[ferry_pos].front();
                        q[ferry_pos].pop();
                    }
                    else
                    {
                        trips++;
                        ferry_pos = !ferry_pos;
                        break;
                    }
                }
                //cout << len <<"\n";
                //getchar();
            }
        }

        cout << trips+1<<"\n";
    }
}
