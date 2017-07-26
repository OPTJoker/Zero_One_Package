//
//  Goods.h
//  fist
//
//  Created by 张雷 on 2017/7/24.
//  Copyright © 2017年 Allen. All rights reserved.
//

#ifndef Goods_h
#define Goods_h

#include <stdio.h>

typedef struct goods{
    
    int value;
    int weight;    
    char *name;
    
} GOODS;


// 初始化货物
GOODS* init(int w, int v, char *name);


// 打印货物信息
void logGoods(GOODS g);

#endif /* Goods_h */
