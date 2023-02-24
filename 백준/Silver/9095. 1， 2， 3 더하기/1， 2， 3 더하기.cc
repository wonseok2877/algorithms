/*
# 문제 재정의
 DP 문제. 점화식 찾자!
# 계획
 1. 테이블 정의
    D[i] = i 를 1,2,3의 합으로 나타내는 방법의 수
 2. 점화식 찾기
    D[4] = ?...
    1+1+1+1, 3+1, 2+1+1, 1+2+1  --> 3을 나타내는 방법 +1 = D[3]
    1+1+2, 2+2                  --> 2를 나타내는 방법 +2 = D[2]
    1+3                         --> 1을 나타내는 방법 +3 = D[1]

    => D[i] = D[1] + ... + D[i-1]
 3. 초기값 정하기
    D[1]=1, D[2]=2, D[3]=4
# 복잡도 검증
# 회고
*/
#include <bits/stdc++.h>
using namespace std;

int t,n;
int D[12]; // 점화식 배열

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;

    D[1] = 1, D[2] = 2, D[3] = 4; // 초기값

    for (int i = 4; i < 11; ++i) {// 배열 채우기
        D[i] = D[i - 1] + D[i - 2] + D[i - 3];
    }

    while (t--) {
        cin >> n;
        cout << D[n] << '\n';
    }
}