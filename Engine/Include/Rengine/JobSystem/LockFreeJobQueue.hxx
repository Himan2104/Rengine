#pragma once

#include <atomic>
#include <functional>

namespace Ren::MT
{
class LockFreeJobQueue
{
private:
    struct Node
    {
        std::function<void()> task;
        Node* next;
    };

    std::atomic<Node*> head{nullptr};
    std::atomic<Node*> tail{nullptr};

public:
    LockFreeJobQueue()
    {
        Node* dummy = new Node();
        head.store(dummy);
        tail.store(dummy);
    }

    ~LockFreeJobQueue()
    {
        while (head.load())
        {
            Node* temp = head.load();
            head.store(temp->next);
            delete temp;
        }
    }

    void push(std::function<void()> job)
    {
        Node* newNode = new Node{job, nullptr};
        Node* oldTail = tail.load();

        while (!tail.compare_exchange_weak(oldTail, newNode)) { oldTail = tail.load(); }

        oldTail->next = newNode;
    }

    bool pop(std::function<void()>& job)
    {
        Node* oldHead  = head.load();
        Node* nextNode = oldHead->next;

        if (nextNode)
        {
            job = nextNode->task;
            head.store(nextNode);
            delete oldHead;
            return true;
        }
        return false;
    }
};
} // namespace Ren::MT
