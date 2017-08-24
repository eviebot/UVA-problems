#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	lli n, t, d1, d2, x, y;
	while(cin >> n){
		if(!n)
			break;

		t = sqrt(n);
		if(n == t*t){
			if(t%2){
				x = t;
				y = 1;
			}
			else{
				y = t;
				x = 1;
			}
		}
		else{

			d1 = n-t*t;
			d2 = t+1;
			//cout << d1 << " "<< d2 << "\n";
			if(t%2){
				if(d1 <= d2){
					x = t+1;
					y = d1;
				}else{
					y = t+1;
					x = d2*d2-n+1;
				}
			}
			else{
				if(d1 <= d2){
					y = t+1;
					x = d1;
				}else{
					x = t+1;
					y = d2*d2-n+1;
				}
			}
		}
		cout <<y << " "<< x << "\n";
	}
}