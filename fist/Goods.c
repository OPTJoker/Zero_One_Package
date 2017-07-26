//
//  Goods.c
//  fist
//
//  Created by 张雷 on 2017/7/24.
//  Copyright © 2017年 Allen. All rights reserved.
//

#include "Goods.h"
#include <stdlib.h>
// 初始化货物
GOODS* init(int w, int v, char *name)
{
    GOODS *g = malloc(sizeof(GOODS));
    g->weight = w;
    g->value = v;
    g->name = name;
    
    return g;
}

// 打印货物信息
void logGoods(GOODS g)
{
    printf("name:%s g.w:%d  g.v:%d\n", g.name, g.weight, g.value);
}
