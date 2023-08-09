/* ¼öÃ£±â */
// 23.08.09
// https://www.acmicpc.net/problem/1920 

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int A[100000];

int main(){
    int N , M;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    sort(A, A + N);

    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int num;
        scanf("%d", &num);
        printf("%d\n", binary_search(A, A+N, num));
    }
    return 0;
}