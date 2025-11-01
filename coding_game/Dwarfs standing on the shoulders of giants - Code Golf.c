#include <stdio.h>

#define MAX 1000

typedef struct {
    int first;
    int second;
} Pair;

int N;
Pair arr[MAX];
int answer = -1;

int max(int a, int b) {
    return a > b ? a : b;
}

void func(int first, int depth) {
    if (depth > answer)
        answer = depth;

    for (int i = 0; i < N; i++) {
        if (arr[i].first == first) {
            func(arr[i].second, depth + 1);
        }
    }
}

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }

    for (int i = 0; i < N; i++) {
        func(arr[i].second, 2);
    }

    printf("%d\n", answer);

    return 0;
}
