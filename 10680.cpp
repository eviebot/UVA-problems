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

int multiply(int dig, int n){
	return (dig*n)%10;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int sieve[1000010], n, i, j, storage[1000010] = {0};
	for(i = 2; i <= 1000000; ++i){
		if(!sieve[i]){
			j = i;
			while(j <= 1000000){
				sieve[j] = i;
				j += i;
			}
		}
	}
	int temp = 1;
	for(i = 1000; i <= 1000000; ++i){
		if(sieve[i] == i)
			temp = multiply(temp, i);
		storage[i] = temp;
	}
	while(cin >> n){
		if(!n)
			break;

		int n2 = 0, n5 = 0, lastdig = 1, m = 2, n3 = 0;
		while(n/m){
			n2++;
			m *= 2;
		}
		m = 3;
		while(n/m){
			n3++;
			m *= 3;
		}
		m = 5;
		while(n/m){
			n5++;
			m *= 5;
		}
		//cout << n2 << " "<< n3 << " "<< n5 << "\n";
		for(i = 1; i <= n3; ++i)
			lastdig = multiply(lastdig, 3);
		if(n2 > n5){
			for(i = 1; i <= n2-n5; ++i)
				lastdig = multiply(lastdig, 2);
		}
		else{
			for(i = 1; i <= n5-n2; ++i)
				lastdig = multiply(lastdig, 5);
		}
		for(i = 7; i <= min(1000, n); ++i){
			if(sieve[i] == i){
				m = i;
				int x =0 ;
				while(n/m){
					x++;
					m *= i;
				}
				for(j = 1; j <= x; ++j)
					lastdig = multiply(lastdig, i);
			}
		}
		if(n > 1000)
			lastdig = multiply(lastdig, storage[n]);

		cout << lastdig << "\n";
	}
}