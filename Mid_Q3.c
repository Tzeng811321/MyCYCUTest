//計算機概論 期中考 第三題 考題:學生資料建檔(結構與鏈結)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //tolower toupper
#define TRUE 1
#define TEMP_PERCENT    0.30
#define MID_PERCENT     0.30
#define FINAL_PERCENT   0.40

void edit();
void display();
void write();
void flushBuffer(); 

int main()
{
    char ch;
    char id[8], name[10];
    double t_score, m_score, f_score;
	int count = 0, flag = 0;
    head = (struct student *) malloc(sizeof(struct student ));
    head->next = NULL;
    // 讀取「Input3.txt」內學生資料，依照名字英文A~Z排序(只考慮第一個英文字母) 
	if ((fptr = fopen(Input3.txt, "r")) == NULL) {
		puts("File open failed!");
		puts("Create a file!");
		if((fptr = fopen(fname, "w")) == NULL)
		    exit(1);	//非正常運行導致程式中斷
	}
    //依照名字英文A~Z排序(只考慮第一個英文字母)，且計算每位學生的平均成績並印出在終端機。
	while(fscanf(fptr, "%s %s %lf %lf %lf", id, name, &t_score, &m_score, &f_score) != EOF){
		
		/* 重新配置一ˊ的新的結構 */
		fdata_n = (struct student *) malloc(sizeof(struct student)); 
		fdata_n->next = NULL;
		/* 將檔案的資料放到結構中 */
		strcpy(fdata_n->id, id);
		strcpy(fdata_n->name, name);
		fdata_n->temp_score = t_score;	
		fdata_n->mid_score = m_score;	
		fdata_n->final_score = f_score;	

		if (flag == 0){
		  	current = fdata_n;
		 	current->next = NULL;
		  	head->next = current;
		  	flag = 1;
		}
		else { 
		  	current->next = fdata_n;
		  	current = current->next;
		}
		count++;
	}
	display();

    while (TRUE) {
	    printf("\n*****************************************");
	    printf("\n* Type 'i' to enter new student's data  *");
	    printf("\n*      'd' to delete one student's data *");
        printf("\n*      'q' to query one student's data  *");
	    printf("\n*      'm' to modify one student's data *");
	    printf("\n*      'l' to list all students' data   *");
	    printf("\n*      'e' to exit program and save     *");
	    printf("\n*****************************************");
	    printf("\nplease enter your choice : ");

        ch = tolower(getchar());
        flushBuffer();
	    switch (ch) {
	        case 'e':
			    edit();
				break;
	        case 'l' :
		        display();
		        break;
	        case 'e' :
			    write();
		        exit(0);
	        default  :
		        printf("\nPlease select one choice !\n");
	     }
    }
    return 0;
}

/**** edit function ****/
void edit(){
    //更改一位學生的資料後，依照姓名排序。
	char id[8];
	printf("\nWhich student ID do you want to modify ? ");
	scanf("%s", id);
	flushBuffer();
	current=head->next;
	while (current != NULL && strcmp(current->name, name[0]))
		current=current->next; 

	if(current ==NULL) {
		printf("Data is not found\n");
	    return;
    }
	/* input new data */
    printf("\nEnter ID            : ");
    scanf("%s", current->id);
    printf("Enter name          : ");
    scanf("%s", current->name);
    printf("Enter Temp Score    : ");
    scanf("%lf", &current->temp_score);
    printf("Enter Mid Score     : ");
    scanf("%lf", &current->mid_score);
    printf("Enter Final Score   : ");
    scanf("%lf", &current->final_score);
    flushBuffer();
}
/**** list function ****/
void display(){
	char id[8];
	double average;
	printf("\nWhich student ID do you want to query  ? ");
	scanf("%s", id);
	flushBuffer();

	current=head->next;
	while (current != NULL && strcmp(current->id, id))
		current=current->next; 

	if (current ==NULL) {
		printf("Data is not found\n");
	    return;
    }
    printf("\n\n  學號     姓名       平時成績  ");
    printf("期中成績  期末成績  學期平均");
    printf("\n  -------  ---------   ------------  ");
	printf("------  ------  --------\n");
    printf("  %-7s", current -> id);
	printf("  %-10s", current -> name);
	printf("  %-13.1f", current -> temp_score);
	printf("  %-6.1f", current -> mid_score);
	printf("  %-6.1f", current -> final_score);

    average = calaverage(current);
    printf("  %5.1f\n", average);

}
/**** write function ****/
void write(){
    //將每一位學生的資料(包含學期平均成績)輸出到「Output3.txt」
	if((fptr = fopen(Output3.txt, "w")) == NULL) {
		puts("File open failed!");
		exit(1);
	}
	current = (struct student *) malloc(sizeof(struct student));
	current->next = NULL; 
	current = head->next;
	while(current != NULL){
		fprintf(fptr, "%s %s %f %f %f\n", current->id, current->name, 
				current->temp_score, current->mid_score, current->final_score);
		current = current->next;
	}
	fclose(fptr);
}

void flushBuffer(){
	while (getchar() != '\n')
		continue; 
}