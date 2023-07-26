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

    /*for(int st=0; st<n; st++)
    {
        int strLen = 0;
        int en = st+1;
        while(st<en && en<n)
        {
            if(check[a[en]]<k)
            {
                check[a[en]]++;
                strLen++;
                en++;
                continue;
            }
            else
                break;
        }
        res = max(res, strLen);
        fill(check, check+MAX, 0);
    }*/

    int st = 0;
    int en = 0;
    
    while(st<=en && en<n)
    {
        if(check[a[en]]<k)
        {
            check[a[en]]++;
            en++;
        }
        else
        {
            check[a[st]]--;
            st++;
        }
        res = max(res, en-st);
    }

    cout << res;
    return 0;
}