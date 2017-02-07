#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front

int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long int SZ, P, sqroot, m_sq, row, col, t;

    while(true)
    {
        cin >> SZ >> P;
        row = 0;
        col = 0;
        if(SZ==0)
            break;
        sqroot = sqrt(P);
        t = (sqroot+1)/2;
        if(sqroot%2==0)
            sqroot--;
        m_sq = sqroot*sqroot;
        if(m_sq == P)
        {
            row = (sqroot-1)/2;
            col = (sqroot-1)/2;
        }
        else{
        if(P >= m_sq+1 && P <= m_sq + sqroot +1)
        {
            row = t;
            col = (m_sq + t - P);
        }
        else if(P >= m_sq + sqroot +2 && P <= m_sq + 2*(sqroot+1))
        {
            col = -(t);
            row = (m_sq + t + sqroot +1 - P);
        }
        else if(P >= m_sq + 2*(sqroot+1)+1 && P <= m_sq + 3*(sqroot+1))
        {

            row = -t;
            col = -(m_sq + t + 2*(sqroot+1) - P);
        }
        else if(P >= m_sq + 3*(sqroot+1)+1 && P <= m_sq + 4*(sqroot+1))
        {
            col = t;
            row = -(m_sq + t + 3*(sqroot+1) - P);
        }}
        row += (SZ+1)/2;
        col += (SZ+1)/2;
        cout << "Line = "<< row<< ", column = "<< col <<".\n";
    }
}
