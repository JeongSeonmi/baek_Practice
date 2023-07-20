/* ��ǥ ���� */
// 23.07.21
// https://www.acmicpc.net/problem/18870

#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000001
using namespace std;
int N;
vector<pair<int, int>>num;  //���� ����, ���� ����
vector<int>ans(MAX);  //������ ���ڸ� ������ �迭

void ZIP(){     //num�� first�� ���� ����, second�� ���ڰ� �ִ� �ڸ�
    sort(num.begin(), num.end());   //�������� ������ ���� ���� ���� ����

    int cnt = 0;
    int min = num[0].first;    //�ּҰ�, ���� ���ڸ� ������ ����
    ans[num[0].second] = 0;
    for(int i = 1; i < N; i++){
        if(min == num[i].first){
            ans[num[i].second] = cnt;
        }
        else{
            ans[num[i].second] = ++cnt;
            min = num[i].first;     //������������ ���ĵ� �����̱⶧���� �̵��ϸ� ���� ���� ������Ʈ
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        int c;
        cin >> c;
        num.push_back({c, i});
    }

    ZIP();
    
    for(int i = 0; i < N; i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}