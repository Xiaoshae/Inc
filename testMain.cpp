#include <iostream>

#include "inc.h"


void incName::itf(void);

int main(void) {

	using std::cout;
	using std::endl;

	cout << "Welcome to infoContainer" << endl;


	incName::itf();

	return 0;
}

void incName::itf(void) {

	using std::cout;
	using std::endl;

	inc a;
	
	cout << a.base << endl;



	cout << a.getName() << endl;
	a.setName("base");
	cout << a.getName() << endl;
	
}