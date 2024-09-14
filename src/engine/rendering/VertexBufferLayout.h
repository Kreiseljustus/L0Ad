#pragma once

#include <vector>
#include <glew.h>

struct VertexBufferLayoutElement {
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int GetTypeSize(unsigned int type) {
		switch (type) {
		case GL_FLOAT: return sizeof(GLfloat);
		case GL_UNSIGNED_INT:return sizeof(GLuint);
		case GL_UNSIGNED_BYTE: return sizeof(GLbyte);
		}
		return 0;
	}
};

class VertexBufferLayout {
private:
	unsigned int m_Stride;
	std::vector<VertexBufferLayoutElement> m_Elements;

	void Push(unsigned int type, unsigned int count, unsigned char normalized) {
		m_Elements.push_back({ type,count,normalized });
		m_Stride += count * VertexBufferLayoutElement::GetTypeSize(type);
	}

public:
	VertexBufferLayout() : m_Stride(0) {}

	void AddFloat(unsigned int count) { Push(GL_FLOAT, count, GL_FALSE); }
	void AddUnsignedInt(unsigned int count) { Push(GL_UNSIGNED_INT, count, GL_FALSE); }
	void AddUnsignedByte(unsigned int count) { Push(GL_UNSIGNED_BYTE, count, GL_FALSE); }

	inline const std::vector<VertexBufferLayoutElement> GetElements() const { return m_Elements; }
	inline unsigned int GetStride() const { return m_Stride; }
};