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
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
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