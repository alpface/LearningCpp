//
//  FindCommonParentViews.m
//  FindCommonParentViews
//
//  Created by swae on 2019/7/22.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#import "FindCommonParentViews.h"

@implementation FindCommonParentViews

// 查找一个view的所有父视图
+ (NSArray<UIView *> *)findAllSuperViewsWithView:(UIView *)view {
    
    UIView *tempView = view.superview;
    NSMutableArray *array = @[].mutableCopy;
    while (tempView != nil) {
        [array addObject:tempView];
        tempView = tempView.superview;
    }
    return array;
}

// 查找两个视图的共同父视图
+ (NSArray<UIView *> *)findCommonParentViewsWithViewA:(UIView *)viewA viewB:(UIView *)viewB {
    
    // 查找视图a的所有父视图
    NSArray *aSuperViews = [self findAllSuperViewsWithView:viewA];
    // 查找视图b的所有父视图
    NSArray *bSuperViews = [self findAllSuperViewsWithView:viewB];
    NSMutableArray *commonSuperViews = @[].mutableCopy;
    NSInteger i = 0;
    while (i < MIN(aSuperViews.count, bSuperViews.count)) {
        // 倒序方式获取各视图的父视图
        UIView *superViewA = aSuperViews[aSuperViews.count - 1 - i];
        UIView *superViewB = bSuperViews[bSuperViews.count - 1 - i];
        // 比较两个父视图是否相同，如果相同则放入到共同的父视图数组中
        if (superViewA == superViewB) {
            [commonSuperViews addObject:superViewA];
        }
        else {
            // 不相同则退出循环
            break;
        }
        i++;
    }
    return commonSuperViews;
}

@end
