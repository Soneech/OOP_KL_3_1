#ifndef APPLICATION_H
#define APPLICATION_H
#include "Base.h"

class Application : public Base {
	public:
		Application(Base* head);
		void build_tree_objects();
		int execute();
};
#endif
