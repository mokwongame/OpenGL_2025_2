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

	// 초기 설정 + 배경색 설정
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0f); // 물체는 카메라에서 가장 멀리(1.0f) 있다고 초기화(clear)
	OglScreen::colorrefToRgb(r, g, b, m_nBackColor);
	glClearColor(r, g, b, 1.0f);

	// 구 그리기
	OglScreen::colorrefToRgb(r, g, b, m_nSphereColor);
	glColor4f(r, g, b, 1.0f);
	//gluSphere();
}
