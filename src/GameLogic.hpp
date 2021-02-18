#ifndef ENGINE_GAMELOGIC_HPP
#define ENGINE_GAMELOGIC_HPP

#include <memory>

namespace engine {

    class GameLogic {
    public:
        virtual void init(){}
        virtual void input(){}
        virtual void update(){}
        virtual void render() const {}
    };
}

typedef std::shared_ptr<engine::GameLogic> GameLogicPtr;

#endif //ENGINE_GAMELOGIC_HPP
