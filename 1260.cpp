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


    int test_cases, i, sum, j, A;

    cin >> test_cases;

    for(int lel = 0; lel < test_cases; ++lel)
    {
        cin >> A;
        int arr[A];
        sum = 0;
        for(i = 0; i< A; i++)
        {
            cin >> arr[i];
            for(j = 0; j< i; j++)
            {
                if(arr[j] <= arr[i])
                {
                    ++sum;
                }
            }
        }
        cout << sum <<"\n";
    }
}
