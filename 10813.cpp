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

    int n_games, lelouch, t1, t2, c, q, i, j, k, l, BINGO[5][5],temp, pos[2], dir[4][2][2] = {{{0, 1}, {0, -1}}, {{1,0}, {-1, 0}}, {{1, 1}, {-1, -1}}, {{-1, 1}, {1, -1}}};
    bool BINGO_flag[2], end_flag;
    vector <bool> flag(76);
    cin >> n_games;

    for(q=1; q <= n_games; q++)
    {
        end_flag = false;
        for(i = 0; i< 76;i++)
            flag[i] = false;
        for(i = 0; i< 5;i++)
        {
            for(j = 0; j< 5;j++)
            {
                if(!(i==2&& j==2))
                {
                    cin >>BINGO[i][j];
                }
            }
        }
        BINGO[2][2] = -1;
        for(c=1;c<=75;c++)
        {
            cin >> temp;
            if(!end_flag)
            {
                for(i = 0; i< 5;i++)
                {
                    for(j = 0; j< 5;j++)
                    {
                        if(temp==BINGO[i][j])
                        {
                            flag[temp]=true;
                            break;
                        }
                    }
                    if(flag[temp])
                        break;
                }
                if(flag[temp])
                {
                    if(i==j)
                    {
                        lelouch = 3;
                    }
                    else if(4-i==j)
                    {
                        lelouch = 4;
                    }
                    else
                    {
                        lelouch = 2;
                    }
                    for(k = 0; k < lelouch;k++)
                    {
                        BINGO_flag[0] = false;
                        BINGO_flag[1] = false;
                        if(4-i==j)
                        {
                            if(k==2)
                                continue;
                        }
                        for(l = 0; l<2;l++)
                        {
                            t1 = i;
                            t2 = j;
                            while(true)
                            {
                                pos[0] = t1+dir[k][l][0];
                                pos[1] = t2+dir[k][l][1];
                                t1 += dir[k][l][0];
                                t2 += dir[k][l][1];
                                if(pos[0]>4 || pos[0]<0 || pos[1] > 4 || pos[1] <0)
                                {
                                    BINGO_flag[l] = true;
                                    break;
                                }
                                if(!( (pos[0]==2&&pos[1]==2) || flag[BINGO[pos[0]][pos[1]]] ))
                                {
                                    break;
                                }
                            }
                        }
                        if(BINGO_flag[0] && BINGO_flag[1])
                        {
                            cout << "BINGO after "<<c<<" numbers announced\n";
                            end_flag = true;
                            break;
                        }
                    }
                }
            }
        }
    }
}
