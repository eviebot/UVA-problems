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
	lli n, m, type, t, ans;
	while(cin >> n >> m >> type){
		if(!n){
			break;
		}

		t = (n-7)*(m-7);

		if(t%2){
			if(!type){
				ans = t/2;
			}
			else{
				ans = t/2+1;
			}
		}
		else{
			ans = t/2;
		}
		cout << ans << "\n";
	}
}