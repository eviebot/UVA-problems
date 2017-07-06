#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

ofstream outfile;
ifstream infile;

int si;
unordered_map <string , int> matcher;
vector <string> storage;
vector <int> dist;
vector <bool> visited;
bool checker(int a, int b)
{
    string s1 = storage[a], s2 = storage[b];
    if( s1.size() != s2.size())
        return false;

    bool flag = true;
    for(int i = 0; i < s1.size(); ++i)
    {
        if( s1[i] != s2[i] )
        {
            if( flag)
                flag = false;
            else
                return false;
        }
    }
    return true;
}
int finddist(int src, int dest)
{
    if( src == dest)
        return 0;
    visited[src] = 1;
    dist[src] = 0;
    queue <int> myq;
    myq.push(src);

    int j, temp;
    while(true)
    {
        temp = myq.front();
        myq.pop();
        for(j = 1; j <= si; ++j)
        {
            if( !visited[j] && checker(j, temp) )
            {
                dist[j] = dist[temp]+1;
                visited[j] = 1;
                myq.push(j);
                if( j == dest)
                    return dist[dest];
            }
        }
    }
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    fastIO;
	string s, w1, w2;
	int T, i;
	cin >> T ;

	cin.ignore(2);

    for(int z = 0; z < T; ++z)
    {
        dist.clear();
        visited.clear();
        matcher.clear();
        storage.clear();

        storage.pb("");
        dist.pb(0);
        visited.pb(0);

        si = 0;
        while(getline(cin , s))
        {
            if( s == "*")
                break;

            storage.pb(s);
            matcher.insert( (MP (s, ++si)) );
            dist.pb(0);
            visited.pb(0);
        }
        while(getline( cin , s))
        {
            if( s.length() == 0)
                break;
            stringstream ss(s);
            ss >> w1 >> w2;

            for(i = 1; i <= si ; ++i)
            {
                visited[i] = 0;
                dist[i] = 0;
            }
            cout <<w1 << " "<< w2 << " "<< finddist( matcher.find(w1)->se , matcher.find(w2)->se)<< "\n";
        }
        cout << "\n"[z==T-1];
    }
}
