/* Ω∫≈√ */
// 23.08.02
// https://www.acmicpc.net/problem/10828

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int stack[10000];
int cnt = 0;

void push(int x){
    stack[cnt] = x;
    cnt++;
}

void pop(){
    if(cnt != 0){
        cnt--;
        printf("%d\n", stack[cnt]);
        stack[cnt] = 0;
    }
    else{
        printf("-1\n");
    }
}

void top(){
    if(cnt != 0){
        printf("%d\n", stack[cnt - 1]);
    }
    else{
        printf("-1\n");
    }
}

void size(){
    printf("%d\n", cnt);
}

void empty(){
    if(cnt != 0){
        printf("0\n");
    }
    else{
        printf("1\n");
    }
}

int main(){
    int N;
    char commend[10] = {0, };

    scanf("%d", &N);

    while(N--){
        scanf("%s", &commend);
        if(!strcmp(commend, "push")){
            int num;
            scanf("%d", &num);
            push(num);
        }
        else if(!strcmp(commend, "pop")){
            pop();
        }
        else if(!strcmp(commend, "top")){
			top();
		}
		else if(!strcmp(commend, "size")){
			size();
		}
		else if(!strcmp(commend, "empty")){
			empty();
		}
	}

    return 0;
}