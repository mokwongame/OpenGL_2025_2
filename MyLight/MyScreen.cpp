#include "pch.h"
#include "MyScreen.h"

MyScreen::MyScreen(void)
{
	m_nBackColor = DEF_BACK_COLOR;
	m_nSphereColor = DEF_SPHERE_COLOR;
	m_sphereAlpha = 1.0f;

	m_pQobj = nullptr;
	DefLightParam();
}

MyScreen::~MyScreen()
{
	if (m_pQobj) gluDeleteQuadric(m_pQobj);
}

void MyScreen::SetLightParam(void)
{
	// ����
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); // 0�� ������ ��� �����ϰ� ��

	glLightfv(GL_LIGHT0, GL_AMBIENT, m_lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, m_lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, m_lightSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, m_lightPos);

	// material
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_AMBIENT, m_lightAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_lightDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m_lightSpecular);
	glMaterialfv(GL_FRONT, GL_EMISSION, m_mtlEmit);
	glMaterialf(GL_FRONT, GL_SHININESS, m_mtlShine);
}

void MyScreen::DefLightParam(void)
{
	// light
	m_lightAmbient[0] = m_lightAmbient[1] = m_lightAmbient[2] = 0.2f; // RGB ����
	m_lightAmbient[3] = 1.0f; // alpha
	m_lightDiffuse[0] = m_lightDiffuse[1] = m_lightDiffuse[2] = 0.5f; // RGB ����
	m_lightDiffuse[3] = 1.0f; // alpha
	m_lightSpecular[0] = m_lightSpecular[1] = m_lightSpecular[2] = 0.9f; // RGB ����
	m_lightSpecular[3] = 1.0f; // alpha
	m_lightPos[0] = m_lightPos[1] = m_lightPos[2] = 1.0f; // (x, y, z) ����
	m_lightPos[3] = 0.0f; // ���籤��(�¾籤) ����

	// material
	m_mtlEmit[0] = m_mtlEmit[1] = m_mtlEmit[2] = 0.0f; // RGB ����
	m_mtlEmit[3] = 1.0f; // alpha
	m_mtlShine = 100.0f;
}

void MyScreen::InitOpenGL(void)
{
	OglScreen::InitOpenGL();

	StartRC();
	if (m_pQobj) gluDeleteQuadric(m_pQobj);
	m_pQobj = gluNewQuadric();
	gluQuadricDrawStyle(m_pQobj, GLU_FILL);
	gluQuadricNormals(m_pQobj, GLU_SMOOTH);
	SetLightParam();
	SetViewport();
	StopRC();
}

void MyScreen::RenderScene(void)
{
	GLfloat r, g, b;

	// �ʱ� ���� + ���� ����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0f); // ��ü�� ī�޶󿡼� ���� �ָ�(1.0f) �ִٰ� �ʱ�ȭ(clear)
	OglScreen::colorrefToRgb(r, g, b, m_nBackColor);
	glClearColor(r, g, b, 1.0f);

	// �� �׸���
	OglScreen::colorrefToRgb(r, g, b, m_nSphereColor);
	glColor4f(r, g, b, m_sphereAlpha); // glColor3f() �ᵵ ��: alpha = 1�� ���
	if (m_pQobj) gluSphere(m_pQobj, 200., 30, 30);
}
