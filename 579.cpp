
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    double hours, minutes,degrees;
    while(true)
    {
        cin >> s;
        if(s=="0:00")
            break;
        hours = double(atof(s.substr(0, s.find(':')).c_str()));
        minutes = double(atof(s.substr(s.find(':')+1, 2).c_str()));
        minutes /= 5;
        hours += (minutes/12.0);
        //cout << hours << " "<< minutes<<"\n";
        degrees = (max(hours, minutes)-min(hours, minutes))*30;
        degrees = round(degrees*1000)/1000.0;
        if(degrees >= 180)
            degrees = 360.0 - degrees;
        cout << fixed;
        cout << setprecision(3);
        cout << setprecision(3) <<degrees<<endl;
    }
}
