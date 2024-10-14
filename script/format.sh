clang-format -i ../07-signal/five_children.c

#!/bin/bash

# 格式化代码
clang-format -i *.c *.h

# 检查命名约定
clang-tidy *.c *.h --config-file=.clang-tidy
