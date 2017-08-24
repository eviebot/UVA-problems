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

set <lli> mylist;
lli maxn = 2000000000;

void make(lli base, lli multi){
	for(int i = 1; i <= 50; ++i){
		
		if(base > maxn)
			return;
		mylist.insert(base);
		if(multi == 2){
			make(base, 3);
		}
		else if(multi == 3){
			make(base, 5);
		}
		else if(multi == 5){
			make(base, 7);
		}
		base *= multi;
	}
}

string checker(int n){
	int t = n%10, v = n%100;
	if(v > 10 && v < 20){
			return "th";
	}
	if(t == 1){
		return "st";
	}
	else if(t == 2){
		return "nd";
	}
	else if(t == 3){
		return "rd";
	}
	return "th";
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	mylist.insert(1);
	make(1, 2);

	set <lli>::iterator iter;
	vector <lli> newvec;

	newvec.pb(0);
	for(iter = mylist.begin(); iter != mylist.end(); ++iter){
		newvec.pb(*iter);
	}
	int n;
	while(cin >> n){
		if(!n)
			break;

		string suffix;
		suffix = checker(n);

		cout << "The "<< n << suffix << " humble number is "<< newvec[n] << ".\n";
	}

}