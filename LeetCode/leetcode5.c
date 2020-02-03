/*************************************************************************
	> File Name: leetcode5.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月21日 星期三 11时35分35秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

char *longestPalindrome(char *s) {
    if (strlen(s) == 0) return NULL;
    int start = 0, end = 0;
    for (int i = 0; i < strlen(s); i++) {
        int len1 = expandaroundcenter(s, i, i);
        int len2 = expandaroundcenter(s, i, i + 1);
        int len = max(len1, len2);
        if (len > end - start) {
            start = i - ((len - 1) >> 1);
            end = i + (len >> 1);
        }
    }
    char *p = malloc(sizeof(char) * (end - start + 2));
    strncpy(p, s + start, end - start + 1);
    p[end - start + 1] = '\0';
    return p;
}

int expandaroundcenter(char *s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < strlen(s) && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
} 

int main() {
    char *str = (char *)malloc(sizeof(char) * 1000);
    scanf("%s", str);
    printf("%s\n", longestPalindrome(str));
    return 0;
}
