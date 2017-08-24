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
	int data[400001][2];
	int i, j, n, k, c =0;

	for(i = 1; i <= 1000; ++i){
		for(j = 1; j <= i; ++j){
			int t = __gcd(i, j);
			if(t == 1){
				data[++c][0] = j;
				data[c][1] = i;
			}
		}
	}


	while(cin >> n >> k){
		vector <pair <double, int>> newa;
		int i = 1;
		while(data[i][1] <= n){
			newa.pb(MP((double)(data[i][0])/data[i][1], i));
			++i;
		}

		sort(newa.begin(), newa.end());

		cout << data[newa[k-1].se][0] << "/"<< data[newa[k-1].se][1] << "\n";
	}
}