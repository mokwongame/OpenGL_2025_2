#pragma once
#include <GL/glew.h>

class OglCube
{
public:
	OglCube(void);

	void SetRgba(const COLORREF arColor[], const GLfloat arAlpha[]);
	void Draw(GLfloat halfLen) const; // 정육면체의 길이 = halfLen*2
	void Draw(GLfloat halfLen, GLuint texId) const; // texture mapping; 정육면체의 길이 = halfLen*2

protected:
	COLORREF m_arColor[6];
	GLfloat m_arAlpha[6];
};

