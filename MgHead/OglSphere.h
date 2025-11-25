#pragma once
#include "GL/glew.h"

#define DEF_SPH_SLICE	(30)
#define DEF_SPH_STACK	(30)

class OglSphere
{
public:
	OglSphere(void);
	~OglSphere();

	void SetRgba(COLORREF col, GLfloat alpha = 1.0f)
	{
		m_nColor = col;
		m_alpha = alpha;
	}
	void Create(void);
	void Draw(GLdouble radius, GLint slice = DEF_SPH_SLICE, GLint stack = DEF_SPH_STACK) const;

protected:
	GLUquadric* m_pQobj;
	COLORREF m_nColor;
	GLfloat m_alpha;
};

#undef DEF_SPH_SLICE
#undef DEF_SPH_STACK

