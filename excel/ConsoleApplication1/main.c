// ConsoleApplication1.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
//#define _POSIX_C_SOURCE 200809L

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#define GetCurrentDir _getcwd

#define MAX_NAME_LENGTH 80
#define DELIMITER ","
typedef struct
{
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    int height;
} Person;

Person* parse_person(const char *line) {
    Person* person = calloc(1, sizeof(Person));
    return person;
}

int main(void)
{
    FILE* fp = NULL;
    char* line = NULL;
    size_t len = 0;
    size_t read;

    char directory[_MAX_PATH];
    const char* pwd = GetCurrentDir(directory, _MAX_PATH);
    printf("directory: %s\n", pwd);
    fopen_s(&fp, "persons.csv", "r");
    if (fp == NULL) {
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
                const Person* person = parse_person(current_buffer);
                free(person), person = NULL;
                printf("%s\n", current_buffer);
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