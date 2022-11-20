#pragma once
#include "defines.h"
#include "students.h"
//--------------------------------------------------------------------------------------
/**
 * Checking and entering grades for the student
 * score - the student's grade
 * stud- A pointer to a node of studrnd.
 */
void check_insertion_grades(Student* stud, int score);
//--------------------------------------------------------------------------------------
/**
 * Checks if there is more information about that student and adds them
 * list - A pointer to a manager structure.
 * stud - A pointer to a node of studrnd.
 * return 0 if there was an update
 */
int check_if_there_is(PList list, Student* stud);
//--------------------------------------------------------------------------------------
/**
 * Checks that the fields are correct
 * field - request field.
 * return a different positive number for each field and 0 if the field is invalid
 */
int check_field(char* field);
//--------------------------------------------------------------------------------------
/**
 * Advances the pointer to the operator and checks for correctness
 * copy_line - copy of string.
 * return  1 if the operator is invalid
 */
int check_operator(char** copy_line);
//--------------------------------------------------------------------------------------
/**
 * Checking if entered only numbers 
 * print - If you want prints in case of an error, enter a positive number if you don't want prints, enter 0
 * str - string
 * return 0 if the test is successful
 */
int chek_id_select(char* str, int print);//8
//--------------------------------------------------------------------------------------
/**
 * Checking if entered a correct grade for select
 * print - If you want prints in case of an error, enter a positive number if you don't want prints, enter 0
 * str - string
 * return 0 if the test is successful
 */
int chek_only_numbers_for_score(char* str, int print);//7
//--------------------------------------------------------------------------------------
/**
 * Checking if entered only numbers
 * print - If you want prints in case of an error, enter a positive number if you don't want prints, enter 0
 * str - string
 * return 0 if the test is successful
 */
int chek_grade_select(char* str, int print);//6
//--------------------------------------------------------------------------------------
/**
 * Checking if entered only numbers and that the identity card is not longer or shorter than 9
 * print - If you want prints in case of an error, enter a positive number if you don't want prints, enter 0
 * str - string
 * return 0 if the test is successful
 */
int chek_only_numbers_for_id(char* str, int print);//5
//--------------------------------------------------------------------------------------
/**
 * Checking If you entered the word id
 * print - If you want prints in case of an error, enter a positive number if you don't want prints, enter 0
 * str - string
 * return 0 if the test is successful
 */
int chek_id(char* str, int print);//4
//--------------------------------------------------------------------------------------
/**
 * Checking If you entered the word second name
 * print - If you want prints in case of an error, enter a positive number if you don't want prints, enter 0
 * str - string
 * return 0 if the test is successful
 */
int chek_second_name(char* str, int print);//3
//--------------------------------------------------------------------------------------
/**
 * Checking If you entered only letters
 * print - If you want prints in case of an error, enter a positive number if you don't want prints, enter 0
 * str - string
 * return 0 if the test is successful
 */
int chek_only_letters(char* str, int print);//2
//--------------------------------------------------------------------------------------
/**
 *  Checking If you entered the word first name
 * print - If you want prints in case of an error, enter a positive number if you don't want prints, enter 0
 * str - string
 * return 0 if the test is successful
 */
int chek_first_name(char* str, int print);//1
//--------------------------------------------------------------------------------------
/**
 *  Allocates memory Copies a string
 *  Deletes the spaces Converts letters to lowercase
 * string - string
 * return a new string with no spaces and lowercase letters
 */
char* keeps_checks(char* string);