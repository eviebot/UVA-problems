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

	int n, ppl, i;
	while(cin >> n){
		if(n== -1)
			break;

		int upper = sqrt(n)+1, t;

		for(ppl = upper; ppl >= 2; --ppl){
			t = n;
			bool flag =true;
			for(i = 1; i <= ppl && flag; ++i){
				//cout << ppl << " "<< t << "\n";
				--t;
				if( t%ppl)
					flag = false;
				t = (t/ppl)*(ppl-1);
			}
			if(t%ppl || !flag)
				continue;
			cout << n << " coconuts, "<< ppl << " people and 1 monkey\n";
			break;
		}
		if(ppl == 1)
			cout << n << " coconuts, no solution\n";
	}
}