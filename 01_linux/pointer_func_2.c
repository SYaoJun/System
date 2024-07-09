
#include <stdio.h>
#include <stdbool.h>
typedef int (*my_func_ptr)(int a, int b);
int add(int a, int b){
    return a+b;
}
int subtract(int a, int b){
    return a - b;
}
#define NUM 100

my_func_ptr callback_array[NUM];

void init(){
    callback_array[0] = add;
    callback_array[1] = subtract;
}

int main(){
    for(int i = 0; i < 2; i++){
        callback_array[i](99, 11);
    }
    return 0;
}