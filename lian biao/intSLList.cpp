#include "intSLList.h"
#include <iostream>

IntSLList::~IntSLList()
{
    for (IntSLLNode *p; !isEmpty();)
    {
        p = head->next;
        delete head;
        head = p;
    }
}

[[maybe_unused]] void IntSLList::addToHead(int el)
{
    head = new IntSLLNode(el, head);
    if (tail == nullptr)
        tail = head;
}

[[maybe_unused]] void IntSLList::addToTail(int el)
{
    if (tail != nullptr)
    {
        tail->next = new IntSLLNode(el);
        tail = tail->next;
    }
    else head = tail = new IntSLLNode(el);
}

[[maybe_unused]] int IntSLList::deleteFromHrad()
{
    int el = head->info;
    IntSLLNode *tmp = head;
    if (head == tail)
        head = tail = nullptr;
    else head = head->next;
    delete tmp;
    return el;
}

[[maybe_unused]] int IntSLList::deleteFromTail()
{
    int el = tail->info;
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        IntSLLNode *tmp;
        for (tmp = head; tmp->next != tail; tmp = tmp->next);
        delete tail;
        tail = tmp;
        tail->next = nullptr;
    }
    return el;
}

[[maybe_unused]] void IntSLList::deleteNode(int el)
{
    if (head != nullptr)
        if (head == tail && el == head->info)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            if (el == head->info)
            {
                IntSLLNode *tmp = head;
                head = head->next;
                delete tmp;
            }
        }
            else
            {
                IntSLLNode *pred, *tmp;
                for (pred = head, tmp = head->next;
                     tmp != nullptr && tmp->info != el; pred = pred->next, tmp = tmp->next);

                if (tmp != nullptr)
                {
                    pred->next = tmp->next;
                    if (tmp == tail)
                        tail = pred;
                    delete tmp;
                }
            }

}

[[maybe_unused]] bool IntSLList::isInList(int el) const
{
    IntSLLNode *tmp;
    for (tmp = head; tmp != nullptr && tmp->info != el; tmp = tmp->next);
    return tmp != nullptr;
}


