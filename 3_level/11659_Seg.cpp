/* 구간 합 구하기 4 */
// 23.07.18
// https://www.acmicpc.net/problem/11659
// 세그먼트 트리를 사용해 푼 문제

#include<iostream>
using namespace std;

typedef long long ll;
int num[100001];   
int tree[400004];

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

void update(int node, int start, int end, int index, int value){
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

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    
    init(1, 0, N-1);

    int Rbegin, Rend;
    for(int i = 0; i < M; i++){
        cin >> Rbegin >> Rend;
        int sum = interval_sum(1, 0, N - 1, Rbegin - 1, Rend - 1);
        cout << sum << "\n";
    }
    return 0;
}