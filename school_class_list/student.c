#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "student.h"

static void student_print(Person* person) {
	Student *this = (Student *)person;
	this->super_print((Person *)this);
	printf("Mat.Nr:\t\t%d\n", this->mat_nr);
}
static void student_greet(Person *person, const char *greeting) {
	printf("Hallo, ich bin ein Student: %s\n", greeting);
}
Student* student_new() {
	Student *this = calloc(sizeof(char), sizeof(Student));
	Person *super = person_new();
	
	memcpy(&this->super, super, sizeof(Person));
	this->super.greet = &student_greet;
	this->super_print = this->super.print;
	this->super.print = &student_print;
	return this;
}
