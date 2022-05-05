#include "Base.h"
#include <iostream>
using namespace std;

Base::Base(Base* head, string name) {
	this->head = head;
	this->name = name;
	this->indicator = 0;
	if (head != nullptr)
		head->children.emplace_back(this);
}

void Base::set_name(string name) {
	this->name = name;
}

string Base::get_name() {
	return name;
}

void Base::print_hierarchy() {
	Base* current_object = this;
	cout << current_object->get_name();

	while (!current_object->children.empty()) {
		cout << endl;
		cout << current_object->get_name();
		for (auto& obj : current_object->children) {
			cout << " " << obj->get_name();
		}
		current_object = current_object->children.back();
	}
}

void Base::change_head(Base* new_head) {
	if (head != nullptr && new_head != nullptr) {
		head->children.erase(find(head->children.begin(), head->children.end(), this));

		this->head = new_head;
		head->children.insert(head->children.begin(), this);
	}
}

Base* Base::get_head() {
	return head;
}

Base* Base::find_element(const string& obj_name) {
	if (name == obj_name) 
		return this;
	for (auto child: children) {
		Base* result = child->find_element(obj_name);
		if (result != nullptr) 
			return result;
	}
	return nullptr;
}

void Base::print_tree() {
	if (this->get_head() == nullptr)
		cout << name;

	string tabs = "";
	Base* head_temp = this;
	while (head_temp->get_head() != nullptr) {
		head_temp = head_temp->get_head();
		tabs += "    ";
	}
	for (auto child: children) {
		cout << endl << tabs << child->get_name();
		child->print_tree();
	}
}

void Base::print_readiness() {
	if (this->get_head() == nullptr) {
		cout << this->name;
		if (!this->indicator)
			cout << " is not ready";
		if (this->indicator)
			cout << " is ready";
	}

	string tabs = "";
	Base* head_temp = this;
	while (head_temp->get_head() != nullptr) {
		head_temp = head_temp->get_head();
		tabs += "    ";
	}

	for (auto child : children) {
		cout << endl << tabs << child->get_name();
		if (!child->indicator)
			cout << " is not ready";
		if (child->indicator)
			cout << " is ready";
		child->print_readiness();
	}
}

void Base::set_readiness(int new_indicator) {
	if ((this->get_head() != nullptr && this->get_head()->indicator != 0) || this->get_head() == nullptr) {
		if (new_indicator == 0) {
			for (auto& child : this->children)
				child->set_readiness(0);
		}
		this->indicator = new_indicator;
	}
}

Base::~Base() {
	for (int i = 0; i < children.size(); i++) {
		delete children[i];
	}
}