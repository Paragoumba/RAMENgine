#ifndef CONFINED_WINDOW_HPP
#define CONFINED_WINDOW_HPP

class Window {
public:
    Window(int width, int height);

    virtual void setTitle(const char* title) = 0;
    [[nodiscard]] virtual bool shouldClose() const = 0;
    virtual void swapBuffers() const = 0;
    virtual void update() const = 0;

    ~Window();

private:
    int m_width;
    int m_height;
};

#endif //CONFINED_WINDOW_HPP
