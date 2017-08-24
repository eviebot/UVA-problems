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

	int data[10001][10], i, j, t;
	lli sum[10];

	for(i = 1; i <= 10000; ++i){
		for(j = 0; j < 10; ++j)
			data[i][j] = 0;
	}

	for(i = 1; i <= 10000; ++i){
		t = i;
		while(t){
			data[i][t%10]++;
			t/= 10;
		}
	}

	cin >> t;
	int n;
	for(int z = 1; z <= t; ++z){
		cin >> n;
		for(i = 0; i < 10; ++i)
			sum[i] = 0;

		for(i = 1; i <= n; ++i)
		{
			for(j = 0; j < 10; ++j){
				sum[j] += data[i][j];
			}
		}

		for(j = 0; j < 9; ++j)
			cout << sum[j] << " ";
		cout << sum[9];
		cout << "\n";
	}

}