#include "pch.h"
#include "MyScreen.h"

MyScreen::MyScreen(void)
{
	SetBackColor(RGB(0, 0, 255));
}

void MyScreen::InitOpenGL(void)
{
	OglScreen::InitOpenGL();

}

void MyScreen::InitRender(void)
{
	OglScreen::InitRender();

}

void MyScreen::RenderScene(void)
{
	OglScreen::RenderScene();

}