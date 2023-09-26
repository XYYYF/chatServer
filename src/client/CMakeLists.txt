aux_source_directory(. SRC_LIST)    # 定义一个变量，包含了该目录下的所有源文件

add_executable(ChatClient ${SRC_LIST}) # 指定生成可执行文件

target_link_libraries(ChatClient muduo_base pthread) # 指定可执行文件链接时需要依赖的库文件