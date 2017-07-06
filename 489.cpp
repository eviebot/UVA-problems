#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    /*ofstream cout;
    cout.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);

    unsigned int n, counter, i, j, hang;
    string sol, guess;
    bool checker;
    char c;
    while(true)
    {
        cin  >> n;
        if(n==-1)
            break;
        bool flag[26] = {false};
        hang = 0;
        counter = 0;
        cin >> sol >> guess;
        cout << "Round "<< n << "\n";
        for(i = 0; i< guess.length();i++)
        {
            c = guess[i];
            checker = false;
            for(j = 0; j< sol.length();j++)
            {
                if(c==sol[j]&& !flag[(c-'a')])
                {
                    checker = true;
                    counter++;
                }
            }
            if(!checker && !flag[(c-'a')])
                hang++;
            if(hang>=7)
            {
                cout << "You lose.\n";
                break;
            }
            else if(counter == sol.length())
            {
                cout << "You win.\n";
                break;
            }
            flag[(c-'a')] = true;
        }

        if(hang < 7 && counter < sol.length())
            cout << "You chickened out.\n";
    }
}
