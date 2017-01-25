#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back

void rbq(int i, int j, vector<vector <char>> & vec, char x)
{
    int k , lelouch, t1 = i, t2 = j;
    vector <vector <int>> dir;
    char c;
    if(x=='r')
    {
        dir= {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        lelouch = 3;
    }
    else if(x=='b')
    {
        dir = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        lelouch = 3;
    }
    else if(x=='q')
    {
        dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        lelouch = 7;
    }
    for(k = 0; k<=lelouch;k++)
    {
        while(true)
        {
            t1 += dir[k][0];
            t2 += dir[k][1];
            if(t1 < 0 || t1 > 7 || t2 < 0 || t2 > 7)
            {
                t1 = i;
                t2 = j;
                break;
            }
            c = vec[t1][t2];
            if(c=='0'||c=='1')
                vec[t1][t2] = '1';
            else
            {
                t1 = i;
                t2 = j;
                break;
            }
        }
    }
}

void kk(int i, int j, vector<vector <char>> & vec, char x)
{
    vector <vector<int>> dir;
    int t1, t2;
    if(x=='n'){
        dir= {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}};}
    else
        dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for(int k = 0; k <= 7;k++)
    {
        t1 = i+ dir[k][0];
        t2 = j+dir[k][1];
        if(t1 < 0 || t1 > 7 || t2 < 0 || t2 > 7)
        {
            continue;
        }
        if(vec[t1][t2]=='0' || vec[t1][t2] =='1')
            vec[t1][t2] = '1';
    }
}

void pawn(int i, int j, vector<vector <char>> & vec, char x)
{
    int t1, t2;
    vector <vector <int>> dir;
    if(x=='p')
    {
        dir = {{1, 1}, {1, -1}};
    }
    else
    {
        dir = {{-1, 1}, {-1, -1}};
    }
    for(int k = 0; k< 2;k++)
    {
        t1 = i+ dir[k][0];
        t2 = j+ dir[k][1];

        if((t1 < 0 || t1 > 7 || t2 < 0 || t2 > 7))
            continue;
        if(vec[t1][t2]=='0' || vec[t1][t2] =='1'){
            vec[t1][t2] = '1';
        }
    }
}

int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int i, index, j, k, sum;
    char c;
    vector <vector <char>> myvec;
    vector <char> temp;
    vector <vector <char>>::iterator row;
    vector <char>::iterator col;
    while(cin>> s)
    {
        sum = 0;
        index = 0;
        myvec.clear();
        temp.clear();
        for(i = 1; i<=8;i++)
        {
            for(j = 1;j<=8;)
            {
                c = s[index];
                if(!(49<=c && c<=56))
                {
                    temp.pb(c);
                    j++;
                }
                else
                {
                    j+= (int)(c)-(int)('0');
                    for(k = 1; k<=c-'0';k++)
                        temp.pb('0');
                }
                index++;
            }
            myvec.pb(temp);
            index++;
            temp.clear();
        }
        for(i = 0; i< 8;i++)
        {
            for(j = 0; j< 8;j++)
            {
                c = myvec[i][j];
                if(!(c=='p'||c=='P'))
                    {c = tolower(c);}
                if(c=='r' || c=='b' || c=='q')
                    rbq(i, j, myvec, c);

                else if(c == 'n' || c=='k')
                    kk(i, j, myvec, c);
                else if(c=='p' ||c=='P')
                    pawn(i, j, myvec, c);
            }
        }

        for(row=myvec.begin();row!=myvec.end();row++)
        {
            for(col = row->begin();col!=row->end();col++)
            {
                if(*col=='0')
                    sum ++;
            }
        }
        cout << sum << "\n";

    }
}
