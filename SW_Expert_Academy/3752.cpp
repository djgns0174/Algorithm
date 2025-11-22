#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_VALUE 10001

using namespace std;

int T, N;
vector<bool>dp;
vector<int>answers; 

void solve(int input, int start) //dp값 구하기
{
    for(int i=start*100; i>=0; i--)
    {
        if(dp[i])
        {
            dp[i + input] = true;
        }
    }
}

void input()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int input;
        cin >> input;
        solve(input, i+1);
    }
}

void output()
{
    for(int i=0; i<T; i++) 
    {
        cout << "#" << i+1 << " " << answers[i] << endl;   
    }
}

void answer_push()
{
    int answer = 0;
    for(int i=0; i<dp.size(); i++)
    {
        if(dp[i]) answer++;
    }
        
    answers.push_back(answer);
}

int main(int argc, char** argv)
{
	int test_case;
    cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        dp = vector<bool>(MAX_VALUE, false);
        dp[0] = 1;

        input();
        answer_push();
	}

    output();

	return 0;
}