#include "Shader.h"

#include "glew.h"
#include <iostream>

#include <fstream>
#include "../Logging.h"
#include <sstream>
#include <filesystem>
#include <ext.hpp>

Shader::Shader(std::string filepath) {
    ShaderProgramSource source = ParseShader(filepath);

    //print("Full path to shader file: " << std::filesystem::current_path() << "/" << filepath);

    //print("VERTEX" << source.VertexShaderSource);
    //print("FRAGMENT" << source.FragmentShaderSource);

    m_RendererID = CreateShader(source.VertexShaderSource, source.FragmentShaderSource);

}

Shader::~Shader() {

}

unsigned int Shader::Get() {
    return m_RendererID;
}

void Shader::Bind() const {
    glUseProgram(m_RendererID);
}

void Shader::SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3) {
    glUniform4f(GetUniformLocation(name), f0, f1, f2, f3);
}

void Shader::SetUniform1f(const std::string& name, float f0) {
    glUniform1f(GetUniformLocation(name), f0);
}

void Shader::SetUniform3f(const std::string& name, float f0, float f1, float f2) {
    glUniform3f(GetUniformLocation(name), f0, f1, f2);
}

void Shader::SetUniformMatrix4fv(const std::string& name, glm::mat4& matrix) {
    glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

unsigned int Shader::CreateShader(std::string& vertexShader, std::string& fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int Shader::GetUniformLocation(const std::string& name)
{
    if (UniformLocationCache.find(name) != UniformLocationCache.end())
        return UniformLocationCache[name];

    int location = glGetUniformLocation(m_RendererID, name.c_str());
    if (location == -1) {
        std::cout << "No active uniform variable with name " << name << " found" << std::endl;
    }

    UniformLocationCache[name] = location;
    std::cout << "Returning " << location << std::endl;
    return location;
}

unsigned int Shader::CompileShader(unsigned int type, std::string& src) {
    unsigned int id = glCreateShader(type);
    const char* source = src.c_str();
    glShaderSource(id, 1, &source, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << message << std::endl;

        glDeleteShader(id);
        return 0;
    }

    return id;
}

Shader::ShaderProgramSource Shader::ParseShader(const std::string& filepath) {
    std::ifstream stream(filepath);

    enum class ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::cout << "Opened file " << filepath << std::endl;

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while (getline(stream, line)) {
        std::cout << "LINE";
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos) {
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos) {
                type = ShaderType::FRAGMENT;
            }
        }
        else {
            ss[(int)type] << line << "\n";
        }
    }

    return { ss[0].str(), ss[1].str() };
}
