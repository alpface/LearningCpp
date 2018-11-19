//
//  ModuleA.h
//  02
//
//  Created by xiaoyuan on 2018/11/19.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#ifndef ModuleA_h  // 对于模块ModuleA来说，这个宏是为了防止头文件的重复引用
#define ModuleA_h

/*
 extern "C"的主要作用就是为了能够正确实现C++代码调用其他C语言代码。加上extern "C"后，会指示编译器这部分代码按C语言的进行编译，而不是C++的。由于C++支持函数重载，因此编译器编译函数的过程中会将函数的参数类型也加到编译后的代码中，而不仅仅是函数名；而C语言并不支持函数重载，因此编译C语言代码的函数时不会带上函数的参数类型，一般之包括函数名。
 
 这个功能十分有用处，因为在C++出现以前，很多代码都是C语言写的，而且很底层的库也是C语言写的，为了更好的支持原来的C代码和已经写好的C语言库，需要在C++中尽可能的支持C，而extern "C"就是其中的一个策略。
 
 extern "C" 主要用在下面的情况：
 1、C++代码调用C语言代码
 2、在C++的头文件中使用
 3、在多个人协同开发时，可能有的人比较擅长C语言，而有的人擅长C++，这样的情况下也会有用到
 

 */


#ifdef __cplusplus  //而这一部分就是告诉编译器，如果定义了__cplusplus(即如果是cpp文件， extern "C"{ //因为cpp文件默认定义了该宏),则采用C语言方式进行编译
extern "C"{
#endif
 
   int fun(int, int);
    
#ifdef __cplusplus
}
#endif

#include <stdio.h>

#endif /* ModuleA_h */
