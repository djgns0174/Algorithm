#include<iostream>
#define endl "\n"

using namespace std;

vector<int>combination;

void comb(int start, int depth, int n, int r)
{
    if(depth == r)
    {
        for(int value : combination) cout << value << " " ;
        cout << endl;
    }

    for(int i=start; i<=n; i++)
    {
        combination.push_back(i);
        comb(i+1, depth+1, n, r);
        combination.pop_back();
    }
}

int main(void)
{
    comb(1, 0, 5, 2);
    
    return 0;
}