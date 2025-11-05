#pragma once
#include "OglScreen.h"
#include "OglLightMtl.h"

class MyScreen :
	public OglScreen
{
public:
	MyScreen(void);

	COLORREF m_nBackColor;
	OglLightMtl m_lightMtl;

protected:
	virtual void InitOpenGL(void);
	virtual void RenderScene(void);
};

