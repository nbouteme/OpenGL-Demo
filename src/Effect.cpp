#include <Effect.hpp>
#include <Shader.hpp>
#include <Assets.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLfloat quad[] =
{
    -1.0f,  1.0f,  0.0f, 1.0f,
     1.0f,  1.0f,  1.0f, 1.0f,
     1.0f, -1.0f,  1.0f, 0.0f,

     1.0f, -1.0f,  1.0f, 0.0f,
    -1.0f, -1.0f,  0.0f, 0.0f,
    -1.0f,  1.0f,  0.0f, 1.0f
};

using namespace std;

shared_ptr<Effect> Effect::BasicEffect()
{
	return shared_ptr<Effect>(new Effect(ShaderRes->getString("basicPE.glsl").c_str()));
}

shared_ptr<Effect> Effect::ReverseColor()
{
	return shared_ptr<Effect>(new Effect(ShaderRes->getString("basicReverse.glsl").c_str()));
}

shared_ptr<Effect> Effect::Blur()
{
	return shared_ptr<Effect>(new Effect(ShaderRes->getString("basicBlur.glsl").c_str()));
}

#include <cassert>
#include <Application.hpp>

Effect::Effect(const char *fs) :
	m_shader(make_shared<Shader>(ShaderRes->getString("quad.glsl").c_str(), fs))
{
	int dim[4];
	glGetIntegerv(GL_VIEWPORT, dim);

	glGenFramebuffers(1, &fbId);
	glBindFramebuffer(GL_FRAMEBUFFER, fbId);

	glGenTextures(1, &texId);
    glBindTexture(GL_TEXTURE_2D, texId);
    glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGB, 
				 dim[2],
				 dim[3],
				 0,
				 GL_RGB,
				 GL_UNSIGNED_BYTE, 
				 nullptr);
    glTexParameteri(GL_TEXTURE_2D,
					GL_TEXTURE_MIN_FILTER,
					GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
					GL_TEXTURE_MAG_FILTER,
					GL_LINEAR);
	glFramebufferTexture2D(GL_FRAMEBUFFER,
						   GL_COLOR_ATTACHMENT0,
						   GL_TEXTURE_2D,
						   texId,
						   0);

	glGenRenderbuffers(1, &rbId);
	glBindRenderbuffer(GL_RENDERBUFFER, rbId);
	glRenderbufferStorage(GL_RENDERBUFFER,
						  GL_DEPTH24_STENCIL8,
						  dim[2],
						  dim[3]);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, 
							  GL_DEPTH_STENCIL_ATTACHMENT,
							  GL_RENDERBUFFER,
							  rbId);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	assert(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE);

	glGenVertexArrays(1, &m_vao);
	glGenBuffers     (1, &m_vbo);

	glBindVertexArray(m_vao);
	glBindBuffer     (GL_ARRAY_BUFFER, m_vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, false, 16, nullptr);
    glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, false, 16, (void *)8);
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
}

void Effect::active()
{
	glBindFramebuffer(GL_FRAMEBUFFER, fbId);
    glBindTexture(GL_TEXTURE_2D, texId);
	glClearColor(0.1f, 0.1f, 0.9f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//	glBindRenderbuffer(GL_RENDERBUFFER, rbId);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Effect::present()
{
	glBindVertexArray(m_vao);
    glBindTexture(GL_TEXTURE_2D, texId);
	glUseProgram(m_shader->getProgramid());

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glBindVertexArray(0);
	glUseProgram(0);
}

Effect::~Effect()
{
    glDeleteTextures     (1, &texId);
	glDeleteFramebuffers (1, &fbId );
	glDeleteRenderbuffers(1, &rbId );
}
