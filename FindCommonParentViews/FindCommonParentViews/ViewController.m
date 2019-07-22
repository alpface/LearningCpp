//
//  ViewController.m
//  FindCommonParentViews
//
//  Created by swae on 2019/7/22.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#import "ViewController.h"
#import "FindCommonParentViews.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIView *viewA;

@property (weak, nonatomic) IBOutlet UIView *viewB;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    NSArray *commonSuperViews  = [FindCommonParentViews findCommonParentViewsWithViewA:self.viewA viewB:self.viewB];
    NSLog(@"%@", commonSuperViews);
}


@end
