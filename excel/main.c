// ConsoleApplication1.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 80
#define MAX_NUMBER_OF_COLUMNS 40
#define MAX_PATH 512
#define DELIMITER ","

typedef struct
{
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    int height;
} Person;

Person* parse_person(char ** columns) {
    Person* person = calloc(1, sizeof(Person));
    int col = 0;
    strncpy(person->first_name, columns[col++], MAX_NAME_LENGTH);
    strncpy(person->last_name, columns[col++], MAX_NAME_LENGTH);
    person->height = atoi(columns[col++]);
    return person;
}
void print_person(FILE *fp, Person *person) {
    fprintf(fp, "Person first_name=%s, last_name=%s, height=%d\n", person->first_name, person->last_name, person->height);
}
enum ParserState {
    outside, // no '"' found until now
    inside // reading the current string inside the first '"'
};
char ** parse_csv_line(const char *line) {
    char **fields = calloc(MAX_NUMBER_OF_COLUMNS, sizeof(char *));
    char **current_field = fields;
    char *destination_buffer = malloc(strlen(line)); // we remove the "" and set replace the comma by a \0, so that should be enough :)
    enum ParserState state = outside;
    char *current_write_position = destination_buffer; //the location where the next byte is written to.
    const char *reading_position; // the next position we will read from the line.
    int numberOfColumnsFinished = 0;
    for (const char *reading_position = line; *reading_position && numberOfColumnsFinished < MAX_NUMBER_OF_COLUMNS; reading_position++) {
        char ch = *reading_position;
        switch(state) {
            case outside:
                if (ch == '"') { // start of new string 
                    *current_field = current_write_position;
                    state = inside;
                } else if (ch == '"') {
                    // ignore
                } else {
                    // ignore this stuff
                }
                break;
            case inside:
                if (ch == '"') { // end of next string
                    state = outside;
                    *current_write_position++ = '\0';
                    numberOfColumnsFinished++;
                    current_field = &fields[numberOfColumnsFinished];
                } else {
                    *current_write_position++ = ch;
                }
                break;
        }
    }
    return fields;
}
int main(void)
{
    char *line = NULL;
    long max_path = pathconf(".", _PC_PATH_MAX);

    char current_directory[MAX_PATH];
    char *directory = getwd(current_directory);
    printf("directory: %s\n", directory);

    FILE * fp = fopen("persons.csv", "r");
    if (!fp) {
        printf("cannot open file\n");
        exit(EXIT_FAILURE);
    }

    char buffer[80];
    int fertig = 0;
    int count_of_lines = 0;
    while (!fertig) {
        const char* current_buffer = fgets(buffer, 80, fp);
        if (current_buffer) {
            if (count_of_lines > 0) {
                char **columns = parse_csv_line(current_buffer);
                Person* person = parse_person(columns);
                print_person(stdout, person);
                free(person), person = NULL;
                free(columns), columns = NULL;
            }
            else {
                printf("skip header line %s", current_buffer);
            }
            count_of_lines++;
        } else {
            fertig = 1;
        }
    }
    fclose(fp);
    if (line) {
        free(line);
    }
    exit(EXIT_SUCCESS);
}


                /*

                [Spalte][Zeile]

                durchlaufen, wenn spalte='"'
                    dann zeile anschuen und ausschrieben
                    falls zeichen = '"' dann spalte ++;



                        
                 "Vorname", "Nachname", "Groesse"
                 "John", "Doe", "170"
                 "Max", "Muster", "180",





                */