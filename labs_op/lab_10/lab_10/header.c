#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 255
#define M 12
#define I 3
typedef struct student {
    char surname[N];
    char name[N];
    int day;
    int month;
    int year;
    int mark[I];
    int age;
}stud;

typedef struct listOfStudents {
    stud mdata;
    struct listOfStudents* next;
} list;

void createList(char* fname, list **ppHeadList) {
    list* pNew, * pRun;
    FILE* fin;

    fin = fopen(fname, "rb");
    if (!fin) return -1;

    pNew = (list*)malloc(sizeof(list));
    pNew->next = NULL;

    fread(&(pNew->mdata), sizeof(stud), 1, fin);
    *ppHeadList = pNew;
    pRun = pNew;

    printf("%-10s %-8s| %02d.%02d.%d | %d %d %d\n", pNew->mdata.surname,
        pNew->mdata.name, pNew->mdata.day, pNew->mdata.month,
        pNew->mdata.year, pNew->mdata.mark[0], pNew->mdata.mark[1],
        pNew->mdata.mark[2]);

    while (!feof(fin)) {
        pNew = (list*)malloc(sizeof(list));
        pNew->next = NULL;

        fread(&(pNew->mdata), sizeof(stud), 1, fin);

        if (feof(fin)) {
            free(pNew);
        }
        else {
            pRun->next = pNew;
            pRun = pNew;
            printf("%-10s %-8s| %02d.%02d.%04d | %d %d %d\n", pNew->mdata.surname,
                pNew->mdata.name, pNew->mdata.day, pNew->mdata.month,
                pNew->mdata.year, pNew->mdata.mark[0], pNew->mdata.mark[1],
                pNew->mdata.mark[2]);
        }
    }
    fclose(fin);
}

void insertElem(stud* insert, list **ppHeadList) {
    list* newStud, * pRun, * pPrev;
    pPrev = NULL;
    pRun = *ppHeadList;

    newStud = (list*)malloc(sizeof(stud));
    newStud->next = NULL;
    newStud->mdata = *insert;

    if (!pRun) {
        *ppHeadList = newStud;
    }
    else {
        if (strcmp((*ppHeadList)->mdata.surname, newStud->mdata.surname) > 0) {
            newStud->next = *ppHeadList;
            *ppHeadList = newStud;
        }
        else {
            while ((pRun != NULL) && (strcmp(pRun->mdata.surname, newStud->mdata.surname) < 0)) {
                pPrev = pRun;
                pRun = pRun->next;
            }
            newStud->next = pPrev->next;
            pPrev->next = newStud;
        }
    }
}

void printList(list* pHeadList) {
    if (!pHeadList) {
        printf("\nList is empty");
        return 0;
    } 
    printf("\n\tList of students\n");
    list* pNew = pHeadList;
    while (pNew) {
        printf("%-10s %-8s| %02d.%02d.%04d | %d %d %d\n", pNew->mdata.surname,
            pNew->mdata.name, pNew->mdata.day, pNew->mdata.month,
            pNew->mdata.year, pNew->mdata.mark[0], pNew->mdata.mark[1],
            pNew->mdata.mark[2]);
        pNew = pNew->next;
    }
}

void infoNewStud(stud** ppinsert) {
    *ppinsert = (stud*)malloc(sizeof(stud));
    printf("\nEnter info about new student:\nSurname:");
    scanf("%s", &(*ppinsert)->surname);
    printf("Name:");
    scanf("%s", &(*ppinsert)->name);
    printf("Day of birth:");
    scanf("%i", &(*ppinsert)->day);
    printf("Month of birth:");
    scanf("%i", &(*ppinsert)->month);
    printf("Year of birth:");
    scanf("%i", &(*ppinsert)->year);
    for (int i = 0;i < 3;i++) {
        printf("Enter %i mark:", i + 1);
        scanf("%i", &(*ppinsert)->mark[i]);
    }
}

void deleteElem(list** ppHeadList) {
    if (*ppHeadList) {
        list* pRun, * pPrev;
        pPrev = *ppHeadList;
        pRun = pPrev->next;
        int k = 0, h = 0;

        while (h == 0) {
            for (int i = 0;i < 3;i++) {
                if ((pPrev->mdata.mark[i] == 4) || (pPrev->mdata.mark[i] == 5))
                    k++;
            }
            if (k == 0) {
                if (!(*ppHeadList)->next) {
                    free(*ppHeadList);
                    *ppHeadList = NULL;
                    return 0;
                }
                *ppHeadList = pPrev->next;
                free(pPrev);
                pPrev = *ppHeadList;
                pRun = pPrev->next;
            }
            else {
                pPrev = pPrev->next;
                pRun = pPrev->next;;
                k = 0;
                h++;
            }
        }

        while (pRun != NULL) {
            for (int i = 0;i < 3;i++) {
                if ((pRun->mdata.mark[i] == 4) || (pRun->mdata.mark[i] == 5))
                    k++;
            }
            if (k == 0) {
                pPrev->next = pRun->next;
                free(pRun);
                pRun = pPrev->next;
            }
            else {
                pPrev = pPrev->next;
                pRun = pRun->next;
                k = 0;
            }
        }
    }
    else {
        printf("List is empty");
        return 0;
    }
    if (!(*ppHeadList)) {
        printf("List is empty");
        return 0;
    }
}

void freeList(list** ppHeadList) {
    list* pRun = *ppHeadList;
    while (pRun) {
        *ppHeadList = pRun->next;
        free(pRun);
        pRun = *ppHeadList;
    }
    *ppHeadList = NULL;
}