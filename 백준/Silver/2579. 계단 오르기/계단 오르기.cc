/*
# 문제 재정의
 DP 문제. 점화식 찾자!
# 계획
 1. 테이블 정의
    D[i][j] = 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을때 점수합의 최댓값, 단 i번째 계단은 반드시 밟아야 함. 그래서 j= 1 OR 2. 3이상이 되면 규칙 위반
 2. 점화식 찾기
    어디까지나 점화식만 이끌어내는게 목표이기 때문에, k-2번째 밑으로 내려갈 필요가 없다.
    D[k][1] = max( D[k-2][1], D[k-2][2] ) + S[k]
    D[k][2] = D[k-1][1] + S[k]
    k-1번째 계단을 밟은 순간에는 1개의 계단을 연속해서 밟은 상태여야 한다. 만약 2개라면 규칙 때문에 k번째 계단을 밟는게 불가능하니까.

 3. 초기값 정하기
    D[1][1]=S[1], D[1][2]=0, D[2][1]= S[2], D[2][2] = S[1] + S[2], D[3][1] = D[1] + S[3], D[3][2] = D[2][1] + S[3]
# 복잡도 검증
# 회고
 - 연속된 3계단을 모두 밟아서는 안된다는 제약조건 때문에 점화식 세우는게 어려움.
 따라서 기존의 D[i] 방법은 이 문제를 풀기에 적절하지 않다.
 왜 2차원 배열 D[i][j]를 써야 하는가? --> 지금까지 몇 개의 계단을 밟았는지에 대한 정보가 추가로 있어야 점화식을 세울 때 계단을 오르는 규칙을 고려할 수 있기 때문.
 - 이렇게 문제의 제약조건이나 경우의 수를 2차원 배열로 나타낼 수 있다는걸 배웠다.
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int S[302];  // 계단 배열
int D[302][3]; // 점화식 배열

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> S[i];
    }

    if (n == 1) {// CONDITION: n=1일때
        cout << S[1];
        return 0;
    }

    // 초기값
    D[1][1] = S[1];
    D[1][2] = 0;
    D[2][1] = S[2];
    D[2][2] = S[1] + S[2];
    
    for (int i = 3; i <= n; ++i) {// DP : 계단에 대한 점화식
        D[i][1] = max( D[i-2][1], D[i-2][2] ) + S[i];
        D[i][2] = D[i-1][1] + S[i];
    }

    cout << max(D[n][1], D[n][2]);
}