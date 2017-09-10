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

vector <int> factors;
unordered_map <int, int> mymap;

void doit(int multi, int step, int index){

	if(multi != 1){
		mymap.insert(MP(multi, step));
	}
	if(index == factors.size())
		return ;
	doit(multi*factors[index], step+1, index+1);
	doit(multi, step, index+1);
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int n, i, t;
	while(cin >> n){
		if(!n)
			break;
		if(n == 1){
			cout << 1 << "\n";
			continue;
		}
		t = n;
		factors.clear();
		mymap.clear();
		for(i = 2; i <= sqrt(n); ++i){
			if(!(n%i)){
				while(!(n%i)){
					n /= i;
				}
				factors.pb(i);
			}
		}

		if(n != 1){
			factors.pb(n);
		}
		n = t;
		t--;
		
		doit(1, 0, 0);
		for(auto it:mymap){
			if(it.se%2){
				t = t - (n/it.fi)+1;
			}else{
				t = t + (n/it.fi)-1;
			}
			//cout << it.fi << " "<< it.se << " "<< n/it.fi-1 << "\n";
		}
		cout << t << "\n";
	}
}
		
		