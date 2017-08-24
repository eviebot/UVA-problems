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

	fastIO;
	int n, t, i, data[10002], ans;

	for(i = 0; i <= 10000; ++i){
		data[i] = (i*(i+1))/2;
	}

	while(cin >> n){
		int upper = 10000, lower = 0, mid;
		while(upper != lower){

			mid = (lower+upper)/2;
			//cout << lower << " "<< upper << " "<< data[mid] << "\n";
			
			if(n <= data[mid])
				upper = mid;
			else
				lower = mid+1;
		}
		ans = upper;
		int tot = upper+1, num;

		cout << "TERM "<< n << " IS ";
		if(upper%2){
			num = tot-(n-data[upper-1]);
			cout << num << "/"<< tot-num << "\n";
		}
		else{
			num = n-data[upper-1];
			cout << num << "/"<< tot-num << "\n";
		}
	}
}