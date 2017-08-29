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

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int arr[2000], i, n;

	fastIO;
	while(true){
		cin >> arr[1];
		if(!arr[1])
			break;

		i = 1;
		while(true){
			cin >> arr[++i];
			if(!arr[i])
				break;
		}
		int t = __gcd(abs(arr[i-1]-arr[1]), 0);
		//cout << t << "\n";
		n = i-1;
		for(i = 2; i < n; ++i){
			t = __gcd(t, abs(arr[i]-arr[i-1]));
		}

		cout << t << "\n";
	}
}