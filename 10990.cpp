#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_fronto
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

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int n, i, t, prev;
	vector <int> sieve, sum, dphi;
	sieve.resize(2000010);
	sum.resize(2000010);
	dphi.resize(2000010);
	for(i = 2; i <= 2000000; ++i)
		sieve[i] = i;
	sum[1] = 1;
	sieve[1] = 0;
	dphi[1] = 0;
	for(i = 2; i <= 2000000; ++i){
		if(sieve[i] == i){
			int j= i;
			while(j <= 2000000){
				sieve[j] -= sieve[j]/i;
				j += i;
			}
		}
	}
	for(i= 2; i <= 2000000; ++i){
		dphi[i] = dphi[sieve[i]]+1;
		sum[i] = sum[i-1]+dphi[i];
		
	}

	int test, a, b;
	cin >> test;
	for(i = 1; i <= test; ++i){
		cin >> a >> b;
		cout << sum[b] - sum[a-1] << "\n";
	}
}