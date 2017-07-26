//
//  Bag.c
//  fist
//
//  Created by 张雷 on 2017/7/25.
//  Copyright © 2017年 Allen. All rights reserved.
//

#include "Bag.h"
#include <stdlib.h>

BAG *InitBag(int v, char *name)
{
    BAG *bag = malloc(sizeof(BAG));
    
    bag->name = name;
    bag->cur_w = 0;
    bag->cur_v = 0;
    bag->volume = v;
    
    bag->goods_arr = NULL;
    bag->cnt = 0;
    
    return bag;
}

void AddGoods(BAG*bag, GOODS *g){
    
    // 分配内存
    if (NULL == bag->goods_arr) {
        bag->goods_arr = malloc(sizeof(GOODS));
    }else{
        bag->goods_arr = realloc(bag->goods_arr, bag->cnt+1);
    }
    
    // 增加goods
    bag->goods_arr[bag->cnt] = *g;
    (bag->cur_w) += g->weight;
    (bag->cur_v) += g->value;
    
    (bag->cnt)++;
}

void ShowBag(BAG *bag)
{
    printf("\n ====== bag:%s ======\n", bag->name);
    printf("volume:%d\n",bag->volume);
    printf("cur_w:%d\n",bag->cur_w);
    printf("cur_v:%d\n",bag->cur_v);
    printf("cnt:%d",bag->cnt);
    printf("\n");
    
}


GOODS GetGoodsAtIndex(BAG *bag, int idx)
{
    if (idx<bag->cnt) {
        return bag->goods_arr[idx];
    }else{
        printf(">>Error:[%p](%d)数组越界", bag, idx);
        GOODS *g = NULL;
        return *g;
    }
    
}
