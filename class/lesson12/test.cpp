//
// Created by 姚军 on 2022/11/28.
//

#include <iostream>
#include <cstdio>

using namespace std;
int main() {
    int num = 999;
    int *temp = &num;
    int **ptr = &temp;

    printf("ptr_value = %d\n", ptr);
    printf("=============\n");
    printf("ptr_first_level = %d\n", *ptr);
    printf("temp_value = %d\n", temp);
    printf("num_addr = %d\n", &num);
    printf("=============\n");
    printf("ptr_second_level = %d\n", **ptr);
    printf("temp_first_level = %d\n", *temp);
    printf("num_value = %d\n", num);

    return 0;
}