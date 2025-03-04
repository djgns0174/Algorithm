#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

int main(void){
    string str;
    cin >> str;
    stringstream ss(str);
    string number1;
    vector<int> arr;

    while(getline(ss, number1, '-')){

        stringstream subss(number1);
        string number2;

        int sum = 0;
        while(getline(subss, number2, '+')){
            sum += stoi(number2);
        }
        arr.push_back(sum);
    }

    int answer = arr.at(0);
    for(int i=1; i<arr.size(); i++){
        answer -= arr.at(i);
    }

    cout << answer << endl;
}