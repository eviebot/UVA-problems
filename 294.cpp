#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;

int finder(int x){
	int multi = 1;
	for(int i = 2; i <= sqrt(x); ++i){
		int c = 0;
		while(!(x%i)){
			c++;
			x /= i;
		}
		multi *= (c+1);
	}
	if(x != 1)
		multi *= 2;
	return multi;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int n, l, r, i, maxi, index;
	cin >> n;

	for(int z = 0; z < n; ++z){
		cin >> l >> r;
		maxi = 0;
		for(i = l; i <= r; ++i){
			int t = finder(i);
			//cout << i << "\n";
			if(t > maxi){
				maxi = t;
				index = i;
			}
		}
		cout << "Between "<<l<<" and "<< r << ", "<< index << " has a maximum of "<< maxi<< " divisors.\n";
	}
}