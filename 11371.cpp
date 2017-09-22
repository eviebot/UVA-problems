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

lli n, a, b;
int c1[10], c2[10];

void finder(){
	a = 0;
	b = 0;
	int i;
	for(i = 9; i >=0; --i){
		while(c1[i]){
			a = (a*10) + i;
			c1[i]--;
		}
	}

	for(i = 1; i < 10; ++i){
		if(c2[i]){
			b = i;
			c2[i]--;
			break;
		}
	}
	for(i = 0; i < 10; ++i){
		while(c2[i]){
			b = (b*10)+i;
			c2[i]--;
		}
	}
	cout << a << " - "<< b << " = "<< a-b << " = 9 * "<< (a-b)/9 << "\n";
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");
	fastIO;
	while(cin >> n){
		memset(c1, 0, sizeof c1);
		memset(c2, 0, sizeof c2);

		while(n){
			c1[n%10]++;
			c2[n%10]++;
			n/=10;
		}

		finder();
	}
}