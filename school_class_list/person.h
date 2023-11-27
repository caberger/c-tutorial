#pragma once

struct _Person;
typedef struct _Person Person;

/** member function without arguments */
typedef void (*function_0)(Person *);
/** member function with 1 argument */
typedef void (*function_1)(Person *, const char *greeting);
/** static member function */
typedef void (*function_static)(void);

struct _Person {
	// properties
	int year_of_birth;
	char first_name[40];
	char last_name[40];

	// methods
	function_0 print;
	function_1 greet;
	function_static header;

	// destructor
	function_0 delete;
};

/** Person constructor */
Person *person_new();
