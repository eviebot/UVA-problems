#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second


int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int sum, tempsum, maximum, i, num, j, n;
    vector <int> vec, vec1;
    while(cin >> n)
    {
        num = pow(2, n);
        maximum = 0;
        vec.clear();vec1.clear();
        bitset <16> bit, tempbit;
        for(i = 0; i< num; i++)
        {
            cin >> tempsum;
            vec.pb(tempsum);
        }
        bit.reset();
        while(true)
        {
            tempsum = 0;
            for(j = 0; j< n; j++)
            {
                tempbit = bit;
                tempbit[j] = !tempbit[j];
                tempsum += vec[tempbit.to_ulong()];
            }
            vec1.pb(tempsum);
            bit = bit.to_ulong()+1;
            if(bit[n]==1)
                break;
        }
        bit.reset();
        while(true)
        {
            sum = vec1[bit.to_ulong()];
            for(j = 0; j< n; j++)
            {
                tempbit = bit;
                tempbit[j] = !tempbit[j];
                tempsum = vec1[tempbit.to_ulong()];
                if(sum + tempsum> maximum)
                    maximum = sum + tempsum;
            }
            bit = bit.to_ulong()+1;
            if(bit[n]==1)
                break;
        }
        cout << maximum<<"\n";
    }
    return 0;
}
