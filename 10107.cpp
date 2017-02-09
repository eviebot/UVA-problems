#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front

int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long int num, len=0, med;
    multiset <long long int> myset;
    multiset <long long int>::iterator median;

    while(cin >> num)
    {
        len++;
        myset.insert(num);
        median = myset.begin();
        if(len%2==1)
        {
            advance(median, len/2);
            med = *median;
        }
        else
        {
            advance(median, len/2-1);;
            med = *median;
            advance(median, 1);
            med += *median;
            med/=2;
        }
        cout<< med <<"\n";
    }
}
