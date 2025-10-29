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
	GLfloat m_sphereAlpha;

	GLfloat m_fps; // frame per second
	int m_nFrameMs;
	GLfloat m_ang;
	GLfloat m_rps;	// rotation per second

protected:
	void SetLightParam(void);
	void DefLightParam(void);
	virtual void InitOpenGL(void);
	virtual void RenderScene(void);

	GLUquadric* m_pQobj;
	GLfloat m_lightAmbient[4]; // ambient light(�ֺ���): RGBA
	GLfloat m_lightDiffuse[4]; // diffuse light(Ȯ�걤): RGBA
	GLfloat m_lightSpecular[4]; // specular light(���籤): RGBA
	GLfloat m_lightPos[4];		// ���� ��ġ (x, y, z, w): w = 0�̸� ���籤��, w != 0�̸� �� ����
	GLfloat m_mtlEmit[4];		// ��ü�� �߱�(emission) Ư��: RGBA
	GLfloat m_mtlShine;			// ��ü�� ����: ���� �������� �ݼ�ó�� ������ ��
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

