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
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE  SOFTWARE.
 */

#include "renderer.hpp"
#include "debug.hpp"

#include "3rd/glad/glad.h"

#include <GL/glu.h>

Renderer::Renderer(SDL_GLContext& gl_context) {
    // making _renderer point to a copy of the renderer pointer.
    _gl_context = gl_context;

    // Load glad
    if(!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
        Debug::log_err("Failed to load GLAD");
        exit(1);
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 600, 0);
    glMatrixMode(GL_MODELVIEW);
}

void Renderer::render_cube(float size) {
    glClearColor(0.1, 0.1, 0.6, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(Object object) {
    glBufferData(GL_ARRAY_BUFFER, object.vertices.size() * sizeof(glm::vec3),
                 &object.vertices[0], GL_STATIC_DRAW);
}

void Renderer::rotate(float angle, float x, float y, float z) {
    glRotatef(angle, x, y, z);
}

void Renderer::rotate(float angle, Vector3<float> v) {
    glRotatef(angle, v.m_x, v.m_y, v.m_z);
}
