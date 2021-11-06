#include <stdio.h>
/*
	Creating new file with new static data
	input: string with file name and path to it
	output: 1 if succeeded, 0 if failed
*/
int createDataFile(char*);
/*
	Update sum per UserId
	input: string userID, double NewAmount, string filePath
	output: 1 if succeeded, 0 if failed
*/
int updateDataFile(char*, double, char*);
/*
	printing file on screen
	input:file path
*/
void printDataFile(char*);

void main() {
	char fileName[100];
	double amount;
	char userId[10];
	printf("insert name of new data file\n");
	gets(fileName);
	if(!createDataFile(fileName)) {
		printf("Failed to create file\n");
		exit(0);
	}
	printDataFile(fileName);
	do {
		printf("insert UserId to update:");
		gets(userId);
		printf("insert shoping price to add:");
		scanf("%lf", amount);
	} while (updateDataFile(userId, amount, fileName));

	printDataFile(fileName);
}

int updateDataFile(char *userID, double newSum, char*FN) {

	return 0;

}
int createDataFile(char*FN) {
	int i;
	char *userID[] = {"31221983","31241983","34221983","39221983","31221993"}, 
		*userName[] = { "Moshe","Dina","Beni","Osnat","Hana" };
	double amount[] = {234.06,536.3,3375,35.34,476.9};
	FILE *F;
	F = fopen(FN, "w+");
	if (!F) { 
		printf("failed to create file\n"); 
		return 0; 
	}
	for (i = 0; i < 5; i++) {
		fprintf(F, "%9s%30s%8.2lf\n", userID[i], userName[i], amount[i]);
	}
	fclose(F);
	return 1;
}
void printDataFile(char* FN) {
	char userID[10], userName[31];
	double amount;
	FILE *F;
	F = fopen(FN, "r");
	while (fscanf(F, "%9s%30s%8lf", userID, userName, &amount)>0) {
		printf("%9s%30s%8.2lf\n", userID, userName, amount);
	}
	fclose(F);
}