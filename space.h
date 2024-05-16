
#ifndef __SPACE__

#define __SPACE__

#include <iostream>

using std::string;
using std::cout;
using std::cerr;
using std::endl;

namespace n_space {

	template<class t>
	class space {

	private:

		t* pv;
		size_t* n;

	private:
		void copy(const t& v); void s_free(void);

	public:

		// 将一个数值 赋值给 即将要创建的类
		// 赋值
		space(const t& v);

		// 将已有的 类 赋值给 即将要创建的类
		// 创建链接
		space(const space<t>& s);

		~space(void);

		// 将已有的 类 赋值给 已经存在的类
		// 赋值
		space<t>& operator=(const space<t>& s);

		space<t> operator+(const space<t>& s) const;

		bool operator==(const space<t>& s) const;

		bool operator!=(const space<t>& s) const;

		bool operator>(const space<t>& s) const;

		bool operator>=(const space<t>& s) const;

		bool operator<(const space<t>& s) const;

		bool operator<=(const space<t>& s) const;

		space<t>& operator++(void);

		space<t> operator++(int dummy);

		space<t>& operator--(void);

		space<t> operator--(int dummy);

		operator t(void);

		void copy(const space<t>& s);

		void share(const space<t>& s);

		void set_value(const t& v);

		t& get_value(void);

	};

}


namespace n_space {

	// 赋值
	template<class t>
	space<t>::space(const t& v) {

		space<t>& object = *this;

		object.pv = nullptr;
		object.n = nullptr;

		object.copy(v);

		return;

	}

	// 共享
	template<class t>
	space<t>::space(const space<t>& s) {

		space<t>& object = *this;

		object.pv = nullptr;
		object.n = nullptr;

		object.share(s);

		return;

	}

	// 释放
	template<class t>
	space<t>::~space(void) {

		space<t>& object = *this;

		object.s_free();

		return;

	}

	template<class t>
	space<t>& space<t>::operator=(const space<t>& s) {

		space<t>& object = *this;

		object.set_value(*(s.pv));

		return object;

	}

	template<class t>
	space<t> space<t>::operator+(const space<t>& s) const {

		const space<t>& tt = *this;

		space<t> temp((*(tt.pv)) + (*(s.pv)));

		return temp;
	}

	template<class t>
	bool space<t>::operator==(const space<t>& s) const {

		const space<t>& tt = *this;

		return ((*(tt.pv)) == (*(s.pv)));
	}

	template<class t>
	bool space<t>::operator!=(const space<t>& s) const {

		const space<t>& tt = *this;

		return ((*(tt.pv)) != (*(s.pv)));

	}

	template<class t>
	bool space<t>::operator<(const space<t>& s) const {

		const space<t>& tt = *this;

		return ((*(tt.pv)) < (*(s.pv)));
	}

	template<class t>
	bool space<t>::operator<=(const space<t>& s) const {
		const space<t>& tt = *this;

		return ((*(tt.pv)) <= (*(s.pv)));
	}

	template<class t>
	bool space<t>::operator>(const space<t>& s) const {

		const space<t>& tt = *this;

		return ((*(tt.pv)) > (*(s.pv)));
	}

	template<class t>
	bool space<t>::operator>=(const space<t>& s) const {

		const space<t>& tt = *this;

		return ((*(tt.pv)) >= (*(s.pv)));
	}

	template<class t>
	space<t>& space<t>::operator++(void) {

		space<t>& object = *this;
		*(object.pv)++;

		return object;
	}

	template<class t>
	space<t> space<t>::operator++(int dummy) {

		space<t>& object = *this;

		space<t> temp(*(object.pv));

		*(object.pv)++;

		return temp;
	}

	template<class t>
	space<t>& space<t>::operator--(void) {

		space<t>& object = *this;
		*(object.pv)--;

		return object;
	}

	template<class t>
	space<t> space<t>::operator--(int dummy) {

		space<t>& object = *this;

		space<t> temp(*(object.pv));

		*(object.pv)--;

		return temp;
	}


	template<class t>
	space<t>::operator t(void) {

		space<t>& object = *this;

		return *(object.pv);

	}

	template<class t>
	void space<t>::copy(const t& v) {

		space<t>& object = *this;

		if (object.pv != nullptr && object.n != nullptr)
			object.s_free();


		try {
			object.pv = new t;
			*(object.pv) = v;
		}
		catch (...) {
			cerr << "space class init new t memory error" << endl;
			throw;
		}

		try {
			object.n = new size_t;
			*(object.n) = 1;
		}
		catch (...) {
			cerr << "space class init new size_t memory error" << endl;
			throw;
		}

		return;

	}

	template<class t>
	void space<t>::copy(const space<t>& s) {

		space<t>& object = *this;

		object.copy(*(object.pv));

		return;

	}

	template<class t>
	void space<t>::share(const space<t>& s) {

		space<t>& object = *this;

		if (object.pv != nullptr && object.n != nullptr)
			object.s_free();

		object.pv = s.pv;
		object.n = s.n;
		(*(object.n))++;

		return;

	}

	template<class t>
	void space<t>::s_free(void) {

		space<t>& object = *this;

		if (*(object.n) <= 1) {
			delete object.pv;
			delete object.n;
		}
		else {
			(*(object.n))--;
		}

		return;

	}



	template<class t>
	void space<t>::set_value(const t& v) {

		space<t>& object = *this;

		*(object.pv) = v;

		return;

	}

	template<class t>
	t& space<t>::get_value(void) {

		space<t>& object = *this;

		return *(object.pv);

	}

}


#endif // !__SPACE__
