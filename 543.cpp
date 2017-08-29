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
	int i, n, t;
	int arr[1000010];

	for(i = 1; i <= 1000000; ++i)
		arr[i] =0;

	for(i = 2; i <= 1000000; ++i){
		if(!arr[i]){
			int j = i;
			while(j <= 1000000){
				arr[j] = i;
				j += i;
			}
		}
	}

	while(cin >> n){
		if(!n)
			break;
		bool flag = true;
		for(i = 2; i <= n && flag; ++i){
			if(arr[i] == i && arr[n-i] == n-i){
				cout << n << " = "<< i << " + "<< n-i << "\n";
				flag = false;
			}
		}
		if(flag){
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}
}