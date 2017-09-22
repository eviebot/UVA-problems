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

int fib[1010][300];
void add(int index){
	int i;
	for(i = 1; i < 300; ++i){
		fib[index][i]= fib[index-1][i] + fib[index-2][i];
	}
	for(i= 1; i < 300; ++i){
		while(fib[index][i] >= 10){
			fib[index][i+1]++;
			fib[index][i] -= 10;
		}
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");
	fastIO;
	memset(fib, 0, sizeof fib);
	fib[0][1] = 1;
	fib[1][1] = 2;
	for(int i= 2; i <= 1000; ++i){
		add(i);
	}

	int n;
	while(cin >> n){
		bool flag = false;
		for(int i= 299; i > 0; --i){
			if(fib[n][i])
				flag = true;
			if(flag){
				cout << fib[n][i] ;
			}
		}
		cout << "\n";
	}
}