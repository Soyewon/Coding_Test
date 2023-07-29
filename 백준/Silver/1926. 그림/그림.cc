#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; // 세로, 가로
    int board[501][501]; // 그림 값 저장
    bool visit[501][501]; // 방문 여부
    int picNum = 0; // 그림 개수
    int colored; // 그림 당 색칠된 칸 개수
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> q;
    int res = 0; // 색칠된 칸 최대
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            // 색칠된 칸이고, 방문한 적이 없을 때
            if(board[i][j]==1 && !visit[i][j])
            {    
                q.push({i, j});
                visit[i][j] = true;
                picNum++;
                colored = 0;

                while(!q.empty())
                {
                    pair<int, int> now = q.front();
                    q.pop();
                    colored++;

                    for(int i=0; i<4; i++)
                    {
                        int nx = now.first + dx[i];
                        int ny = now.second + dy[i];

                        // 범위를 벗어났을 때
                        if(nx <0 || nx>=n || ny<0 || ny>=m)
                            continue;
                        // 색칠이 안된 칸이거나, 이미 방문한 적이 있을 때
                        if(board[nx][ny]==0 || visit[nx][ny])
                            continue;
                        
                        // 색칠이 되어있고, 방문한 적이 없으며 범위 내에 있을 때
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            res = max(res, colored);
        }
    }

    cout << picNum << '\n' << res;
    return 0;

}