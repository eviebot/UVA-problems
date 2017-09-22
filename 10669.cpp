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
	int sieve[1000010] = {0}, n, i, j, t;

	sieve[1] = 1;
	for(i =2 ;i <= 1000000; ++i){
		if(!sieve[i]){
			j = i;
			while(j <= 1000000){
				sieve[j] = i;
				j += i;
			}
		}
	}

	while(cin >> n){
		if(!n)
			break;

		t = n;
		unordered_set <int> temp;
		while(t != 1){
			temp.insert(sieve[t]);
			t /= sieve[t];
		}
		cout << n << " : "<< temp.size() << "\n";
	}
}