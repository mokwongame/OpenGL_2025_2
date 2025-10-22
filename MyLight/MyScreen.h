#pragma once
#include "OglScreen.h"

#define DEF_BACK_COLOR	RGB(127, 127, 127)
#define DEF_SPHERE_COLOR	RGB(255, 0, 0)

class MyScreen :
	public OglScreen
{
public:
	MyScreen(void);
	~MyScreen();

	COLORREF m_nBackColor;
	COLORREF m_nSphereColor;

protected:
	void InitOpenGL(void);
	virtual void RenderScene(void);

	GLUquadric* m_pQobj;
};

