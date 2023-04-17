#include <stdio.h>

int main() {
    int N, score, min_pass = 101, max_fail = -1;
    int scores[30];

    scanf("%d", &N);

    // 讀入 N 個分數
    for (int i = 0; i < N; i++) {
        scanf("%d", &score);
        scores[i] = score;

        // 更新最低及格分數
        if (score >= 60 && score < min_pass) {
            min_pass = score;
        }

        // 更新最高不及格分數
        if (score < 60 && score > max_fail) {
            max_fail = score;
        }
    }

    // 對分數進行排序（選擇排序）
    for (int i = 0; i < N - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < N; j++) {
            if (scores[j] < scores[min_index]) {
                min_index = j;
            }
        }
        int temp = scores[i];
        scores[i] = scores[min_index];
        scores[min_index] = temp;
    }

    // 輸出成績排序
   for (int i = 0; i < N; i++) {
   	  printf("%d", scores[i]);
    	  if (i != N - 1) printf(" ");
     }
	printf("\n");

    // 輸出最高不及格分數
    if (max_fail == -1) {
        printf("best case\n");
    } else {
        printf("%d\n", max_fail);
    }

    // 輸出最低及格分數
    if (min_pass == 101) {
        printf("worst case\n");
    } else {
        printf("%d\n", min_pass);
    }

    return 0;
}