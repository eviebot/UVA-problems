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
	lli l, u, i, j, multiplier;
	int arr[70000], builder[1000020];
	for(i = 1; i < 70000; ++i)
		arr[i] =0;

	for(i = 2; i < 70000; ++i){
		if(!arr[i]){
			j = i;
			while(j < 70000){
				arr[j] = i;
				j += i;
			}
		}
	}

	while(cin >> l >> u){
		if(l == 1)
			++l;
		for(i = 0; i <= u-l; ++i)
			builder[i] = 0;

		for(i = 2; i < 70000; ++i){
			if(arr[i] == i){
				
				if(l%i)
					j = i - l%i;
				else
					j = 0;
				while(j <= u-l){
					builder[j] = i;
					//cout << j << " "<< i << "\n";
					j += i;
				}
			}
		}

		for(i = 0; i <= u-l; ++i){
			//cout << i << " "<< builder[i] << "\n";
			if(!builder[i]){
				j = i;
				while(j <= u-l)
				{
					builder[j] = i+l;
					//cout << j << "s"<< i << "\n";
					j += (l+i);
				}
			}
		}
		int prev = -1, mini = INT_MAX, maxi = 0, c1, c2, d1, d2;
		for(i = 0; i <= u-l; ++i){
			//cout << i << " "<< builder[i] << "\n";
			if(builder[i] == i+l )
			{
				if(prev == -1){
					prev = i;
				}else{
					if(i-prev < mini){
						mini = i-prev;
						c2 = i+l;
						c1 = prev+l;
					}
					if(i-prev > maxi){
						maxi = i-prev;
						d1 = prev+l;
						d2 = i+l;
					}
					prev =i;
				}
			}
		}
		if(mini == INT_MAX){
			cout << "There are no adjacent primes.\n";
		}
		else{
			cout << c1 << ","<< c2<<" are closest, "<< d1 << ","<< d2 << " are most distant.\n";
		}
	}
}