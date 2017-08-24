#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
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
	int n;
	while(cin >> n){
		if(!n)
			break;

		if(n == 1){
			cout << n << "\n";
			continue;
		}
		int l = pow(2, (int)(log2(n)));
		//cout << l << "\n";
		l = n-l;
		if(l){
			cout << 2*l << "\n";
		}
		else{
			cout << pow(2, log2(n));
		}
	}
}