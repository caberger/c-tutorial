#include <stdio.h>
#include <string.h>

#include "person.h"
#include "student.h"

int main(void) {
	printf("--- a student ---\n");

	Student *student = student_new(); // we allocate a student
	student->mat_nr = 123456; // and set her data

	// a student is a person, so we treat her as a person from now on...
	Person *person = (Person *)student; 
	strcpy(person->first_name, "Jane");
	strcpy(person->last_name, "Roe");
	person->year_of_birth = 1995;
	(*person->header)();
	(*person->greet)(person, "Student");

	(person->print)(person);

	printf("\n--- a person ---\n");
	Person *person2 = person_new(); // now we create a "normal" person
	strcpy(person2->first_name, "Joe");
	strcpy(person2->last_name, "Sixpack");
	person2->year_of_birth = 1997;
	(*person2->header)();
	(*person2->greet)(person, "Normale Person");
	(*person2->print)(person2);
	
	printf("=== done ===\n");
	return 0;
}
