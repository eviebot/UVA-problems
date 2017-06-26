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

int dist[54][54], m, n, src[2], dest[2];
bool visited[54][54];

struct xxx
{
    int dir[2];
    int r, c, remaining;
    bool flag;
};
struct xxx start;

void BFS()
{
    queue <struct xxx> myq;
    struct xxx temp;
    struct xxx pusher;
    int j, row, col, trow, tcol;
    myq.push(start);
    row = start.r;
    col = start.c;
    trow = row;tcol = col;

    dist[start.r][start.c] = 0;
    visited[start.r][start.c] = 1;
    for(j = 0; j < 3; ++j)
    {
        trow += start.dir[0];
        tcol += start.dir[1];

        if( !visited[trow][tcol])
        {
            visited[trow][tcol] = 1;
            dist[trow][tcol] = 1;
            pusher = start;
            pusher.r = trow;
            pusher.c = tcol;
            pusher.flag = false;
            myq.push(pusher);
        }
        else
            break;
    }

    while(!myq.empty())
    {
        //getchar();
        temp = myq.front();
        myq.pop();
        row = temp.r;
        col = temp.c;
        trow = row;tcol = col;
        if( temp.flag)
        {
            for(j = 0; j < 2; ++j)
            {
                trow += temp.dir[0];
                tcol += temp.dir[1];

                if( !visited[trow][tcol] )
                {
                    visited[trow][tcol] = 1;
                    dist[trow][tcol] = min(dist[trow][tcol], dist[row][col]);
                    pusher = temp;
                    pusher.r = trow;
                    pusher.c = tcol;
                    pusher.flag = false;
                    myq.push(pusher);
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            for(j = 0; j < 3; ++j)
            {
                trow += temp.dir[0];
                tcol += temp.dir[1];

                if( !visited[trow][tcol] )
                {
                    visited[trow][tcol] = 1;
                    dist[trow][tcol] = min(dist[trow][tcol], dist[row][col]+1);
                    pusher = temp;
                    pusher.r = trow;
                    pusher.c = tcol;
                    pusher.flag = false;
                    myq.push(pusher);
                }
                else
                {
                    break;
                }
            }
        }

        if( !temp.dir[0])
        {
            if( !visited[temp.r+1][temp.c])
            {
                pusher.r = temp.r+1;
                pusher.c = temp.c;
                pusher.dir[0] = 1;
                pusher.dir[1] = 0;pusher.flag = true;
                myq.push(pusher);
                visited[pusher.r][pusher.c] = 1;
                dist[pusher.r][pusher.c] = min(dist[pusher.r][pusher.c], dist[temp.r][temp.c] + 2);
            }
            if( !visited[temp.r-1][temp.c])
            {
                pusher.r = temp.r-1;
                pusher.c = temp.c;
                pusher.dir[0] = -1;
                pusher.dir[1] = 0;pusher.flag = true;
                myq.push(pusher);
                visited[pusher.r][pusher.c] = 1;
                dist[pusher.r][pusher.c] = min(dist[pusher.r][pusher.c], dist[temp.r][temp.c] + 2);
            }
            if( !visited[temp.r][temp.c - temp.dir[1]] )
            {
                pusher.r = temp.r;
                pusher.c = temp.c-temp.dir[1];
                pusher.dir[0] = 0;
                pusher.dir[1] = -temp.dir[1];pusher.flag = true;
                myq.push(pusher);
                visited[pusher.r][pusher.c] = 1;
                dist[pusher.r][pusher.c] = min(dist[pusher.r][pusher.c], dist[temp.r][temp.c] + 3);
            }
        }
        else
        {
             if( !visited[temp.r][temp.c+1])
            {
                pusher.r = temp.r;
                pusher.c = temp.c+1;
                pusher.dir[0] = 0;
                pusher.dir[1] = 1;pusher.flag = true;
                myq.push(pusher);
                visited[pusher.r][pusher.c] = 1;
                dist[pusher.r][pusher.c] = min(dist[pusher.r][pusher.c], dist[temp.r][temp.c] + 2);
            }
            if( !visited[temp.r][temp.c-1])
            {
                pusher.r = temp.r;
                pusher.c = temp.c-1;
                pusher.dir[0] = 0;
                pusher.dir[1] = -1;pusher.flag = true;
                myq.push(pusher);
                visited[pusher.r][pusher.c] = 1;
                dist[pusher.r][pusher.c] = min(dist[pusher.r][pusher.c], dist[temp.r][temp.c] + 2);
            }
            if( !visited[temp.r-temp.dir[0]][temp.c] )
            {
                pusher.r = temp.r-temp.dir[0];
                pusher.c = temp.c;
                pusher.dir[0] = -temp.dir[0];
                pusher.dir[1] = 0;pusher.flag = true;
                myq.push(pusher);
                visited[pusher.r][pusher.c] = 1;
                dist[pusher.r][pusher.c] = min(dist[pusher.r][pusher.c], dist[temp.r][temp.c] + 3);
            }
        }
    }
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    int i, j;
    bool dec;
    string direction;
    int counter = 0;
    while(infile >> m >> n)
    {
        if( !n)
            break;
        ++counter;
        for(i = 0; i <= m+2; ++i)
        {
            for (j =0; j <= n+2; ++j)
            {
                visited[i][j] = 0;
                dist[i][j] = 1e6;
            }
        }
        for(i =0 ; i <= n+2; ++i)
        {
            visited[0][i] = 1;
            visited[m+2][i] = 1;
        }
        for(i = 0; i <= m+2; ++i)
        {
            visited[i][0] = 1;
            visited[i][n+2] = 1;
        }

        for(i = 1; i <= m; ++i)
        {
            for(j = 1; j <= n; ++j)
            {
                infile >> dec;
                if( dec)
                {
                    visited[i][j] = 1;
                    visited[i][j+1] =1;
                    visited[i+1][j] = 1;
                    visited[i+1][j+1] = 1;
                }
            }
        }
        /*cout << "  ";
        for(i = 0; i <m+3; ++i)
            cout << i%10 << " ";
        cout << "\n";
        for(i = 0; i < m+3; ++i)
        {
            cout << i%10 << " ";
            for(j = 0; j <= n+2; ++j)
            {
                cout << visited[i][j] <<' ';
            }
            cout << '\n';
        }
        cout << "\n\n";*/
        infile >> src[0] >> src[1] >> dest[0] >>dest[1] >> direction;

        start.r = src[0]+1;
        start.c = src[1]+1
        if( visited[start.r][start.c])
        {
            cout << -1 << "\n";
            continue;
        }
        if( direction == "south")
        {
            start.dir[0] = 1;
            start.dir[1] = 0;
        }
        else if( direction == "north")
        {
            start.dir[0] = -1;
            start.dir[1] = 0;
        }
        else if( direction == "east")
        {
            start.dir[0] = 0;
            start.dir[1] = 1;
        }
        else
        {
            start.dir[0] = 0;
            start.dir[1] = -1;
        }
        start.flag = true;
        BFS();
        if( dist[dest[0]+1][dest[1]+1] == 1e6)
            cout << -1 << '\n';
        else
            cout << dist[dest[0]+1][dest[1]+1]<<"\n";
    }
}
