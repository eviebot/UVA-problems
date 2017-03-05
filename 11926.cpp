#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second

bool return_that_val(int a, int b, int c, int d)
{
        if(a == c)
        {
            return false;
        }

        if( (c > a && c < b) || (a > c && a < d))
        {
            return false;
        }
        else
            return true;
}

int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector <pair<int, pair<int, int>>> storage;
    int n,m ,i, j, rep, t1, t2, l, c, inc1, inc2;
    bool flag, breaker;

    while(true)
    {
        cin >> n >> m;
        storage.clear();
        flag = true;
        if(n==0 && m==0)
        {
            break;
        }
        for(i = 0; i< n; i++)
        {
            cin >> t1 >> t2;
            l = storage.size();
            for(j = 0; j< l && flag; j++)
            {
                if(flag){
                flag = return_that_val(t1, t2, storage[j].fi, storage[j].se.fi);}
            }
            storage.pb(make_pair(t1, make_pair(t2, 0)));
        }

        for(i = 0; i< m; i++)
        {
            cin >> t1 >> t2>> rep;
            c = 0;
            breaker = true;
            l = storage.size();
            while(breaker)
            {
                inc1 = rep*c+t1;
                inc2 = rep*c+t2;
                c++;
                if(inc1 > 1000000)
                    break;
                if(inc2 > 1000000)
                {
                    inc2 = 1000000;
                    breaker = false;
                }

                for(j = 0; j< l && flag; j++)
                {
                    if(storage[j].se.se==0)
                    {
                        flag = return_that_val(inc1, inc2, storage[j].fi, storage[j].se.fi);
                    }
                    else
                    {
                        bool anotherone = true;
                        int st1 = storage[j].fi, st2 = storage[j].se.fi, repper = storage[j].se.se;
                        while(anotherone)
                        {
                            if(st1>1000000)
                                break;
                            if(st2>1000000)
                            {
                                st2 = 1000000;
                                anotherone = false;
                            }
                            if(flag){
                            flag = return_that_val(inc1, inc2, st1, st2);}
                            st1 += repper;
                            st2 += repper;
                        }
                    }
                }
            }
            storage.pb(make_pair(t1, make_pair(t2, rep)));
        }
        if(flag)
        {
            cout << "NO CONFLICT\n";
        }
        else
        {
            cout << "CONFLICT\n";
        }
    }
}
