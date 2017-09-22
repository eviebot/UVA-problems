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

int fin[310];
int fib[20];
bool checker(){
	bool flag = false;
	int i;
	for(i = 1; i < 300; ++i){
		while(fin[i] && fin[i+1]){
			fin[i]--;
			fin[i+1]--;
			fin[i+2]++;
			flag = true;
		}
	}
	for(i = 3; i <= 300; ++i){
		while(fin[i] >= 2){
			fin[i] -= 2;
			fin[i+1]++;
			fin[i-2]++;
			flag = true;
		}
	}
	if(fin[1] >= 2){
		for(i = 10; i >= 1; --i){
			if(fin[1] >= fib[i]){
				fin[1] -= fib[i];
				fin[i]++;
				flag = true;
			}
		}
	}
	if(fin[2] >= 2){
		fin[2] *= 2;
		for(i = 10; i >= 1; --i){
			if(fin[2] >= fib[i]){
				fin[2] -= fib[i];
				fin[i]++;
				flag = true;
			}
		}
	}
	return flag;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");
	fastIO;
	int i;
	string s1, s2;
	fib[1] = 1;
	fib[2] = 2;
	for(i = 3; i <= 10; ++i){
		fib[i] = fib[i-1]+fib[i-2];
	}
	bool tflag = false;
	while(cin >> s1 >> s2){
		if(tflag)
			cout << "\n";
		else
			tflag = true;
		if(s1 == "0" && s2 == "0"){
			cout<< "0\n";
			continue;
		}
		string s = "";
		for(i = 0; i <= 300; ++i)
			fin[i] = 0;

		for(i = 0; i < s1.size(); ++i){
			if(s1[s1.size()-i-1] == '1')
				fin[i+1]++;
		}
		for(i= 0; i < s2.size(); ++i){
			if(s2[s2.size()-i-1] == '1')
				fin[i+1]++;
		}

		while(checker());
		bool flag = false;
		for(i = 300; i > 0; --i){

			if(fin[i])
				flag = true;

			if(flag){
				s += (fin[i]+'0');
			}
		}
		cout << s<< "\n";
	}
}