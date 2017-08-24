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
	int coords[200001][2], adder[6][2] = {{-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0, 1}};

	coords[1][0] = 0;
	coords[1][1] = 0;


	int m = 1, c = 2, x = 0, y = 0, i, j;

	while(c < 100001){
		x++;
		for(i = 0; i < 6; ++i){
			for(j = 0; j < m; ++j){
				x += adder[i][0];
				y += adder[i][1];
				coords[c][0] = x;
				coords[c][1] = y;
				++c;
			}
		}
		++m;
		//cout << c << " "<< m << "\n";
	}
	int n;
	while(cin >> n){
		cout << coords[n][0] << " "<< coords[n][1] << "\n";
	}
}