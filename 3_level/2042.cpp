/* 구간 합 구하기 */
// 23.07.19
// https://www.acmicpc.net/problem/2042

#include<iostream>
using namespace std;

typedef long long ll;
ll num[1000001];   
ll tree[4000004];

ll init(int node, int start, int end){
    if(start == end){
        tree[node] = num[start];
        return tree[node];
    }
    int mid = (start + end) / 2;
    tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
    return tree[node];
    
}

ll interval_sum(int node, int start, int end, int left, int right){
    if(left > end || right < start){
        return 0;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    int mid = (start + end) / 2;
    return interval_sum(node * 2, start, mid, left, right) + interval_sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, ll value){
    if(index < start || index > end){
        return;
    }

    tree[node] += value;
    
    if(start == end){
        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, value);
    update(node * 2 + 1, mid + 1, end, index, value);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;    //수의 개수, 수의 변경이 일어나는 횟수, 구간의 합을 구하는 횟수 
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    
    init(1, 0, N - 1);
  
    int set, left;
    ll right;
    for(int i = 0; i < (M + K); i++){
        cin >> set >> left >> right;
        if(set == 1){
            ll temp = right - num[left - 1];
            num[left - 1] = right;
            update(1, 0, N - 1, left - 1, temp);
            
        }
        else if(set == 2){
            ll sum = interval_sum(1, 0, N - 1, left - 1, right - 1);
            cout << sum << "\n";
        }
    } 

    return 0;
}