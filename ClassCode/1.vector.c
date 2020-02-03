/*************************************************************************
	> File Name: 1.vector.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年06月30日 星期日 15时17分56秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

#define default_value(n, val) ((#n)[0] ? n + 0: val)
#define init(n) __init(default_value(n, 10))

Vector *__init(int n) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *)malloc(sizeof(int) * n);
    vec->size = n;
    vec->length = 0;
    return vec;
}

int insert(Vector *vec, int ind, int val) {
    if (vec == NULL) return 0;
    if (vec->length == vec->size) {
        if (!expand(vec)) return 0;
        printf("expand vector\n");
    }
    if (ind < 0 || ind > vec->length) return 0;
    for (int i = vec->length - 1; i > ind; i--) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[ind] = val;
    vec->length += 1;
    return 1;
}

int erase(Vector *vec, int ind) {
    if (vec == NULL) return 0;
    if (vec->length == 0) return 0;
    if (ind < 0 || ind >= vec->length - 1) return 0;
    for (int i = ind + 1; i < vec->length; i++) {
        vec->data[i - 1] = vec->data[i]; 
    }
    vec->length -= 1;
    return 1;
}

int expand(Vector *vec) {
    int new_size = vec->size *= 2;
    int *p = (int *)realloc(vec->data, sizeof(int) * vec->size);
    if (p == NULL) return 0;
    vec->size = new_size;
    vec->data = p;
    return 1;
}

int find(Vector *vec, int val) {
    if (val == NULL) return -1;
    for (int i = 0; i < vec->length; i++) {
        if (vec->data[i] == val) return i;
    }
    return -1;
}

void output(Vector *vec) {
    printf("Vector(%d) = [", vec->length);
    for (int i = 0; i < vec->length; i++) {
        if (i != 0) printf(", ");
        printf("%d", vec->data[i]);
    }
    printf(" ]\n");
    return ;
}

void output_ind(Vector *vec, int ind) {
    int flag = 0; 
    flag += printf("Vector(%d) = [", vec->length);
    for (int i = 0; i < vec->length; i++) {
        if (i != 0) flag += (i <= ind) * printf(", ");
        flag += (i <= ind) * printf("%d", vec->data[i]);
    }
    printf("]\n");
    flag -= 1;
    printf("%d\n", flag);
    for (int i = 0; i < flag; i++) {
        printf(" ");
    }
    printf("^\n");
    for (int i = 0; i < flag; i++) {
        printf(" ");
    }
    printf("|\n");
    return ;
}

void clear(Vector *vec) {
    if (vec == NULL) return;
    free(vec->data);
    free(vec);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Vector *vec = init(1);
    int op, ind, val;
    for (int i = 0; i < MAX_OP; i++){
        op = rand() % 4;
        ind = rand() % (vec->length + 2);
        val = rand() % 100;
        switch(op) {
            case 2:
            case 3:
            case 0: {
                printf("insert %d at %d to vector\n", val, ind);
                insert(vec, ind, val);
            } break;
            case 1: {
                printf("erase element at %d from vector\n", ind);
                erase(vec, ind);
            } break;
        }
        output(vec);
    }
    int search = 0;
    while (~scanf("%d", &search)) {    
        output_ind(vec, find(vec, search));
    }
    return 0;
}
