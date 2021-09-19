//
// Created by 赵泉 on 2021/9/19.
//

#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNode
{
public:
    IntSLLNode()
    {
        next = 0;
    }

    IntSLLNode(int el, IntSLLNode *ptr = 0)
    {
        info = el;
        next = ptr;
    }

    int info;
    IntSLLNode *next;
};

class IntSLList
{
public:
    IntSLList()
    {
        head = tail = 0;
    }

    ~IntSLList();

    int isEmpty()
    {
        return head == 0;
    }

    [[maybe_unused]] void addToHead(int);

    [[maybe_unused]] void addToTail(int);

    [[maybe_unused]] int deleteFromHrad();

    [[maybe_unused]] int deleteFromTail();

    [[maybe_unused]] void deleteNode(int);

    [[maybe_unused]] bool isInList(int) const;

private:
    IntSLLNode *head, *tail;
};


#endif //LIAN_BIAO_INTSLLIST
