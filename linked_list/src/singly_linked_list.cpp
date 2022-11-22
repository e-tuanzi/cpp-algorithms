/****************************************************
* @copyright: e-tuanzi
*
* @file: singly_linked_list.cpp
* @brief: 单向链表的cpp实现
* @author: e-tuanzi
* @create: 2022-11-22
* @version: v1
* ==========      Update Log              ==========
2022-11-22  创建文件
2022-11-23  添加基本插入删除状态查询等函数
****************************************************/

#include "../include/singly_linked_list.h"

#include <cstdio>

#include <new>
#include <iostream>

TSinglyLinkedList::TSinglyLinkedList() {
    // 创建头结点
    head_ = new TSinglyLinkedNode(-1);
}

TSinglyLinkedList::~TSinglyLinkedList() {
    // 从首元素节点开始释放空间
    TSinglyLinkedNode * next;
    auto * current_ptr = head_->next;
    while(current_ptr!= nullptr){
        next = current_ptr->next;
        delete current_ptr;
        current_ptr = next;
    }
    // 释放结束后重置指针
    head_->next = nullptr;
}

TSinglyLinkedNode* TSinglyLinkedList::begin() {
    return head_->next;
}

TSinglyLinkedNode* TSinglyLinkedList::end() {
    // 从头节点访问到尾结点
    auto* end_ptr = head_;
    while(end_ptr->next!= nullptr){
        end_ptr = end_ptr->next;
    }
    return end_ptr;
}

int TSinglyLinkedList::front() {
    return begin()->data;
}

int TSinglyLinkedList::back() {
    return end()->data;
}

bool TSinglyLinkedList::push_front(int val) {
    // 将首节点暂存，插入新节点后，将首节点放在新节点后面
    auto* front_ptr = begin();
    bool result;
    try{
        auto* node = new TSinglyLinkedNode(val);
        head_->next = node;
        node->next = front_ptr;
        result = true;
    }catch (std::bad_alloc& e){
        printf("[ERROR]: memory alloc failed!\n");
        std::cout<<e.what()<<std::endl;
        result = false;
    }
    return result;
}

void TSinglyLinkedList::pop_front() {
    // 取到首节点的下一个节点，直接去掉首节点
    auto* front_ptr = begin();
    // 当节点不够时，直接置空
    if(front_ptr== nullptr||front_ptr->next== nullptr){
        head_->next = nullptr;
        return;
    }
    auto* next = front_ptr->next;
    head_->next = next;
    delete front_ptr;
}

bool TSinglyLinkedList::push_back(int val) {
    // 取到尾结点后插入新节点
    auto* end_ptr = end();
    bool result;
    try{
        auto* node = new TSinglyLinkedNode(val);
        end_ptr->next = node;
        result = true;
    }catch (std::bad_alloc& e){
        printf("[ERROR]: memory alloc failed!\n");
        std::cout<<e.what()<<std::endl;
        result = false;
    }
    return result;
}

void TSinglyLinkedList::pop_back() {
    // 双指针同时获取尾结点和尾结点的前一节点
    // 释放尾结点内存后，将前一节点的next置空
    auto* last_ptr = begin();
    // 节点个数不够时，直接置空
    if(last_ptr == nullptr || last_ptr->next == nullptr){
        delete last_ptr;
        head_->next = nullptr;
        return;
    }
    auto* end_ptr = last_ptr->next;
    while(end_ptr->next!= nullptr){
        last_ptr = last_ptr->next;
        end_ptr = last_ptr->next;
    }
    delete end_ptr;
    last_ptr->next = nullptr;
}

bool TSinglyLinkedList::clear() {
    // 遍历释放空间，最后置空头指针
    TSinglyLinkedNode * next;
    auto * current_ptr = begin();
    while(current_ptr!= nullptr){
        next = current_ptr->next;
        delete current_ptr;
        current_ptr = next;
    }
    head_->next = nullptr;
    return true;
}

int TSinglyLinkedList::size() {
    auto* current_ptr = begin();
    int counter = 0;
    while (current_ptr != nullptr){
        ++counter;
        current_ptr = current_ptr->next;
    }
    return counter;
}

bool TSinglyLinkedList::empty() {
    if(head_->next== nullptr)
        return true;
    return false;
}



void TSinglyLinkedList::show() {
    auto* current_ptr = begin();
    int counter = 0;
    while (current_ptr != nullptr){
        printf("%d -> ", current_ptr->data);
        ++counter;
        current_ptr = current_ptr->next;
    }
    printf("null\nsize: %d\n", counter);
}

namespace test{

    void end_test() {
        printf("=================================================================\n");
    }

    void front(TSinglyLinkedList* list) {
        printf("list front element is %d\n", list->front());
        end_test();
    }

    void back(TSinglyLinkedList* list) {
        printf("list back element is %d\n", list->back());
        end_test();
    }

    void push_front(TSinglyLinkedList* list, int times) {
        printf("[INFO]: test push front\n");
        printf("[INFO]: before push\n");
        list->show();
        int i = times + 1;
        while(--i){
            list->push_front(i);
        }
        printf("[INFO]: push %d times\n", times);
        list->show();
        end_test();
    }

    void pop_front(TSinglyLinkedList* list, int times) {
        printf("[INFO]: test pop front\n");
        printf("[INFO]: before pop\n");
        list->show();
        int i = times + 1;
        while(--i){
            list->pop_front();
        }
        list->show();
        printf("[INFO]: pop %d times\n", times);
        end_test();
    }

    void push_back(TSinglyLinkedList* list, int times){
        printf("[INFO]: test push back\n");
        printf("[INFO]: before push\n");
        list->show();
        int i = 1;
        while(i < times + 1){
            list->push_back(i);
            ++i;
        }
        list->show();
        printf("[INFO]: push %d times\n", times);
        end_test();
    }

    void pop_back(TSinglyLinkedList* list, int times) {
        printf("[INFO]: test pop back\n");
        printf("[INFO]: before pop\n");
        list->show();
        int i = times + 1;
        while(--i){
            list->pop_back();
        }
        list->show();
        printf("[INFO]: pop %d times\n", times);
        end_test();
    }

    void clear(TSinglyLinkedList* list, int times) {
        printf("[INFO]: test clear\n");
        printf("[INFO]: before clear\n");
        list->show();
        int i = times + 1;
        while(--i){
            list->clear();
        }
        list->show();
        printf("[INFO]: clear %d times\n", times);
        end_test();
    }

    void empty(TSinglyLinkedList* list) {
        if(list->empty()){
            printf("empty is true\n");
        } else{
            printf("empty is false\n");
        }
        end_test();
    }

    void size(TSinglyLinkedList* list) {
        printf("list size: %d\n", list->size());
        end_test();
    }



    void TEST_insert_and_erase() {
        auto* list = new TSinglyLinkedList();
        test::push_front(list, 10);
        test::pop_front(list, 5);
        test::push_back(list, 10);
        test::pop_front(list, 20);
        test::push_front(list, 10);
        test::pop_back(list, 5);
        test::push_back(list, 10);
        test::pop_back(list, 20);
        test::push_back(list, 10);
        test::clear(list, 1);
    }

    void TEST_list_state() {
        auto* list = new TSinglyLinkedList();
        list->show();
        test::empty(list);
        test::push_back(list, 10);
        list->show();
        test::empty(list);
        test::front(list);
        test::back(list);
        test::size(list);
    }
}


int main(){
    test::TEST_insert_and_erase();
    test::TEST_list_state();
    return 0;
}