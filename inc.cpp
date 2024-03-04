#include "inc.h"


namespace incName {

	inc::inc(u8 newName, null newFet,
		null (*newCreateFet)(null nowFet),
		bool (*newEndingFet)(null nowFet)) {

		inc& object = *this;

		
		object.base = new thmulte;

		if (object.base != NULL) {

			multeSpec& specific = *object.base;

			specific.Name = newName;
			specific.Fet = newFet;
			specific.Her = (fh)NULL;
			specific.Son = (sn)(NULL);
			specific.amSon = 0;

			object.createFet = newCreateFet;
			object.endingFet = newEndingFet;
		}

	}

	bool inc::setName(u8 newName) {
		inc& object = *this;

		bool StatusCode = false;

		//结构存在
		if (object.base != NULL) {

			multeSpec& specific = *object.base;
			specific.Name = newName;

			StatusCode = true;
		}

		return StatusCode;
	}

	u8 inc::getName(void) {

		inc& object = *this;

		u8 nowName;

		//结构存在
		if (object.base != NULL) {

			multeSpec& specific = *object.base;
			nowName = specific.Name;

		}

		return nowName;
	}
		
	bool inc::setFet(null newFet, ace(*nowEngdingFet)(null Fet)) {

		inc& object = *this;

		bool StatusCode = false;

		if (object.createFet != NULL && object.endingFet != NULL) {

			multeSpec& specific = *object.base;

			bool endingJedge;

			//释放
			endingJedge = object.endingFet(specific.Fet);

			//释放成功
			if (endingJedge == true) {

				//生成新的Fet副本
				specific.Fet = object.createFet(newFet);

				//成功
				if (specific.Fet != NULL)
					StatusCode == true;
				

			}
		}

		return StatusCode;
	}

	null inc::getFet(void) {

		inc& object = *this;

		null nowFet = NULL;

		//结构存在
		if (object.base != NULL) {

			multeSpec& specific = *object.base;
			nowFet = specific.Fet;

		}

		return nowFet;

	}

	bool inc::setAutoFet(null(*newCreateFet)(null nowFet),
		bool (*newEndingFet)(null nowFet)) {

		inc& object = *this;

		bool StatusCode = false;

		if (newCreateFet != NULL && newEndingFet != NULL) {

			object.createFet = newCreateFet;
			object.endingFet = endingFet;
			StatusCode = true;

		}
		
		return StatusCode;

	}

}