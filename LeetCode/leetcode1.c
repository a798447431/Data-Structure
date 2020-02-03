/*************************************************************************
	> File Name: leetcode1.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月12日 星期一 16时29分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target){
    int *returnSize = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                returnSize[0] = i;
                returnSize[1] = j;
                return returnSize; 
            }
        }
    }
    return returnSize;
}

int main() {
    int nums[4] = {2 , 5, 11, 15};
    int target = 9;
    int *returnSize = twoSum(nums, 4, target);
    printf("1 : %d 2: %d", returnSize[0], returnSize[1]);
    return 0;
}

