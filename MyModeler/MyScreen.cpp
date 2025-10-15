#include "pch.h"
#include "MyScreen.h"
#include <GL/GLU.h>

MyScreen::MyScreen(void)
{
	m_nBackColor = DEF_BACK_COLOR;
	m_nTriColor = DEF_TRI_COLOR;
}

void MyScreen::RenderScene(void)
{
	// �ʱ�ȭ
	GLfloat r = 0.0f, g = 0.0f, b = 0.0f;

	// OpenGL ����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	OglScreen::colorrefToRgb(r, g, b, m_nBackColor);
	glClearColor(r, g, b, 1.0f); // ���� ����
	OglScreen::colorrefToRgb(r, g, b, m_nTriColor);
	glColor3f(r, g, b); // �ﰢ�� �� ����
}
