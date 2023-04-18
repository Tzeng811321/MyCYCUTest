#include <stdio.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int nums[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &nums[i]);
    }

    qsort(nums, 10, sizeof(int), cmp);

    int evens[10], odds[10];
    int even_count = 0, odd_count = 0;

    for (int i = 0; i < 10; i++) {
        if (nums[i] % 2 == 0) {
            evens[even_count++] = nums[i];
        } else {
            odds[odd_count++] = nums[i];
        }
    }

    qsort(evens, even_count, sizeof(int), cmp);
    qsort(odds, odd_count, sizeof(int), cmp);
    for (int i = 0; i < even_count; i++) {
        printf(" %d", evens[i]);
    }
    for (int i = odd_count - 1; i >= 0; i--) {
        printf(" %d", odds[i]);
    }
    printf("\n");

    return 0;
}
