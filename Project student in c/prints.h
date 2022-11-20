#pragma once
#include "defines.h"
#include "students.h"
//--------------------------------------------------------------------------------------
/**
 * Prints the list to a file
 * out - A pointer to file
 * list - A pointer to a manager structure.
 */
void Print_list_to_file(PList list, FILE* out);
//--------------------------------------------------------------------------------------
/**
 * Prints the list to the console
 * list - manager structure
 */
void print_list_to_cons(List list);
//--------------------------------------------------------------------------------------
/**
 * Print the nodes with warnings
 * list - manager structure
 */
void print_warning(List list);
//--------------------------------------------------------------------------------------
//Print the header row
void print_head();
//--------------------------------------------------------------------------------------
/**
 * print node
 * ptr -  A pointer of a student structure
 */
void print_node(Student* ptr);
//--------------------------------------------------------------------------------------
void Printing_user_instructions();
//--------------------------------------------------------------------------------------
