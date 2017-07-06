#include <iostream>     // fuckin rekt gg tilted rekt
using namespace std;

int main()
{

    do
    {
        int months, dep_data;
        double DP, loan, car_val, month_dec;
        cin >> months >> DP >> loan >> dep_data;
        double per_dep[dep_data];
        int mno[dep_data];
        month_dec = loan / months;
        if(months < 0 ){break;}
        for(int i = 0; i < dep_data; i++)
        {
            cin >> mno[i] >> per_dep[i];
        }

        car_val = (DP + loan)* (1- per_dep[0]);

        if(loan < car_val){cout << "0 months" << endl;}
        else
        {
            int k = 1;
            for(int i = 1; i <= months; i++)
            {
                if(i == mno[k])
                {
                    ++k;
                }
                car_val *= (1- per_dep[k-1]);
                loan -= month_dec;
                if(loan < car_val)
                {
                    cout << i ;
                    if(i == 1){cout << " month"<<endl;break;}
                    else{cout << " months" << endl;break;}
                }

            }
        }
    }while(true);
}
