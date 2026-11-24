# 코딩 문제 - 햄버거 만들기
[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/133502)

## 문제 풀이
### 시도
1. solution 함수 내에서 ingredient 배열을 순회한다.
2. for문의 i가 3 이상일 때, ingredient의 i, i-1, i-2,i-3 인덱스에 위치한 값을 비교한다.
3. 만약, 각 순서대로 1,3,2,1의 값이 나온다면 answer에 1을 더한다.
	1. ingredient에서 검사한 인덱스 부분을 제거한다.
	2. i를 -1로 재설정한다.
	3. for문의 시작 지점에서 size를 ingredient.size()로 재설정한다.
4. i의 값이 ingredient의 크기를 넘어가거나 순회를 끝마치면 answer을 반환한다.

```C++
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int size = ingredient.size();

    for (int i = 0; i < size; i++)
    {
        size = ingredient.size();

        if (i >= size)
            return answer;

        if (i - 3 < 0)
            continue;

        if (ingredient[i] == 1     &&
            ingredient[i - 1] == 3 &&
            ingredient[i - 2] == 2 &&
            ingredient[i - 3] == 1)
        {
            answer++;

            ingredient.erase(ingredient.begin() + (i - 3), ingredient.begin() + i);
            i = -1;
        }
    }

    return answer;
}
```

### 기존 시도의 문제점
- erase()의 삭제 범위 오류
- erase() 실행 과정에서 뒤에 있는 원소들을 앞으로 이동시켜야 하기에 시간 복잡도가 O(N^2)에 가까워진다. 시간 초과가 발생할 가능성이 있다.
- i = -1로 인해 불필요한 탐색을 실행한다.

### 개선
**AI를 사용하여 개선 방안을 찾았다.**
1. for문으로 ingredient를 순회한다.
2. stack에 ingredient의 요소를 순차적으로 넣는다.
3. 만약 stack에서 stackTop, stackTop-1, stackTop-2, stackTop-3이 각각 1,3,2,1이라면 해당 범위의 값을 제거하고, 나머지 값은 남긴다.
	1. answer을 1증가시킨다.
4. 순회가 끝나면 answer을 반환한다.