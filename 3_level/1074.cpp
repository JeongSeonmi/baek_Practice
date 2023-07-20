/* Z */
// 23.07.20
// https://www.acmicpc.net/problem/1074

#include<iostream>
using namespace std;
int N, r, c, count = 0; //사각형 크기, 행, 열

void Z(int y, int x, int size){
    if(y == r && x == c){    //목표 좌표에 도착한 경우 도착횟수 출력
        cout << count << endl;
        return;
    }

    if(r < y + size && c < x + size && r >= y && c >= x){   //위치에서 사각형을 4등분해서 이동
        Z(y, x, size / 2);  //제 1 사분면 
        Z(y, x + size / 2, size / 2);   //제 2 사분면
        Z(y + size / 2, x, size / 2);   //제 3 사분면
        Z(y + size / 2, x + size / 2, size / 2);    //제 4 사분면
    }   //사분면을 순서대로 이동하는 이유 : Z모양으로 이동하기 위해 제 1 2 3 4 사분면 순서로 이동한다.
    count += size * size;   //사각형 범위에 없으면 사각형 크기만큼 횟수 저장
}

int main(){
    cin >> N >> r >> c;
    Z(0, 0, (1 << N));  //(0, 0)부터 시작해서 사각형 Z모양으로 이동
    return 0;
}
