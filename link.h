#pragma once

#ifndef __LINK__

#define __LINK__

#include "space.h"
#include <string>

using std::string;

namespace lib_inc {

	class inc;

	namespace n_link {


		enum class types {
			Copy = 0,
			Hard = 1,
			Symbolic = 2,
			Mount = 3,
			Folder = 4
		};

		enum class ctypes {
			// 被挂载点删除
			Delete = 0,
			UpperLayer = 1,
			JoinLink = 2,
			UnLink = 3
		};

		using sinc = n_space::space<inc**>;
		using gen = n_space::space<void*>;
		using am = n_space::space<size_t>;

		using incptr = inc*;
		using linkGroup = inc**;

		class link {

		private:

			// 当前inc的类型 
			types linktype;

			union {
				// 相对/绝对路径的Symbolic
				string SymbolicTarget;
				// 直接挂载到某处
				incptr Target;	
			};

		
			// 硬链接 数量
			am hn_link;

			// 当一个普通类型从成为挂载类型，则将普通类型中原有的son保存下来
			// 当取消挂载的时候，在设置回去

			// son的备份
			linkGroup backSon;

			gen& data;
			sinc& son;
			am& amSon;

			// 链接到当前inc的节点组
			linkGroup notice;

			// 节点组数量
			size_t amNotice;

		public:

			link(inc & i);
			~link(void);

		private:

			bool expand(void);

			void zoomOut(void);

			//接收
			bool takeOver(ctypes cs);

			//传递
			bool transfer(ctypes cs);

			bool joinLink(inc& i);

			bool unLink(inc& i);


		public:


			bool append(incptr i);

			bool reduce(incptr i);

			void Copy(const link& l);

			inc& operator[](const size_t& n);
			const inc& operator[](const size_t& n) const;

		};
	}
}


#endif


