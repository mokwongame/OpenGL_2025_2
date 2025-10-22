#pragma once
#include "OglScreen.h"

class MyScreen :
	public OglScreen
{
public:
	MyScreen(void);

protected:
	virtual void RenderScene(void);
};

