#include "pch.h"
#include "MyScreen.h"

#define TIMERID_RENDER	(1)

MyScreen::MyScreen(void)
{
	m_nBackColor = RGB(127, 127, 127);
	m_sphere.SetRgba(RGB(0, 255, 0));

	m_fps = 50.;
	m_nFrameMs = int(1000. / m_fps);
	m_ang = 0.f;
	m_rps = 0.2f * 360.f / 1000.f;

	m_bTexMap = false;
}

void MyScreen::SetTexture2D(void)
{
	// texture 생성
	glGenTextures(1, &m_texId); // generate textures
	glBindTexture(GL_TEXTURE_2D, m_texId); // m_texId가 가리키는 텍스터 구조에 설정을 시작함
	// texture 설정: m_texId에 따라
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 확대(텍셀 -> 픽셀)할 때 사용; GL_NEAREST는 빠르지만 픽셀의 정확도가 떨어짐
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 멀리 있는 물체에는 aliasing(가짜 패턴)이 생길 수있음 -> 방지하려면 mip map 사용
	// 비트맵을 텍셀로 선택
	OglScreen::SetTexImage2D(_T("./res/dog.jpg"));
	// texture 사용 선택
	glEnable(GL_TEXTURE_2D);
}

void MyScreen::InitOpenGL(void)
{
	OglScreen::InitOpenGL();
	m_lightMtl.SetDCRC(m_hDC, m_hRC);

	StartRC();
	m_sphere.Create();
	m_lightMtl.SetLightParam();
	SetTexture2D();
	SetViewport();
	StopRC();
}

void MyScreen::RenderScene(void)
{
	if (m_bTexMap) glEnable(GL_TEXTURE_2D);
	else glDisable(GL_TEXTURE_2D);

	glPushMatrix();
	glLoadIdentity();
	glRotatef(m_ang, 1.0f, 0.0f, 0.0f); // x축을 회전축으로 회전
	glRotatef(m_ang, 0.0f, 1.0f, 0.0f); // y축을 회전축으로 회전

	//m_sphere.Draw(200.);
	if (m_bTexMap) m_cube.Draw(100., m_texId);
	else m_cube.Draw(100.);

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
		GLfloat step = m_rps * m_nFrameMs;
		m_ang += step;
		if (m_ang > 360.f) m_ang -= 360.f;
		Invalidate(FALSE);
	}

	OglScreen::OnTimer(nIDEvent);
}

int MyScreen::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (OglScreen::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	SetTimer(TIMERID_RENDER, m_nFrameMs, NULL);

	return 0;
}
