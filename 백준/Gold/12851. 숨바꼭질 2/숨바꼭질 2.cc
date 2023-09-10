#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
bool check = true; // 처음으로 위치가 같은지
int visit[100003] = { 0 };
int result = 100003;
int resultNum = 0;

void bfs(int a, int b) {

    queue<pair<int, int>> q;
    q.push(make_pair(a,b)); // (위치, 시간)
    visit[a] = true; 
 
    while(!q.empty()){ // 큐가 빌 때까지

        int cur = q.front().first; 
        int time = q.front().second;
        q.pop();
 
        visit[cur] = true; // pop 후 방문 처리
        // 다른 방법(위치 및 시간 동일) 
        if(!check && result == time && cur == k){
            resultNum++; // 카운트
        }
        // 처음으로 동생과 위치 및 시간이 동일할 때
        if(check && cur == k){ 
            result = time; // 최소 시간 저장
            check = false; // 처음 방문 여부 false로
            resultNum++; // 카운트
        }
 
        // 한칸 +1, -1 걷기
        if(cur+1 < 100001 && cur+1 >= 0 && !visit[cur+1]){ // +1
            q.push(make_pair(cur + 1, time + 1)); 
        }
        if(cur-1 < 100001 && cur-1 >= 0 && !visit[cur-1]){ // -1 
            q.push(make_pair(cur - 1, time + 1));
        }
        if(cur*2 < 100001 && cur*2 >= 0 && !visit[cur*2]){
            // 순간이동 *2
            q.push(make_pair(cur * 2, time + 1));
        }
    }
}
int main(){
    cin >> n >> k;
 
    bfs(n, 0);
    cout << result << endl; // 걸리는 최소 시간
    cout << resultNum << endl; // 방법 개수
    return 0;
}
