#include "Application.h"
#include "Object2.h"
#include "Object3.h"
#include "Object4.h"
#include "Object5.h"
#include "Object6.h"
#include <iostream>
#include <string>
using namespace std;

Application::Application(Base* head) : Base(head, "child") { }

void Application::build_tree_objects() {
	string name_parent, name_child;
	int type;
	cin >> name_parent;
	this->set_name(name_parent);

	do {
		cin >> name_parent;
		if (name_parent != "endtree") {
			cin >> name_child >> type;
			Base* parent_node = find_element(name_parent);
			switch (type) {
				case 2:
					new Object2(parent_node, name_child);
					break;
				case 3:
					new Object3(parent_node, name_child);
					break;
				case 4:
					new Object4(parent_node, name_child);
					break;
				case 5:
					new Object5(parent_node, name_child);
					break;
				case 6:
					new Object6(parent_node, name_child);
					break;
				default:
					break;
			}
		}
	} while (name_parent != "endtree");
}

int Application::execute() {
	string name_temp;
	int indicator;
	while (cin >> name_temp >> indicator) {
		Base* found = find_element(name_temp);
		if (found != nullptr) 
			found->set_readiness(indicator);
	}
	cout << "Object tree" << endl;
	print_tree();
	cout << endl << "The tree of objects and their readiness" << endl;
	print_readiness();
	return 0;
}