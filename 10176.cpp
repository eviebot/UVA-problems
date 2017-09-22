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

void answer(string s){
	int i = s.size(), multi = 0;
	for(int j = 0; j < i; ++j){
		multi = (multi*2)%(131071);
		if(s[j] == '1')
			multi++;
	}
	if(multi%131071)
		cout << "NO\n";
	else
		cout << "YES\n";
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	string s;
	char c;
	while(cin >> c){
		if(c == '\n')
			continue;
		else if(c == '#'){
			answer(s);
			s = "";
			continue;
		}
		s += c;
	}
}