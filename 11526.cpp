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
	lli cases, i, t, n, prev, next, sum = 0;
	cin >> cases;
	for(int z = 0; z < cases; ++z){
		sum = 0;
		cin >> n;
		i = 1;
		prev = n;
		if(n <= 0){
			cout << "0\n";
			continue;
		}
		while(true){
			next = n/(i+1);
			if(prev == next)
				break;
			sum += (i * (prev-next));
			++i;
			prev = next;
			//cout << i << " "<< prev << " "<< sum<<"\n";
			//getchar();
		}

		for(i = 1; i <= next; ++i){
			sum += (n/i);
		}

		cout << sum << "\n";
	}
}