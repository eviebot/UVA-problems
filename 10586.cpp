#include <bits/stdc++.h>
using namespace std;

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

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int n, k, i, t;

	int coeff[20000];
	while(cin >> n >> k){
		if( n== -1)
			break;

		for(i = 0; i <= n; ++i){
			cin >> coeff[i];
		}

		int diff = n-k;
		while(diff >= 0){
			coeff[diff] -= coeff[diff+k];
			coeff[diff+k] = 0;
			--diff;
		}

		bool flag = true;

		i = 0;
		while(i <= n){
			if(coeff[i]){
				cout << coeff[i];
				flag = false;
				++i;
				break;
			}
			++i;
		}
		for(; i <=n; ++i){
			if(coeff[i]){
				cout << " "<< coeff[i];
			}
		}
		if(flag){
			cout << "0";
		}
		cout << "\n";
	}
}