#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back


int empty_slot(int x, int *a)
{
    while(true)
    {
        if(!a[x])
            return x;
        if(x==52)
            return -1;
        x++;
    }
}
int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[53]={0}, princess[3], prince[2], i;
    while(true)
    {
        for(i = 1; i<=52;i++)
            arr[i]=0;
        for(i = 0; i< 3 ;i++)
        {
            cin >> princess[i];
            arr[princess[i]] = 1;
        }
        cin >> prince[0]>> prince[1];
        arr[prince[0]]=1; arr[prince[1]]=1;
        if(prince[0]==0 && prince[1]==0)
            break;
        sort(princess, princess+3);
        sort(prince, prince+2);
        if(prince[0]> princess[2] && prince[1] > princess[2])
            cout<<empty_slot(1, arr)<<'\n';
        else if(prince[1] >princess[2] && prince[0]> princess[1])
            cout << empty_slot(princess[1], arr)<<"\n";
        else if(prince[1] > princess[2])
            cout << empty_slot(princess[2], arr)<<'\n';
        else if(prince[1]<princess[2] && prince[0]> princess[1])
            cout << empty_slot(princess[1], arr)<<"\n";
        else
            cout << "-1\n";
    }
}
