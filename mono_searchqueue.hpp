/* mono_searchqueue.hpp
 * class MonoSearchQueue implement queue of MonoSearchNode.
 * thread t(queue.method())
 */

#ifndef _MONO_SEARCHQUEUE_HPP_
#define _MONO_SEARCHQUEUE_HPP_

#include <vector>

class MonoSearchNode;

class MonoSearchQueue
{
    int m_worker;
    std::vector<MonoSearchNode*> m_queue;
public:
    MonoSearchQueue();
    ~MonoSearchQueue();
    void start_work();
    void add_node(MonoSearchNode*);
    MonoSearchNode* pop_node();
    bool has_node();
    void end_node();
private:
};

#endif