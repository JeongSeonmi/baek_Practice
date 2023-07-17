/* 나무 자르기 */
// 23.07.17
// https://www.acmicpc.net/problem/2805

#include<iostream>
#include<algorithm>
using namespace std;
long long N, M;  //나무의 수, 가져갈 나무 길이
long long tree[100001];

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> tree[i];
    }

    sort(tree, tree + N);

    long long low = 1;
    long long high = tree[N - 1];
    while(low <= high){
        long long sum = 0;
        long long mid = (low + high) / 2;
        for(int i = 0; i < N; i++){
            if(tree[i] > mid){
                sum += tree[i] - mid;
            }
        }
        if(sum >= M){
            low = mid + 1;
        }else{
            high = mid - 1;            
        }
    }
    cout << high << endl;
    return 0;
}