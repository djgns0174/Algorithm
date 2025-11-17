#include<iostream>
#include<vector>

#define MAX_SEC 11111

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

    vector<string> answers; //정답 저장용 벡터

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, M, K;
        cin >> N >> M >> K;

        vector<int>is_arrived(MAX_SEC+1, 0); // 초당 사람들이 몇명 도착하는지 저장하는 벡터
        for(int i=0; i<N; i++)
        {
            int input;
            cin >> input;

            is_arrived[input]++;
        }

        string answer = "Possible";

        int sec = 0; //현재 시간(초)
        int bread = 0; //빵의 개수(누적)
        while(true)
        {   
            
            if(sec > MAX_SEC) break;
            
            if(sec % M == 0 && sec != 0) bread += K;
            
            if(is_arrived[sec] > 0) //사람이 오면
            {
                bread -= is_arrived[sec]; // 사람이 온 만큼 빵개수 감소
                if(bread < 0)
                {
                    answer = "Impossible";
                    break;
                }
                
                is_arrived[sec] = 0;
            }

            sec++;
        }
        
        answers.push_back(answer);
	}

    for(int i=0; i<answers.size(); i++) //정답 출력
        cout << "#" << i+1 << " " << answers[i] << endl;

	return 0;
}