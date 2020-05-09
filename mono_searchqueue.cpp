#include "mono_searchqueue.hpp"

MonoSearchQueue::MonoSearchQueue() : m_worker(0), m_queue(std::vector<MonoSearchNode*>()) { }

MonoSearchQueue::~MonoSearchQueue() { }

void MonoSearchQueue::add_node(MonoSearchNode* node)
{
    m_queue.push_back(node);
}

MonoSearchNode* MonoSearchQueue::pop_node()
{
    if (!m_queue.empty()) {
        ++m_worker;
        MonoSearchNode* node = m_queue.back();
        m_queue.pop_back();
        return node;
    }
    else
        return nullptr;
}

bool MonoSearchQueue::has_node()
{
    return m_worker > 0 || !m_queue.empty();
}

void MonoSearchQueue::end_node()
{
    --m_worker;
}