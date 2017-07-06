#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

int main()
{   
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector <char> vec;

    int co = 1, i, len, j;
    char c;
    string str;
    while(true)
    {
        getline(cin, str);
        if(str=="end")
            break;
        vec.clear();
        vec.pb(str[0]);
        for(i = 1; i< str.length(); i++)
        {
            c = str[i];
            len = vec.size();
            for(j = 0; j< len ; j++)
            {
                if( c <= vec[j])
                {
                    vec[j] = c;
                    break;
                }
            }
            if(j == len)
            {
                vec.pb(c);
            }
        }
        cout << "Case "<< co <<": "<< vec.size()<<"\n";
        co++;
    }
}

