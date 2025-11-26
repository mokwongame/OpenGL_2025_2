#pragma once

#include "OglScreen.h"

class MyScreen :
	public OglScreen
{
public:
	MyScreen(void);

protected:
	virtual void InitOpenGL(void);
	virtual void InitRender(void);
	virtual void RenderScene(void);
};

