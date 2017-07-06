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

int n;
double r, temp;
double edist(int arr[][2], int n1, int n2)
{
    int a = arr[n1][0] - arr[n2][0], b = arr[n1][1] - arr[n2][1];
    return sqrt(double( a*a + b*b ));
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    int T, i;
    cin >> T;

    for(int z = 1; z <= T; ++z)
    {
        cin >> n >> r;
        int coords[n+1][2], states = 1;
        for(i = 1; i <= n; ++i)
        {
            cin >> coords[i][0] >> coords[i][1];
        }

        bool visited[n+1] = {false};
        int recent = 1;
        visited[1] = true;
        double dist[n+1] = {100000.0}, sumc = 0, sums = 0;

        dist[1] = 0.0;
        set <pair <double, int>> prim;
        set <pair <double, int>>::iterator iter;
        for(i = 2; i <= n; ++i){
            prim.insert( MP (100000.0, i));
            dist[i] = 100000.0;}

        while(prim.size())
        {
            for(i = 1; i <= n; ++i)
            {
                if( !visited[i])
                {
                    iter = prim.find( MP(dist[i], i ));
                    temp = edist(coords, recent, i);
                    if( temp < iter->fi)
                    {
                        prim.erase(iter);
                        prim.insert( MP (temp, i));
                        dist[i] = temp;
                    }
                }
            }
            iter = prim.begin();
            recent = iter->se;
            if( iter->fi > r)
            {
                sums +=  iter->fi;
                ++states;
            }
            else
            {
                sumc += iter->fi;
            }
            visited[iter->se] = 1;
            prim.erase(iter);
        }
        cout << "Case #"<< z << ": "<< states << ' '<< (int)(round(sumc)) << ' '<< (int)(round(sums))<< '\n';

    }
}
