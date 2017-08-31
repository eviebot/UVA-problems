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
typedef long long ll;

using namespace std;

ofstream outfile;
ifstream infile;

unsigned long long  power(lli base, lli po){
	unsigned long long  multi = 1;
	for(int j = 0; j < po; ++j){
		multi *= base;
	}
	return multi;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	string s;
	unsigned long long p, e, t;
	unsigned long long  n;
	while(getline(cin , s)){
		istringstream iss(s);
		iss >> p;
		if(!p)
			break;
		n = 1;
		iss >> e;
		n *= power(p, e);

		while(iss >> p >> e){
			n *= power(p, e);
		}
		--n;
		if(n == 1){
			cout << "1 1\n";
			continue;
		}
		priority_queue <pair <int, int>> myq;
		int tt = sqrt(n)+1;
		for(t = 2; t <= tt; ++t){
			int c = 0;
			while( !(n%t)){
				n /= t;
				++c;
			}
			if(c){
				myq.push(MP(t, c));
			}
		}
		if(n != 1){
			myq.push(MP(n, 1));
		}
		pair <int, int> pp = myq.top();
		myq.pop();
		cout << pp.fi << " "<< pp.se;
		while(!myq.empty()){
			pair <int, int> pp = myq.top();
			myq.pop();

			cout << " "<< pp.fi << " "<< pp.se;
		}
		cout << "\n";
	}
}