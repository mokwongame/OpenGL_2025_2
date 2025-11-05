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
	StopRC();
}

void MyScreen::RenderScene(void)
{

}

