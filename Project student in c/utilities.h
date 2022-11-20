#pragma once
#include "defines.h"
//--------------------------------------------------------------------------------------
/**
 * Deleting spaces without deleting between two words
 * str1 - string
 */
char* Delete_surrounding_spaces(char* str1);
//--------------------------------------------------------------------------------------
/**
 * Allocates exact memory for a string
 * in - a pointer to file
 * return a string
 */
char* Minimum_allocation_str(FILE* in);
//--------------------------------------------------------------------------------------
/**
 * Deletes spaces in a string
 * str1 - string
 * return the copy of the str1 without spaces
 */
char* delete_space(char* str1);
//--------------------------------------------------------------------------------------
/**
 * Convert a string to lowercase
 * str - string
 */
void str_to_low(char* str);
//--------------------------------------------------------------------------------------
/**
 * Solves the problem of a file not found
 * file_name - file name
 */
void Error_file(char** file_name);