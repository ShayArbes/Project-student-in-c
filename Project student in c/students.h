#pragma once
#include "defines.h"
#include "utilities.h"
typedef struct Student
{
	struct Student* next;
	char* first_name;
	char* second_name;
	char* id;
	char* name_of_course;
	char* warning;
	int grades[3];
	float avg;
}Student;

typedef struct list
{
	Student* head;
	int size;
}List, * PList;
//--------------------------------------------------------------------------------------
/**
*Searches within the list according to the requested value.
* request_field - holds the field.
* operator - holds the operator.
* value - The value you want to search for.
* list - manager structure
* ptr - A node that points to the head of the list
* Distance_cells_in_memory - The amount of cells in memory from the beginning of the structure to the requested type
* cb(void*, void*) - a pointer to a generic function that compares the first name or last name or ID
 */
void utils_Search_the_list(char operator,char* value, Student * ptr, int Distance_cells_in_memory, int(*cb)(void*, void*));
//--------------------------------------------------------------------------------------
/**
 * Searches within the list according to the requested value.
 * request_field - holds the field.
 * operator - holds the operator.
 * value - The value you want to search for.
 * list - manager structure
 */
void search_the_list(char* request_field, char operator , char* value, List list);
//--------------------------------------------------------------------------------------
/**
 * Checks what the first word he entered is and activates a function accordingly
 * line - Holds the string entered by the user.
 * list - A pointer to a manager structure.
 */
Student* parse_str(char* line, PList list);
//--------------------------------------------------------------------------------------
/**
 * A function that inserts values into a linked list according to what the user has entered
 * line - Holds the string entered by the user.
 * return Node of a new student if user wrote set
 */
Student* setfunc(char* line);
//--------------------------------------------------------------------------------------
/**
 * Decodes input and prints all students who meet the criteria requested by the user
 * line - Holds the string entered by the user.
 * list - A pointer to a manager structure.
 */
void selectfunc(char* line, List list);
//--------------------------------------------------------------------------------------
/**
 * Creates a linked list from the file
 * in - A pointer to file
 * list - A pointer to a manager structure to holds a linked list from the file
 */
void file_into_list(FILE * in, PList list);
//--------------------------------------------------------------------------------------
/**
 * Deletion of a student based on an ID card
 * list - manager structure
 */
void delete_student(PList list);
//--------------------------------------------------------------------------------------
/**
 * Matching access to value
 * stud - A pointer to a node of studrnd.
 * token -A pointer to field
 * return a string
 */
int Matching_access_to_value(Student * stud, char** token);
//--------------------------------------------------------------------------------------
/**
 * Keeps node sorted by last name in a linked list
 * list - A pointer to a manager structure.
 * student - A pointer to a node of studrnd.
 */
void insert(PList list, Student * student);
//--------------------------------------------------------------------------------------
/**
 * If such a student exists, update details
 * list - A pointer to a manager structure.
 * student - A pointer to a node of studrnd.
 */
void Update_details_if_necessary(PList list, Student * student);
//--------------------------------------------------------------------------------------
/**
 * Average calculator
 * ptr - A pointer to a Node of studrnd..
 * return grade point average
 */
float calc_avg(Student * ptr);
//--------------------------------------------------------------------------------------

/**
 * Releases a node
 * node - A pointer to a pointer of a student structure
 */
void free_node(Student * node);
//--------------------------------------------------------------------------------------
/**
 * Releases a list
 * list -  A pointer to a manager structure.
 */
void free_list(PList list);
//--------------------------------------------------------------------------------------
/*specific functions for comparison
* stud, value - The fields that are intended for comparison
* return 0 if the variables are equal, a positive number if stud is greater than value and negative number if value is greater than stud
*/
int float_Cmp(void* stud, void* value);
int int_Cmp(void* stud, void* value);
int str_Cmp(void* stud, void* value);

//--------------------------------------------------------------------------------------




