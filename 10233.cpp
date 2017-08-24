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
	cout << fixed << setprecision(3);
	lli n, m, t;
	double dist = sqrt(3)/6.0, dist2 = sqrt(3)/2.0;
	while(cin >> n >> m){
		++n;++m;
		t = sqrt(n);
		lli lvl1, lvl2;

		if(t * t == n)
			lvl1 = t-1;
		else
			lvl1 = t;

		t = sqrt(m);
		if(t*t == m)
			lvl2 = t-1;
		else
			lvl2 = t;

		lli diff1 = n - lvl1*lvl1, diff2 = m - lvl2 * lvl2;

		double hori, hori1, hori2,  vert;
		hori1 = diff1 - lvl1-1, hori2 = diff2 - lvl2-1;
		hori = (double)(abs(hori2-hori1)) * .5;

		if( ( diff1%2 && diff2%2 ) || ( !(diff1%2) && !(diff2%2) ) ){
			vert = abs(lvl2-lvl1) * dist2;
		}
		else{
			if(lvl2 < lvl1){
				t = diff2;
				diff2 = diff1;
				diff1 = t;
			}

			if( !(diff1%2) ){
				vert = abs(lvl2-lvl1)*dist2 + dist;
			}
			else{
				vert = abs(lvl2-lvl1)*dist2 - dist;
			}
		}
		//cout << hori << " "<< vert << " ";
		cout << sqrt(hori*hori + vert*vert) << "\n";
	}
}