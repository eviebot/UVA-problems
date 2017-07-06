#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second


int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, i, j, t1, t2, rep, c, k;
    bool thestorage[1000001], flag;
    while(true)
    {
        cin >> n >> m;
        if(n==0 && m==0)
            break;
        flag = true;
        for(i = 1; i<=1000000; i++)
            thestorage[i] = false;
        for(i = 0; i < n; i++)
        {
            cin >> t1 >> t2;

            for(j = t1; j< t2; j++)
            {
                if(thestorage[j])
                {
                    flag = false;
                    break;
                }
                thestorage[j] = true;
            }
        }
        for(i =0; i< m ; i++)
        {
            cin >> t1 >> t2 >> rep;
            
            for(i = 0; t2+i*rep< 1000000; i++)
            {
                j = t1 + i*rep;
                k = t2 + i*rep;
                for(c = j; c< k; c++)
                {
                    if(thestorage[c])
                    {
                        flag = false;
                        break;
                    }
                    thestorage[c]= true;
                }
            }
        }

        if(flag)
        {
            file << "NO CONFLICT\n";
        }
        else
        {
            file << "CONFLICT\n";
        }
    }
}
