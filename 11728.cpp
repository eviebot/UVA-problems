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
vector <pair <int, int>> factors;
unordered_set <int> myset;
void doit(int multi, int index){

	myset.insert(multi);
	if(index == factors.size())
		return;

	for(int i = 0; i <= factors[index].se; ++i){
		doit(multi, index+1);
		multi *= factors[index].fi;
	}
}
int finder(int x){
	if(x == 1)
		return 1;
	myset.clear();
	factors.clear();
	int sum = 0, val = sqrt(x);
	
	for(int i = 2; i <= val; ++i){
		if(!(x%i)){
			int c =0;
			while(!(x%i)){
				c++;
				x /= i;
			}
			factors.pb(MP(i, c));
		}
	}
	if(x != 1){
		factors.pb(MP(x, 1));
	}

	doit(1, 0);
	for(auto it:myset){
		sum += it;
	}
	if(sum > 1000)
		return 0;
	return sum;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int arr[1001] ;
	for(int i =1 ; i <= 1000; ++i)
		arr[i] = -1;

	for(int i = 1; i <= 1000; ++i){
		int t = finder(i);
		arr[t] = i;
	}

	int n, z = 1;
	while(cin >> n){
		if(!n)
			break;
		cout <<"Case "<< z++ << ": "<< arr[n] << "\n";
	}
}