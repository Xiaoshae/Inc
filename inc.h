#ifndef __INC__

#define __INC__

#include <iostream>
#include <string>
#include <cstdlib>
#include <new>

using std::string;


namespace nsl_inc {


	class inc;

	inline namespace nsl_sn {


		class sn {

		private:

			inc** son;
			size_t amSon;

		protected:

			bool expand(void);
			bool expand(size_t amSon);


			bool reduce(void);
			bool reduce(size_t amSon);

			size_t sonOffset(const inc & i) const;

			


		public:

			sn(void) : son(nullptr), amSon(0) {  }

			sn(const sn& s);

			sn& operator=(const sn& s);

			const inc & operator[](size_t whnum) const;

			inc& operator[](size_t whnum);

			const inc& operator[](const string& name) const;

			inc& operator[](const string& name);

			bool push(const inc& i);

			inc& pop(const inc& i);
			
		};



	}



	class inc {

	private:

		string name;
		void* data;
		inc* father;
		sn son;

	protected:

		void* copy(void*& t,const void* s) {
			t = const_cast<void *>(s);
			return t;
		}

		void* assignment(void*& t,const void* s) {
			t = const_cast<void *>(s);
			return t;
		}

	public:

		inc(const string& name, void* data = nullptr)
			: name(name), data(data), father(nullptr), son(sn()) { }

		inc(const char* C_name = "", void* data = nullptr) 
			: inc((const string)(C_name), data) { }


		inc(const inc& i) :name(i.name),father(i.father),son(i.son) {

			inc& object = *this;

			//object.name = i.name;
			object.data = copy(object.data,i.data);
			//object.father = i.father;
			//object.son = i.son;

		}

		inc& operator=(const inc& i) {
			inc& object = *this;

			object.name = i.name;
			object.data = assignment(object.data, i.data);
			object.father = i.father;
			object.son = i.son;

			return object;
		}

		bool operator>(const inc& i) const;
		bool operator<(const inc& i) const;
		bool operator>=(const inc& i) const;
		bool operator<=(const inc& i) const;
		bool operator==(const inc& i) const;
		bool operator!=(const inc& i) const;

		bool insert(const inc& i) {

			inc& object = *this;

			return object.son.push(i);

		}

		bool insert(const string& name, void* data) {

			inc& object = *this;

			return object.insert(inc(name, data));

		}

		inc& remove(const inc& i) {

			inc& object = *this;

			return object.son.pop(i);

		}


	};


}



#endif // !__INC__
