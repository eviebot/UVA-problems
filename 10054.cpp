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
	int T, n, u, v, i, j, color, prev;
	bool colorflags[100];

	infile >> T;
	for(int z = 1; z <= T; ++z){
		infile >> n;
		int graph[n+1][4];
		vector <int> scolor;

		for(i = 1; i <= 50; ++i)
			colorflags[i] = 0;

		for(i = 1; i <= n; ++i){
			infile >> u >> v;

			if(u == v){
				scolor.pb(u);
				--i;
				--n;
			}
			else{
			colorflags[u] = 1;
			colorflags[v] = 1;
			graph[i][0] = u;
			graph[i][1] = v;
			graph[i][2] = 0;
			graph[i][3] = 0;}
		}
		
		bool flag = true;
		if(!n){
			for(i = 1; i < scolor.size(); ++i){
				if(scolor[i] != scolor[0])
					flag = false;
			}
		}
		else{
			flag = true;
			prev = 1;
			graph[1][3] = 1;
			for(i = 2; i <= n && flag; ++i){

				if(graph[prev][3] == 1){
					color = graph[prev][1];
				}
				else if(graph[prev][3] == 2) {
					color = graph[prev][0];
				}
				cout << i << " "<< prev << " "<< color << "\n";

				int sum = 0;
				for(j = 1; j <= n; ++j){
					
					if(graph[j][3])
						++sum;
				}
				cout << sum << " out of "<< n <<" are part of necklace.\n";


				bool temp_flag = false;
				//cout << prev <<  " "<< color << "\n";	
				for(j = 2; j <= n; ++j){

					if(!graph[j][3]){
						if(i == 53)
							cout << "element "<< j << "\n";
						if(graph[j][0] == color){
							graph[prev][2] = j;
							prev = j;
							graph[j][3] = 1;
							temp_flag = true;
							break;
						}
						else if(graph[j][1] == color){
							graph[prev][2] = j;
							prev = j;
							graph[j][3] = 2;
							temp_flag = true;
							break;
						}
					}
				}
				flag = temp_flag;
			}
		}
		if(flag){
			if(graph[prev][3] == 1){
				if(graph[prev][1] != graph[1][0])
					flag = false;
			}
			else if(graph[prev][3] == 2) {
				if(graph[prev][0] != graph[1][0])
					flag = false;
			}

			for(i = 0; i < scolor.size(); ++i){
				if(!colorflags[scolor[i]])
				{
					flag = false;
					break;
				}
			}
		}
		cout << "Case #"<< z << "\n";
		if(flag){
			prev = 1;
			for(i = 1; i <= n; ++i){
				if(graph[prev][3] == 1){
					cout << graph[prev][0] << " "<< graph[prev][1] << "\n";
				}
				else{
					cout << graph[prev][1] << " "<< graph[prev][0] << "\n";
				}
				prev = graph[prev][2];
			}
			cout << "\n";
		}
		else{
			cout << "some beads may be lost\n\n";
		}
	}
	return 0;
}