#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
#define MAX 100001

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    pair<int, int> sch[MAX];

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> sch[i].second >> sch[i].first; // first: 끝나는시간 second: 시작시간
    }

    sort(sch, sch+n); // 끝나는 시간순 정렬

    int res = 0;
    int t = 0;

    for(int i=0; i<n; i++)
    {
        if(t>sch[i].second) // 현재 시간이 시작시간보다 크다면 해당 회의 사용불가
            continue;
        else
        {
            res++; // 회의 추가
            t = sch[i].first; // 회의 끝난시간
        }

    }

    cout << res;
}