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
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, t, cost, fcost, i;

    while(true)
    {
        cin >> n;
        if(n==0)
            break;
        priority_queue <int, vector <int>, greater<int> > que;
        fcost = 0;
        for(i = 0; i< n; i++)
        {
            cin >> t;
            que.push(t);
        }

        while(que.size() != 1)
        {
            cost = que.top();
            que.pop();
            cost += que.top();
            que.pop();
            que.push(cost);
            fcost += cost;
        }

        cout << fcost << "\n";
    }
}
