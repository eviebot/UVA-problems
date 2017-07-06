#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
int bin_search(vector <int> & vec, int start, int en, int val)
{
    if(en < start)
    {
        return -1;
    }
    int mid = (en+start)/2;
    if(vec[mid] == val)
    {
        return val;
    }
    else if(vec[mid] > val)
    {
        bin_search(vec, start, mid-1, val);
    }
    else
    {
        bin_search(vec, mid+1, en, val);
    }
}
int main()
{
    ofstream outfile;
    outfile.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n_books, var, i, price, p1, p2, diff, ans;
    while(cin >> n_books)
    {
        vector <int> vec;
        diff = 1000001;
        for(i = 0; i< n_books; ++i)
        {
            cin >> var;
            vec.pb(var);
        }
        cin >> price;
        sort(vec.begin(), vec.end());

        for(i = 0; i< n_books; ++i)
        {
            p1 = vec[i];
            if(p1 <= price)
            {
                p2 = bin_search(vec, 0, i-1, price - p1);
                if(p2 != -1)
                {
                    if(p2 <= p1 && (p1-p2) < diff)
                    {
                        diff = p1-p2;
                        ans = p2;
                    }
                    else if(p1 < p2 && (p2-p1) < diff)
                    {
                        diff = p2 - p1;
                        ans = p1;
                    }
                }
                else
                {
                    p2 = bin_search(vec, i+1, n_books-1, price - p1);
                    if(p2 != -1)
                    {
                        if(p2 < p1 && (p1-p2) < diff)
                        {
                            diff = p1-p2;
                            ans = p2;
                        }
                        else if(p1 < p2 && (p2-p1) < diff)
                        {
                            diff = p2 - p1;
                            ans = p1;
                        }
                    }
                }
                //cout << p1 <<" "<< p2 <<'\n';
            }
            else
            {
                break;
            }
        }
        cout << "Peter should buy books whose prices are "<< ans<<" and "<<(price-ans)<<".\n\n";
    }
    return 0;
}
