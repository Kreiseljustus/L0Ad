#pragma once

#include "Application.h"

#include "rendering/Shader.h"
#include "rendering/VertexArray.h"
#include "rendering/VertexBuffer.h"
#include "rendering/IndexBuffer.h"
#include "rendering/Renderer.h"

namespace Editor {
	class EditorApplication : public Engine::Application {
	public:
		EditorApplication();
		virtual ~EditorApplication();

	protected:
		virtual void onUpdate() override;
		virtual void onRender() override;
		virtual void onEvent(GLFWwindow* window, int key, int scancode, int action, int mods) override;

        virtual void pastInit() override;

        float vertices[144] = {
            // Vertex positions       // Normals

            // Front face (z = 0.5)
             0.5f, -0.5f,  0.5f,      0.0f,  0.0f,  1.0f,  // Vertex 0
            -0.5f, -0.5f,  0.5f,      0.0f,  0.0f,  1.0f,  // Vertex 1
             0.5f,  0.5f,  0.5f,      0.0f,  0.0f,  1.0f,  // Vertex 2
            -0.5f,  0.5f,  0.5f,      0.0f,  0.0f,  1.0f,  // Vertex 3

            // Back face (z = -0.5)
             0.5f, -0.5f, -0.5f,      0.0f,  0.0f, -1.0f,  // Vertex 4
            -0.5f, -0.5f, -0.5f,      0.0f,  0.0f, -1.0f,  // Vertex 5
             0.5f,  0.5f, -0.5f,      0.0f,  0.0f, -1.0f,  // Vertex 6
            -0.5f,  0.5f, -0.5f,      0.0f,  0.0f, -1.0f,  // Vertex 7

            // Left face (x = -0.5)
            -0.5f, -0.5f,  0.5f,     -1.0f,  0.0f,  0.0f,  // Vertex 8
            -0.5f,  0.5f,  0.5f,     -1.0f,  0.0f,  0.0f,  // Vertex 9
            -0.5f, -0.5f, -0.5f,     -1.0f,  0.0f,  0.0f,  // Vertex 10
            -0.5f,  0.5f, -0.5f,     -1.0f,  0.0f,  0.0f,  // Vertex 11

            // Right face (x = 0.5)
             0.5f, -0.5f,  0.5f,      1.0f,  0.0f,  0.0f,  // Vertex 12
             0.5f,  0.5f,  0.5f,      1.0f,  0.0f,  0.0f,  // Vertex 13
             0.5f, -0.5f, -0.5f,      1.0f,  0.0f,  0.0f,  // Vertex 14
             0.5f,  0.5f, -0.5f,      1.0f,  0.0f,  0.0f,  // Vertex 15

             // Top face (y = 0.5)
             -0.5f,  0.5f,  0.5f,      0.0f,  1.0f,  0.0f,  // Vertex 16
              0.5f,  0.5f,  0.5f,      0.0f,  1.0f,  0.0f,  // Vertex 17
             -0.5f,  0.5f, -0.5f,      0.0f,  1.0f,  0.0f,  // Vertex 18
              0.5f,  0.5f, -0.5f,      0.0f,  1.0f,  0.0f,  // Vertex 19

              // Bottom face (y = -0.5)
              -0.5f, -0.5f,  0.5f,      0.0f, -1.0f,  0.0f,  // Vertex 20
               0.5f, -0.5f,  0.5f,      0.0f, -1.0f,  0.0f,  // Vertex 21
              -0.5f, -0.5f, -0.5f,      0.0f, -1.0f,  0.0f,  // Vertex 22
               0.5f, -0.5f, -0.5f,      0.0f, -1.0f,  0.0f   // Vertex 23
        };

        unsigned int triangles[36] = {
            // Front face
            0, 2, 3, 0, 3, 1,

            // Back face
            6, 4, 5, 6, 5, 7,

            // Left face
            8, 10, 11, 8, 11, 9,

            // Right face
            12, 13, 15, 12, 15, 14,

            // Top face
            16, 18, 19, 16, 19, 17,

            // Bottom face
            20, 21, 23, 20, 23, 22
        };

        VertexArray* va = nullptr;
        VertexBuffer* vb = nullptr;
        VertexBufferLayout* layout = nullptr;
        IndexBuffer* ib = nullptr;
        Shader* shader = nullptr;
        Renderer* renderer = nullptr;
	};
}