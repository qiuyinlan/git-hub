#!/bin/bash

seconds=0

while true; do
    # 计算时、分、秒
    hours=$((seconds / 3600))    # 计算小时
    minutes=$(( (seconds % 3600) / 60 ))  # 计算分钟
    secs=$((seconds % 60))  # 计算秒数

    # 清屏
    clear

    # 格式化输出为 时:分:秒
    echo "已运行: $(printf "%02d:%02d:%02d" $hours $minutes $secs)"

    # 等待1秒，增加秒数
    sleep 1
    ((seconds++))
done
