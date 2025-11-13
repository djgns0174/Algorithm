#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

    vector<int> answers; //정답 저장용 벡터

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin >> N;
        
        int answer = 0;

        vector<vector<int>> arr(N, vector<int>(N,0));

        for(int i=0; i<N; i++) // 입력받기
        { 
            string input;
            cin >> input;
            for(int j=0; j<N; j++)
            {
                arr[i][j] = input[j]-'0';
            }
        }

        for(int i=0; i<N; i++) // 가운데 행 전부 더하기
            answer += arr[N/2][i];
        
        int row = (N/2)-1; 
        int start_col = 1;
        int end_col = N-2;
        while(row >= 0) //가운데부터 윗행들 더하기
        {
            for(int i=start_col; i<=end_col; i++)
                answer += arr[row][i];

            row--;
            start_col++; 
            end_col--;
        }
        
        row = (N/2)+1;
        start_col = 1;
        end_col = N-2;
        while(row < N) // 가운데부터 아랫행들 더하기
        {
            for(int i=start_col; i<=end_col; i++)
            {
                answer += arr[row][i];
            }
            row++;
            start_col++; 
            end_col--;
        }
        
        answers.push_back(answer);
	}

    for(int i=0; i<answers.size(); i++) //정답 출력
        cout << "#" << i+1 << " " << answers[i] << endl;

	return 0;
}