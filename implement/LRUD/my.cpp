#include<iostream>
using namespace std;

int main(){
    vector<string>inputArr;
    int n;
    cin >> n;

    int resultX = 1;
    int resultY = 1;
    int cnt = 0;

    while(1){
        string str;
        cin >> str;
        inputArr.push_back(str);
        cnt++;
    }

    for(int i=0; i<6; i++){
        string a = inputArr[i];
        if(a == "L"){
            if(resultX == 1) continue;
            resultX --;
        } else if(a == "R"){
            if(resultX == n) continue;
            resultX ++;
        } else if(a == "U"){
            if(resultY == 1) continue;
            resultY --; 
        }else if(a == "D"){
            if(resultY == n) continue;
            resultY ++;
        }
    }

    cout << resultY;
    cout << " ";
    cout << resultX;

    return 0;
}