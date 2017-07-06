
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back



int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int req, proposals, i, k;
    double compliance, price, supply, mini;
    string s, final_name, prop_name;
    int j =  1;
    //ofstream file;
    //file.open("out.txt");
    while(true)
    {
        cin >> req >> proposals;
        cin.ignore(1,'\n');
        if(req==0 && proposals==0)
           break;
        if(j!=1)
        {
            cout<<"\n";
            //file << "\n";
        }
        price = 0;
        compliance = 0;
        for(i = 1; i<=req;i++){
            getline(cin , s);
        }
        for(i = 1;i<= proposals;i++)
        {
            getline(cin , prop_name);
            cin >> price >> supply;
            cin.ignore(1,'\n');
            if(i==1)
            {
                mini = price;
            }
            for(k = 1; k<= supply;k++){
                getline(cin , s);
                }
            if((double(supply)/req)> compliance)
            {
                compliance = double(supply)/req;
                final_name = prop_name;
                mini = price;
            }
            else if((double(supply)/req)== compliance && price < mini )
            {
                mini = price;
                final_name = prop_name;
            }
        }
        cout << "RFP #"<< j << "\n"<< final_name<<"\n";
        //file << "RFP #"<< j << "\n"<< final_name<<"\n";
        j++;
    }
}




