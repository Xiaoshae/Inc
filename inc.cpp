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

	inc::~inc(void) {

	}

	// 支持 None Hard
	// 默认 None
	bool inc::inCrease(const string& name, const gen& data) {

		inc& o = *this;

		bool judge = false;

		if (nullptr == data)
			judge = o.inNone(inc(name, data));
		else
			judge = o.inHard(inc(name, data));

		return judge;

	}

	// 支持 None Hard inFolder Mount isSymbolic(const inc & i) inHardLink
	// 默认 Hard
	bool inc::inCrease(const inc& i, const types& ts) {

		inc& o = *this;

		bool judge = false;

		switch (ts) {
		case types::None: {
			judge = o.inNone(i);
			break;
		}
		case types::Hard: {
			judge = o.inHard(i);
			break;
		}
		case types::Folder: {
			judge = o.inFolder(i);
			break;
		}
		case types::Mount: {
			judge = o.inMount(i);
			break;
		}
		case types::Symbolic: {
			judge = o.inSymbolic(i);
			break;
		}
		case types::HardLink: {
			judge = o.inHardLink(i);
			break;
		}
		}

		return judge;

	}

	// 支持 Symbolic
	bool inc::inCrease(const string& name, const string & path) {

		inc& o = *this;

		bool judge = false;

		return judge;
	}

	bool inc::inNone(const string& name) {


	}

	bool inc::inNone(const inc& i) {

	}

	bool inc::inHard(const string& name, const gen& data) {


	}

	bool inc::inHard(const inc& i) {

		inc& o = *this;

		bool judge = false;

		if (i.CheckName() == true)
			judge = o.son.inCrease(i);

		return judge;
	}

	bool inc::inFolder(const inc& i) {

		return true;
	}

	bool inc::inMount(const inc& i) {

		return true;
	}

	bool inc::inSymbolic(const string& name, const string& path) {

	}

	bool inc::inSymbolic(const inc& i) {

		return true;
	}

	bool inc::inHardLink(const inc& i) {

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



	bool inc::reduce(const string& name) {

		inc& o = *this;

		return true;
	}

	bool inc::CheckName(void) const {

		const inc& o = *this;

		bool judge = true;

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
						judge = false;
						break;
					}

					j++;
				}

				i++;
			}

		}
		else {
			judge = false;
		}



		return judge;
	
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
