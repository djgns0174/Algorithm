#include<iostream>
#include<vector>
#define MODULO 1234567891

using namespace std;

vector<long long>factorial;

long long func(int a, int p) //페르마의 소정리
{
    if(p == 0) return 1;
    long long temp = func(a, p/2); //분할정복으로 a^p-2 계산
    long long value = (temp * temp) % MODULO;
    if(p % 2 != 0) value = (value * a) % MODULO;

    return value;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin >> T;

    vector<long long>answers; // 정답 저장용 벡터

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, R;
        cin >> N >> R;
        
        long long answer = 1;

        if(R == 0)
        {
            answers.push_back(answer);
            continue;
        }

        factorial = vector<long long>(N+1, 0); //팩토리얼 0! ~ N! 까지 저장하는 벡터
        factorial[0] = 1;
        
        for(int i=1; i<=N; i++)
        {
            factorial[i] = (factorial[i-1] * i) % MODULO;
        }

        long long a = factorial[R] * factorial[N-R] % MODULO;
        long long a_1 = func(a, MODULO-2);  // a^-1

        answer = (factorial[N] * a_1) % MODULO;
        
        answers.push_back(answer);
	}

    for(int i=0; i<T; i++) cout << "#" << i+1 << " " << answers[i] << endl;

	return 0;
}