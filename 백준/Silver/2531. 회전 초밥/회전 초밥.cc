#include <iostream>
#include <queue>

using namespace std;

// 연속적k개 -> 할인된 정액 가격 제공
// 초밥종류 쿠폰 1개 -> 연속k개 먹을 경우 해당 초밥1개 무료 제공
// 벨트에 없으면 새로 만들어 제공

// 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; // 접시 수
    int d; // 초밥 가짓수
    int k; // 연속해서 먹는 접시 수
    int c; // 쿠폰 번호
    int sushi[3001]; // 스시 종류 각 몇개인지 저장용
    int plate[30001];

    cin >> n >> d >> k >> c;
    
    for(int i=0; i<n; i++)
    {    
        cin >> plate[i];
    }

    int res = 0;
    for(int st=0; st<n; st++)
    {
        int cnt = 0;
        for(int i=0; i<k; i++)
        {
            if(st+i>=n)
            {
                int tmp = st+i-n;
                if(sushi[plate[tmp]]==1)
                    continue;
                else
                {
                    sushi[plate[tmp]]=1;
                    cnt++;
                }
            }
            else
            {
                if(sushi[plate[st+i]]==1) // 이미 먹은 종류의 초밥이라면
                    continue;
                else // 처음 먹는 종류라면
                {
                    sushi[plate[st+i]]=1;
                    cnt++;
                }
            }
        }
        if(sushi[c]==0) cnt++;
        res = max(res, cnt);
        fill(sushi, sushi+3001, 0);
    }
    cout << res;
    return 0;
}