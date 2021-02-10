//#include "gangster.h"
//#include "core.h"
//gangster::gangster() {
//	investor();
//	patience = 0;
//	outbreak = 0;
//	lastbuy = 0;
//}
//void gangster::update() {
//	target = 1;
//	for (int i = 1; i <= 5; i++) {
//		lastcount[i] = tcore->bitcoins[i]->dealTotal;
//	}
//	for (int i = 1; i <= 5; i++) {
//		if (tcore->bitcoins[i]->dealTotal > tcore->bitcoins[target]->dealTotal) target = i;
//	}
//	if (tcore->totalDeal >= lastcount * 1.5) {
//		dealsell(lastbuy, 3, i, tcore->bitcoins[lastbuy]);//收割
//		patience = 0;
//		continue;
//	}
//	if (patience > outbreak && target != lastbuy) {//按捺不住
//		dealsell(lastbuy, 3, i, tcore->bitcoins[lastbuy]);//卖掉所有
//	}
//	patience++;
//	dealbuy(target, 3, i, property / tcore->bitcoins[target]);//向人多地方下手
//	lastbuy = target;
//}
