#include "defines.h"
#include "utilities.h"
#include "checks.h"
#include "prints.h"
#include "students.h"

int str_Cmp(void* stud, void* value) {
	return strcmp(*(char**)stud, (char*)value);
}

int int_Cmp(void* stud, void* value) {
	return *(int*)stud - atoi((char*)value);
}

int float_Cmp(void* stud, void* value) {

	if (*(float*)stud > atof((char*)value))
		return 1;
	if (*(float*)stud < atof((char*)value))
		return -1;
	return 0;
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Student* student = NULL;//structure of a student
	FILE* in = NULL;//Holds a file to read
	FILE* out = NULL;//File holder for writing
	char* input = NULL;//Holds all input from the user
	List list = { 0 };//management structure
	char* file_name = NULL;//file name
	file_name = _strdup("Student_information.csv");

	while ((!(in = fopen(file_name, "r+"))) && *file_name != '1') // Opening a file for reading or opening a new file by pressing 1
	{

		Error_file(&file_name);//If opening the file fails, lets enter a new name 
	}

	if (strcmp(file_name, "1") != 0) {
		file_into_list(in, &list);//Scans the file and puts it in a linked list
		print_list_to_cons(list);//Prints the list to the console
		if (in) fclose(in);//Closes a file
	}
	else {// if Enter the number 1 opens a new file with the name "Student_Information"
		free(file_name);
		file_name = _strdup("Student_information.csv");
	}
	Printing_user_instructions();
	do {
		if (input) {
			free(input);
			input = NULL;
		}
		do
		{
			printf("\n-->\n");
			input = Minimum_allocation_str(stdin);//Gets a string dynamically
		} while (!(input));//If the assignment was not successful, it returns to the beginning

		 if (strcmp(input, "quit") != 0)
		{
			 
			student = parse_str(input, &list);//Checks if the user wrote set or select and sends to the appropriate function
			if (student) {
				Update_details_if_necessary(&list, student);//If such a student exists, update details
				if (student->id){ 
					insert(&list, student);
					printf("\nNew student details have been successfully updated!!\n");
				}
				else

					printf("\nStudent details have been successfully updated\n");
					
			}
		}

	} while (strcmp(input, "quit"));
	if (input)
		free(input);

	while ((!(out = fopen(file_name, "w")))) //Opens a file for writing
	{
		Error_file(&file_name);
	}

	Print_list_to_file(&list, out);
	fclose(out);
	free(file_name);
	free(out);
	free_list(&list);
	return 0;
}
