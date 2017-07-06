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
    ofstream outfile;
    outfile.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int N, M, i, j, var, q, L, U, ans, temporary, temporary1, y;
    while(cin >> N && cin >> M)
    {
        if(!N)
            break;
        vector <vector <int>> vec;
        vector <int> temp;
        int builder[N][2];
        for(i = 0; i < N; ++i)
        {
            temp.clear();
            for(j = 0; j< M ; ++j)
            {
                cin >> var;
                temp.pb(var);
            }
            vec.pb(temp);
        }
        cin >> q;
        for(y = 0; y < q; ++y)
        {
            ans = 0;
            cin >> L >> U;
            for(j = 0; j< N; ++j)
            {
                builder[j][0] = lower_bound((vec[j]).begin(), (vec[j]).end(), L)-vec[j].begin();
                builder[j][1] = (upper_bound(vec[j].begin(), vec[j].end(), U)-vec[j].begin())-1;
            }
            for(j = 0; j < N; ++j)
            {
                temporary = builder[j][1] - builder[j][0];
                temporary1 = temporary+1;
                cout << builder[j][0]<<" "<< builder[j][1]<<" "<< temporary1<<"\n";
                if(temporary > 0)
                {
                    for(i = j-1; i>= 0; --i)
                    {
                        if(builder[j][0] <= builder[i][0] && builder[j][1] <= builder[i][1] )
                        {
                            --temporary;
                        }
                        else
                        {
                            break;
                        }
                    }
                    cout << temporary<<"\n";
                    if(temporary > 0)
                    {
                        for(i = j+1; i < N; ++i)
                        {
                            if(builder[j][0] <= builder[i][0] && builder[j][1] <= builder[i][1] )
                            {
                                --temporary;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
                if(temporary <= 0)
                {
                    if(ans < temporary1)
                        ans = temporary1;
                }
            }
            cout << ans<<"\n";
        }
        cout << "-\n";
    }
    return 0;
}
