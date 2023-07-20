/* 집합 */
// 23.07.21
// https://www.acmicpc.net/problem/11723

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector<int> arr(21, 0);    // 0으로 초기화된 크기 21의 벡터
string eng ="";
int num, M;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> eng;
        if(eng == "add"){
            cin >> num;
            if(arr[num] == 0){
                arr[num] = 1;
            }
        }
        else if(eng == "remove"){
            cin >> num;
            if(arr[num] == 1){
                arr[num] = 0;
            }
        }
        else if(eng == "check"){
            cin >> num;
            if(arr[num] == 0){
                cout << "0\n";
            }
            else cout << "1\n";
        }
        else if(eng == "toggle"){
            cin >> num;
            if(arr[num] == 1){
                arr[num] = 0;
            }
            else arr[num] = 1;
        }
        else if(eng == "all"){
            for(int j = 1; j <= 20; j++){
                arr[j] = 1;
            }
        }
        else if(eng == "empty"){
            for(int j = 1; j <= 20; j++){   //memset(arr, 0, sizeof(arr));
                arr[j] = 0;
            }
        }
    }
}