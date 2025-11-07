#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<climits>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;

	int T;
	cin>>T;
    
    vector<int> answers(T+1, 0);

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;  // 건물 개수
        cin >> N;

        vector<int>height(N, 0);

        for(int i=0; i<N; i++) cin >> height[i];


        for(int i=2; i<N-2; i++)
        {
            stack<int>adj_idx;
            adj_idx.push(i-1);
            adj_idx.push(i-2);
            adj_idx.push(i+1);
            adj_idx.push(i+2);

            bool flag = true;
            int min_value = INT_MAX;

            while(!adj_idx.empty())
            {
                int idx = adj_idx.top(); adj_idx.pop();
                int adj_height = height[idx];

                int diff = height[i] - adj_height;

                if(diff < 0) 
                {
                    flag = false;
                    break;
                }

                min_value = min(min_value, diff);
            }

            if(flag && min_value != INT_MAX) 
            {
                answers[test_case] += min_value;
            }
        }
	}

    for(int i=1; i<=T; i++) cout << "#" << i << " " << answers[i] << endl;

	return 0;
}