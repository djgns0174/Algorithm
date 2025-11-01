#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 256

int doll_stack[STACK_SIZE];
int doll_top = -1;

int sum_stack[STACK_SIZE];
int sum_top = -1;

void reset_stacks() {
    doll_top = -1;
    sum_top = -1;
}

void push_doll(int val) { doll_stack[++doll_top] = val; }
int pop_doll() { return doll_stack[doll_top--]; }
int peek_doll() { return doll_stack[doll_top]; }
int is_doll_empty() { return doll_top == -1; }

void push_sum(int val) { sum_stack[++sum_top] = val; }
int pop_sum() { return sum_stack[sum_top--]; }
void peek_add_sum(int val) { sum_stack[sum_top] += val; }

int solve() {
    char line[260];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return -1;
    }

    line[strcspn(line, "\n")] = 0;

    int tokens[STACK_SIZE];
    int num_tokens = 0;
    char *endptr;
    long val;

    char *token = strtok(line, " ");
    while (token != NULL) {
        val = strtol(token, &endptr, 10);

        if (*endptr != '\0') return -1;
        if (val == 0) return -1;
        if (val < -200 || val > 200) return -1;

        if (num_tokens >= STACK_SIZE) return -1;
        tokens[num_tokens++] = (int)val;
        token = strtok(NULL, " ");
    }

    if (num_tokens == 0) {
        return -1;
    }

    reset_stacks();
    int solid_dolls = 0;

    for (int i = 0; i < num_tokens; i++) {
        int current_val = tokens[i];

        if (current_val < 0) {
            int size = -current_val;
            push_doll(size);
            push_sum(0);
        } else {
            int size = current_val;

            if (is_doll_empty()) {
                return -1;
            }
            if (peek_doll() != size) {
                return -1;
            }

            int popped_size = pop_doll();
            int popped_sum = pop_sum();

            if (popped_sum >= popped_size) {
                return -1;
            }

            if (popped_sum == 0) {
                solid_dolls++;
            }

            if (!is_doll_empty()) {
                peek_add_sum(popped_size);
            } else {
                if (i != num_tokens - 1) {
                    return -1;
                }
            }
        }
    }

    if (!is_doll_empty()) {
        return -1;
    }

    return solid_dolls;
}

int main() {
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", solve());
    }

    return 0;
}
