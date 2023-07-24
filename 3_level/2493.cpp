/* ž */
// 23.07.24
// https://www.acmicpc.net/problem/2493

#include<iostream>
#include<stack>
using namespace std;
stack<pair<int, int>> st;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
    int N, h;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> h;   
        while(!st.empty()){
            if(st.top().second > h){
                cout << st.top().first << " ";
                break;
            }
            else st.pop();
        }
        if(st.empty()){
            cout << "0 ";
        }
        st.push({i + 1, h});
    }
}

/*
#include<iostream>
#include<stack>
#define MAX 5000000
using namespace std;
stack<pair<int, int>> st;
int ans[MAX] = {0, };
int h[MAX] ={0, };

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> h[i];
    }
    for(int i = N - 1; i >= 0; i--){
        while(!st.empty() && st.top().second < h[i]){
                ans[st.top().first] = i + 1;
                st.pop();
        }
        st.push({i, h[i]});
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] <<" ";
    }
    return 0;
}
*/