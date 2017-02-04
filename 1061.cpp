#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front

int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);

    map <string, string> mymap;
    map <string, string>::iterator iter;
    map <string, string>::iterator iter1;
    mymap.insert(make_pair("AA", "A"));
    mymap.insert(make_pair("AB", "AB"));
    mymap.insert(make_pair("AO", "A"));
    mymap.insert(make_pair("BB", "B"));
    mymap.insert(make_pair("BO", "B"));
    mymap.insert(make_pair("OO", "O"));
    map <string, string>::iterator itend ;
    set <string> myset;
    set <string>::iterator iterate;
    set <string>::iterator iterate_end;
    vector <string> myvec;
    string s[3], str1, str2, str;
    int i , j, counter=1, index;
    bool neg_flag, flag;
    char c1;
    while(true)
    {
        myset.clear();
        myvec.clear();
        str= "";
        cin >> s[0] >> s[1] >> s[2];

        if(s[0]=="E")
            break;

        else if(s[2] == "?")
        {
            neg_flag = false;
            str = "";
            for(i =0; i< 2; i++)
            {
                if((s[i])[0] == 'A' && (s[i])[1] =='B')
                {
                    myvec.pb("AB");
                }
                else if((s[i])[0] == 'B')
                {
                    myvec.pb("BO");
                }
                else if((s[i])[0] == 'O')
                {
                    myvec.pb("OO");
                }
                else
                {
                    myvec.pb("AO");
                }
            }
            str1 = myvec[0];
            str2 = myvec[1];
            for(i = 0; i< 2;i++)
            {
                for(j = 0; j< 2;j++)
                {
                    str ="";
                    str += str1[i];
                    str += str2[j];
                    sort(str.begin(), str.end());
                    iter = mymap.find(str);
                    myset.insert(iter->second);

                }
            }
            iterate_end= myset.end();
            advance(iterate_end,-1);
            if(s[0].find('-')!=string::npos && s[1].find('-')!= string::npos)
            {
                neg_flag=true;
            }
            iterate= myset.begin();
            s[2] = "{";
            for(; iterate != iterate_end ;iterate++)
            {
                if(!neg_flag)
                {
                    s[2] += *iterate+"+, "+ *iterate+"-, ";
                }
                else
                {
                    s[2] += *iterate + "-, ";
                }
            }
            if(!neg_flag)
            {
                s[2] += *iterate+"+, "+ *iterate+"-}";
            }
            else
            {
                s[2] += *iterate + "-}";
            }
            if(s[2].length()==4)
                s[2] = s[2].substr(1, 2);
        }
        else
        {
            neg_flag = false;
            if(s[0]=="?"){
                index = 0;s[0]="";}
            else{
                index = 1;s[1]="";}
            c1 = (s[2])[s[2].length()-1];
            s[2] = s[2].substr(0, s[2].length()-1);
            if((s[1-index])[0] == 'A' && (s[1-index])[1] =='B')
            {
                str2 = "AB";
            }
            else if((s[1-index])[0] == 'B')
            {
                str2 = "BO";
            }
            else if((s[1-index])[0] == 'O')
            {
                str2 = "OO";
            }
            else
            {
                str2= "AO";
            }
            iter = mymap.begin();
            itend = mymap.end();
            for(; iter!= itend; iter++)
            {
                str1 = iter->first;
                flag = true;
                for(i =0; i< 2 && flag;i++)
                {
                    for(j = 0; j< 2;j++)
                    {
                        str = "";
                        str += str1[i];
                        str += str2[j];
                        sort(str.begin(), str.end());
                        iter1 = mymap.find(str);
                        if(iter1->second == s[2])
                        {
                            //cout << iter->first<<" + "<< str2<<" = "<< s[2]<<"\n";
                            myset.insert(iter->second);
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if(c1=='+' && s[1-index][s[1-index].length()-1] == '-')
                neg_flag = true;
            if(myset.size()==0)
            {
                s[index] = "IMPOSSIBLE";
            }
            else
            {
                s[index] = "{";
                iterate_end = myset.end();
                advance(iterate_end, -1);
                for(iterate = myset.begin(); iterate != iterate_end; iterate++)
                {
                    if(!neg_flag)
                    {
                        s[index] += *iterate +"-, "+*iterate+"+, ";
                    }
                    else
                    {
                        s[index] += *iterate+"+, ";
                    }
                }
                iterate_end++;
                if(!neg_flag)
                    s[index] += *iterate +"-, " + *iterate+"+}";
                else
                    s[index] += *iterate + "+}";
            }
            s[2] += c1;
        }

        cout << "Case "<< counter<<": "<< s[0] << " "<< s[1] <<" "<< s[2]<<"\n";
        counter++;
    }
}
