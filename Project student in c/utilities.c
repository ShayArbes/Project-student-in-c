#include "utilities.h"
char* Delete_surrounding_spaces(char* str1) {

	if (str1 == NULL)return 0;
	char* str2 = calloc(strlen(str1) + 1, sizeof(char));
	if (str2 == NULL)
	{
		printf("allocation failed!");
		exit(1);
	}
	int flag = 0;
	int j = 0;
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != ' ') {
			str2[j] = str1[i];
			j++;
			if (str1[i + 1] == ' ' && str1[i + 2] != ' ' && str1[i + 2] != '\0') {//Keeps the space in case of two names
				i++;
				str2[j] = str1[i];
				j++;
			}
		}
	}
	return str2;
}

char* Minimum_allocation_str(FILE* in) {
	char* temp;//Holds the input temporarily
	char* input = NULL;//Holds the input
	char tempbuf[CHUNK];//Holds part of a string 10 characters long
	int inputlen = 0;//Sum the final length of the input
	int templen = 0;//Summed up the length of tempbuf
	do {
		if (fgets(tempbuf, CHUNK, in) == NULL)return NULL;//Takes 10 characters from the string and stores them inside tempbuf
		templen = (int)strlen(tempbuf);//Contains the length of tempbuf
		temp = (char*)realloc(input, inputlen + templen + 1);//Makes a realloc for the temp in case the allocation fails
		if (temp == NULL)//Checks if the assignment was successful
		{
			printf("allocation faild");
			free(input);
			return 0;
		}
		input = temp;
		strcpy(input + inputlen, tempbuf);// Concatenate the strings 
		inputlen += templen;// Sum the length of the new string with the old
	} while (templen == CHUNK - 1 && tempbuf[CHUNK - 2] != '\n');//The loop runs until the length of a templen is equal to 9 and the last character is a line drop

	input[strlen(input) - 1] = '\0';//Replaces the line break with 0

	return  input;
}

char* delete_space(char* str1) {

	if (str1 == NULL)return 0;
	char* str2 = calloc(strlen(str1) + 1, sizeof(char));
	if (str2 == NULL)
	{
		printf("allocation failed!");
		exit(1);
	}
	int j = 0;
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != ' ') {
			str2[j] = str1[i];
			j++;
		}
	}
	return str2;
}


void str_to_low(char* str) {
	if (str == NULL)return;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] > 'A' && str[i] < 'Z')
			str[i] = tolower(str[i]);

	}
}

void Error_file(char** file_name) {

	free(*file_name);//!!
	printf("The input file is incorrect\nPlease try entering a different file name or write 1 and a new file will open\n ");

	*file_name = Minimum_allocation_str(stdin);

}