#include <stdio.h>
#include <string.h>

struct Account {
    char name[8];
    int age;
    int income;
};

void swap(struct Account *a, struct Account *b) {
    struct Account temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct Account accounts[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (accounts[j].age > accounts[j+1].age || 
                (accounts[j].age == accounts[j+1].age && accounts[j].income > accounts[j+1].income)) {
                swap(&accounts[j], &accounts[j+1]);
            }
        }
    }
}

int main() {
    struct Account accounts[5];
    int i;

    // 使用者輸入五筆資料
    for (i = 0; i < 5; i++) {
        scanf("%s", accounts[i].name);
        scanf("%d", &accounts[i].age);
        scanf("%d", &accounts[i].income);
    }

    // 將資料依年紀排序
    sort(accounts, 5);

    // 輸出資料表格
    printf("username  age  salary\n");
    for (i = 0; i < 5; i++) {
        printf("%8s%5d%8d\n", accounts[i].name, accounts[i].age, accounts[i].income);
    }

    return 0;
}