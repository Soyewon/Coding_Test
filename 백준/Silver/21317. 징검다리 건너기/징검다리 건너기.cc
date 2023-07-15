#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
#define MAX 987654321;

int n, k; // 돌의 개수, 매우 큰 점프 에너지
pair<int, int> jump[21];
int energy[21][2]; // energy[i][] : i번째 돌까지 가는데 사용한 최소에너지
// energy[i][0] : 큰 점프 아직 안 했을 때. energy[i][1] : 큰 점프 했을 때

void dp()
{
    for(int i=1; i<=n; i++)
    {
        energy[i][0] = MAX;
        energy[i][1] = MAX;
    }

    energy[1][0] = 0;
    energy[2][0] = jump[1].first;
    energy[3][0] = min(jump[1].first + jump[2].first, jump[1].second);

    for(int i=4; i<=n; i++)
    {
        energy[i][0] = min(energy[i-1][0] + jump[i-1].first, energy[i-2][0]+jump[i-2].second);
        int temp = min(energy[i-1][1] + jump[i-1].first, energy[i-2][1] + jump[i-2].second);
        energy[i][1] = min(temp, energy[i-3][0] + k );
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int small, big;
    for(int i=1; i<n; i++)
    {   
        cin >> small >> big;
        jump[i] = make_pair(small, big);
    }
    cin >> k;

    dp();
    int res = min(energy[n][0], energy[n][1]);
    cout << res;

    return 0;
}