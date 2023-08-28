CMAKE_MINIMUM_REQUIRED(VERSION 3.25)

PROJECT(DataStructure)

# 设置 C++ 标准版本
set(CMAKE_CXX_STANDARD 17)  # 例如，设置为 C++17

## Algorithm
#add_executable(binary_search 算法/查找/二分查找.cpp)
#add_executable(choose_sort 算法/排序/选择排序.cpp)
#add_executable(recursive 算法/递归.cpp)
#add_executable(quick_sort 算法/排序/快速排序.cpp)
# 查找
add_executable(fibonacci_search
        算法/查找/斐波那契查找.cpp)
#
## Data Structure
#
## 链表
#add_executable(node_listed 数据结构/链表/链表.cpp)
#target_include_directories(node_listed PRIVATE 数据结构/链表)
#
## 静态链表（再也不想碰这个 JB 数据结构了）
#add_executable(static_linkList 数据结构/链表/静态链表.cpp)
#target_include_directories(static_linkList PRIVATE 数据结构/链表)
#
## 循环链表
#add_executable(circular_linked_list 数据结构/链表/循环链表.cpp 数据结构/链表/循环链表.h)
#
## 双向链表
#add_executable(double_linked_list 数据结构/链表/双向链表.cpp 数据结构/链表/双向链表.h)
#
## 栈
#add_executable(sequence_stack 数据结构/栈/顺序栈.cpp 数据结构/栈/顺序栈.h)
#add_executable(linked_stack 数据结构/栈/链式栈.cpp 数据结构/栈/链式栈.h)
#add_executable(Fibonacci_sequence 算法/斐波那契数列.cpp)
#
## 队列
#add_subdirectory(./数据结构/队列)
#add_executable(sequence_queue 数据结构/队列/顺序队列.cpp 数据结构/队列/顺序队列.h)
#add_executable(linked_queue 数据结构/队列/链式队列.cpp 数据结构/队列/链式队列.h)
#add_executable(template_linked_queue
#        数据结构/队列/模板链式队列.h
#        数据结构/队列/模板链式队列.cpp
#)

#
## 串
#add_executable(string 数据结构/串/串.cpp 数据结构/串/串.h)
#
## 树
#add_executable(tree1 数据结构/树/孩子表示法.cpp)
#add_executable(tree2 数据结构/树/二叉树.cpp)
#add_executable(tree3 数据结构/树/线索二叉树.cpp 数据结构/树/线索二叉树.h)
#
#add_executable(tree_forest_binary_tree
#        数据结构/树/T_BT_F/main.cpp
#        )
#target_link_directories(tree_forest_binary_tree PRIVATE
#        "${CMAKE_SOURCE_DIR}/数据结构/树/T_BT_F/*.h"
#)
#add_executable(Haffman_Tree 数据结构/树/哈夫曼树.cpp 数据结构/树/哈夫曼树.h)

# 图
add_subdirectory(./数据结构/图)

add_executable(graph 数据结构/图/main.cpp)

target_link_libraries(graph PUBLIC adjacency_matrix)
#target_link_libraries(graph PUBLIC AdjacencyList)
target_link_libraries(graph PUBLIC AOV)
#target_link_libraries(graph PUBLIC crossing_linked_list)
#target_link_libraries(graph PUBLIC multi_adjacency_list)

target_include_directories(adjacency_matrix PUBLIC
        "${CMAKE_SOURCE_DIR}/数据结构/图")

# message(STATUS main-- "${CMAKE_SOURCE_DIR}/数据结构/图/")