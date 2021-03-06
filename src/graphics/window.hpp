/**
 * MIT License
 *
 * Copyright (c) 2018 Rafael C. Nunes
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE  SOFTWARE.
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

#include <cinttypes>

// Kokiri related includes

#include "../utils/debug/debug.hpp"

/**
 * @brief An abstraction over the SDL_Window struct that provides an object
 * oriented facilities.
 */
class Window {
public:
    Window(int width, int height, const std::string &title);
    Window(int width, int height, const std::string &title, int32_t flags);
    ~Window();

    /**
     * @brief Returns a pointer to the current SDL_Window.
     */
    SDL_Window   *get_window();
    /**
     * @brief Returns a pointer to the current renderer of the window.
     */
    SDL_Renderer *get_renderer();

    /**
     * @brief Returns the width of the window
     */
    int width();
    /**
     * @brief Returns the height of the window
     */
    int height();

private:
    SDL_Window* m_window;
    SDL_Renderer* m_window_renderer;

    int m_width;
    int m_height;
};


#endif // WINDOW_H
