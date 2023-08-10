/* Àý´ë°ª Èü */
// 23.08.10
// https://www.acmicpc.net/problem/11286

#include<iostream>
#include<queue>
using namespace std;

struct cmp{
    bool operator()(int x, int y){
        if(abs(x) == abs(y)){
            return x > y;
        }
        else{
            return abs(x) > abs(y);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int, vector<int>, cmp>pq;
    int N;

    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        if(num == 0){
            if(pq.empty()){
                cout << "0\n";
            }   
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(num);
        }
    }
}