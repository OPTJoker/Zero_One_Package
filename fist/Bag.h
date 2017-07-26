//
//  Bag.h
//  fist
//
//  Created by 张雷 on 2017/7/25.
//  Copyright © 2017年 Allen. All rights reserved.
//

#ifndef Bag_h
#define Bag_h

#include <stdio.h>
#include "Goods.h"

typedef struct bag{
    char *name;     // name;
    int volume;     // 当前剩余容积
    
    int cur_w;      //weight
    int cur_v;      //value
    GOODS *goods_arr;   // 物品序号
    int cnt;      // 包里物品数量
    
} BAG;

BAG *InitBag(int v, char *name);
void ShowBag(BAG *bag);

void AddGoods(BAG*bag, GOODS *g);
int GetBagCnt(BAG *bag);

#endif /* Bag_h */
