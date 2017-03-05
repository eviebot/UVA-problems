#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair


bool checker(vector <queue <int>> & vec)
{
    int i;
    for(i = 0; i< vec.size(); i++)
    {
        if(! vec[i].empty() )
            return true;
    }
    return false;
}
int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int lelouch, N, S, Q, time, i, item, j, s_no, t;
    stack <int> mystack;
    vector <queue <int>> stations;
    cin >> lelouch;
    for(int willywonka = 0; willywonka < lelouch; willywonka ++)
    {
        while(! mystack.empty())
        {
            mystack.pop();
        }
        stations.clear();
        time = 0;
        cin >>  N >> S >> Q;

        for(i = 0; i< N; i++)
        {
           cin >> t;
           queue <int> temp;
           for(j = 1; j<= t; j++)
           {
               cin >> item;
               temp.push(item);
           }
           stations.pb(temp);
        }

        s_no = 0;
        while(checker(stations) || !mystack.empty())
        {
            while(true)
            {
                if(mystack.empty())
                    break;
                item = mystack.top();
                ++time;
                if(item-1 != s_no)
                {
                    if(stations[s_no].size() != Q)
                    {
                        stations[s_no].push(item);
                        mystack.pop();
                    }
                    else
                    {
                        --time;
                        break;
                    }
                }
                else
                    mystack.pop();
            }
            while(true)
            {
                if(stations[s_no].empty() || mystack.size() == S)
                {
                    break;
                }

                item = stations[s_no].front();
                mystack.push(item);
                stations[s_no].pop();
                ++time;
            }
            time += 2;
            s_no++;
            if(s_no == N)
            {
                s_no = 0;
            }
        }
        cout << time-2<<"\n";
    }
}
