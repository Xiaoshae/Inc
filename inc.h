#pragma once

#ifndef __INC__

#define __INC__

#include <iostream>

#include "space.h"
#include "sn.h"
#include "link.h"

using std::string;
using std::cout;
using std::cerr;
using std::endl;

namespace lib_inc {


	class inc;

	using incptr = inc**;
	using gen = n_space::space<void*>;

	using n_sn::sn;
	using n_link::link;

	using n_link::types;

	class inc {

	private:

		friend class link;

		string name;
		gen data;
		incptr father;
		sn son;
		link links;

	public:

		inc(const char* name = "", const gen& data = nullptr) :
			inc(string(name), data)
		{
			;
		}

		explicit inc(const string& name, const gen& data = nullptr) :
			name(name),
			data(nullptr),
			father(nullptr),
			son(),
			links(*this)
		{
			;
		}

		inc(const inc& i);

		~inc(void);

	private:


	public:

		// 支持 Copy
		bool Increase(const string& name, const gen& data = nullptr);

		// 支持 Copy Hard Mount
		// 默认 Copy
		bool Increase(const inc& i, const types& linktype);

		// 支持 Symbolic
		bool Increase(const string& path, const types& linktype);

		// inCopy
		bool inCopy(const inc& i);

		// inHard
		bool inHard(const inc& i);

		// inSymbolic
		bool inSymbolic(const inc& i);

		// inMount
		bool inMount(const inc& i);

		bool Copy(const inc& i);

		bool Mount(const inc& i);

		bool reduce(const string& name);

		bool CheckName(void) const;

		string GetName(void) const;

		void* GetData(void) const;

		size_t GetSonquantity(void) const;

		bool joinLink(const inc& i);

		bool unLink(const inc& i);

		operator void* (void) const ;

		inc& operator[](const size_t & n);

		const inc& operator[](const size_t& n)const;

		inc& operator[](const string& name);

		const inc& operator[](const string& name)const;

		bool operator==(const inc& i) const;

		bool operator!=(const inc& i) const;

		bool operator<(const inc& i) const;

		bool operator<=(const inc& i) const;

		bool operator>(const inc& i) const;

		bool operator>=(const inc& i) const;

	};

}

#endif // !__INC__
