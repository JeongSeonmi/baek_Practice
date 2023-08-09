/* 체스판 다시 칠하기 */
// 23.08.04
// https://www.acmicpc.net/problem/1018

#include<iostream>
#define MAX 51
using namespace std;
string board[MAX];

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> board[i];
    }

    int min = N * M;
    for(int i = 0; i <= N- 8; i++){
		for(int j = 0; j <= M - 8; j++){
			int cnt = 0;

            /*  시작이 B일 때 */
			for(int k = i; k < i + 8; k++){
				for(int  z = j; z < j + 8; z++){
					if(z % 2 == 0 && k % 2 == 0){
						if(board[k][z] != 'B'){
							cnt++;
						}
					}
					else if(z % 2 == 0 && k % 2 !=0){
						if(board[k][z] != 'W'){
							cnt++;
						}
					}
					else if(k % 2 == 0){
						if(board[k][z] != 'W'){
							cnt++;
						}
					}
					else{
						if(board[k][z] != 'B'){
							cnt++;
						}
					}
				}
			}
			if(min > cnt){ 
                min = cnt;
            }

            /* 시작이 W일 때 */
			cnt = 0;
			for(int k = i; k < i + 8; k++){
				for(int z = j; z < j + 8; z++){
					if(z % 2 == 0 && k % 2 == 0){
						if(board[k][z] != 'W'){
							cnt++;
						}
					}
					else if(z % 2 == 0 && k % 2 != 0){
						if(board[k][z] != 'B'){
							cnt++;
						}
					}
					else if(k % 2 == 0){
						if(board[k][z] != 'B'){
							cnt++;
						}
					}
					else{
						if(board[k][z] != 'W'){
							cnt++;
						}
					}
				}
			}
			if(min > cnt){
                min = cnt;		
		    } 

        }
	}
	cout << min;    //시작이 B일 때와 W일 때 cnt 최소값 비교
	
	return 0;
}