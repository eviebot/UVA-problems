
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L, i, fin;
    string s;
    //ofstream fout;
    bool outofplane;
    //fout.open("out.txt");
    while(true){
    cin >> L;
    if(L==0)
        break;
    outofplane = false;
    fin = 10001;
    for(i = 1; i<= (L-1);i++)
    {
        cin >> s;
        if(s=="No")
            continue;
        else if(s=="+y" && !outofplane)
        {
            fin ++;
        }
        else if(s=="-y" && !outofplane)
        {
            fin --;
        }
        else if(!outofplane && (fin%4 == 1 || fin%4== 3) && s=="+z")
        {
            outofplane=true;
            fin++;
        }
        else if(!outofplane && (fin%4 == 1 || fin%4== 3) && s=="-z")
        {
            outofplane=true;
            fin--;
        }

        else if(outofplane && (fin%4==2 || fin%4==0) && s=="+z")
        {
            outofplane=false;
            fin++;
        }

        else if(outofplane && (fin%4==2 || fin%4==0) && s=="-z")
        {
            outofplane=false;
            fin--;
        }
        //fout << "fin="<<fin<<"\n"<<"outofplane?"<<outofplane<<"\n";
    }
    fin = fin%4;

    if(fin==1)
    {
        cout <<"+x\n";
        //fout << "+x\n";
    }
    else if(fin==3)
    {
        cout <<"-x\n";
        //fout <<"-x\n";
    }
    else if(fin==2)
    {
        if(outofplane)
        {
            cout <<"+z\n";
            //fout <<"+z\n";
        }
        else
        {
            cout <<"+y\n";
            //fout <<"+y\n";
        }
    }
    else if(fin == 0)
    {
        if(outofplane)
        {
            cout <<"-z\n";
            //fout <<"-z\n";
        }
        else
        {
            cout <<"-y\n";
            //fout <<"-y\n";
        }
    }
    }
}
