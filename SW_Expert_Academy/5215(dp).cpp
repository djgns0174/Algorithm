#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(int argc, char** argv)
{

	int test_case;
	int T;
	cin>>T;

    vector<int>answers;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, L;   
        cin >> N >> L;

        vector<pair<int,int>> arr;
        vector<int>dp(L+1, 0);
        
        for(int i=0; i<N; i++) //입력 받기
        {
            pair<int,int> input;
            cin >> input.first >> input.second;
            arr.push_back(input);
        }

        for(int i=0; i<N; i++)
        {
            int score = arr[i].first;
            int calorie = arr[i].second;

            for(int j=L; j>=calorie; j--) //Bottom-up 방식을 사용하면 이미 쓴 재료를 중복해서 사용할 수 있기 때문에 위에서 아래로 내려가야됨.
            {
                dp[j] = max(dp[j], dp[j-calorie] + score);
            }
        }

        answers.push_back(dp[L]);
	}

    for(int i=0; i<answers.size(); i++)
        cout << "#" << i+1 << " " << answers[i] << endl;

	return 0;
}