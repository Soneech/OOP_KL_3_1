#ifndef OBJECT3_H
#define OBJECT3_H
#include "Base.h"
#include <string>
using namespace std;

class Object3 : public Base {
public:
	Object3(Base* head, string name);
};
#endif