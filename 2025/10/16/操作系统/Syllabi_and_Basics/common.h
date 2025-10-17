#ifndef COMMON_H
#define COMMON_H

#include <time.h>

// 忙等待指定秒数
static inline void Spin(int seconds) {
    time_t start = time(NULL);
    while ((time(NULL) - start) < seconds) {
        // 空循环，什么都不做
    }
}

#endif // COMMON_H