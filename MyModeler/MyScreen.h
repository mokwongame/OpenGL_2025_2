#pragma once
#include "OglScreen.h"

#define DEF_BACK_COLOR	RGB(255, 255, 255)
#define DEF_TRI_COLOR	RGB(255, 0, 0)

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
};

