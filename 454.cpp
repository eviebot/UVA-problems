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
    int N, i, j, k, l;
    string s;
    vector <string> myvec;
    vector <pair<string, string>> finale;
    bool flag;
    getline(cin, s);
    N = stoi(s);
    getline(cin, s);
    for(int o = 0 ; o< N;o++)
    {
        myvec.clear();
        finale.clear();
        while(getline(cin, s))
        {
            if(s.length()==0)
            {
                break;
            }
            myvec.pb(s);
        }
        //file << myvec.size();
        l = myvec.size();
        int arr[l][100] ;
        for(i = 0; i< l;i++)
        {
            for(j = 0; j< 100;j++)
                arr[i][j] = 0;
        }
        for(i = 0; i< l;i++)
        {
            s = myvec[i];
            for(j = 0; j< s.length();j++)
            {
                if( s[j] != ' ')
                {
                    arr[i][s[j] - 33] ++;
                }
            }
        }
        for(i = 0; i< l;i++)
        {
            for(j = i+1; j< l;j++)
            {
                flag = true;
                for(k = 0; k < 100;k++)
                {
                    if( ! (arr[i][k] == arr[j][k]))
                        flag = false;
                }
                if(flag)
                {
                    if(myvec[i] > myvec[j])
                        finale.pb(make_pair( myvec[j], myvec[i] ));
                    else
                        finale.pb(make_pair( myvec[i], myvec[j] ));
                    //finale.pb(make_pair( myvec[i], myvec[j] ));
                }
            }
        }
        vector <pair<string, string>>::iterator it = finale.begin();
        sort(finale.begin(), finale.end());
        for(; it!= finale.end();it++)
        {
            cout<< it->first <<" = "<< it->second<<"\n";
        }
        if(o!=N-1)
            cout <<"\n";
    }
}
