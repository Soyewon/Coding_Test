#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int st = 0;
    int en = 0;
    int cnt = 0;
    int sum = 0;
    int arr[10001];

    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> arr[i];

    while(st<n)
    {
        if(sum >= m)
        {
            sum -= arr[st];
            st++;
        }
        else
        {
            sum += arr[en];
            en++;
        }
        if(sum == m)
            cnt++;
    }

    cout << cnt;
    return 0;

}