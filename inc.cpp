#include "inc.h"

namespace lib_inc {


	inc::inc(const string& name, const gen& data) :
		name(name),
		data(nullptr),
		father(nullptr),
		son(),
		links(*this){

		return;
	}

	inc::~inc(void) {

	}

	// 支持Copy
	bool inc::Increase(const string& name, const gen& data) {

		inc& object = *this;

		return object.inCopy(inc(name, data));

		return true;
	}

	// 支持	Copy Hard Mount
	// 默认	Copy
	bool inc::Increase(const inc& i, const types& links) {

		inc& object = *this;

		bool result = false;

		switch (links){
			case types::Copy : {
				result = object.inCopy(i);
				break;
			}
			case types::Hard : {
				result = object.inHard(i);
				break;
			}
			case types::Mount: {
				result = object.inMount(i);
				break;
			}
		}

		return result;
	
	}

	// 支持 Symbolic
	bool inc::Increase(const string& path, const types& links) {
	
		return true;
	}

	bool inc::inCopy(const inc& i) {

		return true;
	}

	bool inc::inHard(const inc& i) {

		return true;
	}

	bool inc::inSymbolic(const inc& i) {

		return true;
	}

	bool inc::inMount(const inc& i) {

		return true;
	}

	bool inc::Copy(const inc& i) {

		inc& object = *this;

		object.name = i.name;
		object.data = i.data;
		object.son.Copy(i.son);
		//object.links = i.links.Copy();

		return true;
	}

	bool inc::Hard(const inc& i) {

		return true;
	}

	bool inc::Mount(const inc& i) {

		return true;
	}

	bool inc::Symbolic(const inc& i) {

		return true;
	}


	bool inc::reduce(const string& name) {

		inc& object = *this;

		return true;
	}

	bool inc::CheckName(void) const {

		return true;
	}

	bool inc::operator==(const inc& i) const {

		const inc& o = *this;

		return o.name == i.name;
	}

	bool inc::operator!=(const inc& i) const {

		const inc& o = *this;

		return o.name != i.name;
	}

	bool inc::operator<(const inc& i) const {

		const inc & o = *this;

		return o.name < i.name;
	}

	bool inc::operator<=(const inc& i) const  {

		const inc& o = *this;

		return o.name <= i.name;

	}

	bool inc::operator>(const inc& i) const  {

		const inc& o = *this;

		return o.name > i.name;

	}

	bool inc::operator>=(const inc& i) const {

		const inc& o = *this;

		return o.name >= i.name;
	}


}
