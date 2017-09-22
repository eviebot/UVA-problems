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

	
	int n, i, t, j;
	vector <int> sieve, mu, M;
	for(i = 0; i <= 1000010; ++i){
		sieve.pb(0);
		mu.pb(0);
		M.pb(0);
	}
	sieve[1] = 1;
	for(i = 2; i <= 1000000; ++i){
		if(!sieve[i]){
			j = i;
			while(j <= 1000000){
				if(!sieve[j])
					sieve[j] = i;
				j += i;
			}
		}
	}

	mu[1] = 1;
	M[1] = 1;
	for(i = 2; i <= 1000000; ++i){
		t = i;
		int prev = 0, sum = 0;
		while(t != 1){
			if(sieve[t] == prev){
				mu[i] = 0;
				M[i] = M[i-1];
				break;
			}
			sum++;
			prev = sieve[t];
			t /= sieve[t];
		}
		if(prev != sieve[t]){
			if(!(sum%2)){
				mu[i] = 1;
				M[i] = M[i-1]+1;
			}else{
				mu[i] = -1;
				M[i] = M[i-1]-1;
			}
		}
	}

	while(scanf("%d", &n)){
		if(!n)
			break;
		printf("%8d%8d%8d\n", n, mu[n], M[n]);
	}
}