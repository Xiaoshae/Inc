

#ifndef __INC__

#define __INC__

#include <iostream>
using std::string;
using std::cout;
using std::cerr;
using std::endl;

namespace lib_inc {

	inline namespace n_space {

		template<class t>
		class space {

		private:

			t* data;
			size_t* n;

		private:
	
			void copy(const t& data);

		public:

			// 将一个数值 赋值给 即将要创建的类
			// 赋值
			space(const t& data);

			// 将已有的 类 赋值给 即将要创建的类
			// 创建链接
			space(const space<t>& s);

			~space(void);

			// 将已有的 类 赋值给 已经存在的类
			// 赋值
			space<t>& operator=(const space<t>& s);

			operator t(void);

			
			void copy(const space<t>& s);

			void share(const space<t>& s);

		};

	}

	class n_inc::inc;

	inline namespace n_sn{

		class sn {

		private:
			inc*** son;
			size_t * amSon;

		public:

			sn(void);

			sn(const sn& s);

			sn& operator=(const sn& s);


			void hard(const sn& s);

			void symbolic(const sn& s);

			void copy(const sn& s);

			size_t getIndex(const string& name);

			inc& getObject(const size_t index);

			inc& getObject(const string& name);

			bool push(const inc& i);

			inc & pop(const size_t index);

			inc & pop(const string& name);

			const inc& operator[](const size_t index) const;

			inc& operator[](const size_t index);

			const inc& operator[](const string& name) const;

			inc& operator[](const string& name);

		};

	}

	inline namespace n_inc {
		
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


}

#endif // !__INC__
