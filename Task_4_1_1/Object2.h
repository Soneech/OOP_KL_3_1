#ifndef OBJECT2_H
#define OBJECT2_H
#include "Base.h"
#include <string>
using namespace std;

class Object2 : public Base {
public:
	Object2(Base* head, string name);
};
#endif