/* ch13 13.2c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //tolower toupper
#define TRUE 1
#define TEMP_PERCENT    0.30
#define MID_PERCENT     0.30
#define FINAL_PERCENT   0.40

struct student {
    char id[8]; /* 學號 */
    char name[10]; /* 姓名 */
    double temp_score; /* 平時 */
    double mid_score; /* 期中 */
    double final_score; /* 期末 */
    struct student *next;
};

struct student  *head, *prev, *current, *ptrnew, *fdata_n;
FILE *fptr;
char fname[20];
void insert();
void del();
void query();
void modify();
void display();
void write();
void flushBuffer(); 
double calaverage(struct student *);

int main()
{
    char ch;
    int count = 0, flag = 0;
    char id[8], name[10];
    double t_score, m_score, f_score;
    head = (struct student *) malloc(sizeof(struct student ));
    head->next = NULL;

    printf("please input a file name: ");
	scanf("%s", &fname);
	flushBuffer();
	/* 讀入檔案 */
	if ((fptr = fopen(fname, "r")) == NULL) {
		puts("File open failed!");
		puts("Create a file!");
		if((fptr = fopen(fname, "w")) == NULL)
		    exit(1);
	}
	while (fscanf(fptr, "%s %s %lf %lf %lf", 
		id, name, &t_score, &m_score, &f_score) != EOF)
	{
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
	printf("There are %d records in the %s file!", count, fname);
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
	        case 'i' :
		        insert();
		        break;
	        case 'd' :
		        del();
		        break; 
		    case 'q':
                query();
                break;  
		    case 'm':
			    modify();
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

/**** insert function ****/
void insert()
{
    ptrnew = (struct student *) malloc(sizeof(struct student ));
    /* head is always empty */
    /* add a node to list front */
    printf("\nEnter ID            : ");
    scanf("%s", ptrnew -> id);
    printf("Enter name          : ");
    scanf("%s", ptrnew -> name);
    printf("Enter Temp Score    : ");
    scanf("%lf", &ptrnew -> temp_score);
    printf("Enter Mid Score     : ");
    scanf("%lf", &ptrnew -> mid_score);
    printf("Enter Final Score   : ");
    scanf("%lf", &ptrnew -> final_score);
    flushBuffer();
	 
    /* insert algorithm */
    ptrnew->next=head->next;
    head->next = ptrnew;
}

/**** delete function ****/
void del()
{
    char id[8];
    double average;
    printf("\nWhat student ID do you want to delete ? ");
    scanf("%s", id);
    flushBuffer(); 
    prev=head;
    current=head->next;
    while(current != NULL && strcmp(current->id, id) != 0) { 
	    prev=current;
	    current=current->next;
    }

    if(current == NULL) {
	    printf("Data not found\n");
 	    return;
    } 
  
    printf("\n\n  學號     姓名       平時成績  ");
    printf("期中成績  期末成績  學期平均");
    printf("\n  -------  ---------    ------------  ");
    printf("------  ------  --------\n");
    printf("  %-7s", current -> id);
    printf("  %-10s", current -> name);
    printf("  %-13.1f", current -> temp_score);
    printf("  %-6.1f", current -> mid_score);
    printf("  %-6.1f", current -> final_score);

    average = calaverage(current);
    printf("  %5.1f\n", average);

    printf("\nAre you sure to delete this record ? (Y/N) : ");
    if (toupper(getchar()) == 'Y') {
    	prev->next=current->next;
        free(current);
	    printf("\nRecord deleted.\n");
    }
    else
        printf("\nRecord not deleted.\n");
    flushBuffer();
}

/**** query function *****/ 
void query()
{
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

/*** midify function ****/
void modify()
{
	char id[8];
	printf("\nWhich student ID do you want to modify ? ");
	scanf("%s", id);
	flushBuffer();
	current=head->next;
	while (current != NULL && strcmp(current->id, id))
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
void display()
{
    double average;
    if(head -> next ==NULL)
	    printf("\n list is empty\n");
    else {
    	printf("\n\n  學號     姓名       平時成績  ");
    	printf("期中成績  期末成績  學期平均");
    	printf("\n  -------  ---------   ------------  ");
		printf("------  ------  --------\n");
        current = head->next;
	    while(current != NULL) {
	        printf("  %-7s", current -> id);
	        printf("  %-10s", current -> name);
	        printf("  %-13.1f", current -> temp_score);
	        printf("  %-6.1f", current -> mid_score);
	        printf("  %-6.1f", current -> final_score);

            average = calaverage(current);

	        printf("  %5.1f\n", average);
		    current = current -> next;
        }
    }
}

/**** write function ****/
void write()
{
	if((fptr = fopen(fname, "w")) == NULL) {
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

double calaverage(struct student *current)
{
	double avg;
	
	avg = current -> temp_score    * TEMP_PERCENT    +
 	      current -> mid_score     * MID_PERCENT     +
		  current -> final_score   * FINAL_PERCENT;

	return avg;
}

void flushBuffer()
{
	while (getchar() != '\n')
		continue; 
}
