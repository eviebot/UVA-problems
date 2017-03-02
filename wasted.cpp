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

    int n, m, i, j, t1, t2, rep, fin, c;
    bool thestorage[1000001], flag, finalflag;
    while(true)
    {
        infile >> n >> m;
        if(n==0 && m==0)
            break;
        flag =false;
        for(i = 1; i<=1000000; i++)
            thestorage[i] = false;
        for(i = 0; i< n; i++)
        {
            infile >> t1 >> t2;
            if(thestorage[t1]&& thestorage[t2])
            {
                flag = true;
            }
            thestorage[t1] = true;
            if(!flag){
            for(j = t1+1; j< t2; j++)
            {
                if(thestorage[j])
                {
                    flag = true;
                    break;
                }
                thestorage[j] = true;
            }}
            thestorage[t2] = true;
        }

        for(i =0; i< m ; i++)
        {
            infile >> t1 >> t2 >> rep;
            c=0;
            finalflag = false;
            for(; !flag && !finalflag; )
            {
                j = rep*c+t1;
                fin = rep*c+t2;
                if(fin > 1000000)
                {
                    finalflag = true;
                }
                if(!finalflag){
                    if(thestorage[j]&& thestorage[fin])
                    {
                        flag = true;break;
                    }
                    thestorage[j] = true;
                    j++;
                    if(!flag)
                    {
                        for(; j< fin; j++)
                        {
                            if(thestorage[j])
                            {
                                flag = true;
                                break;
                            }
                            thestorage[j] = true;
                        }
                        thestorage[fin] = true;
                        fin +=rep;
                        j=t1+rep*c;
                        c++;
                    }
                }
                else
                {
                    thestorage[j] = true;
                    j++;
                    for(; j<= 1000000; j++)
                    {
                        if(thestorage[j])
                        {
                            flag = true;
                            break;
                        }
                        thestorage[j] = true;
                    }
                }
            }
        }

        if(flag)
        {
            file << "CONFLICT\n";
        }
        else
        {
            file << "NO CONFLICT\n";
        }
    }
}
