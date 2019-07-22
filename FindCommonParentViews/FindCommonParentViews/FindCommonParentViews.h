//
//  FindCommonParentViews.h
//  FindCommonParentViews
//
//  Created by swae on 2019/7/22.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FindCommonParentViews : NSObject

// 查找两个视图的共同父视图
+ (NSArray<UIView *> *)findCommonParentViewsWithViewA:(UIView *)viewA viewB:(UIView *)viewB;

@end

NS_ASSUME_NONNULL_END
