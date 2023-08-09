/* 단어 정렬 */
// 23.08.04
// https://www.acmicpc.net/problem/1181 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int compare(string x, string y){
    if(x.size() == y.size()){
        return x < y;
    }
    return x.size() < y.size();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<string> str;
    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        str.push_back(temp);
    }

    sort(str.begin(), str.end(), compare);
    str.erase(unique(str.begin(), str.end()), str.end());   //중복되는 단어 삭제

    for(auto iter : str){
        cout << iter << "\n";
    }
}