/* 세로 읽기 */
// 23.07.24
// https://www.acmicpc.net/problem/10798

#include<iostream>
using namespace std;

int main(){
    char str[5][16] = {0, };
    for(int i = 0; i < 5; i++){
        cin >> str[i];
    }

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 5; j++){
            if(str[j][i] != '\0'){  //문자열을 입력받을 때 마지막에 \0도 저장되므로
                cout << str[j][i];
            }
        }
    }

}
