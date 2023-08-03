#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define MAX 100001

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<pair<int, int>> meet; // 회의 시간 저장용
    priority_queue<int, vector<int>, greater<int>> pq; // 작은순 우선정렬
    int room = 1; // 회의실 무조건 하나 이상.
    int res = 0;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        int first, second;
        cin >> first >> second; // first: 회의시작시간 second: 회의종료시간
        meet.push_back({first, second});
    }

    sort(meet.begin(), meet.end()); // 시작시간 순으로 정렬

    pq.push(meet[0].second); // 제일 처음 시작하는 회의의 끝나는 시간 push

    for(int i=1; i<n; i++)
    {
        while(!pq.empty() && pq.top() <= meet[i].first) 
        {
            // 큐가 비어있지 않고, 큐에 들어있는 회의의 끝나는 시간이 다음 회의의 시작시간보다 작거나 같을 시
            pq.pop(); // 회의가 이어질 때는 pop, 이어지지 않을 때는 push된다.
            room -= 1;
        }
        pq.push(meet[i].second);
        room += 1;

        res = max(res, room);
    }
    cout << res;
    return 0;
}