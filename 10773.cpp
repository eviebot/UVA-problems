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

	int T, d, u, v;

	fastIO;
	cout << fixed << setprecision(3);
	cin >> T;
	for(int z = 1; z <= T; ++z){
		cin >> d >> v >> u;
		cout << "Case "<< z << ": ";
		if(u <= v || !v){
			cout << "can't determine\n";
		}
		else{
			double t1 = (double)(d)/u, t2;

			double k = sqrt(double(u)*u-(double)(v)*v);
			t2 = d/k;

			cout << t2-t1 << "\n";
		}
	}
}