#ifndef ENGINE_GAMELOGIC_HPP
#define ENGINE_GAMELOGIC_HPP

#include <memory>
#include <backends/Backend.hpp>

namespace engine {

    class GameLogic {
    public:
        virtual void init(BackendPtr& backendPtr){}
        virtual void input(){}
        virtual void update(double delta){}
        virtual void render(BackendPtr& backendPtr) const {}
    };
}

typedef std::shared_ptr<engine::GameLogic> GameLogicPtr;

#endif //ENGINE_GAMELOGIC_HPP
