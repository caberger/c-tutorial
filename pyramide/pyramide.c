#include <stdio.h>
#include "pyramide.h"

Pyramide createPyramide() {
	Pyramide pyramide;
	pyramide.currentLine = 0;
	pyramide.currentRow = 0;
	
	return pyramide;
}
