#ifndef HEADER_H
#define HEADER_H
typedef struct listOfStudents list;
typedef struct student stud;
void createList(char* fname, list** ppHeadList);
void infoNewStud(stud** ppinsert);
void printList(list* pHeadList);
void insertElem(stud* insert, list** ppHeadList);
void deleteElem(list** ppHeadList);
void freeList(list** ppHeadList);
#endif