#include <iostream>

// 시간복잡도 주의 !!
using namespace std;

#define MAX 2000001

int n;
int arr[MAX];
int x;
int res = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int tmp;

    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        arr[tmp] = 1; // 배열에 있는 숫자인지 여부
    }

    cin >> x;

    for(int i=1; i<(x+1)/2; i++)
    {
        if(arr[i]==1 && arr[x-i]==1) 
            res++;
    }

    cout << res;
    return 0;
}