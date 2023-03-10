/*
# 문제 재정의
 경우의수 문제.
 3갈래(-1, +1, *2)로 쪼개지는 상태공간트리
 특정 포인트가 정해진 경우의 수
# 계획
 상태공간트리를 구현하기 위해 BFS식으로 로직을 짜면 되겠다.

 BFS LOOP(큐가 공백이 아닌동안):
    dequeue -> {value,count}
    IF(value == K): count 출력 후 종료
    IF(value <0 || value >100000): continue
    3가지에 대해 enqueue {value+1, count+1} {value-1, count+1} {value*2, count+1}

 Q. pair가 아니라 배열에 저장하는 방법은 없을까? 효율적이긴 한데...흠
 메모리 초과 때문에 pair을 쓰면 안될것 같다.
 COUNTING 배열을 쓰자.

# 복잡도 검증
 3갈래 상태공간트리이므로
 동생을 찾는 시간이 n이라고 할 때 O(3^n)
# 회고
 - 특정 포인트가 정해진 경우의 수는 BFS가 유리하다.
 - 메모리 초과. pair가 10byte라고 할 때 3^n * 10byte면.. n이 15라면 대략 150MB. 128MB조건 불만족
 - 배열 OutOfBounds 주의하자.
 - 무조건 100000안에서만 놀거라고만 생각하면 안 된다! 이문제는 ㄱㅊ
*/


#include <bits/stdc++.h>
using namespace std;
#define V first
#define C second

int N,K;
int cnt[100001]; // COUNT
queue<int> Q; // BFS Queue

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    Q.push(N); // 상태공간트리 루트 enqueue
    cnt[N] = 1;

    while (cnt[K] == 0) {
        int cur = Q.front();
        Q.pop(); // dequeue

        for (int nxt : {cur-1, cur+1, cur*2})// RANGE LOOP: 3가지 경우의 수 enqueue
            if (nxt >= 0 && nxt <= 100000 && cnt[nxt] == 0 ) {
                Q.push(nxt);
                cnt[nxt] = cnt[cur] + 1;
            }
    }
    cout << cnt[K] -1;
}