#!/bin/bash

# 定义颜色
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # 无颜色

echo "Running tests"
echo "------------------------------------------------------------"

# 测试函数
function run_test {
    local test_name="$1"
    local command="$2"
    local output_file=$3
    local expected_file=$4

    # 执行命令并将输出重定向到临时文件
    eval $command > "$output_file"

    # 比较输出结果和预期结果
    if diff "$output_file" "$expected_file" > /dev/null; then
        printf "%-50s ${GREEN}PASS${NC}\n" "$test_name"
    else
        printf "%-50s ${RED}FAIL${NC}\n" "$test_name"
    fi
}

# 运行测试
run_test "1.1 - command_line_check" "./main -c 4 1 4 < test/1.in" "out/1.out" "test/1.out"
run_test "1.1 - command_line_check" "./main -c 4 1 < test/2.in" "out/2.out" "test/2.out"
