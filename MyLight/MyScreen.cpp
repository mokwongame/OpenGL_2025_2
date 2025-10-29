#include "pch.h"
#include "MyScreen.h"

#define TIMERID_RENDER	(1)

MyScreen::MyScreen(void)
{
	m_nBackColor = DEF_BACK_COLOR;
	m_nSphereColor = DEF_SPHERE_COLOR;
	m_sphereAlpha = 1.0f;

	m_fps = 50.;
	m_nFrameMs = int(1000. / m_fps);
	m_ang = 0.f;
	m_rps = 0.1f * 360.f / 1000.f;

	m_pQobj = nullptr;
	DefLightParam();
}

MyScreen::~MyScreen()
{
	if (m_pQobj) gluDeleteQuadric(m_pQobj);
}

void MyScreen::SetLightAmbient(COLORREF col)
{
	GLfloat r, g, b;
	OglScreen::colorrefToRgb(r, g, b, col);
	m_lightAmbient[0] = r;
	m_lightAmbient[1] = g;
	m_lightAmbient[2] = b;
	glLightfv(GL_LIGHT0, GL_AMBIENT, m_lightAmbient);
}

void MyScreen::SetLightParam(void)
{
	// 광원
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); // 0번 광원을 사용 가능하게 함

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
	m_lightAmbient[0] = m_lightAmbient[1] = m_lightAmbient[2] = 0.2f; // RGB 순서
	m_lightAmbient[3] = 1.0f; // alpha
	m_lightDiffuse[0] = m_lightDiffuse[1] = m_lightDiffuse[2] = 0.5f; // RGB 순서
	m_lightDiffuse[3] = 1.0f; // alpha
	m_lightSpecular[0] = m_lightSpecular[1] = m_lightSpecular[2] = 0.9f; // RGB 순서
	m_lightSpecular[3] = 1.0f; // alpha
	m_lightPos[0] = m_lightPos[1] = m_lightPos[2] = 1.0f; // (x, y, z) 순서
	m_lightPos[3] = 0.0f; // 직사광선(태양광) 선택

	// material
	m_mtlEmit[0] = m_mtlEmit[1] = m_mtlEmit[2] = 0.0f; // RGB 순서
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

	// 초기 설정 + 배경색 설정
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0f); // 물체는 카메라에서 가장 멀리(1.0f) 있다고 초기화(clear)
	OglScreen::colorrefToRgb(r, g, b, m_nBackColor);
	glClearColor(r, g, b, 1.0f);

	glPushMatrix();
	glLoadIdentity();
	glRotatef(m_ang, 0.f, 1.f, 0.f);

	// 구 그리기
	OglScreen::colorrefToRgb(r, g, b, m_nSphereColor);
	glColor4f(r, g, b, m_sphereAlpha); // glColor3f() 써도 됨: alpha = 1인 경우
	if (m_pQobj) gluSphere(m_pQobj, 200., 30, 30);

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
