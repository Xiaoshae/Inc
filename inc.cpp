#include "inc.h"

namespace lib_inc {


	/*
	inc::inc(const char* name, const gen& data = nullptr) :
		inc(string(name), data) {
		;
	}

	explicit inc::inc(const string& name, const gen& data) :
		name(name),
		data(nullptr),
		father(nullptr),
		son(),
		links(*this) {

		return;
	}
	*/

	inc::inc(const inc& i) :data(nullptr), links(*this) {

		inc& o = *this;

		o.Copy(i);

		return;

	}

	inc::~inc(void) {

	}

	// 支持Copy
	bool inc::Increase(const string& name, const gen& data) {

		inc& o = *this;

		return o.inCopy(inc(name, data));

		return true;
	}

	// 支持	Copy Hard Mount
	// 默认	Copy
	bool inc::Increase(const inc& i, const types& links) {

		inc& o = *this;

		bool Judge = false;

		switch (links) {
		case types::Copy: {
			Judge = o.inCopy(i);
			break;
		}
		case types::Hard: {
			Judge = o.inHard(i);
			break;
		}
		case types::Mount: {
			Judge = o.inMount(i);
			break;
		}
		}

		return Judge;

	}

	// 支持 Symbolic
	// ts = types 简称
	bool inc::Increase(const string& path, const types& ts) {

		return true;
	}

	bool inc::inCopy(const inc& i) {

		inc& o = *this;

		o.son.inCopy(i);

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

		inc& o = *this;

		o.name = i.name;
		o.data = i.data;
		o.son.Copy(i.son);
		o.links.Copy(i.links);

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

		const inc& o = *this;

		bool Judge = true;

		size_t i = 0, j, length;

		const string& Name = o.name;

		// length = GetUTF-8Length
		length = 3;

		const char special_chars[9] = { '\\', '/', ':', '*', '?', '\"', '<', '>', '|' }; // 需要检查的特殊字符

		if (length > 0 && length <= 100) {

			while (i < Name.length()) {

				j = 0;
				while (j < 9) {

					if (Name[i] == special_chars[j]) {
						Judge = false;
						break;
					}

					j++;
				}

				i++;
			}

		}
		else {
			Judge = false;
		}



		return Judge;
	
	}

	string inc::GetName(void) const {

		const inc& o = *this;

		return o.name;
	}

	void* inc::GetData(void) const {

		const inc& o = *this;

		return o.data;
	}

	size_t inc::GetSonquantity(void) const {

		const inc& o = *this;

		return o.son.Getquantity();

	}

	inc::operator void* (void) const {

		const inc& o = *this;

		return o.data;
	}

	inc& inc::operator[](const size_t& n) {

		inc& o = *this;

		return o.son[n];

	}

	const inc& inc::operator[](const size_t& n) const {

		const inc& o = *this;

		return o.son[n];

	}

	inc& inc::operator[](const string& name) {

		inc& o = *this;

		return o.son[name];

	}

	const inc& inc::operator[](const string& name) const {

		const inc& o = *this;

		return o.son[name];

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

		const inc& o = *this;

		return o.name < i.name;
	}

	bool inc::operator<=(const inc& i) const {

		const inc& o = *this;

		return o.name <= i.name;

	}

	bool inc::operator>(const inc& i) const {

		const inc& o = *this;

		return o.name > i.name;

	}

	bool inc::operator>=(const inc& i) const {

		const inc& o = *this;

		return o.name >= i.name;
	}


}
