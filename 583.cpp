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
	int n, i, j;
	while(cin >> n){
		if(!n)
			break;
		bool negflag = false;int sum = 0;
		if(n < 0)
			negflag = true;
		map <int, int> factors;
		n = abs(n);
		int t = n;
		for(int i =2; i <= sqrt(n)+1; i++){
			int c = 0;
			while(!(n%i)){
				n /= i;
				++c;
			}
			sum += c;
			if(c){
				factors[i] = c;
			}
		}
		if(n != 1){
			++sum;
			factors[n] = 1;
		}
		//cout << sum << " ";
		if(negflag){
			cout << '-'<<t << " = -1 x ";
		}else{
			cout << t<< " = ";
		}
		j = 1;
		for(auto it:factors){
			
			for(i = 0; i < it.se; ++i){
				if(j == sum){
					cout << it.fi << "\n";
				}else{
					cout << it.fi << " x ";
				}
				++j;
			}
		}
	}
}