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

    int ferry;
    string s;
    int lel, i, n, t, m, time, global_time;
    bool ferry_pos;

    cin >> lel;
    for(int willie = 0; willie < lel; willie ++)
    {
        cin >> n >> t >> m;
        queue <int> q[2];
        queue <int> index[2];
        map <int, int> mymap;
        ferry_pos = false;

        for(i = 0; i< m ; i++)
        {
            cin >> time >> s;
            if(s=="left")
            {
                q[0].push(time);
                index[0].push(i);
            }
            else
            {
                q[1].push(time);
                index[1].push(i);
            }
        }
        if(q[0].front() <= q[1].front())
        {
            global_time = q[0].front();
        }
        else
        {
            global_time = q[1].front()+t;
            ferry_pos = true;
        }
        //cout << q[0].empty()<<" "<< q[1].empty()<<"\n";
        while(checker(q[0], q[1]))
        {
            ferry = 0;

            while(!q[ferry_pos].empty() && q[ferry_pos].front() <= global_time && ferry != n)
            {
                ferry++;
                //cout << "TIME="<<q[ferry_pos].front()<<"\n";
                mymap.insert( MP (index[ferry_pos].front(), global_time+t) );
                index[ferry_pos].pop();
                q[ferry_pos].pop();
            }

            if(ferry!=0)
            {
                global_time += t;
                ferry_pos = !ferry_pos;
                //getchar();
            }
            else
            {
                if(q[!ferry_pos].front() <= global_time)
                {
                    ferry_pos = !ferry_pos;
                    global_time += t;
                    continue;
                }
                else
                {
                    time = q[ferry_pos].front();
                    if(time <= q[!ferry_pos].front())
                    {
                        global_time = time;
                    }
                    else
                    {
                        global_time = q[!ferry_pos].front()+t;
                        ferry_pos = !ferry_pos;
                    }
                    continue;
                }
            }
        }
        map <int, int>::iterator beg = mymap.begin() , END = mymap.end();
        while(beg != END)
        {
            cout << beg->se <<'\n';
            beg++;
        }
        cout <<"\n";
    }
}
