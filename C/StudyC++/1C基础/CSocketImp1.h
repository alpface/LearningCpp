//
//  CSocketImp1.h
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/14.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//  定义实现 28面向接口编程.cpp中的接口

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif
    
    // 初始化
    void init_CSocketImp1(void **handle);
    
    // 发送数据
    void send_CSocketImp1(void *handle, unsigned char *sendData, int sendLen);
    
    // 接收数据
    void recv_CSOcketImp1(void *handle, unsigned char *recvData, int *recvLen);
    
    // 关闭连接
    void close_CSocketImp1(void *handle);
    
#ifdef __cplusplus
}
#endif
