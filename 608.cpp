#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, i, j, k, index[3], counter;
    char c;
    cin >> n;
    string left[3], right[3], judgement[3];
    bool heavy;
    set <int> even;
    set <int> counterfeit;
    set <int>::iterator it1;
    set <int>::iterator it2;
    set <int>::iterator finder;
    for(i = 1; i<= n;i++)
    {
        even.clear();
        counterfeit.clear();
        for(j = 0; j< 3;j++)
        {
            cin >> left[j]>> right[j]>> judgement[j];
            if(judgement[j] == "even")
            {
                index[j] = 0;
                for(k = 0; k< left[j].length();k++)
                {
                    even.insert((left[j])[k]);
                    even.insert((right[j])[k]);
                }
            }
            else if(judgement[j]=="up")
            {
                index[j] = 1;
            }
            else
            {
                index[j] = 2;
            }
            if( (judgement[j]=="up" || judgement[j] == "down") && (left[j].length()*2 < counterfeit.size() || counterfeit.size()==0))
            {
                counterfeit.clear();
                for(k = 0; k < left[j].length();k++)
                {
                    counterfeit.insert((left[j])[k]);
                    counterfeit.insert((right[j])[k]);
                }
            }
            it2 = counterfeit.end();
        }
        for(it1 = counterfeit.begin();it1 != it2;)
        {
            finder = even.find((*it1));
            if(finder!=even.end())
            {
                counterfeit.erase(it1++);
            }
            else
            {
                ++it1;
            }
        }
        if(counterfeit.size()!=1)
        {
            for(j = 0; j< 3;j++)
            {
                for(k = j+1; k< 3;k++)
                {
                    if(index[j]==0 || index[k]==0){
                        continue;}
                    else
                    {
                         it1 = counterfeit.begin();
                         for(;it1!=it2;)
                         {
                             counter=0;
                             c = *it1;
                             if(left[j].find(c)!=string::npos)
                                counter++;
                             else if(right[j].find(c)!=string::npos)
                                counter++;
                             if(left[k].find(c)!=string::npos)
                                counter++;
                             else if(right[k].find(c)!=string::npos)
                                counter++;
                             if(counter==1)
                             {
                                 counterfeit.erase(it1++);
                             }
                             else
                                ++it1;
                         }
                    }
                    if(index[j] == index[k])
                    {
                        it1 = counterfeit.begin();
                        for(;it1!=it2;)
                        {
                            c = *it1;
                            if( (left[j].find(c)!= string::npos && right[k].find(c)!= string::npos) || (right[j].find(c) != string::npos && left[k].find(c)!=string::npos) )
                            {
                                counterfeit.erase(it1++);
                            }
                            else
                                ++it1;
                        }
                    }
                    else
                    {
                        it1 = counterfeit.begin();
                        for(;it1!=it2;)
                        {
                            c = *it1;
                            if( (left[j].find(c)!=string::npos && left[k].find(c)!=string::npos ) || (right[j].find(c)!=string::npos && right[k].find(c)!=string::npos) )
                            {
                                counterfeit.erase(it1++);
                            }
                            else
                            {
                                ++it1;
                            }
                        }
                    }
                }
            }
        }
        it1 = counterfeit.begin();
        c = *it1;
        for(j = 0; j< 3;j++)
        {
            if(left[j].find(c)!=string::npos)
            {
                if(judgement[j]=="up")
                    heavy = true;
                else if(judgement[j]=="down")
                    heavy = false;
            }
            else if(right[j].find(c)!=string::npos)
            {
                if(judgement[j]=="up")
                    heavy = false;
                else
                    heavy = true;
            }
        }

        cout << (char)(c)<< " is the counterfeit coin and it is " << (heavy==true?"heavy":"light")<<".\n";
    }
}
