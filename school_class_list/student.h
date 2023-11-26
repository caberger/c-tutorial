#pragma once
#include "person.h"

struct _Student {
	Person super;
	int mat_nr;
	
	//private
	print_function super_print;
};
typedef struct _Student Student;

Student *student_new();
