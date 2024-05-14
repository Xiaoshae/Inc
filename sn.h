
#ifndef __SN__

#define __SN__

#include "space.h"
#include <string>
#include <cstdlib>

using std::string;


namespace lib_inc {

	class inc;

	namespace n_sn {

		using n_space::space;
		using sinc = space<inc**>;
		using am = space<size_t>;

		class sn {

		private:

			sinc son;
			am amSon;

		public:

			sn(void) :son(nullptr), amSon(0) {
				;
			}

			sinc& getSon(void) {
				sn& object = *this;
				return object.son;
			}

		};



	}

	namespace n_link {

		enum class method {
			hard = 0,
			symbolic = 1,
			mount = 3
		};

		using n_space::space;

		typedef inc* incptr;
		typedef inc** linkGroup;
		using sinc = space<inc**>;
		using gen = space<void*>;

		class link {

		private:

			method links;

			gen& data;
			sinc& son;

			linkGroup notice;
			size_t amNotice;



		private:

			bool expand(void) {

				link& object = *this;

				linkGroup newNotice = reinterpret_cast<linkGroup>(realloc(notice, (amNotice + 1) * 8));

				if (newNotice == nullptr) {
					;
				}

				object.notice = newNotice;
				object.amNotice++;

				return true;

			}

			void zoomOut(void) {

				link& object = *this;

				object.amNotice--;
				object.notice = reinterpret_cast<linkGroup>(realloc(notice, object.amNotice * 8));

				return;
			}

			// 上级发生变化，上级调用下级该函数进行通告
			bool requestNotice(gen& data, sinc& son) {
				link& object = *this;

				// 这里的赋值需要注意,还需要在仔细判断，这里为了抽象，先这么写
				object.data = data;
				object.son = son;

				object.responseNotice();

				return true;

			}

			// 接收当上级的变化通告，将通告继续传递到下级
			bool responseNotice(void) {

				link& object = *this;

				for (int i = 0; i < object.amNotice; i++) {

				}

			}



		public:

			link(gen& data, sinc& son) :data(data), son(son) {
				link& object = *this;
				object.links = method::hard;
				object.notice = nullptr;
				object.amNotice = 0;
				return;
			}

			bool append(incptr i) {

				link& object = *this;

				bool Judge = object.expand();

				if (Judge != true) {

				}

				object.notice[amNotice - 1] = i;

				return true;
			}

			bool reduce(incptr i) {

				link& object = *this;


				size_t n = 0;
				while (n < object.amNotice) {
					if (object.notice[n] == i) {
						break;
					}
					n++;
				}

				// linkGroupo中不存在这个incptr
				if (n == object.amNotice) {

				}

				while (n < object.amNotice - 1) {
					object.notice[n] = object.notice[n + 1];
					n++;
				}

				object.zoomOut();

				return true;
			}


		};
	}


}

#endif // !__SN__
