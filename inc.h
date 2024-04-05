

#ifndef __INC__

#define __INC__

#include <iostream>

#include "space.h"



using std::string;
using std::cout;
using std::cerr;
using std::endl;



namespace lib_inc {

	class inc;


	using am = n_space::space<size_t>;
	using sinc = n_space::space<inc**>;


	inline namespace n_sn {

		class sn {

		private:
			sinc son;
			am amSon;

		public:

			// 新建
			sn(void);

			// 共享
			sn(const sn& s);

			// 共享
			sn& operator=(const sn& s);


			void hard(const sn& s);

			void symbolic(const sn& s);

			void copy(const sn& s);

			size_t getIndex(const string& name);

			inc& getObject(const size_t index);

			inc& getObject(const string& name);

			bool push(const inc& i);

			inc& pop(const size_t index);

			inc& pop(const string& name);

			const inc& operator[](const size_t index) const;

			inc& operator[](const size_t index);

			const inc& operator[](const string& name) const;

			inc& operator[](const string& name);

		};

	}


	class inc {

	private:

		string name;
		void** data;
		inc* father;
		sn son;
		enum class link
		{
			hard = 0,
			symbolic = 1
		};
		link type;
		size_t* n_link;

	private:

		inc(const string& name, void* data, inc* father);

		void setFather(inc* father);

		void hard(const inc& i);

		void symbolic(const inc& i);

		void copy(const inc& i);

		void* d_copy(void*& t, const void* s);


	public:

		inc(const char* C_name = "", void* data = nullptr);

		inc(const string& name, void* data = nullptr);

		inc(const inc& i);

		inc& operator=(const inc& i);

		bool insert(const inc& i);

		bool insert(const string& name, void* data);

		bool remove(size_t index);

		bool remove(const string& name);

		const void* operator[](const size_t index) const;

		void* operator[](const size_t index);

		const inc& operator[](const string& name) const;

		inc& operator[](const string& name);

	};



}

#endif // !__INC__
