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
	int a, b, v, ac, s;
	double PI = 2 * acos(0.0);

	while(cin >> a >> b >> v >> ac >> s){
		if(!a)
			break;
		double acc = (double)(v)/s;

		double angle = (double)(PI)*ac/180;

		double vvert = v* sin(angle), vhori = v * cos(angle), avert = acc * sin(angle), ahori = acc * cos(angle);

		double svert = vvert * s - (.5)*avert*s*s, shori = vhori * s - (.5)*ahori*s*s;

		double aa = (double)(a), bb = (double)(b);

		
		if(shori < aa/2)
			cout << "0 ";
		else{
			cout << 1+(int)((shori-aa/2)/aa) << " ";
		}
		if(svert < bb/2)
			cout << "0\n";
		else{
			cout << 1+(int)((svert-bb/2)/bb) << "\n";
		}	
	}
}