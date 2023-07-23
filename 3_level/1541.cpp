/* 잃어버린 괄호 */
// 23.07.22
// https://www.acmicpc.net/problem/1541

#include<stdio.h>

int main(){
    char str;
    int temp, num, check = 0;   //숫자 하나 저장, 누적결과 저장, 부호체크
    for(scanf("%d", &num); scanf("%c", &str), str != 10;){      //개행(엔터) 문자(ASCII 값 10)가 아닐 때까지 반복
        if(str == '-'){
            check = 1;
        }
        scanf("%d", &temp);
        if(check == 1){ //- 부호라면 temp를 뺌
            num -= temp;
        }
        else{   //+ 부호라면 temp를 더함
            num += temp;
        }
    }
    printf("%d", num);
    return 0;
}

//str != 10을 사용할 경우 코드가 간결해짐!