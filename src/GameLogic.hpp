#ifndef ENGINE_GAMELOGIC_HPP
#define ENGINE_GAMELOGIC_HPP

#include <memory>

namespace engine {

    class GameLogic {
    public:
        virtual void init() = 0;
        virtual void input() = 0;
        virtual void update() = 0;
        virtual void render() const = 0;
    };
}

typedef std::shared_ptr<engine::GameLogic> GameLogicPtr;

#endif //ENGINE_GAMELOGIC_HPP
