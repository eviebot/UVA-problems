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
	lli n, i, last, t;

	fastIO;
	while(cin >> n){
		if(!n)
			break;
		t = n;
		int c = 0;
		for(i = 2; i <= sqrt(n); ++i){
			if(!(n%i)){
				c++;
			while(!(n%i)){
				n/=i;
				last = i;
			}}
		}
		if(n == t){
			cout << "-1\n";
		}else{
			if(n != 1){
				c++;
				last = n;
			}
			if(c < 2){
				cout << "-1\n";
			}else{
			cout << last << "\n";}
		}
	}
}