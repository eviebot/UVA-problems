#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

typedef long long int lli;

int p, q, r, s, t, u;

double find_it(double low, double up)
{
    if( up <= low)
    {
        return -1;
    }
    double mid = (low+up)/2;
    double val;
    val = ((p * exp(-mid)) +  ( q * sin(mid)) + (r * cos(mid)) + (s * tan(mid)) + (t * mid * mid) + u) ;
    //cout << mid <<" " << val <<"\n";

    if( abs(val) < 1e-12)
        return mid;
    else if( val > 0)
    {
        return find_it( mid, up);
    }
    else
    {
        return find_it(low, mid);
    }
}
int main()
{
    ofstream outfile;
    outfile.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    double x;
    while ( scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6)
    {
        if( !p && !q && !r && !s && !t)
        {
            if(u)
                printf("No solution\n");
            else
                printf("0.0000\n");
            continue;
        }
        x = find_it(0.0, 1.0);
        if( x == -1)
            printf( "No solution\n");
        else
        {
            printf("%.4f\n", x);
            if(x == .3238)
            {
                cout << p << " " << q << " " << r << " " << s << " " << t << " " << u << "\n";
            }
        }
    }
}
