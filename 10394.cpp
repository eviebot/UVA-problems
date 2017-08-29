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
#define maxn 20000010
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int i, t, j;
	vector <int> arr;

	for(i = 0; i <= maxn; ++i)
		arr.pb(0);

	for(i = 2; i < maxn; ++i){
		if(!arr[i]){
			j = i;
			while(j < maxn){
				arr[j] = i;
				j += i;
			}
		}
	}
	
	vector <int> prime;
	prime.pb(0);
	prime.pb(3);
	prime.pb(5);
	for(i = 8; i < maxn; ++i){
		if(arr[i] == i && arr[i+2] == i+2){
			prime.pb(i);
			i += 2;
		}
	}
	while(cin >> t){
		cout << '(' << prime[t] << ", "<< prime[t]+2 << ")\n";
	}
}