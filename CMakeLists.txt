cmake_minimum_required(VERSION 3.26)
project(YourProjectName)

set(CMAKE_CXX_STANDARD 17)

# 递归搜索项目根目录下的所有 cpp 文件
file(GLOB_RECURSE CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/HUAWEI_Question/*.cpp)

# 遍历所有找到的 cpp 文件，并生成相应的可执行文件
foreach (CPP_FILE ${CPP_FILES})
    # 获取 cpp 文件所在的目录路径
    get_filename_component(CPP_PATH ${CPP_FILE} DIRECTORY)
    # 设置可执行文件输出路径为 cpp 文件所在目录下的 OUT 文件夹
    set(EXECUTABLE_OUTPUT_PATH ${CPP_PATH}/OUT)

    # 获取文件名（不含路径和扩展名）
    get_filename_component(FILE_NAME ${CPP_FILE} NAME_WE)
    # 生成可执行文件的名称，与原始 cpp 文件名相同
    set(EXECUTABLE_NAME ${FILE_NAME})
    # 添加可执行文件的构建
    add_executable(${EXECUTABLE_NAME} ${CPP_FILE})
endforeach ()
