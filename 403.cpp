#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back

void C5_make_changes(vector <vector <char>> & filer, vector <string> & C2, string x, int r, int c, int index)
{
    int i, row, col = c, l;
    char ch;
    string s;
    for(i = index ; i< x.length();i++)
    {
        ch = x[i];
        if(ch==' ')
            s= C2[26];
        else
            s = C2[ch-65];
        l = s.length();
        for(row = r; row < 60 &&(row-r)<5;row++)
        {
            for(col = c;col < 60 && (col-c)<6;col++)
            {
                if( ( (row-r)*6+col-c ) >= l)
                {
                    break;
                }
                if(s[(row-r)*6 + col-c] != '.')
                    filer[row][col] = s[(row-r)*6 + col-c];
                //cout << s[(row-r)*6 + col-c];
            }
            //cout <<"\n";
        }
        c += 6;
    }
}
void C1_make_changes(vector <vector <char>> & filer, string x, int r, int c, int index)
{
    //PRAISE THE LORD
    int j;
    int l = x.length();
    for(j = c; j< 60;j++, index++)
    {
        if(index >= l)
        {
            break;
        }
        if(x[index]!=' ')
            filer[r][j] = x[index];
    }
}
int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);
    int i, j, row, col_start, len, k, z, t;
    string cmd, font, str, s, s1, s2;
    char c;
    vector <vector <char>> out;
    vector <char> temp;
    for(i = 0; i< 60;i++)
        temp.pb('.');
    vector <string> C5;
    C5.pb(".***..*...*.*****.*...*.*...*.");
    C5.pb("****..*...*.****..*...*.****..");
    C5.pb(".****.*...*.*.....*......****.");
    C5.pb("****..*...*.*...*.*...*.****..");
    C5.pb("*****.*.....***...*.....*****.");
    C5.pb("*****.*.....***...*.....*.....");
    C5.pb(".****.*.....*..**.*...*..***..");
    C5.pb("*...*.*...*.*****.*...*.*...*.");
    C5.pb("*****...*.....*.....*...*****.");
    C5.pb("..***....*.....*..*..*...**...");
    C5.pb("*...*.*..*..***...*..*..*...*.");
    C5.pb("*.....*.....*.....*.....*****.");
    C5.pb("*...*.**.**.*.*.*.*...*.*...*.");
    C5.pb("*...*.**..*.*.*.*.*..**.*...*.");
    C5.pb(".***..*...*.*...*.*...*..***..");
    C5.pb("****..*...*.****..*.....*.....");
    C5.pb(".***..*...*.*...*.*..**..****.");
    C5.pb("****..*...*.****..*..*..*...*.");
    C5.pb(".****.*......***......*.****..");
    C5.pb("*****.*.*.*...*.....*....***..");
    C5.pb("*...*.*...*.*...*.*...*..***..");
    C5.pb("*...*.*...*..*.*...*.*....*...");
    C5.pb("*...*.*...*.*.*.*.**.**.*...*.");
    C5.pb("*...*..*.*....*....*.*..*...*.");
    C5.pb("*...*..*.*....*.....*.....*...");
    C5.pb("*****....*....*....*....*****.");
    C5.pb("..............................");
    for(i = 0; i< 60;i++)
    {
        out.pb(temp);
    }

    while(cin >> cmd)
    {
        if(cmd==".EOP")
        {
            for(i = 0; i< 60;i++)
            {
                for(j = 0; j< 60;j++)
                    cout <<out[i][j];
                cout <<"\n";
            }
            cout <<"\n";
            for(i = 0; i< 60;i++)
            {
                cout <<"-";
            }
            cout <<"\n\n";
            out.clear();
            for(i = 0; i< 60;i++)
            {
                out.pb(temp);
            }
            continue;
        }
        str= "";
        cin >> font;
        cin >> row;
        row --;
        if(cmd == ".P")
            cin>> col_start;
        col_start--;
        cin >> c;
        while(true)
        {
            c = cin.get();
            if(c=='|')
                break;
            str += c;
        }
        if(cmd==".C")
        {
            len = str.length()/2;
            if(str.length()%2==0)
            {
                if(font=="C5")
                {
                    if(str.length() <=10)
                    {
                        C5_make_changes(out, C5, str, row, (5-len)*6 , 0);
                    }
                    else
                    {
                        C5_make_changes(out, C5, str, row, 0, len-5);
                    }
                }
                else
                {
                    if(str.length() <=60)
                    {
                        C1_make_changes(out, str, row, (30-len), 0);
                    }
                    else
                    {
                        C1_make_changes(out, str, row, 0, len-30);
                    }
                }
            }
            else
            {
                if(font=="C5")
                {
                    if(str.length()<= 9)
                    {
                        C5_make_changes(out, C5, str, row, 27-len*6, 0);
                    }
                    else
                    {
                        C5_make_changes(out, C5, str, row, 3, len-4);
                        c = str[len-5];
                        if(c==' ')
                            s= C5[26];
                        else
                            s = C5[c-65];
                        for(k = row; k < 60 && (k-row)<6; k++)
                        {
                            for(z = 0; z <=2;z++)
                            {
                                t = (k-row)*6+z+3;
                                if( t >= s.length() )
                                {
                                    break;
                                }
                                if(s[t]!='.')
                                    out[k][z] = s[t];
                            }
                        }
                    }
                }
                else
                {
                    if(str.length() < 60)
                    {
                        C1_make_changes(out, str, row, 30-len, 0);
                    }
                    else
                    {
                        C1_make_changes(out, str, row, 0, len-31);
                    }
                }
            }
        }
        else if(cmd==".L")
        {
            if(font == "C5")
            {
                C5_make_changes(out, C5, str, row, 0, 0);
            }
            else
            {
                C1_make_changes(out, str, row, 0, 0);
            }
        }
        else if(cmd ==".R")
        {
            if(font =="C5")
            {
                if(str.length() <=10)
                {
                    C5_make_changes(out, C5, str, row, (10-str.length())*6, 0);
                }
                else
                {
                    C5_make_changes(out, C5, str, row, 0, str.length()-10);
                }
            }
            else
            {
                if(str.length() <= 60)
                {
                    C1_make_changes(out, str, row, 60-str.length(), 0);
                }
                else
                {
                    C1_make_changes(out, str, row, 0, str.length()-60);
                }
            }
        }
        else if(cmd ==".P")
        {
            if(font=="C5")
            {
                C5_make_changes(out, C5, str, row, col_start, 0);
            }
            else
            {
                C1_make_changes(out, str, row, col_start, 0);
            }
        }
    }
}
