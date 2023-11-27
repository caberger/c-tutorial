#pragma once
#include "person.h"

struct _Student {
	Person super;
	int mat_nr;
	
	//vtable, @see https://en.wikipedia.org/wiki/Virtual_method_table
	function_0 super_print;
};
typedef struct _Student Student;

Student *student_new();
