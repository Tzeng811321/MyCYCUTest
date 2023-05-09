//計算機概論 期中考 第二題 考題:排序 (12數，特殊規則）
#include <stdio.h>

int main() 
{
    //讀取Input2.txt資料。
    FILE *file = fopen("Input1.txt","r");
    if (file == NULL){
        printf("無法開啟檔案\n");
        return 1;
    }
    for (i = 0; i < 12; i++) {
        if (fscanf(file, "%d", &numbers[i]) != 1) {
            printf("讀取檔案錯誤\n");
            fclose(inputFile);
            return 1;
        }
        fclose(file);

    //排序規則︰奇數在前，從大到小；偶數在後，從小到大。(用底線分隔)
    void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void oddEvenSort(int arr[], int size) {
    int i, j;

    // 對奇數部分進行遞減冒泡排序
    for (i = 1; i < size; i += 2) {
        for (j = 1; j < size - i; j += 2) {
            if (arr[j] < arr[j + 2]) {
                swap(&arr[j], &arr[j + 2]);
            }
        }
    }

    // 對偶數部分進行遞增冒泡排序
    for (i = 0; i < size; i += 2) {
        for (j = 0; j < size - i - 2; j += 2) {
            if (arr[j] > arr[j + 2]) {
                swap(&arr[j], &arr[j + 2]);
            }
        }
    }
}
    //輸出最後運算結果至Output2.txt資料。
    
    return 0;
}