#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gperftools/profiler.h>

void busy_work() {
    for (int i = 0; i < 100000000; ++i) {
        double x = i * 0.5;
        x = x * x;
    }
}

void light_work() {
    for (int i = 0; i < 1000000; ++i) {
        double x = i * 0.1;
    }
}

int main() {
    // 开始性能分析
    ProfilerStart("profile_output.cpu");

    printf("Starting workload...\n");

    // 执行模拟工作负载
    busy_work();
    light_work();

    // 停止性能分析
    ProfilerStop();

    printf("Finished workload. Profile saved to profile_output.cpu\n");

    return 0;
}
