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

	int digits[1000], temp[1000], n_digits = 1, i, t, n, j, digitcount[370][10];
	memset(digits, 0, 3000);
	memset(temp, 0, 3000);
	
	for(i = 0; i < 370; ++i){
		for(j = 0; j < 10; ++j)
			digitcount[i][j] = 0;
	}
	digitcount[1][1] = 1;
	digits[1] = 1;

	for(i = 2; i < 370; ++i){
		for(j = 1; j <= n_digits; ++j){
			temp[j] = digits[j] * i;
			digits[j] = temp[j]%10;
			temp[j] /= 10;
		}

		int c;
		for(j = 1; j <= n_digits; ++j){
			c = j;
			while(temp[j]){
				++c;
				digits[c] += temp[j]%10;
				temp[j]/= 10;
			}
		}
		n_digits = c;
		for(j = 1; j <= n_digits; ++j){
			if(digits[j] >= 10){
				if(j == n_digits)
					++n_digits;
				digits[j+1] += digits[j]/10;
				digits[j] %= 10;
			}
			digitcount[i][digits[j]]++;
		}
	}
	while(cin >> n){
		if(!n)
			break;

		printf("%d! --\n", n);
		printf("   (0)%5d", digitcount[n][0]);
		for(i = 1; i < 5; ++i){
			printf("    (%d)%5d", i, digitcount[n][i]);
		}

		printf("\n   (5)%5d", digitcount[n][5]);
		for(i = 6; i < 10; ++i){
			printf("    (%d)%5d", i, digitcount[n][i]);
		}
		printf("\n");
	}
}