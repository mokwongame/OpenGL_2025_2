#include "pch.h"
#include "MyScreen.h"

MyScreen::MyScreen(void)
{
	m_nBackColor = DEF_BACK_COLOR;
	m_nSphereColor = DEF_SPHERE_COLOR;

	m_pQobj = nullptr;
}

MyScreen::~MyScreen()
{
	if (m_pQobj) gluDeleteQuadric(m_pQobj);
}

void MyScreen::InitOpenGL(void)
{
	OglScreen::InitOpenGL();

	StartRC();
	if (m_pQobj) gluDeleteQuadric(m_pQobj);
	m_pQobj = gluNewQuadric();
	StopRC();
}

void MyScreen::RenderScene(void)
{
	GLfloat r, g, b;

	// �ʱ� ���� + ���� ����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0f); // ��ü�� ī�޶󿡼� ���� �ָ�(1.0f) �ִٰ� �ʱ�ȭ(clear)
	OglScreen::colorrefToRgb(r, g, b, m_nBackColor);
	glClearColor(r, g, b, 1.0f);

	// �� �׸���
	OglScreen::colorrefToRgb(r, g, b, m_nSphereColor);
	glColor4f(r, g, b, 1.0f);
	//gluSphere();
}
