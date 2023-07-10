#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 255
#define M 12
struct student {
	char surname[N];
	char name[N];
	int day;
	int month;
	int year;
	int mark1;
	int mark2;
	int mark3;
	int age;
}student[M];
int main(int argc, char *argv[]) {
	char buffer[N];
	char *temp;
	const char *lim1 = " ";
	int sum, aver;
	FILE* fp = fopen(argv[1], "r");
	sum = 0;

	for (int i = 0; i < M;i++) {
		fgets(buffer, 255, fp);
		strcpy(student[i].surname, strtok(buffer, lim1));
		strcpy(student[i].name, strtok(NULL, lim1));
		int l = 0;
		while (temp = strtok(NULL, lim1)) {
			if(l==0) student[i].day =atoi(temp);
			if(l==1) student[i].month = atoi(temp);
			if (l == 2) student[i].year = atoi(temp);
			if (l == 3) student[i].mark1 = atoi(temp);
			if (l == 4) student[i].mark2 = atoi(temp);
			if (l == 5) student[i].mark3 = atoi(temp);
			l++;
		}
		student[i].age = 365 * (2022 - student[i].year) + 30.5 * (11 - student[i].month) + student[i].day;
		sum += student[i].age;
	}
	fclose(fp);

	for (int step = 0; step < M - 1; step++) {
		int min_idx = step;
		struct student tmp;
		for (int i = step + 1; i < M; i++) {
			if (strcmp(student[i].surname, student[min_idx].surname)<0)
				min_idx = i;
		}
		tmp = student[min_idx];
		student[min_idx] = student[step];
		student[step] = tmp;
	}

	aver = sum / M;

	FILE* fout = fopen(argv[2], "w");
	if (!fout) return 0;
	fprintf(fout,"Sorted list of older students:\n");
	fprintf(fout, "Surname   Name\tBirthday  Marks\n");
	printf("Sorted list of older students:\n");
	printf("Surname   Name\tBirthday  Marks\n");
	for (int i = 0;i < M;i++) {
		if (student[i].age < aver) {
			fprintf(fout, "%s %s %02i.%02i.%i %i %i %i\n", student[i].surname, student[i].name,
				student[i].day, student[i].month, student[i].year,
				student[i].mark1, student[i].mark2, student[i].mark3);
			printf("%s %s %02i.%02i.%i %i %i %i\n", student[i].surname, student[i].name,
				student[i].day, student[i].month, student[i].year,
				student[i].mark1, student[i].mark2, student[i].mark3);
		}
	}
	fclose(fout);

	FILE* foutall = fopen(argv[3], "wb");
	if (!foutall) return 0;
	fwrite(student, sizeof(struct student), M, foutall);
	fclose(foutall);
	return 0;
}