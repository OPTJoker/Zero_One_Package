//
//  main.c
//  fist
//
//  Created by 张雷 on 2017/7/24.
//  Copyright © 2017年 Allen. All rights reserved.

/*
 *********************************
 *  动态规划之01背包问题（最易理解的讲解）
 *  参考博客: 
 *  http://blog.csdn.net/mu399/article/details/7722810
 *********************************

 
 */
//

#include "stdio.h"
#include <stdlib.h>

#include "Goods.h"
#include "Bag.h"

#define CNT 3


int w[CNT] = {3,4,5};
int v[CNT] = {4,5,6};

char *name[20] = {"A","B","C","D","E"};



void analyze(GOODS *gArr, int len, BAG *bag);

void descArr(GOODS *arr, int len);

int main(int argc, char *argv[]) {
    
    // 初始化背包
    BAG *bag = InitBag(10,"[A-bag]");
    
    // 初始化10个物品
    GOODS *goods_arr = NULL;
    for (short i=0; i<CNT; i++) {
        if (!goods_arr) {
            goods_arr = malloc(sizeof(GOODS));
        }else{
            goods_arr = realloc(goods_arr, i+1);
        }
        
        GOODS *goods = init(w[i], v[i], name[i]);
        goods_arr[i] = *goods;
    }
    
    // log初始化
    //descArr(goods_arr, CNT);
    
    // 动态规划求出最优解
    analyze(goods_arr, CNT, bag);
    
    // 输出最优解
    ShowBag(bag);
    
    return 0;
    
}

// 根据 博客教程改编的求解过程
void analyze(GOODS *gArr, int len, BAG *bag)
{
    
    int bagMatrix[len][bag->volume];
    GOODS g;
    
    for(short i=0;i<bag->volume;i++){
        for (short j=0; j<len; j++) {
            bagMatrix[j][i] = 0;
        }
    }
    
    printf("matrix 初始化:\n");
    for (short j=0; j<len; j++) {
        for(short i=0;i<bag->volume;i++){
            printf("%d ",bagMatrix[j][i]);
        }
        printf("\n\n");
    }
    
    
    for (short i=1; i<=bag->volume; i++) {
        for (short j=0; j<len; j++) {
            
            g = gArr[j];
            
            // 背包容量(i)装不下item.weight
            if (g.weight>i) {
                
                if (j==0) {
                    bagMatrix[j][i] = 0;
                }else{
                    bagMatrix[j][i] = bagMatrix[j-1][i];
                }
            }else{
                // 放入背包后的价值总和
                int itemInBag;
                int itemNoInBag;
                if (j==0) {
                    bagMatrix[j][i] = g.value;
                    continue;
                }
                else{
                    itemInBag = bagMatrix[j-1][i-g.weight]+g.value;
                }
                
                itemNoInBag = bagMatrix[j-1][i];
                bagMatrix[j][i] = (itemNoInBag>itemInBag?itemNoInBag:itemInBag);
                int res = bagMatrix[j][i];
                res = 0;
            }
            
        }
    }
    
    printf("matrix:\n");
    for (short i = 0; i<len; i++) {
        for (short j=1; j<10+1; j++) {
            printf("%2d ",bagMatrix[i][j]);
        }
        printf("\n");
    }
    
    //find answer
    for (short i = len-1; i>=0; i--) {
        g = gArr[i];
        if (bag->volume <= 0) {
            printf("\n>>>Err:您的背包过小，无法容纳任何物品\n");
            break;
        }
        if (i==0 && bag->volume>=g.weight) {
            //printf("[inBag:(%s)]\n",g.name);
            bag->volume -= g.weight;
            AddGoods(bag, &g);  // 把物品放进背包
            break;
        }
        
        // 匹配到了itemInBag
        if (g.value == bagMatrix[i][bag->volume] - bagMatrix[i-1][bag->volume-g.weight]) {
            //printf("[inBag:(%s)]\n",g.name);
            bag->volume -= g.weight;
            AddGoods(bag, &g);
        }
    }
}


void descArr(GOODS *arr, int len)
{
    //printf("\n\n============== goods 遍历 ==============");
    for (short i=0; i<len; i++) {
        GOODS *g = &arr[i];
        printf("\ngoods[%s]:(w:%d  v:%d)", g->name, g->weight, g->value);
    }
    printf("\n");
}

