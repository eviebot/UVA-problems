#include <bits/stdc++.h>
#include <string>
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

    int n, filled_pages, t, c, i;
    bool page_flag;
    vector <vector<int>> vec;
    vector <int> temp={0, 0, 0, 0};
    while(true)
    {
        vec.clear();
        cin >> n;
        if(n==0)
            break;
        filled_pages = n/4 ;
        if(n%4!=0)
            filled_pages++;
        for(i = 0; i< filled_pages;i++)
            vec.pb(temp);
        t = 0;
        c = 1;
        cout << "Printing order for "<< n << " pages:\n";
        while(t<filled_pages)
        {

            vec[t][0] = c;
            vec[t][1] = c+1;
            c+=2;
            t++;
        }
        if(n==1)
            vec[0][1] =0;
        while(c<=n)
        {
            vec[t-1][2] = c;c++;
            if(c>n)
                break;
            vec[t-1][3] = c;
            c++;
            t--;
        }

        for(i = 0; i< filled_pages;i++)
        {
            page_flag = true;
            if(vec[i][1]==0 && vec[i][2]==0)
                page_flag = false;
            cout <<"Sheet "<< i+1<<", front: ";
            if(vec[i][3]==0)
                cout << "Blank, ";
            else
                cout << vec[i][3]<<", ";
            cout << vec[i][0]<<"\n";

            if(page_flag)
            {
                cout <<"Sheet "<< i+1<<", back : "<<vec[i][1]<<", ";
                if(vec[i][2]==0)
                    cout << "Blank\n";
                else
                    cout << vec[i][2]<<"\n";
            }
        }
    }
}
