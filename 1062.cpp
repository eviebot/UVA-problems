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

    string str;
    vector <pair <bool , bool>> vec;     // format: bool value, min, max
    vector <vector <int>> storage;
    vector <int>::iterator it[26];
    vector <int> tmp;
    int i, val, j, n_stacks, co= 1, maxi;
    char c;
    while(getline(cin, str))
    {
        if(str=="end")
            break;
        vec.clear();
        storage.clear();
        n_stacks = 0;

        for(i = 0; i< 26; i++)
        {
            vec.pb( MP(false, true));
            storage.pb(tmp);
        }

        for(i = 0; i< str.length(); i++)
        {
            c = str[i];
            val = c - 65;
            cout << c << " - "<< i<<"\n";
            if(!vec[val].fi)
            {
                vec[val].fi = true;
                storage[val].pb(i);
                ++n_stacks;
            }
            else
            {
                storage[val].pb(i);
            }
        }
        for(i = 0; i< 26; i++)
        {
            if(vec[i].fi)
            {
                it[i] = storage[i].end();
                it[i]--;
                //cout << *it[i];
            }
        }
        cout <<"\n\n\n";
        for(i =0 ; i< 26; i++)
        {
            if(vec[i].fi)
            {
                cout << (char)(i+65)<<" = "<<*it[i]<<"\n";
            }
        }
        cout <<"\n\n\n";
        for(i = 25; i>= 0; i--)
        {
            if(vec[i].fi)
            {
                maxi = *it[i];
                cout << (char)(i+65)<< " = "<< maxi <<"\n";
                for(j = i-1; j>= 0; j--)
                {
                    if(vec[j].fi && vec[j].se)
                    {
                        //cout << maxi<<"\n";
                        if(maxi < storage[j][0])
                        {
                            cout << (char)(i+65)<<" below "<< (char)(j+65)<<"\n";
                            n_stacks--;
                            vec[j].se = false;
                            break;
                        }
                        else if(maxi < *it[j] )
                        {
                            cout << (char)(j+65)<<" partially above "<< (char)(i+65);
                            while(*it[j] > maxi)
                            {
                                it[j]--;
                            }
                            break;
                        }
                    }
                }
            }
        }
        cout <<"Case "<< co <<": "<< n_stacks<<"\n";
        co++;
    }
    return 0;
}

