#include<iostream>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int result = 0;

    for(int k=0; k<=n; k++){
        for(int j=0; j<60; j++){
            for(int i=0; i<60; i++){
                if(i%10 == 3 || i/10 == 3
                || k%10 == 3 || k/10 == 3
                || j%10 == 3 || j/10 == 3) result ++;
            }
        }
    }
    cout << result;

    return 0;
}