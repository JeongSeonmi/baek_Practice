#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> P;

int main(){
    int N, minP = 0;   //����� ��
    cin >> N;
    for(int i = 0; i < N; i++){
        int k;
        cin >> k; 
        P.push_back(k);
    }
    sort(P.begin(), P.end());
    
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += P[i] * (N - i);
    }
    cout << sum << endl;
    return 0;

}   