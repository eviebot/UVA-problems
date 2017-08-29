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
	int n, i, t;

	while(cin >> n){
		if(!n)
			break;

		deque <int> d;
		int sum = 1;
		while(n != 1){
			d.push_front(n%2);
			sum += (n%2);
			n /= 2;
		}
		d.push_front(1);

		cout << "The parity of ";
		for(int i = 0; i < d.size(); ++i)
			cout << d[i] ;
		cout << " is "<< sum << " (mod 2).\n";
	}
}