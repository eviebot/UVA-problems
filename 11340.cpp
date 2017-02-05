#include <bits/stdc++.h>
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

    int n , K, M, i, j, k, val, sum, dollar, cent;
    char c;
    string s;
    unordered_map <char, int> mymap;
    cin >> n;
    for(i = 1; i<= n; i++)
    {
        sum = 0;
        mymap.clear();
        cin >> K;
        for(j = 0; j< K; j++)
        {
            cin >> c >> val;
            mymap.insert(make_pair(c, val));
        }
        cin >> M;
        cin.ignore();
        for(j = 0; j< M; j++)
        {
            getline(cin, s);
            for(k = 0; k< s.length();k++)
            {
                sum += mymap[s[k]];
            }
        }
        dollar = sum /100;
        cent = sum %100;
        cout << dollar << "."<< (cent<10?"0":"")<< cent<<"$\n";
    }
}
