/* �Ҿ���� ��ȣ */
// 23.07.22
// https://www.acmicpc.net/problem/1541

#include<stdio.h>

int main(){
    char str;
    int temp, num, check = 0;   //���� �ϳ� ����, ������� ����, ��ȣüũ
    for(scanf("%d", &num); scanf("%c", &str), str != 10;){      //����(����) ����(ASCII �� 10)�� �ƴ� ������ �ݺ�
        if(str == '-'){
            check = 1;
        }
        scanf("%d", &temp);
        if(check == 1){ //- ��ȣ��� temp�� ��
            num -= temp;
        }
        else{   //+ ��ȣ��� temp�� ����
            num += temp;
        }
    }
    printf("%d", num);
    return 0;
}

//str != 10�� ����� ��� �ڵ尡 ��������!