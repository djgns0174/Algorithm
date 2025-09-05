#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> vec = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int row = vec.size();        // 행 개수
    int col = vec[0].size();     // 첫 번째 행의 열 개수

    cout << "행(row): " << row << endl;
    cout << "열(col): " << col << endl;

    return 0;
}