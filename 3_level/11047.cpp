/* µ¿Àü 0 */
// https://www.acmicpc.net/problem/11047

#include<iostream>
#include<vector>
using namespace std;
vector <int> A;
int main(){
    int N, K;
    int cnt = 0;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int pri;
        cin >> pri;
        A.push_back(pri);
    }
    for(int i = N - 1; i >= 0; i--){
        if ( K >= A.at(i)){
            cnt += K / A.at(i);
            K %= A.at(i);    
        }
    }
    cout << cnt << endl;
}