#include<iostream>
#include<vector>

using namespace std;

int N, K;

int answer;

void dfs(int sum, int start, vector<int>arr)
{
    if(sum == K) // 부분수열의 합이 K일때
    {
        answer++;
        return;
    }

    if(sum > K) return; //부분수열의 합이 K보다 클때

    for(int i=start; i<N; i++)
    {
        sum += arr[i];
        dfs(sum, i+1, arr);
        sum -= arr[i];
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

    vector<int>answers;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> K;
        vector<int>arr(N, 0);

        answer = 0; // K값이 되는 경우의 수
        
        for(int i=0; i<N; i++) // 입력받기
            cin >> arr[i];

        int sum = 0; // dfs로 sum 구하기
        for(int i=0; i<N; i++)
        {
            sum = arr[i];
            dfs(sum, i+1, arr);
            sum -= arr[i];
        }

        answers.push_back(answer);
	}

    for(int i=0; i<answers.size(); i++) //정답 출력
        cout << "#" << i+1 << " " << answers[i] << endl;

	return 0;
}