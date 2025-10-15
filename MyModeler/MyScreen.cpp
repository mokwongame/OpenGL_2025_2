#include "pch.h"
#include "MyScreen.h"
#include <GL/GLU.h>

MyScreen::MyScreen(void)
{
	m_nBackColor = DEF_BACK_COLOR;
	m_nTriColor = DEF_TRI_COLOR;
	m_fps = DEF_FPS;
	m_nFrameTimeMs = int(1000.0f / m_fps); // ����: msec
	m_angle = 0.0f;
	m_angStep = 0.0f;
}

void MyScreen::RenderScene(void)
{
	// �ʱ�ȭ
	GLfloat r = 0.0f, g = 0.0f, b = 0.0f;

	// OpenGL ����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	OglScreen::colorrefToRgb(r, g, b, m_nBackColor);
	glClearColor(r, g, b, 1.0f); // ���� ����
	OglScreen::colorrefToRgb(r, g, b, m_nTriColor);
	glColor3f(r, g, b); // �ﰢ�� �� ����

	glPushMatrix();
	glLoadIdentity();
	glRotatef(m_angle, 0.0f, 1.0f, 0.0f); // y�� �������� m_angle��ŭ ȸ��

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.8f, -0.5f, 0.0f); // 1�� ������(vertex)
	glVertex3f(0.8f, -0.5f, 0.0f); // 2�� ������(vertex)
	glVertex3f(0.0f, 0.8f, 0.0f); // 3�� ������(vertex)
	glEnd();

	glPopMatrix();
}

BEGIN_MESSAGE_MAP(MyScreen, OglScreen)
	ON_WM_TIMER()
	ON_WM_CREATE()
END_MESSAGE_MAP()

void MyScreen::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nIDEvent == TIMERID_RENDER)
	{
		// �ﰢ�� ȸ��
		m_angle += m_angStep;
		if (m_angle > 360.0f) m_angle -= 360.0f;
		else if (m_angle < 0.0f) m_angle += 360.0f;
		// WM_PAINT �޽��� ����
		Invalidate(FALSE);
	}
	OglScreen::OnTimer(nIDEvent);
}

int MyScreen::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (OglScreen::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	SetTimer(TIMERID_RENDER, m_nFrameTimeMs, NULL);

	return 0;
}
