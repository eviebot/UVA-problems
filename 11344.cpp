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

bool checker(string s, int d){
	int multi= 0, i;
	for(i = 0; i < s.size(); ++i){
		multi = (multi*10+s[i]-'0')%d;
	}
	if(multi%d)
		return false;
	return true;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	string s;
	int test, i, t, n;
	cin >> test;
	for(int z =0; z < test; ++z){
		cin >> s >> n;
		bool flag = true;
		for(i = 1; i <= n; ++i){
			cin >> t;
			if(flag){
				if(!checker(s, t)){
					cout << s << " - Simple.\n";
					flag = false;
				}
			}
		}
		if(flag){
			cout << s << " - Wonderful.\n";
		}
	}
}