#include <iostream>
using namespace std;

int main()
{
    int k, x, y, x_ , y_;
    do
    {
        cin >> k;
        if(k == 0){break;}
        cin >> x >> y;
        for (int i = 0; i< k; i++)
        {
            cin >> x_ >> y_ ;
            if (x_ == x || y_ == y){
                cout << "divisa" ;
            }
            else if (x_ > x ){
                if (y_ > y){
                    cout << "NE" ;
                }
                else{
                    cout << "SE" ;
                }

            }
            else
            {
                if(y_ > y){
                    cout << "NO" ;
                }
                else{
                    cout << "SO" ;
                }
            }
            cout << endl;
        }
    }while(k!=0);
}
