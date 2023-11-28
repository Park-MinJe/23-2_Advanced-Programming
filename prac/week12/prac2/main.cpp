#include "GraphicEditor.h"

int main() {
	GraphicEditor* ge = new GraphicEditor();
	ge->start();

	delete ge;
}