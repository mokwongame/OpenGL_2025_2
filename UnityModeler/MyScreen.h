#pragma once

#include "OglScreen.h"
#include "OglLightMtl.h"
#include "OglSphere.h"

class MyScreen :
	public OglScreen
{
public:
	MyScreen(void);

protected:
	OglLightMtl m_lightMtl;
	OglSphere m_sphere;

	virtual void InitOpenGL(void);
	virtual void InitRender(void);
	virtual void RenderScene(void);
};

