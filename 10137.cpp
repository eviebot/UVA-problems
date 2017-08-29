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

	fastIO;
	cout << fixed << setprecision(2);
	lli n, t, avg, sum;
	double d;
	lli arr[2000];

	while(cin >> n){
		if(!n)
			break;
		sum = 0;
		for(int i = 0; i < n; ++i){
			cin >> d;
			arr[i] = (int)(d*100);
			sum += arr[i];
		}
		
		avg = sum/n;

		lli tot1 = 0, tot2 = 0, tot;
		
		for(int i = 0; i < n; ++i){
			if( arr[i] < avg )
				tot1 += (avg- arr[i]);
			else
				tot2 += ( arr[i] - avg );
		}
		tot = min(tot2, tot1);
		cout << "$"<< tot/100 <<"."<< (tot%100 < 10?"0":"") << tot%100<<  "\n";
	}
}