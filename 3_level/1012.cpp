#include<iostream>
using namespace std;

void dfs(int arr[][50], int a, int b, int w, int h) {
    if (a < 0 || b < 0 || a >= w || b >= h || arr[a][b] != 1)
        return;
        
    arr[a][b] = 0;

    // 상하좌우로 인접한 배추들에 대해 재귀적으로 탐색
    dfs(arr, a - 1, b, w, h); // 상
    dfs(arr, a + 1, b, w, h); // 하
    dfs(arr, a, b - 1, w, h); // 좌
    dfs(arr, a, b + 1, w, h); // 우
}

int main(){
    int num, w, h, n;  //테스트 케이스, 가로, 세로, 배추 개수
    cin >> num;
    int arr[50][50] = {0};
    for(int k = 0; k < num; k++){
        cin >> w >> h >> n;

        int x, y, cnt = 0; //배추 좌표, 애벌레 개수
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            arr[x][y] = 1;
        }

        //배추밭 탐색
        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                if(arr[i][j] == 1){
                    dfs(arr, i, j, w, h);
                    cnt++;
                }
            }
        }
        
        cout << cnt << "\n";
    }
    return 0;
}