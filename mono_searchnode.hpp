#include <vector>
#include <list>
#include "mono_data.hpp"
#include "mono_bestnode.hpp"

/* Get MonoData and search breakable points from it. */
/* return the best in broken. */
class MonoSearchNode {
public:
    static std::vector<MonoSearchNode*> work_queue;
    MonoData* data;
    MonoBestNode* best;
    MonoSearchNode(Monolis& mono);
    MonoSearchNode(MonoData* data, MonoBestNode* best);
    ~MonoSearchNode();
    void search();
    static MonoSearchNode* get_worknode();
    static bool haswork() { return !work_queue.empty(); }
};
