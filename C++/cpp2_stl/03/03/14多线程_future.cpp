//
//  14多线程_future.cpp
//  03
//
//  Created by xiaoyuan on 2018/12/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <numeric>

/*
 future
 
 目的是为了获得线程函数的返回值，如果使用join的方法，主线程等待次线程结束后，再去读取全局变量即可。但是join是等待次线程结束，而结束有很多种原因，比如正常结束和抛异常提前终止。对于后者，并不能保证join返回后，读取全局变量得到的就是所要的值。
 */

void threadFunc(const std::vector<int> &big_vec, std::promise<double> prom)
{
    double sum = std::accumulate(big_vec.begin(), big_vec.end(), 0.0);
    double avg = 0;
    
    if (!big_vec.empty()) {
        avg = sum / big_vec.size();
    }
    
    prom.set_value(avg);
}

void test01()
{
    std::promise<double> prom;
    std::future<double> fu = prom.get_future();
    
    std::vector<int> v{1,2,3,4,5,6,7};
    // 以右值引用的方式进行传递，本线程中的prom对象转移给了子线程，保证主线程不会一直阻塞
    std::thread th(threadFunc, std::ref(v), std::move(prom));
    th.detach();
    
    double avg = fu.get(); // 阻塞一直到次线程调用set_value
    std::cout << "avg: " << avg << std::endl;
}

int main(int argc, const char *argv[])
{
    test01();
    return EXIT_SUCCESS;
}
