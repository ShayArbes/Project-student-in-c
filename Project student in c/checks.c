#include "checks.h"

void check_insertion_grades(Student* stud, int score) {
	stud->name_of_course = delete_space(stud->name_of_course);
	str_to_low(stud->name_of_course);
	if (strcmp(stud->name_of_course, "clanguage") == 0) {
		stud->grades[C_language] = score;
	}
	else if (strcmp(stud->name_of_course, "computernetworks") == 0) {
		stud->grades[Computer_Networks] = score;
	}
	else if (strcmp(stud->name_of_course, "csfundamentals") == 0) {
		stud->grades[CS_Fundamentals] = score;
	}
	else {
		stud->warning = _strdup("The course name is incorrect");
		return;
	}
	if (score > 100 || score < 0)
		stud->warning = _strdup("Invalid course grade!");

}
int chek_id_select(char* str, int print) {//8
	//case 8://Checking to make sure that he entered only numbers 
	char* str2 = keeps_checks(str);
		for (int i = 0; str2[i] != '\0'; i++) {
			if (str2[i] < '0' || str2[i] > '9')
			{
				if (print)
					printf("The ID you entered is incorrect, please try again");
				free(str2);
				return 1;
			}
		}
}

int chek_only_numbers_for_score(char* str, int print){//7
	char* str2 = keeps_checks(str);
	if (atoi(str2) < -1 || atoi(str2) > 100) {
		if (print)
			printf("Do not write letters and symbols in the grade, please try again");
		free(str2);
		return 1;
	}
	return 0;
}

int chek_grade_select(char* str, int print) {//6
	char* str2 = keeps_checks(str);
	for (int i = 0; str2[i] != '\0'; i++) {
		if (str2[i] < '0' || str2[i] > '9')
		{
			if (print)
				printf("Do not write letters and symbols in the grade, please try again");
			free(str2);
			return 1;
		}
		if (atoi(str2) < 0 || atoi(str2) > 100) {
			if (print)
				printf("Do not write letters and symbols in the grade, please try again");
			free(str2);
			return 1;
		}
	}
	return 0;
}

int chek_only_numbers_for_id(char* str, int print) {//5
	char* str2 = keeps_checks(str);
	for (int i = 0; str2[i] != '\0'; i++) {
		if (str2[i] < '0' || str2[i] > '9' || i >= 9 || str2[i + 1] == '\0' && i < 8)
		{
			if (print)
				printf("The ID you entered is incorrect, please try again");
			free(str2);
			return 1;
		}
	}
	return 0;
}

int chek_id(char* str, int print) {//4
	char* str2 = keeps_checks(str);
	if (strcmp(str2, "id") != 0) {
		if (print)
			printf("You did not enter a correct id. Try again");
		free(str2);
		return 1;
	}
	return 0;
}

int chek_second_name(char* str, int print) {//3
	char* str2 = keeps_checks(str);
	if (strcmp(str2, "secondname") != 0) {
		if (print)
			printf("You did not enter a correct second name. Please Try again");
		free(str2);
		return 1;
	}
	return 0;
}

int chek_only_letters(char* str, int print) {//2
	char* str2 = keeps_checks(str);
	for (int i = 0; str2[i] != '\0'; i++) {
		if (str2[i] < 'a' || str2[i] > 'z')
		{
			if (print)
				printf("Only letters should be written in the first name, no symbols or numbers should be written. Please try again");
			return 1;
		}
	}
	return 0;
}

int chek_first_name(char* str, int print) {//1
	char* str2 = keeps_checks(str);
	if (strcmp(str2, "firstname") != 0) {
		if (print)
			printf("You did not enter a correct first name. Try again");
		free(str2);
		return 1;
	}
	return 0;
}

char* keeps_checks(char* string) {
	char* str = _strdup(delete_space(string));
	str_to_low(str);
	if ((!(str)) || *str == '\0') {
		printf("You did not enter all the details, try again");
		free (str);
		return string;
	}
	return str;
}

int check_if_there_is(PList list, Student* stud) {

	Student* prev = list->head;
	int flag = 0;

	while (prev)
	{
		if (prev->id && stud->id)
		{
			if ((strcmp(prev->id, stud->id)) == 0) {
				if ((strcmp(prev->first_name, stud->first_name)) != 0) {//If the id is equal but the first name is not equal, an error message is printed
					stud->warning = _strdup("First name problem");
					break;
				}
				if ((strcmp(prev->second_name, stud->second_name)) != 0) {//If the last name is changed, update the last name
					free(prev->second_name);
					prev->second_name = _strdup(stud->second_name);
				}

				if (strcmp(stud->name_of_course, "clanguage") == 0)//If there is a grade in the same subject, the grade is updated
					prev->grades[C_language] = stud->grades[C_language];
				else if (strcmp(stud->name_of_course, "computernetworks") == 0)
					prev->grades[Computer_Networks] = stud->grades[Computer_Networks];
				else if (strcmp(stud->name_of_course, "csfundamentals") == 0)
					prev->grades[CS_Fundamentals] = stud->grades[CS_Fundamentals];
				prev->warning = _strdup(stud->warning);
				prev->avg = calc_avg(prev);
				return 0;
			}
		}
		else
		{
			stud->warning = _strdup("There is a problem with the id");
		}
		prev = prev->next;
	}
	return 1;
}

int check_field(char* field) {
	field = delete_space(field);
	if (field == NULL)return 0;
	str_to_low(field);
	char* fields[] = { "firstname" ,"secondname" , "id" ,"average" ,"clanguage" ,"computernetworks","csfundamentals" };
	for (size_t i = 0; i < 7; i++)
	{
		if (strcmp(field, fields[i]) == 0)return i;
	}
	printf("The field you wrote does not exist, please try again");
	return -1;
}

int check_operator(char** copy_line) {

	while (**copy_line != '=' && **copy_line != '!' && **copy_line != '<' && **copy_line != '>')//Advances the pointer to the operator
	{
		(*copy_line)++;
		if (**copy_line == '\0') {//If the end of the string is reached and no operator is detected, an error message is returned
			printf("You did not insert an operator");
			return 1;
		}
	}
	if (**copy_line == '!') {//Checks that after the exclamation mark write the equals character
		if (*(++(*copy_line)) == '=') {
			(--(*copy_line));//Returns the pointer to the first operator
			return 0;
		}
		printf("The operator you entered does not exist");
		return 1;
	}
	return 0;
}





//int check(int number_chek, char* str, int print) {
//	//set first name = xyz, second name = abc, ID = 123456789, c language = 80
//	//enum number_chek { default,chek_first_name, chek_only_letters, check_second_name, check_id, only_numbers_for_id, only_numbers,only_numbers_for_score, cs_fundamentals };
//	char* str2 = keeps_checks(str);/*_strdup(delete_space(str));
//	str_to_low(str2);
//	if ((!(str2)) || *str2 == '\0') {
//		printf("You did not enter all the details, try again");
//		free(str2);
//		return 1;
//	}*/
//	switch (number_chek)
//	{
//	case 1://Checking to make sure that a first name is written
//
//		if (strcmp(str2, "firstname") != 0) {
//			if (print)
//				printf("You did not enter a correct first name. Try again");
//			free(str2);
//			return 1;
//		}
//		break;
//
//	case 2://Check to make sure he entered only letters
//
//		for (int i = 0; str2[i] != '\0'; i++) {
//			if (str2[i] < 'a' || str2[i] > 'z')
//			{
//				if (print)
//					printf("Only letters should be written in the first name, no symbols or numbers should be written. Please try again");
//				return 1;
//			}
//		}
//		break;
//
//	case 3://Checking to make sure that a second name is written
//
//		if (strcmp(str2, "secondname") != 0) {
//			if (print)
//				printf("You did not enter a correct second name. Please Try again");
//			free(str2);
//			return 1;
//		}
//		break;
//
//	case 4://Checking to make sure that a id is written
//
//		if (strcmp(str2, "id") != 0) {
//			if (print)
//				printf("You did not enter a correct id. Try again");
//			free(str2);
//			return 1;
//		}
//		break;
//
//	case 5://Check to make sure that he entered only numbers and that the identity card is not longer or shorter than 9
//
//		for (int i = 0; str2[i] != '\0'; i++) {
//			if (str2[i] < '0' || str2[i] > '9' || i >= 9 || str2[i + 1] == '\0' && i < 8)
//			{
//				if (print)
//					printf("The ID you entered is incorrect, please try again");
//				free(str2);
//				return 1;
//			}
//		}
//		break;
//	case 6://Check to make sure he entered only numbers
//
//		for (int i = 0; str2[i] != '\0'; i++) {
//			if (str2[i] < '0' || str2[i] > '9')
//			{
//				if (print)
//					printf("Do not write letters and symbols in the grade, please try again");
//				free(str2);
//				return 1;
//			}
//			if (atoi(str2) < 0 || atoi(str2) > 100) {
//				if (print)
//					printf("Do not write letters and symbols in the grade, please try again");
//				free(str2);
//				return 1;
//			}
//		}
//		break;
//	case 7://A test that entered a correct grade for select
//
//		if (atoi(str2) < -1 || atoi(str2) > 100) {
//			if (print)
//				printf("Do not write letters and symbols in the grade, please try again");
//			free(str2);
//			return 1;
//		}
//
//		break;
//	case 8://Checking to make sure that he entered only numbers 
//
//		for (int i = 0; str2[i] != '\0'; i++) {
//			if (str2[i] < '0' || str2[i] > '9')
//			{
//				if (print)
//					printf("The ID you entered is incorrect, please try again");
//				free(str2);
//				return 1;
//			}
//		}
//		break;
//
//	default:
//		printf("Inspection number does not exist");
//
//	}
//	free(str2);
//	return 0;
//}