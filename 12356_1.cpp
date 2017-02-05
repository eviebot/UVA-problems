#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front

int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);

    int soldiers, B, i, n1, n2;
    while(true)
    {
        cin >> soldiers>> B;
        if(soldiers ==0)
            break;
        int arrR[soldiers+1];
        int arrL[soldiers+1];
        for(i = 1; i<= soldiers;i++)
        {
            arrR[i] = i+1;
            arrL[i] = i-1;
        }
        for(i = 0; i< B;i++)
        {
            cin >> n1 >> n2;

            if(arrL[n1]!=0)
                cout << arrL[n1]<<" ";
            else
                cout << "* ";

            if(arrR[n2]!=soldiers+1)
                cout << arrR[n2]<<"\n";
            else
                cout <<"*\n";

            arrL[arrR[n2]] = arrL[n1];
            arrR[arrL[n1]] = arrR[n2];
        }
        cout <<"-\n";
    }
}
