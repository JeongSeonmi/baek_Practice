/* 이중 우선순위 큐 */
// 23.08.07
// https://www.acmicpc.net/problem/7662

#include<iostream>
#include<set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int T, k;   //테스트 횟수, 연산의 개수
    cin >> T;
    while(T--){
        cin >> k;
        multiset<int> q; // 중요 : multiset 오름차순 정렬
        while(k--){
            char oper;
            int num;
            cin >> oper >> num;
            if(oper == 'I'){
                q.insert(num);
            }
            if(oper == 'D'){
                if(q.empty()){
                    continue;
                }
                if(num == 1){ //최대값
                    auto iter = q.end(); //맨 끝 값에 +1 해줌
                    iter--; 
                    q.erase(iter);
                }
                if(num == -1){
                    q.erase(q.begin()); // 최소값 삭제
                }
            }
        }
        if(q.empty()){
        cout << "EMPTY" << '\n';
        }
        else{   
            auto iter = q.end();    //끝에서 부터 돌음
            iter--;
            cout << *iter << " " << *q.begin() << '\n';
        }
    }
    
    return 0;
}
