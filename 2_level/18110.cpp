/* solved.ac */
// 23.08.04
// https://www.acmicpc.net/problem/18110

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int level[300001];

int main(){
    int n;
    cin >> n;
    
    if(n == 0){
        cout << "0" << endl;
        return 0;
    }

    for(int i = 0; i < n; i++){
        cin >> level[i];
    }

    sort(level, level + n);
    
    int exceNum = round(n * 0.15);
    double sum = 0;
    for(int i = exceNum; i < n - exceNum; i++){
        sum += level[i];
    }
    int average = round(sum / (n - exceNum * 2));

    cout << average << endl;

    return 0;
}