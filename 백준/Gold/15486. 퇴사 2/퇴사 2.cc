#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
#define MAX 1500001

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    pair<int, int> work[MAX];
    int dp[MAX]; // [i-1]번째 일까지 일해서 i일에 벌어놓은 최대 이익

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> work[i].first >> work[i].second; // first: 상담일수, second: 돈
    }

    int maxMoney = 0;
    int res = 0;
    for(int i=0; i<=n; i++)
    {
        maxMoney = max(maxMoney, dp[i]);
        int nowDate = i;
        if(work[i].first + nowDate <= n)
        {
            dp[i+work[i].first] = max(work[i].second + maxMoney, dp[i+work[i].first]);
            res = max(res, dp[i+work[i].first]);
        }
    }
    cout << res;
    return 0;

}