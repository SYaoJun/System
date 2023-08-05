#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>
// void get_array(char *s){
//     int n = strlen(s);
//     char s_copy[100];
//     int index = 0;
//     for(int i = 0; i < n; i++) {
//         for(char c = 'a'; c <='z'; c++) {
//             if(c != s[i]) {
//                 strcpy(s_copy, s);
//                 s_copy[i] = c;
//                 array[index] = s_copy;
//                 index++;
//             }
//         }
//     }
// }
int main(int argc, char *argv[]) {
    // printf("argc = %d\n", argc);
    char input_str[100];
    char target_str[100];
    int limit = 0;
    for(int i = 1; i < argc; ) {
        if(strcmp(argv[i], "--target") == 0){
            strcpy(target_str, argv[i+1]);
            printf("target_str = %s\n", target_str);
            i += 2;
            continue;
        }else if(strcmp(argv[i], "--from") == 0){
            strcpy(input_str, argv[i+1]);
            printf("input_str = %s\n", input_str);
            i += 2;
            continue;
        }else if(strcmp(argv[i], "--limit") == 0){
            limit = atoi(argv[i+1]);
            printf("limit = %d\n", limit);
            i += 2;
            continue;
        }
    }

    // puts("hello world!");

    // const char s[100] = "bugs";// a ags  //c ags // d ags

    // char array[10][100];

    // array[0] = "bags"; 
    // array[1] = "bagp";

    // // 一个字符串所有的情况枚举出来，放到一个数组中，等用户输入的时候一个字符串之后 ss
    // // 枚举的方法
    // // 1. 遍历第一字符，枚举a-z

    // // 1. ss的合法性，不能是数字，长度不能改变
    // // 2. 查找一下在不在数组中，然后判断一个是不是改变了恰好一位字符
    // get_array(s);
    // char user_input[100];
    // int step = 0;
    // while(true) {
    //     int ret = read(stdin, user_input, sizeof(user_input));
    //     if(cheack_valid(user_input)) {
    //         if(find_in_array(user_input)) {
    //             step++;
    //             new_s = user_input;
    //             if(user_input == target) {
    //                 break;
    //             }
    //         }
    //     }
    // }
    return 0;
}