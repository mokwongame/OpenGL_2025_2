#include "pch.h"
#include "MyScreen.h"

MyScreen::MyScreen(void)
{
	m_nBackColor = RGB(127, 127, 127);
}

void MyScreen::InitOpenGL(void)
{
	OglScreen::InitOpenGL();
	m_lightMtl.SetDCRC(m_hDC, m_hRC);

	StartRC();
	m_sphere.Create();
	m_lightMtl.SetLightParam();
	SetViewport();
	StopRC();
}

void MyScreen::RenderScene(void)
{
	glPushMatrix();
	glLoadIdentity();

	m_sphere.Draw(200.);

	glPopMatrix();
}

