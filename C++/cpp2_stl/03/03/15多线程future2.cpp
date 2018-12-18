//
//  15多线程future2.cpp
//  03
//
//  Created by xiaoyuan on 2018/12/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <functional>
#include <numeric>
#include <vector>

/*
 如果在析构std::promise变量时，还没对std::pormise变量进行设置，那么析构函数就会为其关联的std::future存储一个std::future_error异常。此时，std::future的get()函数会抛出一个std::futre_error异常。
 
 std::future是一次性的。std::promise只能调用一次get_future，std::future也只能调用一次get()。 如果想在多个线程中共享一个std::promise的设置值，可以使用std::shared_future。
 
 有了std::packaged_task，线程函数就可以直接返回一个值。这样显得更加自然。从下面例子也可以看到，std::packaged_task并非一定要作为std::thread的参数，它完全可以在主线程中调用。

 */
int f(int x, int y){return std::pow(x, y);}

void task_lambda()
{
    std::packaged_task<int(int, int)> task([](int a, int b){
        return std::pow(a, b);
    });
    
    std::future<int> result = task.get_future();
    task(2, 9);
    
    std::cout << "task_lambda:\t" << result.get() << std::endl;
}

void task_bind()
{
    std::packaged_task<int()> task(std::bind(f, 2, 11));
    std::future<int> result = task.get_future();
    
    task();
    
    std::cout << "task_bind:\t" << result.get() << std::endl;
}

void task_thread()
{
    std::packaged_task<int(int, int)> task(f);
    std::future<int> result = task.get_future();
    
    std::thread task_td(std::move(task), 2, 10);
    task_td.join();
    
    std::cout << "task_thread:\t" << result.get() << std::endl;
}

void test01()
{
    task_lambda();
    task_bind();
    task_thread();
}

// 再用async进行一层封装
double calAvg(const std::vector<int> &vec)
{
    double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    double avg = 0;
    if (!vec.empty()) {
        avg = sum / vec.size();
    }
    return avg;
}

void test02()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    std::future<double> fu = std::async(calAvg, std::ref(vec));
    
    double avg = fu.get();
    std::cout << "avg = " << avg << std::endl;
}

int main(int argc, const char *argv[])
{
    test02();
    return EXIT_SUCCESS;
}
