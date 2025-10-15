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

	void SetBackColor(COLORREF color) { m_nBackColor = color; }
	void SetTriColor(COLORREF color) { m_nTriColor = color; }

protected:
	virtual void RenderScene(void);

	COLORREF m_nBackColor;
	COLORREF m_nTriColor;
	GLfloat m_fps;
	int m_nFrameTimeMs;
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

