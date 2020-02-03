/*************************************************************************
	> File Name: 单链表转置.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月06日 星期二 10时41分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    int length;
} LinkedList;

Node *init_node(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}

LinkedList *init_linkedlist() {
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(LinkedList *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    Node *p = &(l->head), *node = init_node(val);
    while (ind--) {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

LinkedList reverse(LinkedList head) {
    Node *p, *q, ret;
    ret = head;
    p = &(head.next);
    while (p != NULL) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear_linkedlist(LinkedList *l) {
    if (l == NULL) return ;
    Node *p = *(l->head.next), *q;
    while (p != NULL) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l);
    return ;
}

void output(LinkedList head) {
    int len = 0;
    Node *p = head;
    if (p) { 
        printf("%c", p->data);
        p = p->next;           
    }
    while (p) {
        printf(" %c", p->data);
        p = p->next;      
    }
    printf("\n");
}

int main() { 
    LinkedList *l = init_linkedlist();
    Node *p;
    int n, c;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%c", &c);
        if (i != n - 1) {
            scanf(" ");
        }
        ret = insert(l, i, c);
        if (ret.data == 0) {
            printf("ERROR\n");
            return 1;
        }
        l = ret.next;
    }
    l = reverse(l);
    output(l);
    clear_linkedlist(l);
    return 0;
}
