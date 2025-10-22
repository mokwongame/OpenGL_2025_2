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
	void SetLightParam(void);
	void DefLightParam(void);
	virtual void InitOpenGL(void);
	virtual void RenderScene(void);

	GLUquadric* m_pQobj;
	GLfloat m_lightAmbient[4]; // ambient light(ÁÖº¯±¤): RGBA
	GLfloat m_lightDiffuse[4]; // diffuse light(È®»ê±¤): RGBA
	GLfloat m_lightSpecular[4]; // specular light(Á÷»ç±¤): RGBA
	GLfloat m_lightPos[4];		// ±¤¿ø À§Ä¡ (x, y, z, w): w = 0ÀÌ¸é Á÷»ç±¤¼±, w != 0ÀÌ¸é Á¡ ±¤¿ø
};

