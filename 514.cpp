#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second


int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int N, temp, temp1, i, j;
    bool flag;
    while(true)
    {
        cin >> N;
        if(N==0)
            break;

        while(true)
        {
            flag = true;
            stack <int> mystack;
            cin >> temp;
            if(temp==0)
            {
                cout <<"\n";
                break;
            }
            for(i =1; i< temp; i++)
            {
                mystack.push(i);
            }
            for(i = 1; i< N; i++)
            {
                cin >> temp1;
                if(flag)
                {
                    if(temp1 > temp)
                    {
                        for(j = temp+1; j < temp1; j++)
                        {
                            mystack.push(j);
                        }
                        temp = temp1;
                    }
                    else
                    {
                        if(mystack.top() != temp1)
                        {
                            flag = false;
                        }
                        else
                        {
                            mystack.pop();
                        }
                    }
                }
            }
            if(flag)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
}
