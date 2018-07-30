#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dir.h>
#include<Windows.h>
///------------------------------------------------------------------------------------------------------------------------------------
int check_folder_creat();
int check_folder();
int folder_creat();
int taking_info();
void file_name();
int login();
///------------------------------------------------------------------------------------------------------------------------------------
FILE *test, *data;
char user_name[50];
///------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    A:
    if(!login())
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tWrong Information. Press Enter To Enter Login Page......\n");
        getchar();
        system("cls");
        goto A;
    }

    strcpy(user_name, "SHAJEDUR RAHMAN PANNA");
    printf("TYPE YOUR NAME: %s\n", user_name);
    //gets(user_name);
    check_folder_creat();
    file_name();
    getchar();

    return 0;
}
///------------------------------------------------------------------------------------------------------------------------------------
int check_folder_creat()
{
    int cf=0;
check_folder:
    if(!check_folder())
    {
        printf("NO DATA FOUND. CREATING NEW FILE\n");
        folder_creat();
        cf=cf+1;
        if(cf==3) {printf("CAN NOT MAKE NEW FOLDER. NO ADMINISTRATOR PERMISSION\n"); getchar(); return 0;}
        goto check_folder;
    }
    return 1;
}
///------------------------------------------------------------------------------------------------------------------------------------
int check_folder()
{
    char folder_name[50];

    strcpy(folder_name, user_name);
    strcat(folder_name, "/testing.txt");

    test=fopen(folder_name, "w");
    if(!test) return 0;

    fprintf(test, "ITS JUST USING TO CHECK");
    fclose(test);
    remove(folder_name);
    return 1;
}
///------------------------------------------------------------------------------------------------------------------------------------
int folder_creat()
{
    int fc;
    fc=mkdir(user_name);
    if(!fc) {printf("Directory created\n"); return 1;}
    else {printf("Unable to create directory\n"); return 0;}
}

void file_name()
{
    char fileii[100], tii[10];
	SYSTEMTIME str_t;
	GetLocalTime(&str_t);

	strcpy(fileii, user_name);
	strcat(fileii, "/");
	sprintf(tii, "%4d", str_t.wYear);
	strcat(fileii, tii);
	sprintf(tii, "-%02d", str_t.wMonth);
	strcat(fileii, tii);
    sprintf(tii, "-%02d", str_t.wDay);
	strcat(fileii, tii);
	strcat(fileii, ".txt");

	data=fopen(fileii, "r");
    if(!data)
    {
        fclose(data);
        data=fopen(fileii, "w");
        fprintf(data, "**************Year:%4d    Month:%02d    Date:%02d**************\n", str_t.wYear, str_t.wMonth, str_t.wDay);
        fclose(data);
    }

    data=fopen(fileii, "a");
	printf("Year:%d; Month:%d; Date:%d\n" ,str_t.wYear, str_t.wMonth, str_t.wDay);

    fprintf(data, "TIME:  %02d:%02d:%02d", str_t.wHour, str_t.wMinute, str_t.wSecond);
    fprintf(data, "---------------------------------------------------------------------\n\n");
    fprintf(data, " #|                          TASK                         |       MONEY      |       IN/OUT     |\n");
    taking_info();
    fprintf(data, "______________________________________________________________________________________\n\n");
    fclose(data);
}

int taking_info()
{
    int ciii=1, cii=1;
    int count_task=1;
    char task[10], inout[3];
    double money, totalin=0, totalout=0;

    while(1)
    {
        printf("%02d. Task:  ", cii);
        if(!gets(task) || strlen(task)==0) break;
        fprintf(data, "%02d|%55s|", cii, task);
        cii=ciii;
        printf("\t\tMoney(TK):  ");
        scanf("%lf", &money);

        fprintf(data, "%-17.2lf |", money);
        getchar();
apple:
        printf("\t\tIN/OUT:  ");
        gets(inout);
        if(!strcmp(inout, "IN"))
            totalin=totalin+money;
        else if(!strcmp(inout, "OUT"))
            totalout=totalout+money;
        else
        {
            printf("Wrong Input. Only \"IN\" & \"OUT\" Is Valid");
            goto apple;
        }

        fprintf(data, "%-18s|\n", inout);

        ciii=ciii+1;
        cii=ciii;
    }
    printf("______________________________________________________________________________________\nTOTAL IN MONEY= %15.2lfTK\n", totalin);
    fprintf(data, "______________________________________________________________________________________\nTOTAL IN MONEY= %15.2lfTK\n", totalin);
    printf("TOTAL OUT MONEY=%15.2lfTK\n", totalout);
    fprintf(data, "TOTAL OUT MONEY=%15.2lfTK\n", totalout);
    return 1;
}

int login()
{
    int c, r=0, lenung=0, lenpwg=0;
    char ung[999], pwg[999];
    int un[]={20,9,2,11,6,5,22,19,19,2,9,14,2,15,17,2,15,15,2,-49,17,2,15,15,2,-31,8,14,2,10,13,-49,4,16,14};
    int pw[]={96,86,84,91,98,93,30,31,32};

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tEnter User Name: ");
    gets(ung);
    system("cls");
    if(strlen(ung)==35) lenung=1;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tEnter Password: ");
    gets(pwg);
    system("cls");
    if(strlen(pwg)==9) lenpwg=1;

    if(lenung==1 && lenpwg==1)
    {
        for(c=0; c<35; c++)
        {
            if(ung[c]!=un[c]+95)
                return 0;
            else r=1;
        }
        for(c=0; c<9; c++)
        {
            if(pwg[c]!=pw[c]+19)
                return 0;
            else r=1;
        }
        return r;
    }
    else return 0;
}
