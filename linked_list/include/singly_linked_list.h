/****************************************************
* @copyright: e-tuanzi
*
* @file: singly_linked_list.h
* @brief: 单向链表的cpp实现
* @author: e-tuanzi
* @create: 2022-11-22
* @version: v1
* ==========      Update Log              ==========
2022-11-22  创建文件
2022-11-23  添加基本插入删除状态查询等函数
****************************************************/

#ifndef CPP_ALGORITHMS_SINGLY_LINKED_LIST_H
#define CPP_ALGORITHMS_SINGLY_LINKED_LIST_H

/**
 * @brief: 链表节点
 * @example:
 *      TSinglyLinkedNode * node_ptr = new TSinglyLinkedNode;
 */
struct TSinglyLinkedNode{
    int data;
    TSinglyLinkedNode * next;
    explicit TSinglyLinkedNode(int data, TSinglyLinkedNode * next = nullptr){
        this->data = data;
        this->next = next;
    }
    ~TSinglyLinkedNode()= default;
};

/**
 * @brief: 链表实现类
 */
class TSinglyLinkedList{
private:
    TSinglyLinkedNode * head_;
public:
    /**
     * @brief: 无参构造函数
     * @example:
     *      TSinglyLinkedList* list = new TSinglyLinkedList();
     */
    TSinglyLinkedList();

    /**
     * @brief: 析构函数
     */
    ~TSinglyLinkedList();

    /**
     * @brief: 获得链表首元素
     * @ret: 首元素节点指针
     * @example:
     *      TSinglyLinkedNode* begin_ptr = list->begin();
     */
    TSinglyLinkedNode* begin();

    /**
     * @brief: 获得链表末尾元素
     * @ret: 末尾元素节点指针
     * @example:
     *      TSinglyLinkedNode* end_ptr = list->end();
     */
    TSinglyLinkedNode* end();

    /**
     * @brief: 获得链表首元素的值
     * @ret: 首元素节点的值
     * @example:
     *      int data = list->front();
     */
    int front();

    /**
     * @brief: 获得链表末尾元素的值
     * @ret: 末尾元素节点的值
     * @example:
     *      int data = list->back();
     */
    int back();

    /**
     * @brief: 在链表头部插入一个元素
     * @ret: 插入成功返回true
     * @example:
     *      list->push_front(num);
     */
    bool push_front(int val);

    /**
     * @brief: 在链表头部删除一个元素
     * @ret: 删除成功返回true
     * @example:
     *      list->pop_front();
     */
    void pop_front();

    /**
     * @brief: 在链表尾部插入一个元素
     * @example:
     *      list->push_back(num);
     */
    bool push_back(int val);

    /**
     * @brief: 在链表尾部删除一个元素
     * @ret: 删除成功返回true
     * @example:
     *      list->pop_back();
     */
    void pop_back();

    /**
     * @brief: 清空链表
     * @ret: 清空成功返回true
     * @example:
     *      list->clear();
     */
    bool clear();

    /**
     * @brief: 获取当前链表中元素个数
     * @ret: 元素个数
     * @example:
     *      int sum = list->size();
     */
    int size();

    /**
     * @brief: 判断链表是否为空
     * @ret: 空返回true
     * @example:
     *      list->clear();
     */
    bool empty();
//    bool remove();
//    bool unique();
//    bool sort();
//    bool reserve();
    void show();

};
#endif //CPP_ALGORITHMS_SINGLY_LINKED_LIST_H
