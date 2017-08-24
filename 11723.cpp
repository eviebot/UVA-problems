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
	int r, n, c =1;
	while(cin >> r >> n){
		if(!r)
			break;
		
		cout << "Case "<< c++<< ": ";
		if(r <= n){
			cout << "0\n";
			continue;
		}
		int t = r-n;
		if(t/n > 26 || (t/n==26 && t%n)){
			cout << "impossible\n";
			continue;
		}

		cout << (t%n?t/n+1:t/n)<< "\n";
	}
}