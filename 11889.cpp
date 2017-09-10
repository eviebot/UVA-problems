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

unordered_map <int, int> A, C;
#define mod 1000000007
lli fastexp(lli x, lli y){		// find (x^y)%mod
	lli res = 1;
	x = x;
	while(y){
		if(y&1) 
			res = (res*x);
		y = y>>1;
		x = (x*x);
	}
	return res;
}

void mapper(int x, bool flag){

	for(int i = 2; i <= x; ++i){
		int c = 0;
		while(!(x%i)){
			c++;
			x /= i;
		}
		if(c){
			if(flag)
				A.insert(MP(i, c));
			else
				C.insert(MP(i, c));
		}
	}
	if(x != 1){
		if(flag)
			A.insert(MP(x, 1));
		else
			C.insert(MP(x, 1));
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int test, n, i, a, c;
	cin >> test;
	for(int z =0 ; z < test; ++z){
		
		int b = 1;
		cin >> a >> c;
		A.clear();
		C.clear();
		mapper(a, 1);
		mapper(c, 0);

		bool flag = true;
		unordered_map <int, int>::iterator iter;
		for(iter = A.begin(); iter != A.end(); ++iter){
			if( iter->se > C[iter->fi] )
				flag = false;
			else if(iter->se < C[iter->fi]){
				b *= fastexp(iter->fi, C[iter->fi]);
				//cout << iter->fi << " "<< C[iter->fi] - iter->se << "\n";
			}
		}
		if(flag){
			for(iter = C.begin(); iter!= C.end(); ++iter){
				if(!A[iter->fi])
					b *= fastexp(iter->fi, iter->se);
			}
		}
		if(flag)
			cout << b << "\n";
		else
			cout << "NO SOLUTION\n";
	}
}