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
	unsigned long long  test, tot, i, j, temp;
	string s;
	cin >> test;

	for(int z =1 ;z <= test; ++z){
		cin >> s;
		unsigned long long  ans = 1;
		unsigned long long common[26] = {0}, maxi = 0, index;

		for(i = 0; i < s.size(); ++i){
			common[s[i]-'A']++;
		}
		tot = s.size();
		for(i = 0; i < 26; ++i){
			if(common[i] > maxi){
				maxi = common[i];
				index = i;
			}
		}
		common[index] = 0;
		for(j = maxi+1; j <= tot; ++j){
			ans *= j;
		}
		for(i = 0; i < 26; ++i){
			temp = 1;
			for(lli j=1; j <= common[i]; ++j){
				temp *= j;
			}
			ans /= temp;
		}
		cout << "Data set "<< z << ": "<< 	ans << "\n";
	}
}