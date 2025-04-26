#include<iostream>
#include<algorithm>

#define endl "\n"

using namespace std;

/*
    좋다

    [정답여부]
    84% 틀림 -> 왜 틀렸는지 모르겠음.

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

    vector<pair<long, int>> a;
    for(int i=0; i<n; i++){
        long input;
        cin >> input;
        a.push_back({input, 0});
    }

    sort(a.begin(), a.end());

    // int answer = 0;
    for(int i=0; i<n; i++){
        long good = a[i].first;
        for(int j=0; j<n; j++){
            if(i==j) continue;

            long first = a[j].first;
            long rest = good - first;

            // 나머지 값 이진탐색
            bool find = false;
            int start = 0;
            int end = n-1;
            while(start <= end){
                int key = (start + end) / 2;
                if(rest == a[key].first && key != j && key != i){
                    // answer++;
                    // cout << good << " " << rest << endl;
                    a[i].second = 1;
                    find = true;
                    break;
                }

                if(rest < a[key].first)
                    end = key - 1;
                else
                    start = key + 1;
            }

            if(find) {break;}
        }
    }

    int answer = 0;
    for(int i=0; i<n; i++){
        //test
        // cout << a[i].first << " " << a[i].second << endl;
        if(a[i].second == 1)
            answer++;
    }

    cout << answer << endl;
    
    return 0;
}