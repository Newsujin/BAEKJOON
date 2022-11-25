#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, w, h;
int start_x, start_y; //상근이 인덱스
char building[1005][1005];
int fire[1005][1005];
int mv[1005][1005];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int> > Q;

void BFS(void){
    while(!Q.empty()){ // 불의 이동경로(몇초만에?)
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(building[nx][ny] == '*' || building[nx][ny] == '#') continue;
            if(fire[nx][ny] != -1) continue;
            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    Q.push({start_x, start_y});
    while(!Q.empty()){ // 상근이의 이동경로(몇초만에?)
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(building[nx][ny] == '*' || building[nx][ny] == '#') continue;
            if(mv[nx][ny] != -1) continue;
            if(fire[nx][ny] <= mv[cur.X][cur.Y] + 1 && fire[nx][ny] != -1) continue;
            mv[nx][ny] = mv[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    int min = 1000005;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(i == 0 || i == h-1 || j == 0 || j == w-1){
                if(mv[i][j] != -1 && mv[i][j] < min) min = mv[i][j]; 
            }
        }
    }
    if(min == 1000005) cout << "IMPOSSIBLE\n";
    else cout << min + 1 << '\n';
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        fill(&fire[0][0], &fire[1004][1005], -1);
        fill(&mv[0][0], &mv[1004][1005], -1);
        //fill(시작 위치, 끝나는 위치 +1, 초기화 값);
        cin >> w >> h;
        for(int j = 0; j < h; j++){
            for(int k = 0; k < w; k++){
                cin >> building[j][k];
                if(building[j][k] == '*'){
                    Q.push({j, k});
                    fire[j][k] = 0;
                }
                if(building[j][k] == '@'){
                    start_x = j; start_y = k;
                    mv[start_x][start_y] = 0;
                }
            }
        }
        BFS();
    }
}