#include "students.h"

void delete_student(PList list) {

	Student* current = list->head;//The student I want to delete
	Student* prev = list->head;//The node before the node being deleted
	printf("Please enter the ID card of the student you want to delete: ");
	char* id;
	int flag = 0;//If there is a student with this id;
	id = Minimum_allocation_str(stdin);
	if (!id) {
		printf("No id entered!");
		return;
	}
	while (current)
	{
		if (!(strcmp(current->id, id))) {
			flag = 1;
			if (current == list->head) {//If a study you want to delete is at the top of the list
				list->head = list->head->next;
				free_node(current);
				current = list->head;
				prev = list->head;
				list->size--;

			}
			else {
				prev->next = current->next;
				free_node(current);
				current = prev->next;
				list->size--;
			}

		}
		else {
			if (current != prev)//If they are equal, only the current one should be promoted and leave the prev one before
				prev = prev->next;
			current = current->next;
		}
	}
	if (!flag)
		printf("The ID you entered is incorrect ");
	free(id);
}


float calc_avg(Student* ptr) {

	float avg = 0;//GPA
	int cunt = 0;//Count the number of grades in order to divide the sum of grades at the end
	for (int i = 0; i < 3; i++) {
		if (ptr->grades[i] != -1) {
			avg += ptr->grades[i];
			cunt++;
		}
	}
	if (cunt == 0)cunt++;
	avg /= cunt;
	return avg;
}

Student* parse_str(char* line, PList list) {
	char* token = strtok(line, " ");
	Student* node = NULL;
	if (token && strcmp(token, "select") == 0) {//Checks what the first word he entered is and activates a function accordingly
		token = strtok(NULL, "");
		selectfunc(token, *list);
	}
	else if (token && strcmp(token, "set") == 0) {
		token = strtok(NULL, "");
		node = setfunc(token);
	}
	else if (token && !(strcmp(token, "print"))) {
		token = strtok(NULL, "");
		if (token && !(strcmp(token, "warning")))
			print_warning(*list);// Prints warning
		else print_list_to_cons(*list);// Prints the list
	}
	else if (token && !(strcmp(token, "delete"))) {
		delete_student(list);
	}
	else
	{
		printf("The request does not exist \nPlease try again\n");
	}
	return node;

}
void selectfunc(char* line, List list) {
	/*select first name = Moshe ае select average > 50*/
	//char* temp = line;
	char operator;
	char* copy_line = _strdup(line);//Copies the line to keep the operator
	char* Pcopy_line = copy_line;//to release the beginning of the address
	char* token = strtok(line, "=<>!");//Cuts the line until the operator
	if (!token) {
		free(Pcopy_line);
		return;
		//check the return flag
	}
	char* request_field = _strdup(delete_space(token));
	str_to_low(request_field);
	char* Prequest = request_field;//to release the beginning of the address
	char* value;
	int number_or_string;
	//request_field = delete_space(request_field);//lowers profits
	if ((number_or_string = check_field(request_field)) == -1) {//Checks that the field entered by the user is valid
		printf("The title field does not exist");
		free(Pcopy_line);
		free(Prequest);
		return;
	}
	if (check_operator(&copy_line))//Advances the pointer to the operator and checks that it is valid
	{
		free(Prequest);
		free(Pcopy_line);
		return;
	}
	operator = *copy_line;//Saves the operator
	token = strtok(NULL, "\0");//Cuts the line from the operator to the end of the string
	if (operator == '!')token++;
	if (number_or_string < 2) {
		if (chek_only_letters(token, 1)) {
			free(Pcopy_line);
			free(Prequest);
			return;
		}
	}
	if (number_or_string == 2) {
		if (chek_id_select(token, 1)) {
			free(Pcopy_line);
			free(Prequest);
			return;
		}
	}
	if (number_or_string > 2) {
		if (chek_only_numbers_for_score(token, 1)) {
			free(Pcopy_line);
			free(Prequest);
			return;
		}
	}
	value = _strdup(delete_space(token));//	deletes spaces

	str_to_low(value);

	search_the_list(request_field, operator , value, list);//Searches within the list according to the requested value.
}


void utils_Search_the_list(char operator,char* value, Student* ptr, int Distance_cells_in_memory, int(*cb)(void*, void*))
{
	Student* ptr_node = ptr;//
	void* field_ptr;
	if (operator == '=')
	{
		while (ptr_node)
		{
			field_ptr = ((char*)ptr_node + Distance_cells_in_memory);
			//if (strcmp(delete_space(field_ptr), value) == 0)//If there is a tie, the data of that student is printed
			if (cb(field_ptr, value) == 0)
				print_node(ptr_node);
			ptr_node = ptr_node->next;
			//ptr = ptr->next;
		}
	}
	else if (operator == '!')
	{
		while (ptr_node)
		{
			field_ptr = ((char*)ptr_node + Distance_cells_in_memory);
			//if (strcmp(field_ptr, value) != 0)
			if (cb(field_ptr, value) != 0)
				print_node(ptr_node);
			ptr_node = ptr_node->next;
			//ptr = ptr->next;
		}
	}
	else if (operator == '>')
	{
		while (ptr_node)
		{
			field_ptr = ((char*)ptr_node + Distance_cells_in_memory);
			//if (strcmp(field_ptr, value) > 0)
			if (cb(field_ptr, value) > 0)
				print_node(ptr_node);
			ptr_node = ptr_node->next;
			ptr = ptr->next;
		}
	}
	else if (operator == '<')
	{
		while (ptr_node)
		{
			field_ptr = ((char*)ptr_node + Distance_cells_in_memory);
			//if (strcmp(field_ptr, value) < 0)
			if (cb(field_ptr, value) < 0)
				print_node(ptr_node);
			ptr_node = ptr_node->next;
			ptr = ptr->next;

		}
	}
}
void search_the_list(char* request_field, char operator,char* value, List list) {
	Student* ptr = list.head;
	int Distance_cells_in_memory;
	if (ptr)
	{
		print_head();

		if (strcmp(request_field, "firstname") == 0)
		{

			Distance_cells_in_memory = OFFSETOF(Student, first_name);// Saves the distance of cells in memory from the beginning of the structure to the element
			//utils_Search_the_list
			utils_Search_the_list(operator,value, ptr, Distance_cells_in_memory, str_Cmp);
		}

		if (strcmp(request_field, "secondname") == 0)
		{
			Distance_cells_in_memory = OFFSETOF(Student, second_name);
			utils_Search_the_list(operator,value, ptr, Distance_cells_in_memory, str_Cmp);
		}

		if (strcmp(request_field, "id") == 0)
		{
			Distance_cells_in_memory = OFFSETOF(Student, id);
			utils_Search_the_list(operator,value, ptr, Distance_cells_in_memory, str_Cmp);
		}

		if (strcmp(request_field, "average") == 0)
		{
			Distance_cells_in_memory = OFFSETOF(Student, avg);
			utils_Search_the_list(operator,value, ptr, Distance_cells_in_memory, float_Cmp);

		}
	}
	char field[3][20] = { "clanguage","computernetworks","csfundamentals" };//Checks if there is equality for one of the course names
	for (int i = 0; i < 3; i++)
	{
		if (strcmp(request_field, field[i]) == 0)
		{
			Distance_cells_in_memory = OFFSETOF(Student, grades) + i * sizeof(int);
			utils_Search_the_list(operator,value, ptr, Distance_cells_in_memory, int_Cmp);
		}
	}
}





void free_list(PList list) {
	Student* temp = list->head;
	while (list->head != NULL) {
		temp = temp->next;
		free_node(list->head);
		list->head = temp;

	}
}

void free_node(Student* node) {
	free(node->id);
	free(node->first_name);
	free(node->second_name);
	free(node->name_of_course);
	free(node->warning);
	free(node);

}

int Matching_access_to_value(Student* stud, char** token) {
	char s[] = "=,";//skips
	int field = check_field(*token);//Returns a number that represents the field
	switch (field)
	{
	case -1:
		return 0;//If the field is invalid
		break;
	case first_name://for first name
		*token = strtok(NULL, s);
		if (chek_only_letters(*token, 1))return 0;
		stud->first_name = _strdup(Delete_surrounding_spaces(*token));
		return 1;
		break;

	case second_name://for second name
		*token = strtok(NULL, s);
		if (chek_only_letters(*token, 1))return 0;
		stud->second_name = _strdup(delete_space(*token));
		return 1;
		break;

	case id://for id
		*token = strtok(NULL, s);
		if (chek_only_numbers_for_id(*token, 1))return 0;
		stud->id = _strdup(delete_space(*token));
		return 1;
		break;

	case c_language://for c language
		stud->name_of_course = _strdup("c language");
		*token = strtok(NULL, s);
		if (chek_grade_select(*token, 1))return 0;
		stud->grades[C_language] = atoi(*token);
		return 1;
		break;

	case computer_networks://for computer networks
		stud->name_of_course = _strdup("computer networks");
		*token = strtok(NULL, s);
		if (chek_grade_select( *token, 1))return 0;
		stud->grades[Computer_Networks] = atoi(*token);
		return 1;
		break;
	case cs_fundamentals://for cs fundamentals
		stud->name_of_course = _strdup("cs fundamentals");
		*token = strtok(NULL, s);
		if (chek_grade_select(*token, 1))return 0;
		stud->grades[CS_Fundamentals] = atoi(*token);
		return 1;
		break;
	}

}
Student* setfunc(char* line) {
	//set first name = xyz, second name = abc, ID = 123456789, c language = 80
	if (!(line))return NULL;
	Student* stud = (Student*)calloc(1, sizeof(Student));//A student's node
	if (stud == NULL)
	{
		printf("allocation failed!");
		return stud;
	}
	stud->grades[0] = -1;
	stud->grades[1] = -1;
	stud->grades[2] = -1;
	char s[] = "=,";//skips
	char* token = strtok(line, s);

	while (token)
	{
		if (!(Matching_access_to_value(stud, &token))) {//Checks which field the user entered and enters the content accordingly
			free_node(stud);
			stud = NULL;
			return stud;
		}
		token = strtok(NULL, s);

	}
	stud->avg = calc_avg(stud);
	return stud;
}







void file_into_list(FILE* in, PList list) {

	char ch;
	char* str_file = Minimum_allocation_str(in);// Skip the row of titles
	free(str_file);

	while (str_file = Minimum_allocation_str(in))
	{
		Student* stud = NULL;//A student's node
		stud = (Student*)calloc(1, sizeof(Student));
		if (stud == NULL)
		{
			printf("allocation failed!");
			return list;
		}
		stud->grades[0] = -1;
		stud->grades[1] = -1;
		stud->grades[2] = -1;
		char* token = strtok(str_file, ",");
		if (chek_only_letters(token, 0))//health check
			stud->warning = _strdup("There is a problem with the first name");
		if (token)
			stud->first_name = _strdup(Delete_surrounding_spaces(token));
		token = strtok(NULL, ",");
		if (chek_only_letters(token, 0))//health check
			stud->warning = _strdup("There is a problem with the last name");
		if (token)
			stud->second_name = _strdup(delete_space(token));
		token = strtok(NULL, ",");
		if (chek_only_numbers_for_id(token, 0))//health check
			stud->warning = _strdup("There is a problem with the id");
		if (token)
			stud->id = _strdup(delete_space(token));
		token = strtok(NULL, ",");
		if (token)
			stud->name_of_course = _strdup(token);
		token = strtok(NULL, ",");
		if (chek_grade_select(token, 0))//health check
			stud->warning = _strdup("A problem with the grade");
		if (token) {
			int score = atoi(token);
			check_insertion_grades(stud, score);
		}
		if (check_if_there_is(list, stud))//If such a student exists, he updates his grade
			insert(list, stud);// If the object does not exist in the list, it adds it to the list


		free(str_file);
	}

}


void Update_details_if_necessary(PList list, Student* student)
{
	Student* current = list->head;
	Student* prev = list->head;//Saves the position of the previous element in the list
	while (current)
	{
		if (!(strcmp(current->id, student->id))) {
			if (strcmp(current->first_name, student->first_name)) {//If the user entered an existing id with a different first name, an error message is printed
				free_node(student);
				printf("warning!!\nThe id you entered exists with a different name!");
				student->id = NULL;
				return;
			}
			if (strcmp(current->second_name, student->second_name))
			{
				for (int i = 0; i < 3; i++)
				{
					if (student->grades[i] == -1)
						student->grades[i] = current->grades[i];
				}
				student->avg = calc_avg(student);
				if (current == list->head) {
					list->head = list->head->next;
					free_node(current);
					list->size--;
					return;
				}
				prev->next = current->next;
				free_node(current);
				list->size--;
				return;
			}
			else {
				for (int i = 0; i < 3; i++)
				{
					if (student->grades[i] != -1)
						current->grades[i] = student->grades[i];

				}
				current->avg = calc_avg(current);
				free_node(student);
				student->id = NULL;
				return;
			}
		}
		if (current != prev)
			prev = prev->next;
		current = current->next;
	}
}

void insert(PList list, Student* student) {

	list->size++;
	Student** prev = &list->head;
	student->avg = calc_avg(student);
	while (*prev)
	{
		if ((*prev)->second_name && student->second_name)//Checks that both are not empty
		{
			if ((strcmp((*prev)->second_name, student->second_name)) > 0)
				break;//If it reaches a member that is smaller than it stops the loop
		}
		prev = &((*prev)->next);
	}
	student->next = *prev;
	*prev = student;
}