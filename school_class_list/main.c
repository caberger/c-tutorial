#include <stdio.h>
#include <string.h>

#include "person.h"
#include "student.h"

int main(void) {
	printf("--- a student ---\n");

	Student *student = student_new(); // we allocate a student
	student->mat_nr = 123456; // and set the mat_nr

	// a student is a person, so we treat her as a person from now on...
	Person *person = (Person *)student; 
	strcpy(person->first_name, "Jane");
	strcpy(person->last_name, "Roe");
	person->year_of_birth = 1995;
	person->header();
	person->greet(person, "Student");

	/** call the virtual print function */
	person->print(person); // 
	
	/** call the destructor */
	person->delete(person), person = NULL;

	printf("\n--- a person ---\n");
	person = person_new(); // now we create a "normal" person
	strcpy(person->first_name, "Joe");
	strcpy(person->last_name, "Sixpack");
	person->year_of_birth = 1997;
	person->header();
	person->greet(person, "Normale Person");
	person->print(person);
	person->delete(person), person = NULL;
	
	printf("=== done ===\n");
	return 0;
}
