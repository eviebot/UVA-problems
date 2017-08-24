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

	int n, i, sum;

	printf("PERFECTION OUTPUT\n");
	while(cin>> n){
		sum = 0;
		if(!n)
			break;

		for(i = 1; i <= (n/2); ++i){
			if(!(n%i))
				sum += i;
		}
		printf("%5d  ",n);
		if(sum == n){
			printf("PERFECT\n");
		}
		else if(sum < n){
			printf("DEFICIENT\n");
		}
		else{
			printf("ABUNDANT\n");
		}
	}
	printf("END OF OUTPUT\n");
}