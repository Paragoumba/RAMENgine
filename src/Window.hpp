#ifndef RAMENGINE_WINDOW_HPP
#define RAMENGINE_WINDOW_HPP

#include <memory>

namespace engine {

    class Window {
    public:
        Window(int width, int height);

        virtual void setTitle(const char* title) = 0;
        [[nodiscard]] virtual bool shouldClose() const = 0;
        virtual void swapBuffers() const = 0;
        virtual void pollEvents() const = 0;
        virtual void setSize(int width, int height) = 0;
        [[nodiscard]] int getWidth() const;
        [[nodiscard]] int getHeight() const;

        ~Window();

    protected:
        int m_width;
        int m_height;
    };
}

typedef std::shared_ptr<engine::Window> WindowPtr;

#endif //RAMENGINE_WINDOW_HPP
