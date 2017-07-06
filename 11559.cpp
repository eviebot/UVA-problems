#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, b, h, w, temp, l, z;
    while(scanf("%d %d %d %d", &n,&b,&h,&w)== 4){

    int budget[h];
    bool flag[h];
    for(int i = 0; i< h; i++)
    {
        flag[i] = false;
    }
    for(int i = 0; i< h ; i++)
    {
        cin >> temp;
        for(int j = 0; j< w; j++)
        {
            cin >> l;
            if(l > n)
            {
                if(n*temp <= b)
                {
                    budget[i] = n*temp;
                    flag[i] = true;
                }
            }
        }
        if(flag[i] == false) {budget[i] = -1;}
    }

    for(int i = h-1; i>= 0; i--)
    {
        for(int j = 0;j < i ; j++)
        {
            if(budget[j+1]< budget[j])
            {
                temp = budget[j+1];
                budget[j+1] = budget[j];
                budget[j] = temp;
            }
        }
    }
    for(z = 0; z< h; z++)
    {
        if(budget[z]!=-1){
            cout<< budget[z]<< endl;
            break;
        }
    }

    if(z == h)
    {
        cout<<"stay home"<< endl;

    }}

}
