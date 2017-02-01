#include <bits/stdc++.h>
#include <string>
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

    multiset <int> myset;
    multiset <int>::iterator it;
    multiset <int>::iterator iter;
    bool ender = false, flag , breaker;
    int a, temp, i, Lbound, multiplier, minutes, hours, seconds, c;
    cin >> a;
    if(a==0)
    {
        cin >> temp;
        if(temp==0)
            return 0;
    }
    while(true)
    {
        if(ender)
            break;
        myset.clear();
        myset.insert(a);
        while(true)
        {
            cin >> temp;
            if(temp==0)
            {
                cin >> a;
                if(a==0)
                {
                    ender = true;
                }
                break;
            }
            myset.insert(temp);
        }
        breaker = false;
        for(i = 2; ; i+=2)
        {
            if(breaker)
                break;
            for(it = myset.begin();it!=myset.end();it++)
            {
                Lbound = (*it) * i;
                c=0;
                if(Lbound > 18000)
                {
                    breaker = true;
                    break;
                }
                flag = true;
                for(iter = myset.begin(); iter!=myset.end(); iter++)
                {
                    multiplier = Lbound / (*iter);
                    if(multiplier==0)
                    {
                        c++;
                    }
                    if( multiplier %2 ==1 || (! (Lbound < (multiplier+1)*(*iter) -5 ) ) )
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    breaker= true;
                    break;
                }
            }
        }

        if(flag && c < myset.size())
        {
            seconds = Lbound % 60;
            Lbound /= 60;
            minutes = Lbound %60;
            hours = Lbound/60;
            cout << "0"<< hours<<":"<< (minutes<10?"0":"")<< minutes<<":"<<(seconds<10?"0":"")<< seconds<<"\n";
        }
        else
        {
            cout << "Signals fail to synchronise in 5 hours\n";
        }
    }
}
