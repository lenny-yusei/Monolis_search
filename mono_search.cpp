/* monosearch.cpp */
#include <iostream>
#include <ctime>
#include "monolis.hpp"
#include "mono_move.hpp"
#include "mono_searchnode.hpp"
#include "mono_bestnode.hpp"

class MonoSearch {
public:
    MonoSearch(Monolis& mono) : mono_base(mono) { }

    void start_search() {
        clock_t start = clock();

        MonoSearchNode::init(mono_base);
        MonoSearchNode::start_search();

        clock_t end = clock();
        m_search_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    }

    double search_time() { return m_search_time; }
    MonoBestNode* best() { return MonoSearchNode::result(); }
private:
    Monolis mono_base;
    double m_search_time;
};

int main()
{
    Monolis mono(4, 4, 3);
    mono.show_board();
    
    MonoSearch ms(mono);
    ms.start_search();

    std::cout << "search time: " <<  ms.search_time() << "ms" << std::endl;
    ms.best()->show();

    std::vector<MonoPoint> best_move = ms.best()->best_move.move;
    for (int i = 0; i < best_move.size(); i++) {
        mono.break_from(best_move[i]);
        mono.show_board();
        std::cout << std::endl;
    }
    
    return 0;
}