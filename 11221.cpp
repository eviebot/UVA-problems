#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back

bool magic(string *x, int K)
{
    char arr[K][K], c;
    int i, j, v, top_left[2][2], bot_right[2][2], z;
    for(i = 0, v =0 ; i< K;i++)
    {
        for(j = 0; j< K;j++)
        {
            arr[i][j] = (*x)[v];
            v++;
        }
    }
    z = (K/2 + K%2);
    for(i = 0; i< z;i++)
    {
        top_left[0][0] = i; top_left[0][1] = i;top_left[1][0] = i; top_left[1][1] = i;
        bot_right[0][0] = K-1-i;;bot_right[0][1] = K-1-i;bot_right[1][0] = K-1-i;bot_right[1][1] = K-1-i;
        for(j =0; j< z-i;j++)
        {
            c = arr[top_left[0][0]][top_left[0][1]];
            //cout << c<< " "<< arr[top_left[1][0]][top_left[1][1]] << " "<< arr[bot_right[0][0]][bot_right[0][1]] <<" "<< arr[bot_right[1][0]][bot_right[1][1]] <<"\n";
            if(! (c == arr[top_left[1][0]][top_left[1][1]] && c== arr[bot_right[0][0]][bot_right[0][1]] && c== arr[bot_right[1][0]][bot_right[1][1]]) )
            {
                return false;
            }
            top_left[0][1]++; top_left[1][0] ++;
            bot_right[0][0]--;bot_right[1][1]--;
        }
    }
    return true;
}
void convert_to_lower(string *x)
{
    int len = (*x).length(), i;
    for(i = 0; i< len;i++)
    {
        (*x)[i] = tolower((*x)[i]);
    }
}
int perf_square(string *x)
{
    int len = (*x).length();
    int sq = sqrt(double(len));
    if(sq*sq == len)
        return sq;
    return 0;
}

int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);

    string f, s;
    char c;
    int i, z, n, K;
    bool flag;
    getline(cin, s);
    stringstream ss(s);
    ss >> n;
    for(z = 1; z <= n;z++)
    {
        flag = false;
        f = "";
        getline(cin, s);
        for(i = 0; i< s.length();i++)
        {
            c = s[i];
            if(! (c=='.' || c==',' || c=='!' || c=='?' || c==' ' || c=='(' || c== ')') )
                f += c;
        }
        convert_to_lower(&f);
        K = perf_square(&f);
        cout << "Case #"<< z <<":\n";
        if(K)
        {
            flag = magic(&f, K);
        }
        if(!flag || K==0)
        {
            cout <<  "No magic :(\n";
            continue;
        }
        else
        {
            cout << K <<"\n";
        }
    }
}
