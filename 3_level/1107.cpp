/* ������ */
// 23.08.03
// https://www.acmicpc.net/problem/1107

#include<iostream>
#include<cmath>
using namespace std;
bool broken[10] = {0, };

int check(int c){ //������ �ϴ� ��ư�� ������ ��ȯ�ϴ� �Լ�
    if(c == 0){
        if(!broken[c]){    //0�� ��� 0�� ���峵���� �Ǵ�
            return 1;   
        }
        else{
            return 0;
        }
    }

    int len = 0;
    while(c > 0){
        if(broken[c % 10]){     //�̵��� ä���� ���� �ڸ����� Ȯ��
            return 0;
        }
        len += 1;
        c /= 10;
    }
    return len;
}

int main(){
    int N, num;
    cin >> N >> num;    //�̵��� ä��, ���峭 ��ư�� ��

    for(int i = 0; i < num; i++){
        int b;      //���峭 ��ư
        cin >> b;
        broken[b] = true; //���峭 �κ� ǥ��
    }

    if(N == 100){   // �̵��� ä���� ���� ��ġ�� ���� ��� 0
        cout << 0;
        return 0;
    }

    int cnt = abs(N - 100); // +, -�� ������� ��(�ִ밪)
    
    for(int i = 0; i < 1000000; i++){
		if(check(i) > 0){
			int temp = abs(N - i);  //���� ��ȣ���� �̵��Ϸ��ϴ� ä�α����� ����ؾ� �ϴ� +, - Ƚ�� ���
			
            if(cnt > temp + check(i)){
                cnt = temp + check(i);
            }
		}
	}

	cout << cnt;

	return 0;


}