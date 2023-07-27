/* ���� ����� �� ����� �ɸ��� �Ÿ� */
// 23.07.27
// https://www.acmicpc.net/problem/20529

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;  //tset case
    cin >> T;
    while(T--){
        int studentNum;
        cin >> studentNum;

        vector<string> MBTI;
        for(int i = 0; i < studentNum; i++){
            string str;
            cin >> str; 
            MBTI.push_back(str);
        }

        if(studentNum > 32){
            cout << '0' << "\n";
        }
        else{
            int minNum = 100;
            for(int i = 0; i < studentNum; i++){    //�ٸ� �л��̶� ��
                for(int j = i + 1; j < studentNum; j++){
                    for(int k = j + 1; k < studentNum; k++){
                        int cnt = 0;
                        for(int alpa = 0; alpa < 4; alpa++){    //4���� ��
                            if(MBTI[i][alpa] != MBTI[j][alpa]) cnt++;
                            if(MBTI[j][alpa] != MBTI[k][alpa]) cnt++;
                            if(MBTI[k][alpa] != MBTI[i][alpa]) cnt++;
                        }
                        minNum = min(minNum, cnt); //�Ÿ��� �� �߿��� �ּҰ� ã��
                    }
                }
            }
            cout << minNum << "\n";
        }
    }
    return 0;
}