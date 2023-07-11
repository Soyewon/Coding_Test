// 백준 1463 - 1로 만들기
// https://www.acmicpc.net/problem/1463
// dp

#include <iostream>
#include <algorithm>

using namespace std;

int d[1000001]; // i를 1로 만들 때 사용하는 연산횟수 최솟값 d[i]
int n;

void dp(int n) {
    for(int i=2; i<=n; i++) {
        d[i] = d[i-1] + 1; // 1을 뺄 때
        if(i%2 == 0)
            d[i] = min(d[i], d[i/2]+1);
        if(i%3 == 0)
            d[i] = min(d[i], d[i/3]+1);
    }
}

int main() {
    cin >> n;
    d[1] = 0;

    dp(n);

    cout << d[n];
}
