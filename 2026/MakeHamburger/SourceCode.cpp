#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int size = ingredient.size();

    vector<int> stack(0);

    for (int i = 0; i < size; i++)
    {
        stack.push_back(ingredient[i]);

        int stackTop = stack.size() - 1;

        if (stackTop <= 2)
            continue;

        if (
            stack[stackTop] == 1 &&
            stack[stackTop - 1] == 3 &&
            stack[stackTop - 2] == 2 &&
            stack[stackTop - 3] == 1
            )
        {
            answer++;
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
        }
    }

    return answer;
}