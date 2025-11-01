#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARR 200
#define MAX_LEN 200

typedef struct {
    char name[20];
    int l, r;
    int v[200];
} ARR;

ARR arrs[MAX_ARR];
int arr_cnt = 0;

int func(char *s);

int func_index(char *s)
{
    if ( (s[0]=='-') || (s[0]>='0' && s[0]<='9') )
        return atoi(s);

    return func(s);
}

int func(char *s)
{
    char name[20], idx[200];
    int i, p1=0, p2=0;

    while(s[p1] && s[p1] != '[') p1++;
    strncpy(name, s, p1);
    name[p1] = 0;

    p2 = strlen(s)-1;
    strncpy(idx, s+p1+1, p2-(p1+1));
    idx[p2-(p1+1)] = 0;

    int realIndex = func_index(idx);

    for(i=0;i<arr_cnt;i++){
        if(strcmp(arrs[i].name, name)==0){
            return arrs[i].v[ realIndex - arrs[i].l ];
        }
    }
    return 0; 
}

int main(void)
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        char def[100];
        char eq[5];
        int L,R,i;
        scanf("%s", def); 

        
        char *p1 = strchr(def, '[');
        char *p2 = strstr(def, "..");
        char *p3 = strchr(def, ']');

        char arrName[20];
        strncpy(arrName, def, p1-def);
        arrName[p1-def] = 0;

        char tmp[20];
        strncpy(tmp, p1+1, p2-(p1+1));
        tmp[p2-(p1+1)] = 0;
        L = atoi(tmp);

        strncpy(tmp, p2+2, p3-(p2+2));
        tmp[p3-(p2+2)] = 0;
        R = atoi(tmp);

        scanf("%s", eq); // =

        ARR *a = &arrs[arr_cnt++];
        strcpy(a->name, arrName);
        a->l = L; a->r = R;

        int len = R-L+1;
        for(i=0;i<len;i++) scanf("%d", &a->v[i]);
    }

    char query[200];
    scanf("%s", query);

    printf("%d\n", func(query));
    return 0;
}
