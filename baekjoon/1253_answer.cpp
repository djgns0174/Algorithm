#include<iostream>
#include<algorithm>

using namespace std;

/*
    좋다 - 1253

    [이분탐색]
    1. 완전탐색으로 좋은 값 설정
    2. 좋은 값인지 확인
        1. 완전탐색으로 첫번째 값 설정
        2. 좋은값 - 첫번째 값 = 나머지
        3. 나머지 값이 있는지 이진탐색으로 찾기
    3. 좋은 값이라면 카운트
    4. 반복

    [시간 복잡도]
    n(좋은 값 설정) * n(첫번째 값 설정) * log2(n)(나머지 값 이진탐색)
    = n^2 * log2(n) 으로 통과

    [정답여부]
    84%에서 틀리고 이게 왜 틀리는지 모르겠다.

    [정답코드]
    1. 완전탐색으로 좋은 값 설정
    2. 좋은 값인지 확인
        1. Start, end 를 둬서 투포인터로 접근
        2. 두 값을 더해서 좋은값(target) 보다 
            1. 작으면 start++ (값을 증가시켜야됨)
            2. 크면 end— (값을 감소시켜야됨)
            3. 같으면 중복되는 인덱스가 있는지 검사하고 없으면 좋은 값 판별

    [정답 코드 시간복잡도]
    n(좋은 값 설정) * n(투포인터) = n^2

*/

int main(void){

    int n;
    cin >> n;

    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int answer = 0;
    for(int i=0; i<n; i++){
        int target = a[i];

        int start = 0;
        int end = n-1;
        
        while(start < end){
            int value = a[start] + a[end];

            if(value == target)
            {
                if(start != i && end != i)
                {
                    answer++;
                    break;
                }
                else if(start == i) start++;
                else end--;
            } 
            else if(value < target) start++;
            else end--;
        }
    }

    cout << answer << endl;
    
    return 0;
}