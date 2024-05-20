#include <iostream>
#include "inc.h"
#include "space.h"

using namespace std;

using lib_inc::inc;



int main(void) {

	cout << "Welcome to Program!" << endl;

	using am = n_space::space<size_t>;

	am abc = 0;

	cout << abc << endl;

	abc++;

	cout << abc << endl;

	// exit(0);


	cout << "------Start inc Program!------" << endl;

	inc a = "xiaoshae";

	cout << "Name:\t" << a.GetName() << "\t" << a << endl;


	int length = 0;
	cout << "Length:";

	cin >> length;

	cout << endl;


	for (int i = 0; i < length; i++) {

		string name;

		cin >> name;
	
		a.Increase(name);
		
		cout << "Name:\t" << a[name].GetName() << "\t" << a[name] << "\t" << "Quantity:\t" << a.GetSonquantity() << endl << endl;

	}

	cout << "------output------" << endl << endl;

	for (int i = 0; i < length; i++) {
		cout << "Name:\t" << a[i].GetName() << "\t" << a[i] << endl << endl;
	}




	return 0;
}



