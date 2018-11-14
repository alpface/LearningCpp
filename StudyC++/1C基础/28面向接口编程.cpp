//
//  28面向接口编程.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/14.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CSocketImp1.h"

/* 定义接口 */

// 初始化接口
typedef void (*init_CSocketProtocol)(void **handle);

// 发送接口
typedef void (*send_CSocketProtocol)(void *handle, unsigned char *sendData, int sendLen);

// 接收接口
typedef void (*recv_CSocketProtocol)(void *handle, unsigned char *recvData, int *recvLen);

// 关闭接口
typedef void (*close_CSocketProtocol)(void *handle);

// 业务逻辑代码
void Framework(init_CSocketProtocol init,
               send_CSocketProtocol send,
               recv_CSocketProtocol recv,
               close_CSocketProtocol close)
{
   // 初始化连接
    void *handle = NULL;
    init(&handle);
    
    // 发送数据
    unsigned char buff[1024] = "I'm coder";
    int len = (int)strlen((char *)buff);
    send(handle, buff, len);
    
    // 接受数据
    // 注意：recvData在初始化时，给的大小要足够大，不然会报错:buffer overflow
    unsigned char recvData[1024] = {0};
    int recvLen;
    recv(handle, recvData, &recvLen);
    printf("接受的数据:%s\n", recvData);
    printf("接受的数据的长度:%d\n", recvLen);
    
    // 关闭连接
    close(handle);
    handle = NULL;
    
}

void test()
{
    Framework(init_CSocketImp1, send_CSocketImp1, recv_CSOcketImp1, close_CSocketImp1);
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}

