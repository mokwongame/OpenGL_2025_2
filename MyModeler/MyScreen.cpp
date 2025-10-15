#include "pch.h"
#include "MyScreen.h"
#include <GL/GLU.h>

MyScreen::MyScreen(void)
{
	m_nBackColor = DEF_BACK_COLOR;
	m_nTriColor = DEF_TRI_COLOR;
	m_fps = DEF_FPS;
	m_nFrameTimeMs = int(1000.0f / m_fps); // 단위: msec
	m_angle = 0.0f;
	m_angStep = 0.0f;
}

void MyScreen::RenderScene(void)
{
	// 초기화
	GLfloat r = 0.0f, g = 0.0f, b = 0.0f;

	// OpenGL 실행
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	OglScreen::colorrefToRgb(r, g, b, m_nBackColor);
	glClearColor(r, g, b, 1.0f); // 배경색 설정
	OglScreen::colorrefToRgb(r, g, b, m_nTriColor);
	glColor3f(r, g, b); // 삼각형 색 설정

	glPushMatrix();
	glLoadIdentity();
	glRotatef(m_angle, 0.0f, 1.0f, 0.0f); // y축 기준으로 m_angle만큼 회전

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.8f, -0.5f, 0.0f); // 1번 꼭지점(vertex)
	glVertex3f(0.8f, -0.5f, 0.0f); // 2번 꼭지점(vertex)
	glVertex3f(0.0f, 0.8f, 0.0f); // 3번 꼭지점(vertex)
	glEnd();

	glPopMatrix();
}

BEGIN_MESSAGE_MAP(MyScreen, OglScreen)
	ON_WM_TIMER()
	ON_WM_CREATE()
END_MESSAGE_MAP()

void MyScreen::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == TIMERID_RENDER)
	{
		// 삼각형 회전
		m_angle += m_angStep;
		if (m_angle > 360.0f) m_angle -= 360.0f;
		else if (m_angle < 0.0f) m_angle += 360.0f;
		// WM_PAINT 메시지 생성
		Invalidate(FALSE);
	}
	OglScreen::OnTimer(nIDEvent);
}

int MyScreen::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (OglScreen::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	SetTimer(TIMERID_RENDER, m_nFrameTimeMs, NULL);

	return 0;
}
