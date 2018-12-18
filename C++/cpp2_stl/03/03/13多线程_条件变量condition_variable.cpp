//
//  13多线程.cpp
//  03
//
//  Created by xiaoyuan on 2018/12/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <thread>
#include <list>
#include <mutex>
#include <condition_variable>


// 1. condition_variable
// C++里面使用条件变量实现和信号量相同的功能。下面代码是一个经典的生产者消费者模型：

std::mutex g_mutex;
std::condition_variable cond;
std::list<int> aList;
/*
 std::condition_variable 提供了两种 wait() 函数。当前线程调用 wait() 后将被阻塞(此时当前线程应该获得了锁（mutex），不妨设获得锁 lck)，直到另外某个线程调用 notify_* 唤醒了当前线程。
 在线程被阻塞时，该函数会自动调用 lck.unlock() 释放锁，使得其他被阻塞在锁竞争上的线程得以继续执行。另外，一旦当前线程获得通知(notified，通常是另外某个线程调用 notify_* 唤醒了当前线程)，wait() 函数也是自动调用 lck.lock()，使得 lck 的状态和 wait 函数被调用时相同
 
 */
void threadFunc01()
{
    std::unique_lock<std::mutex> ul(g_mutex);
    // 用一个while循环而不是if，是因为存在虚假唤醒情景。当notify激活了多个线程之后，如果某个线程率先拿到锁将数据取空，其他线程应该再次检查一下数据是否为空。
    while (aList.empty()) {
        cond.wait(ul);
    }
    std::cout << "threadFunc01 get the value: " << aList.front() << std::endl;
}

void threadFunc02()
{
    std::lock_guard<std::mutex> lg(g_mutex);
    aList.push_back(13);
    cond.notify_one();
}

void test01()
{
    std::thread th1(threadFunc01);
    std::thread th2(threadFunc02);
    th1.join();
    th2.join();
}

int main(int argc, const char *argv[])
{
    test01();
    return EXIT_SUCCESS;
}
