#include "inc.h"


namespace incName {

	inc::inc(u8 newName, null newFet) {

		inc& object = *this;

		
		object.base = new thmulte;

		if (object.base != NULL) {

			multeSpec& specific = *object.base;

			specific.Name = newName;
			specific.Fet = newFet;
			specific.Son = (sn)(NULL);
			specific.amSon = 0;


			object.autoFet = false;
			object.newFet = NULL;
			object.endingFet = NULL;

			object.abnCode = false;
		}
		else { //内存分配失败
			object.abnCode = 1;
		}

	}

	bool inc::setName(u8 newName) {
		inc& object = *this;

		bool StatucCode = false;

		//无异常
		if (object.abnCode == false) {

			multeSpec& specific = *object.base;
			specific.Name = newName;

			StatucCode = true;
		}

		return StatucCode;
	}

	u8 inc::getName(void) {

		inc& object = *this;

		u8 nowName;

		if (object.abnCode == false) {

			multeSpec& specific = *object.base;
			nowName = specific.Name;

		}

		return nowName;
	}
		
	bool inc::setFet(null newFet, ace(*nowEngdingFet)(null Fet)) {

		inc& object = *this;

		bool StatucCode = false;

		//开启了自动释放，但是自动释放的地址未提供
		if (object.autoFet == true && (object.endingFet == NULL || nowEngdingFet == NULL)) {
			object.abnCode = 1;
		}

		if(object.abnCode == false){ //无异常

			multeSpec& specific = *object.base;

			ace receiveabnCode = false;

			if (object.autoFet == true && nowEngdingFet != NULL) {

				if (nowEngdingFet == NULL)
					nowEngdingFet = object.endingFet;

				//nowEngdingFet函数返回ace类型的变量
				//如果ace为0（false）表示释放成功
				//如果ace不为0表示出现异常，其值为异常代码
				receiveabnCode = nowEngdingFet(specific.Fet);

			}

			//释放内存失败
			if (receiveabnCode != false) {

				//取出异常码号段
				ace codeSnippet =
					(receiveabnCode / 10000 * 10) + (receiveabnCode / 1000 * 10);

				//不是使用的指定号段
				if (codeSnippet == 65) {
					object.abnCode = 1;
				}
				else {//使用的是指定号段
					object.abnCode = receiveabnCode;
				}


			}

			specific.Fet = newFet;

			StatucCode = true;
		}

		return StatucCode;


	}

	null inc::getFet(void) {

		inc& object = *this;

		null nowFet = NULL;

		if (object.abnCode == false) {

			multeSpec& specific = *object.base;
			nowFet = specific.Fet;

		}

		return nowFet;

	}

}