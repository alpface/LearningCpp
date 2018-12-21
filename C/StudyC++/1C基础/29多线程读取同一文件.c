//
//  29多线程读取同一文件.c
//  StudyC++
//
//  Created by xiaoyuan on 2018/12/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<semaphore.h>
#include <unistd.h>
#define THREAD_NUM 25



typedef struct
{
    FILE *_fp;
    int _nThreadId; // 标识线程的id
    sem_t *_semLock;
}IDD_THREAD_PARAM;

void threadTask(void *args)
{
    char sLine[100+1];
    const IDD_THREAD_PARAM param = (*((IDD_THREAD_PARAM *)args));
    FILE *fpRead = param._fp;
    sem_t *semLock = param._semLock;
    int nid = param._nThreadId;
    
    sem_wait(semLock);
    while (!feof(fpRead)) {
        memset(sLine, 0, sizeof(sLine));
        fgets(sLine, 100, fpRead);
        fprintf(stderr, "Thread ID-%d:%s", nid, sLine);
    }
    sem_post(semLock);
}

void test()
{
    pthread_t *pthreads;
    sem_t semLock;
    pthreads = (pthread_t *)malloc(THREAD_NUM*sizeof(pthread_t));
    
    sem_init(&semLock, 0, 1);
    FILE *fp = fopen("/Users/xiaoyuan/Desktop/aiui.log", "r");
    // 创建线程
    IDD_THREAD_PARAM param;
    for (int i = 0; i < THREAD_NUM; i++) {
        memset(&param, 0, sizeof(IDD_THREAD_PARAM));
        param._fp = fp;
        param._nThreadId = i;
        param._semLock = &semLock;
        pthread_create(pthreads+1, NULL, (void *(*)(void *))threadTask, &param);
    }
    
    for (int i = 0; i < THREAD_NUM; i++) {
        pthread_join(*(pthreads+i), NULL);
    }
    
    if (pthreads != NULL) {
        free(pthreads);
        pthreads = NULL;
    }
    
    fclose(fp);
    fp = NULL;
}

int main(int argc, char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
