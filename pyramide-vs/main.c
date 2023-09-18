#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include "pyramide.h"

int main() {
	Pyramide model = createPyramide();
	model.currentRow = 2;
	printf("Hello World! %dx%d\n", model.currentLine, model.currentRow);

	// This is an intentional memory leak to demonstrate memory debugging
	const char* text = "not freed !";
	char *leak = malloc(strlen(text) + 1);
	strcpy(leak, text);

	// this is intentionally skipped: free(leak);

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
}
