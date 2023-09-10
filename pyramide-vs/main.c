
#include <stdio.h>
#include "pyramide.h"

int main() {
	Pyramide model = createPyramide();
	model.currentRow = 2;

	printf("Hello World! %dx%d\n", model.currentLine, model.currentRow);
}
