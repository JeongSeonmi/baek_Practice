/* 좌표 압축 */
// 23.07.21
// https://www.acmicpc.net/problem/18870

#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000001
using namespace std;
int N;
vector<pair<int, int>>num;  //원래 숫자, 압축 숫자
vector<int>ans(MAX);  //압축한 숫자를 저장할 배열

void ZIP(){     //num의 first는 원본 숫자, second는 숫자가 있던 자리
    sort(num.begin(), num.end());   //오름차순 정렬을 통해 작은 수를 구함

    int cnt = 0;
    int min = num[0].first;    //최소값, 이전 숫자를 저장할 변수
    ans[num[0].second] = 0;
    for(int i = 1; i < N; i++){
        if(min == num[i].first){
            ans[num[i].second] = cnt;
        }
        else{
            ans[num[i].second] = ++cnt;
            min = num[i].first;     //오름차순으로 정렬된 상태이기때문에 이동하며 이전 숫자 업데이트
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