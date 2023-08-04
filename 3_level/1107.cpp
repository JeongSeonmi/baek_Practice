/* 리모컨 */
// 23.08.03
// https://www.acmicpc.net/problem/1107

#include<iostream>
#include<cmath>
using namespace std;
bool broken[10] = {0, };

int check(int c){ //눌러야 하는 버튼의 개수를 반환하는 함수
    if(c == 0){
        if(!broken[c]){    //0인 경우 0이 고장났는지 판단
            return 1;   
        }
        else{
            return 0;
        }
    }

    int len = 0;
    while(c > 0){
        if(broken[c % 10]){     //이동할 채널의 일의 자리부터 확인
            return 0;
        }
        len += 1;
        c /= 10;
    }
    return len;
}

int main(){
    int N, num;
    cin >> N >> num;    //이동할 채널, 고장난 버튼의 수

    for(int i = 0; i < num; i++){
        int b;      //고장난 버튼
        cin >> b;
        broken[b] = true; //고장난 부분 표시
    }

    if(N == 100){   // 이동할 채널이 현재 위치와 같을 경우 0
        cout << 0;
        return 0;
    }

    int cnt = abs(N - 100); // +, -만 사용했을 때(최대값)
    
    for(int i = 0; i < 1000000; i++){
		if(check(i) > 0){
			int temp = abs(N - i);  //누른 번호에서 이동하려하는 채널까지의 사용해야 하는 +, - 횟수 계산
			
            if(cnt > temp + check(i)){
                cnt = temp + check(i);
            }
		}
	}

	cout << cnt;

	return 0;


}