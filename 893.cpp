
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back


bool leap(long long int x)
{
    if(x%4==0)
    {
        if(x%100==0 && !(x%400==0))
            return false;
        return true;
    }
    return false;
}
int main()
{
    //ofstream file;
    //file.open("out.txt");

    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int N, day, month , year;
    bool flag_leap=false, flag= true, flag_366;
    long long int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(true)
    {   flag = true;
        cin >> N >> day >> month>> year;
        if(N==0 && day==0 && month == 0 && year ==0)
        {
            break;
        }
        year= year +(N/146097)*400;
        N = N % 146097;
        //file << N << "\n";
        while(true)
        {flag_366 = false;
            if(leap(year) && month<= 2 && day <= 28)
            {
                N-=366;
                flag_366= true;
            }
            else if(leap(year+1) && (month >=3))
            {
                N-=366;
                flag_366= true;
            }
            else
            {
                N-= 365;
            }
            if(N < 0)
            {
                N += (365+flag_366);
                break;
            }

            year++;
        }

        if(leap(year))
        {
                months[2] = 29;
                flag_leap = true;
        }
        else
        {
                months[2] = 28;
                flag_leap = false;
        }
        if((day+N) <= months[month])
        {
                cout << day+N << " "<< month << " "<< year<<"\n";
                flag = false;
        }
        N -= (months[month]-day);
        //cout << N << "\n";
        while(flag)
        {
            month ++;

            if(month == 13)
            {
            month = 1;year++;
            if(leap(year))
            {
                months[2] = 29;
                flag_leap = true;
            }
            else
            {
                months[2] = 28;
                flag_leap = false;
            }}

            if(N <= months[month])
            {
                if(N==0)
                {
                    month --;
                    break;
                }
                day = N;
                break;
            }
            N -= months[month];
        }
        if(flag){
        //file << day << " "<< month <<" " << year << "\n";
        cout << day << " "<< month <<" " << year << "\n";}
    }
}

