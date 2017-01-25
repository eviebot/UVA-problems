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

    string s;
    int i, index, score[10][2], sum, z;
    char c;
    while(true)
    {
        getline(cin, s);
        if(s[0]=='G')
            break;
        sum = 0;
        for(i = 0; i< 10;i++)
        {
            score[i][0] = 0;
            score[i][1] = 0;
        }
        index = 0;
        for(i = 0 ; i< 9;i++)
        {
            c = s[index];
            index += 2;
            if(c=='X')
            {
                score[i][0] = 10;
                score[i][1] = 0;
                continue;
            }
            score[i][0] = c - '0';
            c = s[index];
            index += 2;
            if(c=='/')
            {
                score[i][1] = 10-score[i][0];
                continue;
            }
            score[i][1] = c-'0';
        }
        for(i = 0 ; i< 2;i++)
        {
            c = s[index];
            index += 2;
            if(c=='X')
            {
                sum += 10;
                score[9][i] = 10;
            }
            else if(c=='/')
            {
                sum = 10;
                score[9][i] = 10-score[9][0];
            }
            else
            {
                sum += c-'0';
                score[9][i] = c-'0';
            }
        }
        if(index < s.length())
        {

            c = s[index];
            if(c=='X')
                sum +=10;
            else if(c=='/')
                sum = 20;
            else
                sum += c-'0';
        }
        for(i = 0; i< 9;i++)
        {
            if(score[i][0]==10)
            {
                z = i+1;
                if(z!=9)
                {
                    if(score[z][0]==10)
                    {
                        sum += 20+score[z+1][0];
                    }
                    else
                    {
                        sum += 10+score[z][0]+score[z][1];
                    }
                }
                if(z==9)
                    sum += 10+score[z][0] +score[z][1];
            }
            else if(score[i][0]+score[i][1]==10)
            {
                sum += 10+score[i+1][0];
            }
            else
                sum += score[i][0] + score[i][1];
        }
        cout << sum <<"\n";
    }
}
