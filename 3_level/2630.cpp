/* 색종이 만들기 */
// 23.07.19, 다시 풀어보기
// https://www.acmicpc.net/problem/2630

#include<iostream>
using namespace std;
int arr[128][128];
int white, blue;

void Cut(int y, int x, int size){
    int check = arr[y][x];
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(check != arr[i][j]){
                check = 2;
            }
            if(check == 2){
                Cut(y, x, size / 2);
                Cut(y, x + size / 2, size / 2);
                Cut(y + size / 2, x, size / 2);
                Cut(y + size / 2, x + size / 2, size / 2);
                return;
            }
        }
    }
    if (check == 0)  //하얀색일 경우
        white++;
    else    //파란색일 경우
        blue++;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    Cut(0, 0, N);
    cout << white << endl;
    cout << blue << endl;
    return 0;
}