#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

bool search_it(set <int> myset, vector <set <int>> & vec)
{
    int l = vec.size(), i;
    set <int>::iterator iter, vect;
    set <int> T;
    for(i =0 ; i< l ; ++i)
    {
        iter = myset.begin();
        T = vec[i];
        vect = T.begin();
        if(*iter == *vect)
        {
            ++iter;
            ++vect;
            if(*iter == *vect)
            {
                ++iter;
                ++vect;
                if(*iter == *vect)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
int permute(int i, int j, int k)
{
    //cout << i <<" "<< j <<" "<< k <<"\n";
    if( i == j && j == k)
    {
        return 1;
    }
    else if( i== j || j == k || i == k)
    {
        return 3;
    }
    else
    {
        return 6;
    }
}
int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int score, combinations, permutations, i, j, k, multiplier[3], temp;

    while(true)
    {
        cin>> score;
        if(score <= 0)
        {
            cout << "END OF OUTPUT\n";
            break;
        }

        combinations = 0;
        permutations = 0;
        vector <set <int>> myvec;
        set <int> temp1;
        if(score == 180)
        {
            combinations = 1;
            permutations = 1;
        }
        else if( score < 180)
        {
            for( i = 1; i< 22; ++i)
            {
                for(multiplier[0] = 1; multiplier[0] < 4; ++multiplier[0])
                {
                    if(i == 21)
                        temp = score - 50;
                    else
                        temp = score - multiplier[0]*i;
                    if(temp == 0)
                    {
                        temp1.clear();
                        temp1.insert((i == 21? 50:i*multiplier[0]));
                        temp1.insert(0);
                        temp1.insert(0);
                        if(search_it(temp1, myvec))
                        {
                            permutations += permute( (i == 21? 50:i*multiplier[0]), 0, 0);
                            ++combinations;
                            myvec.pb(temp1);
                        }
                        break;
                    }
                    else if(temp < 0)
                    {
                        break;
                    }
                    if(i == 21)
                        score -= 50;
                    else
                        score -= multiplier[0] * i;
                    for( j = i; j< 22; ++j)
                    {
                        for(multiplier[1] = 1; multiplier[1] < 4; ++multiplier[1])
                        {
                            if(j == 21)
                                temp = score - 50;
                            else
                                temp = score - multiplier[1]*j;
                            if(temp == 0)
                            {
                                temp1.clear();
                                temp1.insert((i == 21? 50:i*multiplier[0]));
                                temp1.insert((j == 21? 50:j*multiplier[1]));
                                temp1.insert(0);
                                if(search_it(temp1, myvec))
                                {
                                    permutations += permute((i == 21? 50:i*multiplier[0]), (j == 21? 50:j*multiplier[1]), 0);
                                    ++combinations;
                                    myvec.pb(temp1);
                                }
                                break;
                            }
                            else if(temp < 0)
                            {
                                break;
                            }
                            if(j == 21)
                                score -= 50;
                            else
                                score -= multiplier[1]*j;
                            for( k = j; k < 22; ++k)
                            {
                                for(multiplier[2] = 1; multiplier[2] < 4; ++multiplier[2])
                                {
                                    if(k == 21)
                                        temp = score - 50;
                                    else
                                        temp = score - multiplier[2]*k;
                                    if( temp == 0)
                                    {
                                        temp1.clear();
                                        temp1.insert((i == 21? 50:i*multiplier[0]));
                                        temp1.insert((j == 21? 50:j*multiplier[1]));
                                        temp1.insert((k == 21? 50:k*multiplier[2]));
                                        if(search_it(temp1, myvec))
                                        {
                                            permutations += permute((i == 21? 50:i*multiplier[0]), (j == 21? 50:j*multiplier[1]) , (k == 21? 50:k*multiplier[2]));
                                            ++combinations;
                                            myvec.pb(temp1);
                                        }
                                        break;
                                    }
                                    else if(temp < 0)
                                    {
                                        break;
                                    }
                                }
                            }
                            if(j == 21)
                                score += 50;
                            else
                                score += multiplier[1]*j;
                        }
                    }
                    if(i == 21)
                        score += 50;
                    else
                        score += multiplier[0]*i;
                }
            }
        }
        if( combinations == 0)
        {
            cout << "THE SCORE OF "<< score << " CANNOT BE MADE WITH THREE DARTS.\n";
        }
        else
        {
            cout << "NUMBER OF COMBINATIONS THAT SCORES "<< score<<" IS "<< combinations<<".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES "<< score<<" IS "<< permutations<<".\n";
        }
        for(i = 0; i< 70 ; ++i)
            cout << '*';
        cout <<"\n";
    }
}
