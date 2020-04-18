#include <vector>

class MonoBestNode {
public:
    int smallest_num_unbreakable;
    std::vector<int> best_move;
    MonoBestNode();
    ~MonoBestNode();
    void update(int n, std::vector<int> &move);
};