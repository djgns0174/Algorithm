#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    char title[1025];
    int rank;   // -1 means None (TBR)
} Book;

// 비교 함수 for qsort (알파벳 순)
int compareStr(const void *a, const void *b) {
    const char *str1 = *(const char **)a;  // a는 char*의 주소 → char** 로 캐스팅
    const char *str2 = *(const char **)b;  // b도 마찬가지
    return strcmp(str1, str2);
}

int main() {
    int b;
    scanf("%d", &b); fgetc(stdin);

    char new_titles[b][1025];
    for (int i = 0; i < b; i++) {
        scanf("%[^\n]", new_titles[i]); fgetc(stdin);
    }

    int n;
    scanf("%d", &n); fgetc(stdin);

    Book cur_books[n];
    int cur_count = n;

    int max_rank = -1;
    for (int i = 0; i < n; i++) {
        char rank_str[10];
        scanf("%[^\n]", cur_books[i].title); fgetc(stdin);

        // 입력 문자열 끝에 rank 있음 (마지막 공백 기준)
        char *last_space = strrchr(cur_books[i].title, ' ');
        if (last_space) {
            strcpy(rank_str, last_space + 1);
            *last_space = '\0'; // title만 남기기

            if(strcmp(rank_str, "None") == 0)
                cur_books[i].rank = -1;
            else {
                cur_books[i].rank = atoi(rank_str);
                if(cur_books[i].rank > max_rank) max_rank = cur_books[i].rank;
            }
        }
    }

    // 중복 제거: 새 책이 기존 책과 겹치면 기존 책 제거
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < cur_count; j++) {
            if(strcmp(new_titles[i], cur_books[j].title) == 0) {
                // 중복 제거: 최소 rank 책만 제거? 아니면 항상 제거
                for(int k = j; k < cur_count-1; k++) cur_books[k] = cur_books[k+1];
                cur_count--;
                j--; // 한 칸 당김
            }
        }
    }

    while(1)
    {
        int remain = n - cur_count;
        if(b <= remain) // 새책을 전부 넣을 수 있다면
        {
            int answers_size = n - remain + b;
            char* answers[n];

            for(int i=0; i<cur_count; i++)
            {
                answers[i] = cur_books[i].title;
            }

            for(int i=0; i<b; i++)
            {
                answers[cur_count+i] = new_titles[i];
            }

            qsort(answers, answers_size, sizeof(char*), compareStr);

            for(int i=0; i<answers_size; i++)
            {
                printf("%s\n", answers[i]);
            }
            return 0;
        }

        int min_rank = INT_MAX;
        for(int i=0; i<cur_count; i++) // 가장 낮은 rank찾기
        {
            if(cur_books[i].rank == -1) continue;

            if(cur_books[i].rank < min_rank)
            {
                min_rank = cur_books[i].rank;
            }
        }

        if(min_rank == max_rank || min_rank == INT_MAX) // 가장 낮은 rank가 가장 높은 rank라면    
        {
            printf("Your TBR is out of control Clara!");
            return 0;
        }
        
        else 
        {
            for(int i=0; i<cur_count; i++) // 가장 낮은 rank의 책들을 모두 삭제
            {
                if(cur_books[i].rank == min_rank) 
                {
                    for(int j=i; j<cur_count-1; j++)    // 한칸씩 땡기면서 삭제
                    {
                        cur_books[j] = cur_books[j+1];
                    }
                    
                    i--;
                    cur_count--;
                }
            }
        }
    }

    return 0;
}
