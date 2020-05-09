/* mono_islemanager.hpp
 *
 */

#ifndef _MONO_BN_MANAGER_HPP_
#define _MONO_BN_MANAGER_HPP_

#include <vector>

class MonoBestNode;
class MonoSearchNode;
class MonoMove;

class MonoIsleManager
{
public:
    // Array of each best node of isle.
    MonoBestNode* isle;
    // Process of devided isle.
    MonoMove process;
    MonoIsleManager(MonoSearchNode&);
    ~MonoIsleManager();
};

#endif