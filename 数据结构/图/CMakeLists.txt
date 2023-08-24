add_library(adjacency_matrix 邻接矩阵.h 邻接矩阵.cpp)

add_library(AdjacencyList 邻接表.cpp 邻接表.h)

add_library(crossing_linked_list 十字链表.cpp 十字链表.h)

add_library(multi_adjacency_list 邻接多重表.cpp 邻接多重表.h)

add_library(AOV
        AOV图实现.cpp
        AOV图实现.h)

#target_include_directories(MGraph PUBLIC
#        "${CMAKE_SOURCE_DIR}/数据结构/图/")

# message(STATUS Graph-- "${CMAKE_SOURCE_DIR}")
