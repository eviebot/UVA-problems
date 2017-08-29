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


deque <int> make_deque(string s){
	deque <int> d;
	for(int i = 0; i < s.length(); ++i){
		if(s[i] == 'V')
			d.pb(0);
		else if(s[i] == 'U')
			d.pb(1);
		else if(s[i] == 'C')
			d.pb(2);
		else
			d.pb(3);
	}
	return d;
}

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int t, i;
	cin >> t;
	string n1, n2, fin, op;

	cout << "COWCULATIONS OUTPUT\n";

	for(int z =0; z < t; ++z){
		
		cin >> n1 >> n2;

		deque <int> num1 = make_deque(n1), num2 = make_deque(n2), dfin;
		deque <int>::iterator iter;

		for(i = 0; i < 3; ++i){
			cin >> op;

			if(op == "A"){
				int x1 = num1.size(), x2 = num2.size();
				x1--;x2--;

				while(x1 >= 0){
					num2[x2] += num1[x1];
					int temp = num2[x2]/4;
					if(temp > 0){
						num2[x2] -= temp*4;
						if(!x2){
							num2.push_front(temp);
						}else{
							num2[x2-1] += temp;
						}
					}
					x1--;x2--;
				}
			}else if(op == "L"){
				num2.push_back(0);
			}else if(op == "R"){
				iter = num2.end();
				--iter;
				num2.erase(iter);
				num2.push_front(0);
			}
		}

		int x = num2.size();
		if(x < 8){
			while(x != 8){
				num2.push_front(0);
				++x;
			}
		}else if(x > 8){
			cout << "NO\n";
			continue;
		}
		cin >> fin;

		dfin = make_deque(fin);

		bool flag = true;
		for(i = 0; i < 8; ++i){
			if( num2[i] != dfin[i] ){
				cout << "NO\n";
				flag = false;
				break;
			}
		}
		if(flag){
			cout << "YES\n";
		}
	}
	cout << "END OF OUTPUT\n";
}