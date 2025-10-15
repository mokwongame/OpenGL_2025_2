#pragma once
#include "OglScreen.h"

#define DEF_BACK_COLOR	RGB(255, 255, 255)
#define DEF_TRI_COLOR	RGB(255, 0, 0)
#define DEF_FPS		(120.0f)
#define TIMERID_RENDER	(10)

class MyScreen :
	public OglScreen
{
public:
	MyScreen(void);

	GLfloat GetAngStep(void) const { return m_angStep; }
	void SetBackColor(COLORREF color) { m_nBackColor = color; }
	void SetTriColor(COLORREF color) { m_nTriColor = color; }
	void SetAngStep(GLfloat step) { m_angStep = step; }

protected:
	virtual void RenderScene(void);

	COLORREF m_nBackColor;
	COLORREF m_nTriColor;
	GLfloat m_fps;
	GLfloat m_angle, m_angStep;
	int m_nFrameTimeMs;
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

