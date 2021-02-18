#ifndef RAMENGINE_WINDOW_HPP
#define RAMENGINE_WINDOW_HPP

namespace engine {

    class Window {
    public:
        Window(int width, int height);

        virtual void setTitle(const char* title) = 0;
        [[nodiscard]] virtual bool shouldClose() const = 0;
        virtual void swapBuffers() const = 0;
        virtual void pollEvents() const = 0;

        ~Window();

    private:
        int m_width;
        int m_height;
    };
}

#endif //RAMENGINE_WINDOW_HPP
