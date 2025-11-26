#include "pch.h"
#include "MyScreen.h"

MyScreen::MyScreen(void)
{
	SetBackColor(RGB(0, 0, 255));
}

void MyScreen::InitOpenGL(void)
{
	OglScreen::InitOpenGL();

	StartRC();

	m_lightMtl.SetLightParam();
	m_sphere.Create();
	SetViewport();

	StopRC();
}

void MyScreen::InitRender(void)
{
	OglScreen::InitRender();

}

void MyScreen::RenderScene(void)
{
	OglScreen::RenderScene();

	m_sphere.SetRgba(RGB(0, 255, 0));
	m_sphere.Draw(100.);
}