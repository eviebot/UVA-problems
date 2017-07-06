#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

typedef long long int lli;
ofstream outfile;
ifstream infile;

ifstream ifffererere;
vector < vector <bool> > storage;
vector <bool> temp;
char type, c;
int index123, sum;
int row, columns;
bool DB (int rs, int rb, int cs, int cb)
{
    int i, j;
    bool flag1 = storage[rs][cs], flag = storage[rs][cs];
    for(i = rs; i<= rb; ++i)
    {
        for(j = cs; j<= cb; ++j)
        {
            if( storage[i][j] != flag  )
            {
                flag = !flag;
                break;
            }
        }
        if( flag1 != flag)
            return false;
    }
    return true;
}

void BITMAPD(int rows, int rowb, int cols, int colb)
{
    if( sum == row*columns)
        return;
    cin >> c;
    if( c== '\n')
        cin >> c;

    if( c != 'D')
    {
        for(int i = rows; i<= rowb; ++i)
        {
            for(int j = cols; j<= colb; ++j)
            {
                storage[i][j] = c-'0';
                ++sum;
            }
        }
    }
    else
    {
        int rowm, colm;
        rowm = (rows+rowb)/2;
        colm = (cols+colb)/2;

        if( rows == rowb)
        {
            BITMAPD(rowm, rowm, cols, colm);
            BITMAPD(rowm, rowm, colm+1, colb);
        }
        else if(cols == colb)
        {
            BITMAPD( rows, rowm, colm, colm );
            BITMAPD( rowm+1, rowb, colm, colm);
        }
        else
        {
            BITMAPD( rows, rowm, cols, colm );
            BITMAPD( rows, rowm, colm+1, colb );
            BITMAPD( rowm+1, rowb, cols, colm );
            BITMAPD( rowm+1, rowb, colm+1, colb );
        }
    }
}
void BITMAPB ( int rows, int rowb, int cols, int colb )
{
    int rowm, colm;
    rowm = (rows+rowb)/2;
    colm = (cols+colb)/2;

    if(index123 == 50)
    {
        index123 = 0;
        cout << "\n";
    }
    ++index123;
    if( rows == rowb && cols == colb )
    {
        cout << storage[rowm][colm];
    }
    else if( rows == rowb )
    {
        if( DB(rowm , rowm, cols, colb) )
        {
            cout << storage[rowm][cols];
        }
        else
        {
            cout << 'D';
            BITMAPB( rowm, rowm, cols, colm );
            BITMAPB( rowm, rowm, colm+1, colb);
        }
    }
    else if( cols == colb)
    {
        if( DB(rows , rowb, colm, colm) )
        {
            cout << storage[rows][colm];
        }
        else
        {
            cout << 'D';
            BITMAPB( rows, rowm, colm, colm );
            BITMAPB( rowm+1, rowb, colm, colm );
        }
    }
    else
    {
        if( DB( rows, rowb, cols, colb ) )
        {
            cout << storage[rows][cols];
        }
        else
        {
            cout << 'D';
            BITMAPB( rows, rowm, cols, colm );
            BITMAPB( rows, rowm, colm+1, colb );
            BITMAPB( rowm+1, rowb, cols, colm );
            BITMAPB( rowm+1, rowb, colm+1, colb );
        }
    }
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    //ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);

    int i, j;
    while( true)
    {
        cin >> type;

        if( type == '#')
            break;
        cin >> row >> columns;
        temp.clear();
        storage.clear();
        for(i = 0; i<= columns; ++i)
        {
            temp.pb(0);
        }
        storage.pb(temp);


        if(type == 'B')
        {
            for(i = 1; i<= row; ++i)
            {
                for(j = 1; j<= columns; ++j)
                {
                    cin >> c;
                    if( c== '\n')
                    {
                        cin >> c;
                    }
                    temp[j] = c-'0';
                }
                storage.pb(temp);
            }

            index123 = 0;
            cout  <<"D"<< setw(4)<< row<<setw(4)<< columns<<'\n';
            BITMAPB (1, row, 1, columns);
            cout <<'\n';
        }
        else
        {
            for(i = 1; i<= row; ++i)
                storage.pb(temp);
            index123 = 0;
            sum = 0;
            BITMAPD(1, row, 1, columns);
            cout  <<"B"<< setw(4)<< row<<setw(4)<< columns<<'\n';
            for(i = 1; i<= row; ++i)
            {
                for(j = 1; j<= columns; ++j)
                {
                    if(index123 == 50)
                    {
                        index123 = 0;
                        cout <<'\n';
                    }
                    cout << storage[i][j];
                    ++index123;
                }
            }
            cout <<'\n';
        }
    }
}
