/* �������� */
// 23.08.09
// https://www.acmicpc.net/problem/1202

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
priority_queue<int, vector<int>, less<int>>pq;
vector<pair<int, int>>jew;
vector<int>bag;

int main(){
    int N, K;   // ���� ��, ���� ��
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        ll weight, price; // ���� ����, ����;
        cin >> weight >> price;
        jew.push_back({weight, price});
    }
    for(int i = 0; i < K; i++){
        ll mexW;
        cin >> mexW;    // ���濡 ���� �� �ִ� �ִ� ����
        bag.push_back(mexW);
    }

    sort(jew.begin(), jew.end());
    sort(bag.begin(), bag.end());

    ll sum = 0;
    int idx = 0;    //���� ����Ȯ�ο�
    for(int i = 0; i < K; i++){
        while(idx < N && bag[i] >= jew[idx].first){
            pq.push(jew[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << endl;
    return 0;
}