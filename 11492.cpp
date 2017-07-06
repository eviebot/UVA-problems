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

int M, n_lang;
string lang1, lang2, word, src, dest;
unordered_map <string , int> matcher;
vector <string> myvec;
vector <vector <pair <int, string>>> graph;
vector <pair <int, string>> temp;
vector <bool> visited;
vector <pair <int, char>> dist;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int i, j, t;
	while(infile >> M)
	{
	    if( !M)
            break;
		matcher.clear();
		graph.clear();
		myvec.clear();
		dist.clear();
		visited.clear();

		myvec.pb("");
		for(i = 0; i <3; ++i){
		visited.pb(0);
		dist.pb(0);
		graph.pb(temp);}

		infile >> lang1 >> lang2;
		src = lang1;dest = lang2;

		myvec.pb(lang1);
		myvec.pb(lang2);
		matcher.insert(MP(lang1, 1));
		matcher.insert(MP(lang2, 2));

		n_lang = 2;

		for(i =0; i < M; ++i)
		{
			infile >> lang1 >> lang2 >> word;
			if( matcher.find(lang1) == matcher.end() )
			{
				++n_lang;
				myvec.pb(lang1);
				matcher.insert(MP(lang1, n_lang));
				graph.pb(temp);
				visited.pb(0);
				dist.pb(0);
			}
			if( matcher.find(lang2) == matcher.end() )
			{
				++n_lang;
				myvec.pb(lang2);
				matcher.insert(MP(lang2, n_lang));
				graph.pb(temp);
				visited.pb(0);
				dist.pb(0);
			}
			graph[matcher[lang1]].pb(MP(matcher[lang2], word));
			graph[matcher[lang2]].pb(MP(matcher[lang1], word));

		}
		recent = matcher[src];

	}
}
