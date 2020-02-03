/*************************************************************************
	> File Name: ac.automaton1.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月21日 星期三 10时56分29秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 26;
const char BASE = 'a';
const int MAX_SIZE = 100005;

typedef struct TrieNode {
    int count;
    struct TrieNode **next;
    struct TrieNode *fail;
} TrieNode, *Trie;

TrieNode* new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->next = (TrieNode **)malloc(SIZE * sizeof(TrieNode *));
    memset(p->next, 0, SIZE * sizeof(TrieNode *));
    p->fail = NULL;
    p->count = 0;
    return p;
}

void clear(Trie tree) {
    if (!tree) return ;
    for (int i = 0; i < SIZE; i++) {
        if (tree->next[i] == NULL) continue;
        clear(tree->next[i]);
    }
    free(tree);
}

void insert(Trie tree, char *str) {
    TrieNode *p = tree;
    while (*str) {
        if (p->next[str[0] - BASE] == NULL) {
            p->next[str[0] - BASE] = new_node();
            ++(tree->count);
        }
        p = p->next[str[0] - BASE];
        ++str;
    }
    p->count += 1;
}

void build_automaton(Trie root) {
    TrieNode **q = (TrieNode **)malloc((root->count + 1) * sizeof(TrieNode *));
    TrieNode *p, *now;
    root->fail = NULL;
    int head = 0, tail = 0;
    q[tail++] = root;
    while (head < tail) {
        p = q[head++];
        for (int i = 0; i < SIZE; i++) {
            if (p->next[i] == NULL) continue;
            now = p->fail;
            while (now != NULL && now->next[i] == NULL) {
                now = now->fail;
            }
            if (now == NULL) {
                p->next[i]->fail = root;
            } else {
                p->next[i]->fail = now->next[i];
            }
            q[tail++] = p->next[i];
        }
    }
    free(q);
}

int match_count(Trie root, char *str) {
    TrieNode *p = root, *now;
    int total_count = 0;
    while (*str) {
        while (p && p->next[str[0] - BASE] == NULL) {
            p = p->fail;
        }
        if (p == NULL) {
            p = root;
        } else {
            p = p->next[str[0] - BASE];
        }
        now = p;
        while (now != root) {
            total_count += now->count;
            now = now->fail;
        }
        ++str;
    }
    return total_count;
}

int main() {
    char *str = (char *)malloc(MAX_SIZE * sizeof(char));
    Trie root = new_node();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    build_automaton(root);
    scanf("%s", str);
    printf("%d\n", match_count(root, str));
    clear(root);
    free(str);
    return 0;
}
