#pragma once

struct _Person;
typedef struct _Person Person;

typedef void (*print_function)(Person *);
typedef void (*greeting_function)(Person *, const char *greeting);
typedef void (*header_function)(void);

struct _Person {
	// properties
	int year_of_birth;
	char first_name[40];
	char last_name[40];
	// methods
	print_function print;
	greeting_function greet;
	header_function header;
};

Person *person_new();
