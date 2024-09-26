#pragma once

#include <string>
#include <unordered_map>
#include <glm.hpp>

class Shader {
public:
    Shader(std::string filepath);
    ~Shader();

    unsigned int Get();

    void Bind() const;

    void SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3);
    void SetUniform1f(const std::string& name, float f0);
    void SetUniform3f(const std::string& name, float f0, float f1, float f2);
    void SetUniformMatrix4fv(const std::string& name, glm::mat4& matrix);
private:
    unsigned int m_RendererID;

    std::unordered_map<std::string, int> UniformLocationCache;

    struct ShaderProgramSource {
        std::string VertexShaderSource;
        std::string FragmentShaderSource;
    };
    ShaderProgramSource ParseShader(const std::string& filepath);
    unsigned int CompileShader(unsigned int type, std::string& src);
    unsigned int CreateShader(std::string& vertexShader, std::string& fragmentShader);
    int GetUniformLocation(const std::string& name);
};