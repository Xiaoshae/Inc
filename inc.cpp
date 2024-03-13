#include "inc.h"


namespace incName {

	multe createMulte(u8 newName, null newFet, null(*nowCreateFet)(null nowFet));

	inc::inc(u8 newName, null newFet,
		null (*newCreateFet)(null nowFet),
		bool (*newEndingFet)(null nowFet)) {

		inc& object = *this;

		
		object.base = createMulte(newName,newFet,newCreateFet);

		if (object.base != NULL) {

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
		
	bool inc::setFet(null newFet) {

		inc& object = *this;
		multeSpec& specific = *object.base;

		bool StatusCode = false;
		
		//提供创建Fet副本函数，或newFet没有数据
		//提供释放Fet函数，或原Fet没有数据
		if ( ( object.createFet != NULL || newFet == NULL ) &&
			( object.endingFet != NULL || specific.Fet == NULL)) {

			//假设无需创建newFet副本
			null tempFet = NULL;

			//需要创建副本
			if (newFet != NULL) {
				tempFet = object.createFet(newFet);
			}
	

			//创建副本成功，或无需创建
			if (tempFet != NULL || newFet == NULL) {

				//假设不需要释放
				bool endingJedge = true;


				if (specific.Fet != NULL) {
					//释放
					//需要释放，如果释放失败false会覆盖true
					endingJedge = object.endingFet(specific.Fet);
				}
				
				//释放成功，或不需要释放
				if (endingJedge == true) {

					specific.Fet = tempFet;
					StatusCode == true;

				}
				else if(tempFet != NULL){ //释放失败，且之前创建了新的副本
					delete tempFet;
				}

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

		//提供了 创建副本 和 释放函数
		if (newCreateFet != NULL && newEndingFet != NULL) {

			object.createFet = newCreateFet;
			object.endingFet = newEndingFet;
			StatusCode = true;

		}
		
		return StatusCode;

	}

	bool inc::insertSon(u8 newName, null newFet, pwd path) {

		inc& object = *this;

		bool StatusCode = false;

		if (object.base != NULL &&
			object.createFet != NULL && object.endingFet != NULL) {

			sgsn newSgeSon = createMulte(newName, newFet, object.createFet);

			
			

		}


		return StatusCode;
	}

}

namespace incName {

	multe createMulte(u8 newName, null newFet, null(*nowCreateFet)(null nowFet)) {


		//分配multe的空间
		multe SgeMulte = new thmulte;
		//分配vesn的空间
		sn tempSon = new vesn;


		//两片空间分配成功
		//newFet中没有内容，或者提供了nowCreateFet函数
		if (SgeMulte != NULL && tempSon != NULL && ( newFet == NULL || nowCreateFet != NULL ) ) {

			multeSpec& specific = *SgeMulte;

			//newFet中没有内容
			if (newFet == NULL) {
				specific.Fet = newFet;
			}
			else { //有内容，需要创建副本
				specific.Fet = nowCreateFet(newFet);
			}
			
			//创建副本成功，或者newFet没有内容（无需创建副本）
			if (specific.Fet != NULL || newFet == NULL) {

				specific.Name = newName;
				specific.Her = (fh)(NULL);
				specific.Son = tempSon;
				specific.amSon = 0;

			}
			else { //需要创建Fet副本，但是失败了
				delete SgeMulte;
				delete tempSon;
				SgeMulte = NULL;
			}
		}

		return SgeMulte;
	}



}