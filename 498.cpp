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

	string s1, s2;

	fastIO;
	while(getline(cin , s1)){

		getline(cin, s2);
		istringstream iss(s1);
		vector <int> coeff, val;

		int t, n ;
		while(iss >> t){
			coeff.pb(t);
		}
		
		n = coeff.size()-1;

		istringstream iss2(s2);

		iss2 >> t;
		lli sum = 0, multiplier = 1;
		for(int i = n; i >= 0; --i){
			sum += (multiplier * coeff[i]);
			multiplier *= t;
		}

		cout << sum ;
		
		while(iss2 >> t){
			sum = 0; multiplier = 1;
			for(int i = n; i >= 0; --i){
				sum += (multiplier * coeff[i]);
				multiplier *= t;
			}

			cout << " "<<sum ;
		}
		cout << "\n";
	}
}