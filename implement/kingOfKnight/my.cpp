#include<iostream>
using namespace std;

void setUpX(char x1, int &x2){
    if(x1 == 'a'){
        x2 = 1;
    }else if(x1 == 'b'){
        x2 = 2;
    }else if(x1 == 'c'){
        x2 = 3;
    }else if(x1 == 'd'){
        x2 = 4;
    }else if(x1 == 'e'){
        x2 = 5;
    }else if(x1 == 'f'){
        x2 = 6;
    }else if(x1 == 'g'){
        x2 = 7;
    }else if(x1 == 'h'){
        x2 = 8;
    }   
}

void setUpY(char y1, int &y2){
    y2 = y1 - '0';
}

int main(){
    string input;
    cin >> input;

    char charX = input[0];
    int x, y;

    setUpX(charX, x);
    setUpY(input[1], y);

    int result = 0;
    /*
    x-2 -> y-1 or y+1
    x+2 -> y-1 or y+1
    y-2 -> x-1 or x+1
    y+2 -> x-1 or x+1
    */

   if(x-2 >= 1 && y-1 >= 1) result++;
   if(x-2 >= 1 && y+1 <= 8) result ++;

   if(x+2 <= 8 && y-1 >= 1) result ++;
   if(x+2 <= 8 && y+1 <= 8) result ++;

   if(y-2 >= 1 && x+1 <= 8) result ++;
   if(y-2 >= 1 && x-1 >= 1) result ++;
   
   if(y+2 <= 8 && x-1 >= 1) result ++;
   if(y+2 <= 8 && x+1 <= 8) result ++;

   cout << result << endl;
}