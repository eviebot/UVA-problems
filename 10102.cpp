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

    int M, i, j, maximum, temp, mini;
    char c;
    while(cin >> M)
    {
        vector <pair <int, int>> color1, color3;
        vector <pair <int, int>>::iterator iter1, END1, iter3, END3;
        for(i = 1; i<= M; i++)
        {
            for(j = 1; j <= M ; j++)
            {
                cin >> c;
                if(c=='1')
                    color1.pb( MP (i, j));
                else if(c=='3')
                    color3.pb( MP (i, j));
            }
        }

        END1 = color1.end();
        END3 = color3.end();
        iter1 = color1.begin();

        maximum = 0;
        for(; iter1 != END1; ++iter1)
        {
            iter3 = color3.begin();
            mini = abs(iter1->fi - iter3->fi) + abs(iter1->se - iter3->se);
            for( ; iter3 != END3; ++iter3)
            {
                temp = abs(iter1->fi - iter3->fi) + abs(iter1->se - iter3->se);
                if( temp < mini)
                    mini = temp;
            }
            if(mini > maximum)
                maximum = mini;
        }
        cout << maximum<<"\n";
    }

}
