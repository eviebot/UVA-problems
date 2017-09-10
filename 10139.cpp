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
	int sieve[70010], n, m, j, i, nt, mt;

	for(i = 1; i <= 70000; ++i){
		sieve[i] = 0;
	}
	sieve[1] = 1;
	for(i = 2; i <= 70000; ++i){
		if(!sieve[i]){
			j = i;
			while(j <= 70000){
				sieve[j] = i;
				j += i;
			}
		}
	}

	while(cin >> n >> m){
		nt = n;mt = m;
		unordered_map <int, int> mapn;
		bool flag = true;

		for(i = 2; i <= sqrt(n)+1; ++i){
			if(sieve[i] == i){

				int c =0;
				j = i;
				while(n/j){
					c += n/j;
					j *= i;
				}
				mapn[i] = c;
			}
		}
		for(i = 2; i <= sqrt(m)+1; ++i){
			if(sieve[i] == i){
				int c =0;
				while(!(m%i)){
					m /= i;
					++c;
				}
				if(c <= nt/i)
					continue;
				if(c > mapn[i]){
					flag = false;
				}
			}
		}
		if(m != 1){
			//cout << m << "\n";
			if(m > n){
				flag = false;
			}
		}
		if(flag){
			cout << mt << " divides "<< nt << "!\n";
		}else{
			cout << mt << " does not divide "<< nt << "!\n";
		}
	}
}