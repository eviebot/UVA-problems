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

vector <vector <int>> graph;
vector <int> temp;
bool visited[201][201];

void BFS(int root)
{
    bool visit[201] = {false};
    queue <int> myq;
    myq.push(root);
    visit[root]= true;
    int temp, j;
    while(!myq.empty())
    {
        temp = myq.front();
        myq.pop();
        for(j = 0; j < graph[temp].size(); ++j)
        {
            if( !visit[graph[temp][j]])
            {
                visited[min(graph[temp][j] , root)][max( graph[temp][j], root )] = 1;
                visit[graph[temp][j]] = 1;
                myq.push(graph[temp][j]);
            }
        }
    }
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    fastIO;
    int z = 1, NC, NM, x, j, i, start, end, c, src, dest;
    string s1, s2;
    while(cin>> NC)
    {
        if( !NC)
            break;
        c = 1;
        vector <string> myvec(1);
        unordered_map <string, int> mymap;
        graph.clear();
        for(i = 1; i < 201; ++i)
        {
            graph.pb(temp);
            for(j = i+1; j < 201; ++j)
                visited[i][j] = 0;
        }
        for(i = 0; i < NC; ++i)
        {
            start = c;
            cin >> x;
            for(j = 0; j < x; ++j, ++c)
            {
                cin >> s1 ;
                myvec.pb(s1);
                mymap.insert( MP (s1, c));
            }
            end = c;
            for(int v = start; v < end; ++v)
            {
                if( v != end-1)
                    graph[v].pb(v+1);
                for(int w = v+1; w < end; ++w)
                {
                    visited[v][w] = 1;
                }
            }
        }
        /*for(i = 1; i < c; ++i)
        {
            for(j = 1; j < c; ++j)
                cout << visited[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';*/
        cin >> NM;
        for(i = 0; i < NM; ++i)
        {
            cin >> s1 >> s2;
            src = mymap.find(s1)->se;
            dest = mymap.find(s2)->se;
            graph[src].pb(dest);
        }
        for(i = 1; i < c; ++i)
            BFS(i);
        int sum = 0, pairs[2][2];
        for(i = 1; i < c; ++i)
        {
            for(j = i+1; j < c; ++j)
            {
                if( !visited[i][j])
                {
                    if( sum < 2){
                        pairs[sum][0] = i;
                        pairs[sum][1] = j;}
                    ++sum;
                }
            }
        }

        if( sum ){
        cout << "Case "<< z++<< ", "<< sum<< " concurrent events:\n";
        if(sum >= 2)
            cout << '('<<myvec[pairs[0][0]]<<','<<myvec[pairs[0][1]]<<") ("<< myvec[pairs[1][0]]<<','<<myvec[pairs[1][1]]<<") "<<"\n";
        else
            cout << '('<<myvec[pairs[0][0]]<<','<<myvec[pairs[0][1]]<<") "<< "\n";}
        else
            cout << "Case "<< z++<< ", no concurrent events.\n";


    }

}
