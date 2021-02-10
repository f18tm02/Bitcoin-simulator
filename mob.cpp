//#include "mob.h"

//mob::mob() {
//	buyNum = 0;
//	sellNum = 0;
//	max2 = 0;
//}
//void mob::update() {
//	for (int i = 1; i <= 5; i++) {
//        //dealTotal 总交易量
//		if (tcore->bitcoins[i]->dealTotal > tcore->bitcoins[max2]->dealTotal) max2 = i;
//	}						//sell
//    //价格 todo
//    for (int g = 1; g <= 5; g++) {
//        if (this->bitcoins[g] != 0 && g != max2) {
//            sellMent(g, this, this->bitscoins[g]);
//            //卖掉除max2之外的币
//            //币种 对象 卖多少
//        }
//	}
//								//buy
//	buyMent(max2, this, this->property / bitcoins[max2]->money);
//    //
//}
