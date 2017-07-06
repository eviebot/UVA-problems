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

    long long int i, n, sum , diff, a, b;
    cin >> n;

    for(i = 0; i< n;i++)
    {
        cin >> sum >> diff;
        a = (sum+diff)/2;
        b = (sum-diff)/2;
        if(sum < diff || (sum+diff)%2==1)
            cout << "impossible\n";
        else
            cout << a << " "<< b <<"\n";
    }
}
