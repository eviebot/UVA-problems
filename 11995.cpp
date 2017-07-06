#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, i, type, val, sum;
    bool stack_flag, queue_flag, pqueue_flag, DONE;
    while(cin >> n)
    {
        stack <int> mystack;
        queue <int> myqueue;
        priority_queue <int> mypqueue;
        stack_flag = true;
        queue_flag = true;
        pqueue_flag = true;
        DONE = true;
        for(i = 0; i < n; i++)
        {
            cin >> type >> val;
            if(DONE)
            {
                if(type==1)
                {
                    mystack.push(val);
                    myqueue.push(val);
                    mypqueue.push(val);
                }
                else
                {
                    if(mystack.empty())
                    {
                        DONE = false;
                        continue;
                    }

                    if(stack_flag)
                    {
                        if(mystack.top() != val)
                        {
                            stack_flag = false;
                        }
                    }

                    if(queue_flag)
                    {
                        if(myqueue.front() != val)
                        {
                            queue_flag = false;
                        }
                    }

                    if(pqueue_flag)
                    {
                        if(mypqueue.top() != val)
                        {
                            pqueue_flag = false;
                        }
                    }

                    mystack.pop();
                    myqueue.pop();
                    mypqueue.pop();
                }
            }
        }

        sum = pqueue_flag + queue_flag + stack_flag;

        if(!DONE || sum==0)
            cout << "impossible";
        else if(sum > 1)
            cout << "not sure";
        else
        {
            if(stack_flag)
                cout << "stack";
            else if(queue_flag)
                cout << "queue";
            else
                cout << "priority queue";
        }
        cout <<"\n";
    }
}
