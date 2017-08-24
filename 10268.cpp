#include <bits/stdc++.h>
using namespace std;

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

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");
	fastIO;
	lli x, t, i;
	string s1, s2;

	while(getline(cin, s1)){
		getline(cin , s2);

		istringstream iss1(s1);
		istringstream iss2(s2);

		iss1 >> x;
		vector <lli> coeff;

		while(iss2 >> t){
			coeff.pb(t);
		}

		lli n = coeff.size()-2, sum =0, multiplier = 1;
		for(lli i = n, c =1; i >= 0; --i, c++){

			//cout << c << " "<< multiplier << " "<< coeff[i] << " ";
			sum += (multiplier * coeff[i] * c);
			multiplier *= x;
		}

		cout << sum << "\n";
	}
}