/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>

#define THREAD_PRIORITY 5
#define THREAD_STACK_SIZE 500

K_THREAD_STACK_DEFINE(thread_stack, THREAD_STACK_SIZE);

void thread(void * p1, void * p2, void * p3) {
    while(1) {
        k_sleep(1000);
        printk("\n");
    }
}

void main(void) {
    struct k_thread thread_data;
    k_tid_t my_tid = k_thread_create(&thread_data, thread_stack,
                                     K_THREAD_STACK_SIZEOF(thread_stack),
                                     thread,
                                     NULL, NULL, NULL,
                                     THREAD_PRIORITY, 0, K_NO_WAIT);

    uint32_t cnt = 0;
    while(true) {
        k_sleep(100);
        printk("Hello World! %s ... %ui\n", CONFIG_BOARD, cnt++);
    }
}

