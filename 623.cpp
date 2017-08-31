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

	int digits[3000], temp[3000], n_digits = 1, i, t, n, j;
	vector <string> myvec;
	for(i = 0; i <= 1010; ++i)
		myvec.pb("");
	myvec[0] = "1";
	myvec[1] = "1";
	memset(digits, 0, 3000);
	memset(temp, 0, 3000);
	
	digits[1] = 1;

	for(i = 2; i < 1010; ++i){
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
		}
		for(j = n_digits; j >= 1; --j){
			myvec[i] += (digits[j]+'0');
		}
	}
	while(cin >> n){
	
		cout << n << "!\n";
		cout << myvec[n] << "\n";
	}
}