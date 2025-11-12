#pragma once
#include "OglScreen.h"
#include "OglLightMtl.h"
#include "OglSphere.h"
#include "OglCube.h"

class MyScreen :
	public OglScreen
{
public:
	MyScreen(void);

	OglLightMtl m_lightMtl;
	OglSphere m_sphere;
	OglCube m_cube;

protected:
	GLfloat m_fps; // frame per second
	int m_nFrameMs;
	GLfloat m_ang;
	GLfloat m_rps;	// rotation per second
	GLuint m_texId;	// texture ID; 6개가 필요하면 GLuint m_texId[6]

	virtual void InitOpenGL(void);
	virtual void RenderScene(void);
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

