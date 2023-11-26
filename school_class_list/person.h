#pragma once

struct _Person;
typedef struct _Person Person;

typedef void (*print_function)(Person *);

struct _Person {
	int year_of_birth;
	char first_name[40];
	char last_name[40];
	print_function print;
};

Person *person_new();
