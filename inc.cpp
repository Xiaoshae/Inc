﻿#include "inc.h"


namespace nsl_inc {

	inline namespace nsl_sn {

		sn::sn(const sn& s) {

			sn& object = *this;

			bool event = object.expand();

			if (event == true) {

				for (size_t i = 0; i < s.amSon; i++) {

					object[i] = s[i];

				}

			}


		}

		sn& sn::operator=(const sn& s) {

			sn& object = *this;

			if (object.amSon > 0) {
		
				if (object.amSon > s.amSon)
					object.reduce(object.amSon - s.amSon);

				else if(object.amSon < s.amSon)
					object.expand(s.amSon - object.amSon);

			}

			object.amSon = s.amSon;

			for (size_t i = 0; i < object.amSon; i++) {
				object[i] = s[i];
			}

		}

		bool sn::expand(void) {

			sn& object = *this;

			bool event = false;

			// 创建内存 或 扩大内存 inc指针数组
			inc** newptr = reinterpret_cast<inc**>
				(realloc(object.son, sizeof(inc*) * (object.amSon + 1)));

			// 内存分配成功
			if (newptr != nullptr) {

				object.son = newptr;

				// 分配 inc 内存
				try {
					object.son[amSon] = new inc;
				}// 分配 inc 内存失败
				catch (const std::bad_alloc& error) {
					object.son[amSon] = nullptr;
					std::cerr << "memory error:" <<
						"Failed to allocate memory for inc object" <<
						"|" << error.what() << std::endl;
					throw;
				}

				//分配inc内存成功
				if (object.son[amSon] != nullptr) {
					object.amSon++;
					event = true;
				}

			}
			else {
				std::cerr << "memory error:" << "inc pointer arrya memory allocation failed" << std::endl;
				throw;
			}

			return event;
		}

		bool sn::expand(size_t amSon) {

			sn& object = *this;
			bool event = true;

			for (size_t i = 0; i < amSon && event == true; i++) {

				event = object.expand();

			}

			return event;
		}

		bool sn::reduce(void) {

			sn& object = *this;

			bool event = false;

			// 缩小一个内存 要求不为0
			if (object.amSon > 0) {

				delete& (object[amSon - 1]);

				inc** newptr = reinterpret_cast<inc**>
					(realloc(object.son, sizeof(inc*) * (object.amSon - 1)));

				// 缩小内存失败 出现系统级错误 抛出 匿名异常
				if (newptr == nullptr) {
					std::cerr << "memory error:" << "Memory shrink failed" << std::endl;
					throw;
				}
				else { // 缩小内存成功

					object.son = newptr;
					object.amSon--;

					event == true;

				}

			}

			return event;
		}

		bool sn::reduce(size_t amSon) {

			sn& object = *this;
			bool event = true;

			for (size_t i = 0; i < amSon && event == true; i++) {

				event = object.reduce();

			}

			return event;
		}


		bool sn::push(const inc& i) {

			sn& object = *this;

			bool event = false;

			size_t offset = 0;

			while (offset < object.amSon) {

				if (object[offset] < i) {
					offset++;
				}

			}

			if (object[offset] != i) {

				bool ed_event = object.expand();

				if (ed_event = true) {

					for (size_t count = amSon; count > offset; count--) {

						object[count] = object[count - 1];

					}

					object[offset] = i;
					event = true;
				}

			}

			return event;

		}

		const inc& sn::operator[](size_t whnum) const {

			const sn& object = *this;

			if (whnum >= amSon)
				throw;

			return *(object.son[whnum]);

		}

		inc& sn::operator[](size_t whnum) {

			sn& object = *this;

			if (whnum >= amSon)
				throw;

			return *(object.son[whnum]);

		}


	}


	bool inc::operator>(const inc& i)const {

		const inc& object = *this;

		return object.name > i.name;

	}

	bool inc::operator<(const inc& i)const {

		const inc& object = *this;

		return object.name < i.name;

	}

	bool inc::operator>=(const inc& i)const {

		const inc& object = *this;

		return object.name >= i.name;

	}

	bool inc::operator<=(const inc& i)const {

		const inc& object = *this;

		return object.name <= i.name;

	}

	bool inc::operator==(const inc& i)const {

		const inc& object = *this;

		return object.name == i.name;

	}

	bool inc::operator!=(const inc& i)const {

		const inc& object = *this;

		return object.name != i.name;

	}

}