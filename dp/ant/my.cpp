#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> k;  // 크기를 미리 지정하지 않음
vector<int> result;

void func(int temp, int index) {
    if (index >= n) {  // index가 범위를 넘어가면 종료
        result.push_back(temp);
        return;
    }

    temp += k[index];

    func(temp, index + 2);
    if (index + 3 <= n - 1) {
        func(temp, index + 3);
    }
}

int main(void) {
    cin >> n;

    k.resize(n);  // 벡터 크기 설정

    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    for (int i = 0; i < (n / 2); i++) {
        int temp = k[i];  
        func(temp, i + 2);
        if (i + 3 <= n - 1) {
            func(temp, i + 3);
        }
    }

    if (result.empty()) {  // 예외 처리 (결과 벡터가 비어있는 경우)
        cout << 0 << endl;
    } else {
        int answer = *max_element(result.begin(), result.end());
        cout << answer << endl;
    }

    return 0;
}
