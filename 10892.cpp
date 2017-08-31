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

map <int, int> factors;
map <int, int>::iterator iter;
vector <pair <int, int>> myvec;
unordered_set <int> all_factors;
set <pair <int, int>> pairs;
int sum, n;
void adder(int index, int multi){
	all_factors.insert(multi);
	if(index == myvec.size())
		return;
	for(int i = 0; i <= myvec[index].se; ++i){
		adder(index+1, multi);
		multi *= myvec[index].fi;
	}

}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int i, temp;
	while(cin >> n){
		if(!n)
			break;

		factors.clear();
		myvec.clear();
		all_factors.clear();
		pairs.clear();
		if(n == 1){
			cout << "1 1\n";
			continue;
		}

		temp = n;
		sum = 1;
		for(i= 2; i <= sqrt(n)+1; ++i){
			while( !(temp%i) ){
				temp /= i;
				factors[i]++;
			}
		}
		if(temp != 1){
			factors[temp]++;
		}
		for(iter = factors.begin(); iter!= factors.end(); ++iter){
			//cout << iter->fi << " "<< iter->se << "\n";
			myvec.pb(MP(iter->fi, iter->se));
		}

		adder(0, 1);
		int lcm;
		for(auto it1: all_factors){
			for(auto it2: all_factors){
				lcm = (it1/__gcd(it1, it2))*it2;
				if(lcm == n){
					pairs.insert(MP(min(it1, it2), max(it1, it2)));
				}
			}
		}
		cout << n << " "<< pairs.size() << "\n";
	}
}