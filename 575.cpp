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

	string s;

	while(cin >> s){
		if(s == "0")
			break;

		int i = s.size()-1, multi = 1, n = 0;
		
		while(i >= 0){
			n += multi * (s[i]-'0');
			multi = (multi*2)+1;
			--i;
		}
		cout << n << "\n";
	}
}