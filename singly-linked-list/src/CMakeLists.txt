add_library(sll-lib 
    singlyLinkedList.hh
    singlyLinkedList.cc)

add_executable(sll main.cc)

target_link_libraries(sll sll-lib)