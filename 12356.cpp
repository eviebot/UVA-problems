#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front

int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_map <int, int> map1;
    unordered_map <int, int> map2;
    unordered_map <int, int>::iterator iter1;
    unordered_map <int, int>::iterator iter2;

    int soldiers, B, i, n1, n2, pos1 , pos2;
    while(true)
    {
        cin >> soldiers >> B;
        if(soldiers ==0)
            break;
        map1.clear();
        map2.clear();
        for(i = 0; i< B;i++)
        {
            cin >> n1  >> n2;
            map1.insert(make_pair(n1, n2));
            map2.insert(make_pair(n2, n1));
            pos1 = n1-1;
            pos2 = n2+1;
            while(true)
            {
                if(n1<=1)
                {
                    pos1 = -1;
                    break;
                }
                iter1 = map2.find(pos1);
                if(iter1 != map2.end())
                {
                    if(iter1->second == 1 || iter1->second == soldiers)
                    {
                        pos1 = -1;break;
                    }
                    else
                    {
                        pos1 = iter1->second-1;
                    }
                    //cout <<"\n\n"<< pos1 <<"\n\n";
                }
                else
                {
                    break;
                }
            }
            while(true)
            {
                if(n2>=soldiers)
                {
                    pos2 = -1;
                    break;
                }
                iter2 = map1.find(pos2);
                if(iter2 != map1.end())
                {
                    if(iter2->second == 1 || iter2->second == soldiers)
                    {
                        pos2 = -1;break;
                    }
                    else
                    {
                        pos2 = iter2->second+1;
                    }
                }
                else
                {
                    break;
                }
            }
            cout <<(pos1==-1?"*":to_string(pos1))<<" "<<(pos2==-1?"*":to_string(pos2))<<"\n";
        }
        cout <<"-\n";
    }
}
