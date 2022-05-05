#ifndef BASE_H
#define BASE_H
#include <string>
#include <vector>
using namespace std;

class Base {
	protected:
		string name = "default_name";
		Base* head;
		vector<Base*> children;
		int indicator = 0;
	public:
		Base(Base* head, string name);
		~Base();
		void set_name(string name);
		string get_name();
		void print_hierarchy();
		void change_head(Base* new_head);
		Base* get_head();
		
		Base* find_element(const string&);
		void print_tree();
		void print_readiness();
		void set_readiness(int);
};
#endif
