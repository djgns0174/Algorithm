#include<iostream>
using namespace std;

int main(){
    string input;
    cin >> input;

    string resultString(input.size(), ' ');
    int resultInt = 0;
    int idx = 0;

    for(int i=0; i<input.size(); i++){
        int ascii = (int)input[i];
        if(65 <= ascii && ascii <= 90){
            resultString[idx++] = input[i];
        } else {
            int a = ascii - 48;
            resultInt += a;
        }
    }

    sort(resultString.begin(), resultString.end());
    string resultString2 = to_string(resultInt);
    
    cout << resultString + resultString2 << endl;

    return 0;
}