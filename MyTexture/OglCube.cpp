#include "pch.h"
#include "OglCube.h"
#include "OglScreen.h"

OglCube::OglCube(void)
{
	m_arColor[0] = RGB(255, 0, 0);
	m_arColor[1] = RGB(0, 255, 0);
	m_arColor[2] = RGB(0, 0, 255);
	m_arColor[3] = RGB(255, 255, 0);
	m_arColor[4] = RGB(0, 255, 255);
	m_arColor[5] = RGB(255, 0, 255);

	for (int i = 0; i < 6; i++)
		m_arAlpha[i] = 1.0f;
}

void OglCube::SetRgba(const COLORREF arColor[], const GLfloat arAlpha[])
{
	for (int i = 0; i < 6; i++)
	{
		m_arColor[i] = arColor[i];
		m_arAlpha[i] = arAlpha[i];
	}
}

void OglCube::Draw(GLfloat len) const
{
	GLfloat r, g, b;
	glBegin(GL_QUADS);
	// front facet: 전면(#0)
	OglScreen::colorrefToRgb(r, g, b, m_arColor[0]);
	glColor4f(r, g, b, m_arAlpha[0]);
	glVertex3f(-len, -len, len);
	glVertex3f(len, -len, len);
	glVertex3f(len, len, len);
	glVertex3f(-len, len, len);
	// back facet: 후면(#2)
	OglScreen::colorrefToRgb(r, g, b, m_arColor[2]);
	glColor4f(r, g, b, m_arAlpha[2]);
	glVertex3f(len, -len, -len);
	glVertex3f(-len, -len, -len);
	glVertex3f(-len, len, -len);
	glVertex3f(len, len, -len);
	// right facet: 우면(#1)
	OglScreen::colorrefToRgb(r, g, b, m_arColor[1]);
	glColor4f(r, g, b, m_arAlpha[1]);
	glVertex3f(len, -len, len);
	glVertex3f(len, -len, -len);
	glVertex3f(len, len, -len);
	glVertex3f(len, len, len);
	// left facet: 좌면(#3)
	OglScreen::colorrefToRgb(r, g, b, m_arColor[3]);
	glColor4f(r, g, b, m_arAlpha[3]);
	glVertex3f(-len, -len, -len);
	glVertex3f(-len, -len, len);
	glVertex3f(-len, len, len);
	glVertex3f(-len, len, -len);
	// top facet: 상면(#4)
	OglScreen::colorrefToRgb(r, g, b, m_arColor[4]);
	glColor4f(r, g, b, m_arAlpha[4]);
	glVertex3f(-len, len, len);
	glVertex3f(len, len, len);
	glVertex3f(len, len, -len);
	glVertex3f(-len, len, -len);
	// bottom facet: 하면(#5)
	OglScreen::colorrefToRgb(r, g, b, m_arColor[5]);
	glColor4f(r, g, b, m_arAlpha[5]);
	glVertex3f(-len, -len, -len);
	glVertex3f(len, -len, -len);
	glVertex3f(len, -len, len);
	glVertex3f(-len, -len, len);
	glEnd();
}
