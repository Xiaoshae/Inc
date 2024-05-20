
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
		void copy(const t& v);
			
		void s_free(void);

		t& get_value(void);

	public:

		// 将一个数值 赋值给 即将要创建的类
		// 赋值
		space(const t& v);

		// 将已有的 类 赋值给 即将要创建的类
		// 创建链接
		space(const space<t>& s);

		~space(void);

		operator t(void) const ;

		// 将已有的 类 赋值给 已经存在的类
		// 赋值
		space<t>& operator=(const space<t>& s);

		//space<t> operator+(const space<t>& s) const;

		space<t> operator+=(const space<t>& s);

		//space<t> operator-(const space<t>& s) const;

		space<t> operator-=(const space<t>& s);

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



		void copy(const space<t>& s);

		void share(const space<t>& s);

		void set_value(const t& v);

		const t& get_value(void) const ;

	};

}


namespace n_space {

	// 赋值
	template<class t>
	space<t>::space(const t& v) {

		space<t>& o = *this;

		o.pv = nullptr;
		o.n = nullptr;

		o.copy(v);

		return;

	}

	// 共享
	template<class t>
	space<t>::space(const space<t>& s) {

		space<t>& o = *this;

		o.pv = nullptr;
		o.n = nullptr;

		o.share(s);

		return;

	}

	// 释放
	template<class t>
	space<t>::~space(void) {

		space<t>& o = *this;

		o.s_free();

		return;

	}

	template<class t>
	space<t>::operator t(void) const {

		const space<t>& o = *this;

		return o.get_value();

	}


	template<class t>
	space<t>& space<t>::operator=(const space<t>& s) {

		space<t>& o = *this;

		o.set_value(*(s.pv));

		return o;

	}

	/*
	template<class t>
	space<t> space<t>::operator+(const space<t>& s) const {

		const space<t>& tt = *this;

	}
	*/

	template<class t>
	space<t> space<t>::operator+=(const space<t>& s) {

		const space<t>& tt = *this;

	}

	/*
	template<class t>
	space<t> space<t>::operator-(const space<t>& s) const {

		const space<t>& tt = *this;

	}
	*/

	template<class t>
	space<t> space<t>::operator-=(const space<t>& s) {

		const space<t>& tt = *this;


	}

	template<class t>
	bool space<t>::operator==(const space<t>& s) const {

		const space<t>& tt = *this;

		return tt.get_value() == s.get_value();
	}

	template<class t>
	bool space<t>::operator!=(const space<t>& s) const {

		const space<t>& tt = *this;

		return tt.get_value() != s.get_value();
	}

	template<class t>
	bool space<t>::operator<(const space<t>& s) const {

		const space<t>& tt = *this;

		return tt.get_value() < s.get_value();
	}

	template<class t>
	bool space<t>::operator<=(const space<t>& s) const {
		const space<t>& tt = *this;

		return tt.get_value() <= s.get_value();
	}

	template<class t>
	bool space<t>::operator>(const space<t>& s) const {

		const space<t>& tt = *this;

		return tt.get_value() > s.get_value();
	}

	template<class t>
	bool space<t>::operator>=(const space<t>& s) const {

		const space<t>& tt = *this;

		return tt.get_value() >= s.get_value();
	}

	template<class t>
	space<t>& space<t>::operator++(void) {

		space<t>& o = *this;
		o.get_value()++;

		return o;
	}

	template<class t>
	space<t> space<t>::operator++(int dummy) {

		space<t>& o = *this;

		space<t> temp(o.get_value());

		o.get_value()++;

		return temp;
	}

	template<class t>
	space<t>& space<t>::operator--(void) {

		space<t>& o = *this;
		o.get_value()--;

		return o;
	}

	template<class t>
	space<t> space<t>::operator--(int dummy) {

		space<t>& o = *this;

		space<t> temp(o.get_value());

		o.get_value()--;

		return temp;
	}


	template<class t>
	void space<t>::copy(const t& v) {

		space<t>& o = *this;

		if (o.pv != nullptr && o.n != nullptr)
			o.s_free();


		try {
			o.pv = new t;
			*(o.pv) = v;
		}
		catch (...) {
			cerr << "space class init new t memory error" << endl;
			throw;
		}

		try {
			o.n = new size_t;
			*(o.n) = 1;
		}
		catch (...) {
			cerr << "space class init new size_t memory error" << endl;
			throw;
		}

		return;

	}

	template<class t>
	void space<t>::copy(const space<t>& s) {

		space<t>& o = *this;

		o.copy(*(o.pv));

		return;

	}

	template<class t>
	void space<t>::share(const space<t>& s) {

		space<t>& o = *this;

		if (o.pv != nullptr && o.n != nullptr)
			o.s_free();

		o.pv = s.pv;
		o.n = s.n;
		(*(o.n))++;

		return;

	}

	template<class t>
	void space<t>::s_free(void) {

		space<t>& o = *this;

		if (*(o.n) <= 1) {
			delete o.pv;
			delete o.n;
		}
		else {
			(*(o.n))--;
		}

		return;

	}



	template<class t>
	void space<t>::set_value(const t& v) {

		space<t>& o = *this;

		*(o.pv) = v;

		return;

	}

	template<class t>
	t& space<t>::get_value(void) {

		space<t>& o = *this;

		return *(o.pv);
	}

	template<class t>
	const t& space<t>::get_value(void) const {

		const space<t>& o = *this;

		return *(o.pv);

	}

}


#endif // !__SPACE__
