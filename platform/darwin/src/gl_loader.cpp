#include <mbgl/gl/gl.hpp>

#include "TargetConditionals.h"
#if TARGET_OS_IPHONE
    #include <OpenGLES/ES2/gl.h>
    #include <OpenGLES/ES2/glext.h>
#elif TARGET_IPHONE_SIMULATOR
    #include <OpenGLES/ES2/gl.h>
    #include <OpenGLES/ES2/glext.h>
#elif TARGET_OS_MAC
    #if MBGL_USE_GLES2
        #define GL_GLEXT_PROTOTYPES
        #include <GLES2/gl2.h>
        #include <GLES2/gl2ext.h>
    #else
        #include <OpenGL/OpenGL.h>
        #include <OpenGL/gl.h>
        #include <OpenGL/glext.h>
    #endif
#else
    #error Unsupported Apple platform
#endif

#if !defined(MBGL_USE_GLES2)
#define glClearDepthf glClearDepth
#define glDepthRangef glDepthRange
#endif

namespace mbgl {
namespace gl {

void glLoader() {
    GLFunctionPointers fps = {
        glActiveTexture,
        glAttachShader,
        glBindAttribLocation,
        glBindBuffer,
        glBindFramebuffer,
        glBindRenderbuffer,
        glBindTexture,
        glBlendColor,
        glBlendEquation,
        glBlendEquationSeparate,
        glBlendFunc,
        glBlendFuncSeparate,
        glBufferData,
        glBufferSubData,
        glCheckFramebufferStatus,
        glClear,
        glClearColor,
        [](auto... args) { glClearDepthf(args...); },
        glClearStencil,
        glColorMask,
        glCompileShader,
        glCompressedTexImage2D,
        glCompressedTexSubImage2D,
        glCopyTexImage2D,
        glCopyTexSubImage2D,
        glCreateProgram,
        glCreateShader,
        glCullFace,
        glDeleteBuffers,
        glDeleteFramebuffers,
        glDeleteProgram,
        glDeleteRenderbuffers,
        glDeleteShader,
        glDeleteTextures,
        glDepthFunc,
        glDepthMask,
        [](auto... args) { glDepthRangef(args...); },
        glDetachShader,
        glDisable,
        glDisableVertexAttribArray,
        glDrawArrays,
        glDrawElements,
        glEnable,
        glEnableVertexAttribArray,
        glFinish,
        glFlush,
        glFramebufferRenderbuffer,
        glFramebufferTexture2D,
        glFrontFace,
        glGenBuffers,
        glGenerateMipmap,
        glGenFramebuffers,
        glGenRenderbuffers,
        glGenTextures,
        glGetActiveAttrib,
        glGetActiveUniform,
        glGetAttachedShaders,
        glGetAttribLocation,
        glGetBooleanv,
        glGetBufferParameteriv,
        glGetError,
        glGetFloatv,
        glGetFramebufferAttachmentParameteriv,
        glGetIntegerv,
        glGetProgramInfoLog,
        glGetProgramiv,
        glGetRenderbufferParameteriv,
        glGetShaderInfoLog,
        glGetShaderiv,
        glGetShaderSource,
        glGetString,
        glGetTexParameterfv,
        glGetTexParameteriv,
        glGetUniformfv,
        glGetUniformiv,
        glGetUniformLocation,
        glGetVertexAttribfv,
        glGetVertexAttribiv,
        glGetVertexAttribPointerv,
        glHint,
        glIsBuffer,
        glIsEnabled,
        glIsFramebuffer,
        glIsProgram,
        glIsRenderbuffer,
        glIsShader,
        glIsTexture,
        glLineWidth,
        glLinkProgram,
        glPixelStorei,
        glPolygonOffset,
        glReadPixels,
        glRenderbufferStorage,
        glSampleCoverage,
        glScissor,
        [](auto... args) { glShaderSource(args...); },
        glStencilFunc,
        glStencilFuncSeparate,
        glStencilMask,
        glStencilMaskSeparate,
        glStencilOp,
        glStencilOpSeparate,
        glTexImage2D,
        glTexParameterf,
        glTexParameterfv,
        glTexParameteri,
        glTexParameteriv,
        glTexSubImage2D,
        glUniform1f,
        glUniform1fv,
        glUniform1i,
        glUniform1iv,
        glUniform2f,
        glUniform2fv,
        glUniform2i,
        glUniform2iv,
        glUniform3f,
        glUniform3fv,
        glUniform3i,
        glUniform3iv,
        glUniform4f,
        glUniform4fv,
        glUniform4i,
        glUniform4iv,
        glUniformMatrix2fv,
        glUniformMatrix3fv,
        glUniformMatrix4fv,
        glUseProgram,
        glValidateProgram,
        glVertexAttrib1f,
        glVertexAttrib1fv,
        glVertexAttrib2f,
        glVertexAttrib2fv,
        glVertexAttrib3f,
        glVertexAttrib3fv,
        glVertexAttrib4f,
        glVertexAttrib4fv,
        glVertexAttribPointer,
        glViewport,
    };

    setGLFunctionPointers(fps);
}

}  // gl
}  // mbgl