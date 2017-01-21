#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
int suit(char x)
{
    if(x=='S')
        return 0;
    else if(x=='H')
        return 1;
    else if(x=='D')
        return 2;
    else
        return 3;
}
int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n_cards[4], points,i, k, j, suit_flags[4][4];
    bool  stopSTATUS[4];
    string s;
    char c;
    while(getline(cin , s))
    {
        for(i = 0; i< 4;i++)
        {
            n_cards[i] = 0;
            stopSTATUS[i] =false;
            for(k = 0 ; k< 4;k++)
            {
                suit_flags[i][k] =0;
            }
        }
        points = 0;

        for(i = 0; i< s.length();i+=3)
        {
            c = s[i];
            k = suit(s[i+1]);

            n_cards[k] ++;
            if(c=='A')
            {
                points +=4;
                suit_flags[k][0]++;
            }
            else if(c=='K')
            {
                points +=3;
                suit_flags[k][1]++;
            }
            else if(c=='Q')
            {
                points += 2;
                suit_flags[k][2]++;
            }
            else if(c=='J')
            {
                points ++;
                suit_flags[k][3]++;
            }
        }
        for(i = 0 ; i< 4;i++)
        {
            if(suit_flags[i][0])
                stopSTATUS[i]=true;
        }
        for(i = 0; i< 4;i++)
        {
            for(j = 1; j< 4;j++)
            {
                if(suit_flags[i][j]>=1 && !(n_cards[i]> j))
                    points -= suit_flags[i][j];
                if(j!=3 && suit_flags[i][j] && n_cards[i] >= (j+1))
                    stopSTATUS[i]=true;
            }
        }
        k = 0;
        for(i = 0; i< 4;i++)
            k += stopSTATUS[i];
        if(points >= 16 && k==4)
        {
            cout << "BID NO-TRUMP\n";
        }
        else
        {
            for(i = 0; i< 4;i++)
            {
                if(n_cards[i]==2)
                    points++;
                else if(n_cards[i]<=1)
                    points+=2;
            }
            if(points<14)
                cout << "PASS\n";
            else
            {
                int maximum = 0;
                for(i = 0; i< 4;i++)
                {
                    if(n_cards[i] > maximum)
                    {
                        maximum = n_cards[i];
                        k = i;
                    }
                }
                cout << "BID ";
                if(k==0)
                    cout <<"S\n";
                else if(k==1)
                    cout << "H\n";
                else if(k==2)
                    cout << "D\n";
                else
                    cout << "C\n";
            }
        }
    }
}
