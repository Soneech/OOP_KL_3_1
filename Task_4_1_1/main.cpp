#include <iostream>
#include "Application.h"

int main() {
	Application app(nullptr);
	app.build_tree_objects();
	return app.execute();
}