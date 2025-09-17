// MyGlut.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
// GLUT 라이브러리 포함: OpenGL Utility Toolkit
#include <GL/glut.h>

using namespace std;

// 전역 변수
GLfloat red = 1.0f; // 0.0f(없음)~1.0f(빨강)까지 변화
GLfloat green = 1.0f;
GLfloat blue = 1.0f;

GLfloat fps = 120.0f; // frame per second(초당 렌더링할 프레임 수) -> 초당 glFlush() 호출수
GLfloat deltaTimeMsec = 1000.0f/fps; // 프레임 사이의 시간 간격(delta time): 단위 msec(윈도우가 쓰는 시간의 기본 단위)

// OpenGL 프로그래밍: OpenGL 좌표계(오른손: 수학) = Unity 좌표계(왼손: CG)
void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT); // color buffer를 초기화(검정색)
	glColor3f(red, green, blue); // 색깔을 RGB로 설정

	// 객체(모델) 정의
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.8f, -0.5f, 0.0f); // 1번 꼭지점(vertex)
	glVertex3f(0.8f, -0.5f, 0.0f); // 2번 꼭지점(vertex)
	glVertex3f(0.0f, 0.8f, 0.0f); // 3번 꼭지점(vertex)
	glEnd();

	glFlush(); // 픽셀 그리기 요청: 모든 그리기 종료를 기다리지 않음
	//glFinish(); // 펙셀 그리기 완성: 모든 그리기 종료까지 기다림; glFinish()가 호출되면 모든 그림(렌더링)이 완성됨
}

void updateScene()
{
	// 해결책: 게임처럼 프레임 구조로 rendering
	//cout << "update ";
	//renderScene();
	// 시간 측정: clock() 등 여러 가지 방법
	int timeNow = glutGet(GLUT_ELAPSED_TIME); // GLUT 기준으로 경과한 시간을 msec 단위로 얻기(get)
}

void keyInput(unsigned char key, int x, int y) // x, y는 키가 눌러질 때의 마우스 위치
{
	cout << "key = " << key << endl;
	if (key == 'r')
	{
		red = 1.0f;
		green = 0.0f;
		blue = 0.0f;
	}
	else if (key == 'g')
	{
		red = 0.0f;
		green = 1.0f;
		blue = 0.0f;
	}
	else if (key == 'b')
	{
		red = 0.0f;
		green = 0.0f;
		blue = 1.0f;
	}
	// 특별한 호출을 하지 않아도 씬이 갱신됨
}

int main(int argc, char** argv)
{
	// GLUT 초기화
	glutInit(&argc, argv);
	// Window 위치 설정: GLUT 좌표계 = MFC 좌표계
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(640, 320);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); // 색깔은 RGBA로 설정; 버퍼는 single buffer 선택
	glutCreateWindow("My GLUT"); // 캡션 My GLUT으로 윈도우 생성

	glutDisplayFunc(renderScene); // rendering에 사용할 함수 포인터 전달
	glutIdleFunc(updateScene);	// timer 메시지가 발생할 때 호출할 함수 등록 
	glutKeyboardFunc(keyInput);	// 키보드 입력 처리기(message handler, callback)

	glutMainLoop();
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
