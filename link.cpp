#include "link.h"
#include "inc.h"


namespace lib_inc {

	namespace n_link {

		link::link(inc& i) :
			ts(types::None),
			tg(nullptr),
			hn(1),
			i(i),
			sonback(nullptr),
			amSonback(0),
			notice(nullptr),
			amNotice(0)
		{
			;
		}

		link::~link(void) {

		}


		bool link::expand(void) {

			link& o = *this;

			linkGroup newNotice = reinterpret_cast<linkGroup>(realloc(notice, (amNotice + 1) * sizeof(void*)));

			if (newNotice == nullptr) {
				cout << "Error: class link | expand Memory Error!" << endl;
				throw;
			}

			o.notice = newNotice;
			o.amNotice++;

			return true;

		}

		void link::zoomOut(void) {

			link& o = *this;

			o.amNotice--;
			o.notice = reinterpret_cast<linkGroup>(realloc(notice, o.amNotice * sizeof(void*)));

			return;
		}

		// 上级发生变化，上级调用下级该函数进行通告
		bool link::takeOver(ctypes cs) {
			link& o = *this;

			switch (cs)
			{
			case ctypes::Delete: {
				break;
			}
			case ctypes::UpperLayer: {
				// o.son = o.Target->son.son;
				o.transfer(cs);
				break;
			}
			case ctypes::JoinLink: {
				break;
			}
			case ctypes::UnLink: {
				break;
			}
			}

			o.transfer(cs);

			return true;

		}

		// 接收当上级的变化通告，将通告继续传递到下级
		bool link::transfer(ctypes cs) {

			link& o = *this;

			for (int i = 0; i < o.amNotice; i++) {
				o[i].links.takeOver(cs);
				// (*(o.notice[i])).links.takeOver(cs);
			}

			return true;
		}

		

		// 取消链接
		bool link::joinLink(inc& i) {

			link& o = *this;

			return o.append(&i);

		}

		// 取消链接
		bool link::unLink(inc& i) {

			link& o = *this;

			return o.reduce(&i);

		}


		bool link::append(incptr i) {

			link& o = *this;

			bool judge = o.expand();

			if (judge != true) {
				cout << "Error: class link | append to expand Error!" << endl;
				throw;
			}

			o.notice[amNotice - 1] = i;

			return true;
		}

		bool link::reduce(incptr i) {

			link& o = *this;


			size_t n = 0;
			while (n < o.amNotice) {
				if (o.notice[n] == i) {
					break;
				}
				n++;
			}

			// linkGroupo中不存在这个incptr
			if (n == o.amNotice) {

			}

			while (n < o.amNotice - 1) {
				o.notice[n] = o.notice[n + 1];
				n++;
			}

			o.zoomOut();

			return true;
		}

		

		void link::Copy(const link& l) {

			link& o = *this;

			o.ts = l.ts;

			if (o.ts == types::Symbolic) {
				o.stg = l.stg;
			}
			else {
				o.tg = l.tg;
			}

			o.hn = 1;
			o.notice = nullptr;
			o.amNotice = 0;

			return;
		}

		void link::toNone(const link& l) {

			link& o = *this;

			switch (o.ts)
			{
			case types::None: { 
				// None to None 无需任何操作
				break;
			}
			case types::Hard: { 
				// Hard to None 需要删除data 

				// fun() 这里需要调用一个删除删掉data 或者保证data不存在的函数

				o.ts == types::None;

				break;
			}
			case types::Folder: { 
				// Folder to None 需要删除 son 和 data(有的话)

				// fun() 这里需要保证 son 和 data 不存在

				o.ts = types::None;

				break;
			}
			case types::Mount: {
				// Mount to None
				// 1. 取消挂载
				// 2. 用户取消挂载后，如果不存在son和data会自动变为None
				// 3. 也可以手动调用该方法变为None，该方法会 取消挂载 并删除 son 和 data
				break;
			}
			case types::Symbolic: { 
				// Symbolic to None 取消链接
				// 1. 用户取消链接后，会自动变为None
				// 2. 也可以手动调用该方法变为None，该方法会 取消链接
				break;
			}
			}

		}

		void link::toHard(const link & l) {

			link& o = *this;

			switch (o.ts)
			{
			case types::None: { 
				// None to Hard 无需任何操作
				// 1. 当发生变化是会自动进行操作
				break;
			}
			case types::Hard: { 
				// Hard to Hard 无需任何操作
				break;
			}
			case types::Folder: { // Folder to None 需要删除 son 和 data(有的话)
				break;
			}
			case types::Mount: {
				// Mount to None
				// 1. 取消挂载
				// 2. 删除 son 有的话
				// 3. 删除 data 有的话
				break;
			}
			case types::Symbolic: { // Symbolic to None 取消链接
				break;
			}
			}

		}


		inc& link::operator[](const size_t& n) {

			link& o = *this;

			if (!(n >= 0 && n <= o.amNotice)) {
				cout << "Error:out of index" << endl;
				throw;
			}

			return (*(o.notice[n]));
		}

		const inc& link::operator[](const size_t& n) const {

			const link& o = *this;

			if (!(n >= 0 && n <= o.amNotice)) {
				cout << "Error:out of index" << endl;
				throw;
			}

			return (*(o.notice[n]));
		}

		void link::autoSet(void) {

			link& o = *this;

			if (nullptr == i.data && 0 == o.i.son.amSon) {
				o.ts = types::None;
			}
			else if(nullptr != i.data && 0 == o.i.son.amSon) {
				o.ts = types::Hard;
			}
			else if (0 != o.i.son.amSon) {
				o.ts = types::Folder;
			}

		}





	}

}
