#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

bool checker(queue <int> & x1, queue <int> & x2)
{
    if(x1.empty() && x2.empty())
        return false;
    return true;
}

int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int test_cases, n, i, maxi, temp, sum;
    unordered_set <long long int> myset;
    pair <unordered_set <long long int>::iterator, bool> ret;
    vector <int> vec;
    vector <int>::iterator it;
    cin >> test_cases;

    for(int lel = 0; lel < test_cases; lel++)
    {
        cin >> n;
        maxi = 0;
        vec.clear();
        myset.clear();
        sum = 0;
        for(i = 0; i< n; i++)
        {
            cin >> temp;
            vec.pb(temp);
            ret = myset.insert(temp);
            if(ret.se == false)
            {
                if(sum > maxi)
                {
                    maxi = sum;
                }
                sum = 1;
                myset.clear();
                myset.insert(temp);
                it = vec.end();
                advance(it, -2);
                while(*it != temp)
                {
                    ++sum;
                    myset.insert(*it);
                    --it;
                }
                it++;
                vec.erase(vec.begin(), it);
                continue;
            }
            sum ++;
        }
        if(sum > maxi)
            maxi = sum;
        cout << maxi <<"\n";
    }
}
