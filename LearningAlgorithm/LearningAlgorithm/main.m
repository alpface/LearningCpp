//
//  main.m
//  LearningAlgorithm
//
//  Created by swae on 2019/7/21.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "char_reverse.h"
#import "linkedlist_reverse.h"
#import "merge_sorted_list.h"
#import "hash_find.h"

extern void testMeargeList(void);
extern void testLinkedListReverse(void);
extern void testCharReverse(void);
extern void testFindFirstChar(void);

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        
        testFindFirstChar();
    }
    return 0;
}

void testFindFirstChar(void) {
    char *src = "abddehba";
    char firstChar = findFirstChar(src);
    printf("这个字符串:%s中，首次出现的字符为：%c\n", src, firstChar);
}

void testMeargeList(void) {
    int a[9] = {1, 2, 5, 6, 7, 8, 9, 19, 20};
    int b[10] = {2, 3, 4, 6, 8, 10, 11, 18, 21, 29};
    int result[19];
    mergeList(a, 9, b, 10, result);
    for (int i = 0; i < 19; i++) {
        printf("i = %d\n", result[i]);
    }
}

void testLinkedListReverse(void) {
    struct Node *linkedList = construcLinkedtList();
    printinkedtList(linkedList);
    printf("__________\n");
    struct Node *newLinkedList = reverseLinkedList(linkedList);
    printinkedtList(newLinkedList);
    
}

void testCharReverse(void) {
    char str[] = "hello, world";
    char_reverse(str);
    printf("%s\n", str);
}
