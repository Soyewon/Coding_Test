#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 100001

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; // K: 연속된 수 제한개수
    int a[200001];
    int check[MAX];
    int res = 0;

    cin >> n >> k;

    for(int i=0; i<n; i++)
        cin >> a[i];
    
    // 3 2 5 5 6 4 4:7개
    // 2 5 5 6 4 4 : 6개
    // 5 5 6 4 4 : 5개
    // 5 6 4 4 5 7: 6개

    int st = 0;
    int en = 0;
    int strLen = 0;
    while(st<n && en<n && st<=en)
    {
        if(check[a[en]]<k) // 숫자가 k개보다 적게 쓰인 경우
        {
            check[a[en]]++;
            en++;
            strLen++;
        }
        else // 숫자가 k개 이상 쓰인 경우
        {
            check[a[st]]--;
            st++;
            strLen--;
        }
        res = max(res, strLen);
    }

    cout << res;
    return 0;
}