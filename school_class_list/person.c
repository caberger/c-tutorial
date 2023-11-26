#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include <string.h>

static void person_print(Person *this) {
	printf("Vorname:	%s\nNachname:	%s\nGeburtsjahr:	%d\n", this->first_name, this->last_name, this->year_of_birth);
}
/**
* Creates new Person and always makes it valid
* @param void
* @return an new Person
*/
Person* person_new() {
	Person *this = calloc(sizeof(char), sizeof(Person));
	this->print = &person_print;
	return this;
}