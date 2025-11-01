#include <iostream>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int>> arr;
int answer = -1;

void func(int first, int depth)
{
    answer = max(depth, answer);

    for(int i=0; i<N; i++)
    {
        if(arr[i].first == first)
        {
            func(arr[i].second, depth + 1);
        }
    }
}

int main(void)
{
    cin >> N;

    for(int i=0; i<N; i++)
    {
        pair<int,int> p;
        cin >> p.first >> p.second;

        arr.push_back(p);
    }

    for(int i=0; i<N; i++)
    {
        func(arr[i].second, 2);
    }
    
    cout << answer << endl;

    return 0;
}