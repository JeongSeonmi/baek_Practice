/* �мǿ� ���غ� */
// 23.08.02
// https://www.acmicpc.net/problem/9375

#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;  //testcase num
    cin >> n;

    while(n--){
        int num;
        cin >> num;

        map<string, int> clothes;   //�ǻ� ����, �ǻ� ��
        for(int i = 0; i < num; i++){
            string name, tags;
            cin >> name >> tags;

            clothes[tags]++;
        }

        int result = 1;
        for(auto iter = clothes.begin(); iter != clothes.end(); iter++){  //map clothes�� ��ü ��ȸ 
            result *= (iter->second + 1);   //map�� ����� �ǻ�� + 1 �ؼ� ���ϱ�
        }
        cout << result - 1 << "\n"; //�� ���Դ� ��쵵 �����Ƿ� -1
        
    }
    return 0;
}