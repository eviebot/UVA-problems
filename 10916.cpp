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

int year, x, bits;

bool checker(int n){
	double sum = 0;
	for(int i = 2; i <= n; ++i){
		sum += log2(i);
	}
	//cout << sum << " "<< bits<< " "<< n << "\n";
	if(sum < bits)
		return true;
	return false;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	while(cin >> year){
		if(!year)
			break;
		x = (year-1940)/10;
		bits = pow(2, x);

		int upper = 400000, lower = 2, mid;

		while(lower != upper){

			if(lower+1 == upper){
				if(checker(upper))
					++lower;
				else
					upper--;
			}
			mid = (upper+lower)/2;
			if(checker(mid)){
				lower = mid;
			}else{
				upper = mid-1;
			}
		}

		cout << lower << "\n";
	}
}