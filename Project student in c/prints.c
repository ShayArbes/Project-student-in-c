#include "prints.h"

void Print_list_to_file(PList list, FILE* out) {

	Student* temp = list->head;
	if (out)fprintf(out, "name,second name,id,name of course,grade\n");//Prints a header line to fail
	for (int i = 0; i < list->size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (temp->grades[j] != -1) {//Checks if there is a grade in the current profession
				if (out) {//Prints a line with all the student's data with the name of the relevant course and the relevant grade
					fprintf(out, "%s,%s,%s,", temp->first_name, temp->second_name, temp->id);
					if (j == 0)fprintf(out, "%s,", "c language");
					if (j == 1)fprintf(out, "%s,", "computer networks");
					if (j == 2)fprintf(out, "%s,", "cs fundamentals");
					fprintf(out, "%d\n", temp->grades[j]);
				}
			}
		}
		temp = temp->next;
	}
}


void print_list_to_cons(List list) {

	Student* ptr = list.head;
	if (ptr) {
		print_head();
	}
	while (ptr) {
		print_node(ptr);
		ptr = ptr->next;
	}
	printf("\n");

}

void print_warning(List list) {

	Student* ptr = list.head;
	float avg;
	int flag = 1;//If no warnings are found, do not print headers and write a message that no warnings were found
	while (ptr) {
		if (ptr->warning) {
			if (flag) {
				print_head();
				flag = 0;
			}
			print_node(ptr);
		}
		ptr = ptr->next;
	}
	if (flag)
		printf("The file is perfectly fine");
	printf("\n");
}


void print_head() {
	printf("\n\t +--------------------------------------------------------------------------------------------------------------------|\n");
	printf("\t |%-13s |%-13s |%-13s |%-17s |%-17s |%-17s |%-13s |%-5s |\n", "first name", "second name", "    ID", "C language", "Computer Networks", "CS Fundamentals", "average", "warning");
	printf("\t |--------------------------------------------------------------------------------------------------------------------|----------\n");
}

void print_node(Student* ptr) {

	//float avg;
	//avg = calc_avg(ptr);
	printf("\t |%-13s |%-13s |%-13s |%-17d |%-17d |%-17d |%-13.2f |",
		ptr->first_name, ptr->second_name, ptr->id, ptr->grades[C_language],
		ptr->grades[Computer_Networks], ptr->grades[CS_Fundamentals], ptr->avg);
	if (ptr->warning)printf("%-13s ", ptr->warning);
	printf("\n");
	printf("\t |--------------------------------------------------------------------------------------------------------------------|\n");

}

void Printing_user_instructions() {
	printf("\n\t\t\tUSER INSTTUCTIONS\n"
		"\t\t\     ----------------------\n\n"
		"\t1. To update a new student, "
		"first write set and the full details of the new student,\n"
		"\tMake sure the data is correct\n"
		"\tA. separate the fields with a comma\n"
		"\tB. only letters should be entered in the first and last name\n"
		"\tC. a valid ID must contain 9 digits (digits only)\n"
		"\tD. make sure the score is between 0 and 100,\n"
		"\tfor example (set first name = xyz, second name = abc, ID = 123456789, c language = 80)\n"
		"\tYou can also update your last name and grades, just be sure to insert a valid ID card\n\n"
		"\t2. You should get details of students in a controlled way.\n"
		"\tFirst write the word select, the field and the value by which you want to filter the results,\n"
		"\tfor example (select first name = Moshe or select average > 50)\n\n"
		"\t3. To print the entire list, write the word \"print\"\n\n"
		"\t4  To print all students with a warning, write \"print warning\"\n\n"
		"\t5. To delete a student from the list, write the word \"delete\"\n\n"
		"\t6. To end the program and save the changes, write the word \"quit\"\n\n");

}