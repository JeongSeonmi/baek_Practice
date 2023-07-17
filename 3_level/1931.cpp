/* 회의실 배정 */
// 23.07.15
// https://www.acmicpc.net/problem/1931

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> meeting;


int main(){
    int N;
    int start, end;
    cin >> N;
    for(int i = 0; i < N; i++){    
        cin >> start >> end; 
        meeting.push_back(make_pair(end, start));
    }
    
    //sort(meeting.begin(), meeting.end());

    int time = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(time <= meeting[i].second){
                cnt++;
                time = meeting[i].first;
        }
    }

    cout << cnt << endl;
}
