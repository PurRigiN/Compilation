#!/bin/bash

traverse_dir()
{
    for file in `ls testcode/performance_test2021_pre`
    do
        #调用查找指定后缀文件
        check_suffix testcode/performance_test2021_pre/$file
    done
}

##获取后缀为txt或ini的文件
check_suffix()
{
    file=$1
    
    if [ "${file##*.}"x = "sy"x ]; then
        echo $file
        obj/compiler $file
    fi    
}
 
#测试指定目录
traverse_dir