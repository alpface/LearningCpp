//
//  CSocketImp1.c
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/14.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "CSocketImp1.h"


struct Info {
    char data[1024];
    int len;
};

// 初始化
void init_CSocketImp1(void **handle)
{
    if (NULL == handle) {
        return;
    }
    struct Info *info = malloc(sizeof(struct Info));
    memset(info, 0, sizeof(struct Info));
    *handle = info;
}

// 发送数据
void send_CSocketImp1(void *handle, unsigned char *sendData, int sendLen)
{
    if (NULL == handle) {
        return;
    }
    if (NULL == sendData) {
        return;
    }
    struct Info *info = (struct Info *)handle;
    // 将字符串sendData中最多sendLen个字符复制到字符数组info->data中，返回指向info->data的指针。
    strncpy(info->data, sendData, sendLen);
    info->len = sendLen;
}

// 接收数据
void recv_CSOcketImp1(void *handle, unsigned char *recvData, int *recvLen) {
    if (NULL == handle) {
        return;
    }
    if (NULL == recvData) {
        return;
    }
    if (NULL == recvLen) {
        return;
    }
    struct Info *info = (struct Info *)handle;
    
    strncpy(recvData, info->data, info->len);
    *recvLen = info->len;
    return;
}

// 关闭连接
void close_CSocketImp1(void *handle)
{
    if (NULL != handle) {
        free(handle);
        handle = NULL;
    }
}
