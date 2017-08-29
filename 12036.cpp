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

	fastIO;
	int t, n, i, tt;
	cin >> t;
	for(int z = 1; z <= t; ++z){
		cin >> n;
		int arr[200];
		for(i = 0; i <= 100; ++i)
			arr[i] = 0;
		for(i = 0; i < n*n; ++i){
			cin >> tt;
			arr[tt] ++;
		}

		bool flag = true;
		for(i = 0;i <= 100; ++i){
			if(arr[i] > n)
				flag = false;
		}
		cout << "Case "<< z << ": ";
		if(flag)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}