#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include <string.h>

static void person_print(Person *this) {
	printf("Vorname:	%s\nNachname:	%s\nGeburtsjahr:	%d\n", this->first_name, this->last_name, this->year_of_birth);
}
static void person_greet(Person *this, const char *greeting) {
	printf("Hallo (Person) %s\n", greeting);
}
static void person_header() {
	printf("******\n");
}
/**
* Creates new Person and always makes it valid
* @param void
* @return an new Person
*/
Person* person_new() {
	Person *this = calloc(sizeof(char), sizeof(Person));
	this->print = &person_print;
	this->greet = &person_greet;
	this->header = &person_header;
	return this;
}

