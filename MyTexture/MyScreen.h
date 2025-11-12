#pragma once
#include "OglScreen.h"
#include "OglLightMtl.h"
#include "OglSphere.h"

class MyScreen :
	public OglScreen
{
public:
	MyScreen(void);

	OglLightMtl m_lightMtl;
	OglSphere m_sphere;

protected:
	virtual void InitOpenGL(void);
	virtual void RenderScene(void);
};

