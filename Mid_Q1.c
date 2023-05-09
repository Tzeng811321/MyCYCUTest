//計算機概論 期中考 第一題 考題:資料讀取與矩陣運算
#include <stdio.h>

int main() 
{
    //讀取Input1.txt資料
    FILE *file = fopen("Input1.txt","r");
    if (file == NULL){
        printf("無法開啟檔案\n");
        return 1;
    }
    //提示:int meow; fscanf(file,"%d",&meow);
    int meow;
    int m[4][3], mt[3][4];
     
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (fscanf(file, "%d ", &m[i][j]) != 1) {
                printf("读取文件错误\n");
                fclose(file);
                return 1;
            }
        }
    }
    printf("原始矩陣(A)：\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }

    printf("轉換後矩陣(B)：\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mt[j][i] = m[i][j];
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%2d ", mt[i][j]);
        }
        printf("\n");
    }
    

    printf("計算結果(C)：\n");
    int arrc[4] = {4,3,2,1};
    int ccc[3], sum = 0;
    for (int  i = 0; i < 3; i++)
    {
        for (int  j = 0;  j < 4; j++)
        {
            sum += mt[i][j] * arrc[j];
        }
        ccc[i] = sum;
        sum = 0;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", ccc[i]);
    }
    
    
    //輸出最後運算結果至Output1.txt資料
    file = fopen("Output1.txt", "w");
    if (file == NULL){
        printf("無法開啟\n");
        return 1;
    }
    for (int i = 0; i < 3; i++){
        fprintf(file,"%d\n",ccc[i]);
    }
    fclose(file);

    return 0;
}
