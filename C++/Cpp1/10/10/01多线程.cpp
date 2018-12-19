//
//  01多线程.cpp
//  10
//
//  Created by xiaoyuan on 2018/12/19.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <pthread.h>

/*
 头文件#include <pthread.h>
 创建线程
 创建一个 POSIX 线程：
 pthread_create (thread, attr, start_routine, arg)
 参数说明：
 thread    指向线程标识符指针。
 attr    一个不透明的属性对象，可以被用来设置线程属性。您可以指定线程属性对象，也可以使用默认值 NULL。
 start_routine    线程运行函数起始地址，一旦线程被创建就会执行。
 arg    运行函数的参数。它必须通过把引用作为指针强制转换为 void 类型进行传递。如果没有传递参数，则使用 NULL。
 返回值：
 创建线程成功时，函数返回 0，若返回值不为 0 则说明创建线程失败。
 
 终止线程
 终止一个 POSIX 线程：
 pthread_exit (status)
 在这里，pthread_exit 用于显式地退出一个线程。通常情况下，pthread_exit() 函数是在线程完成工作后无需继续存在时被调用。
 如果 main() 是在它所创建的线程之前结束，并通过 pthread_exit() 退出，那么其他线程将继续执行。否则，它们将在 main() 结束时自动被终止。
 */

void printFunc01(void *argv)
{
    std::cout << "hello world" << std::endl;
    // pthread_exit用于强制退出一个线程（非执行完毕退出），一般用于线程内部，并返回一个值，其唯一的参数就是返回值
    pthread_exit((void *)"pthread_exit reture value : hello world");
}

// 使用 pthread_create() 函数创建了 5 个线程，每个线程输出"Hello world！":
void test01()
{
    
    // 定义线程的id变量，用于保存所有线程的id
    pthread_t tids[5];
    for (int i = 0; i < 5; ++i) {
        
        int ret = pthread_create(&tids[i], NULL, (void* (*)(void *))printFunc01, NULL);
        if (ret != 0) {
            std::cout << "创建线程失败，error_code:" << ret << std::endl;
            exit(-1);
        }
        void *a;  // 用于接收pthread_exit的返回值
        // pthread_join用于等待一个线程的结束，也就是主线程中要是加了这段代码，就会在加代码的位置卡主，直到这个线程执行完毕才往下走。
        // pthread_join()函数，以阻塞的方式等待thread指定的线程结束。当函数返回时，被等待线程的资源被收回。如果线程已经结束，那么该函数会立即返回。并且thread指定的线程必须是joinable的。
        pthread_join(tids[i], &a);
        std::cout << (char *)a << std::endl;
    }
    
    /*
     
     一般都是pthread_exit在线程内退出，然后返回一个值。这个时候就跳到主线程的pthread_join了（因为一直在等你结束），这个返回值会直接送到pthread_join，实现了主与分线程的通信。
     */
}

void printFunc02(void *argc)
{
    int v = *(int *)argc;
    std::cout << " hello world: " << v << std::endl;
    // 强制退出线程
    pthread_exit((void *)"printFunc02");
    
    /*
     pthread_exit注意事项：
     这个线程退出的返回值的格式是void*，无论是什么格式都要强转成void*才能返回出来主线程（pthread_exit((void*)tmp);），而这个时候pthread_join就去接这个值，我们传进去一个void*的地址也就是&（void*），传地址进去接值是接口类函数常用的做法，有同样效果的做法是引用&，但是这个做法一来值容易被误改，二来不规范，所以定义一个类型然后把地址传进去修改value。回到题目，这里返回的void*是一个指针类型，必须强转成对应的指针才能用。
     */
}

// 使用 pthread_create() 函数创建了 5 个线程，并接收传入的参数。每个线程打印一个 "Hello world!" 消息，并输出接收的参数，然后调用 pthread_exit() 终止线程。
void test02()
{
    pthread_t tids[5];
    int indexs[5];
    for (int i = 0; i < 5; ++i) {
        indexs[i] = i;
        int ret = pthread_create(&tids[i], NULL, (void* (*)(void *))printFunc02, (int *)&(indexs[i]));
        if (ret != 0) {
            std::cout << "创建线程失败，error_code:" << ret << std::endl;
            exit(-1);
        }
        void *a;
        pthread_join(tids[i], &a);
        std::cout << (char *)a << std::endl;
    }
}

int main(int argc, const char *argv[])
{
//    test01();
    test02();
    return EXIT_SUCCESS;
}
