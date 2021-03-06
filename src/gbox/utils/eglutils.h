#ifndef GBOX_UTILS_EGLUTILS_H_
#define GBOX_UTILS_EGLUTILS_H_

#include <string.h>
#include <EGL/egl.h>

#include "../../log/Log.h"

namespace gbox {

	struct EGLRenderContext {
		EGLint eglMajorVersion;
		EGLint eglMinorVersion;
		EGLDisplay eglDisplay;
		EGLConfig eglConfig;
		EGLSurface eglSurface;
		EGLContext eglContext;
	};

	namespace eglutils {

		const char* eglErrorString(EGLint error) {
			switch (error) {
			case EGL_SUCCESS:
				return "EGL_SUCCESS";
			case EGL_NOT_INITIALIZED:
				return "EGL_NOT_INITIALIZED";
			case EGL_BAD_ACCESS:
				return "EGL_BAD_ACCESS";
			case EGL_BAD_ALLOC:
				return "EGL_BAD_ALLOC";
			case EGL_BAD_ATTRIBUTE:
				return "EGL_BAD_ATTRIBUTE";
			case EGL_BAD_CONFIG:
				return "EGL_BAD_CONFIG";
			case EGL_BAD_CONTEXT:
				return "EGL_BAD_CONTEXT";
			case EGL_BAD_CURRENT_SURFACE:
				return "EGL_BAD_CURRENT_SURFACE";
			case EGL_BAD_DISPLAY:
				return "EGL_BAD_DISPLAY";
			case EGL_BAD_MATCH:
				return "EGL_BAD_MATCH";
			case EGL_BAD_NATIVE_PIXMAP:
				return "EGL_BAD_NATIVE_PIXMAP";
			case EGL_BAD_NATIVE_WINDOW:
				return "EGL_BAD_NATIVE_WINDOW";
			case EGL_BAD_PARAMETER:
				return "EGL_BAD_PARAMETER";
			case EGL_BAD_SURFACE:
				return "EGL_BAD_SURFACE";
			case EGL_CONTEXT_LOST:
				return "EGL_CONTEXT_LOST";
			default:
				return "UNKNOWN_ERROR";
			}
		}

		const char* eglAttributeString(EGLint attribute) {
			switch (attribute) {
			case EGL_BUFFER_SIZE:
				return "EGL_BUFFER_SIZE";
			case EGL_ALPHA_SIZE:
				return "EGL_ALPHA_SIZE";
			case EGL_BLUE_SIZE:
				return "EGL_BLUE_SIZE";
			case EGL_GREEN_SIZE:
				return "EGL_GREEN_SIZE";
			case EGL_RED_SIZE:
				return "EGL_RED_SIZE";
			case EGL_DEPTH_SIZE:
				return "EGL_DEPTH_SIZE";
			case EGL_STENCIL_SIZE:
				return "EGL_STENCIL_SIZE";
			case EGL_CONFIG_CAVEAT:
				return "EGL_CONFIG_CAVEAT";
			case EGL_CONFIG_ID:
				return "EGL_CONFIG_ID";
			case EGL_LEVEL:
				return "EGL_LEVEL";
			case EGL_MAX_PBUFFER_HEIGHT:
				return "EGL_MAX_PBUFFER_HEIGHT";
			case EGL_MAX_PBUFFER_PIXELS:
				return "EGL_MAX_PBUFFER_PIXELS";
			case EGL_MAX_PBUFFER_WIDTH:
				return "EGL_MAX_PBUFFER_WIDTH";
			case EGL_NATIVE_RENDERABLE:
				return "EGL_NATIVE_RENDERABLE";
			case EGL_NATIVE_VISUAL_ID:
				return "EGL_NATIVE_VISUAL_ID";
			case EGL_NATIVE_VISUAL_TYPE:
				return "EGL_NATIVE_VISUAL_TYPE";
			case EGL_SAMPLES:
				return "EGL_SAMPLES";
			case EGL_SAMPLE_BUFFERS:
				return "EGL_SAMPLE_BUFFERS";
			case EGL_SURFACE_TYPE:
				return "EGL_SURFACE_TYPE";
			case EGL_TRANSPARENT_TYPE:
				return "EGL_TRANSPARENT_TYPE";
			case EGL_TRANSPARENT_BLUE_VALUE:
				return "EGL_TRANSPARENT_BLUE_VALUE";
			case EGL_TRANSPARENT_GREEN_VALUE:
				return "EGL_TRANSPARENT_GREEN_VALUE";
			case EGL_TRANSPARENT_RED_VALUE:
				return "EGL_TRANSPARENT_RED_VALUE";
			case EGL_NONE:
				return "EGL_NONE";
			case EGL_BIND_TO_TEXTURE_RGB:
				return "EGL_BIND_TO_TEXTURE_RGB";
			case EGL_BIND_TO_TEXTURE_RGBA:
				return "EGL_BIND_TO_TEXTURE_RGBA";
			case EGL_MIN_SWAP_INTERVAL:
				return "EGL_MIN_SWAP_INTERVAL";
			case EGL_MAX_SWAP_INTERVAL:
				return "EGL_MAX_SWAP_INTERVAL";
			case EGL_LUMINANCE_SIZE:
				return "EGL_LUMINANCE_SIZE";
			case EGL_ALPHA_MASK_SIZE:
				return "EGL_ALPHA_MASK_SIZE";
			case EGL_COLOR_BUFFER_TYPE:
				return "EGL_COLOR_BUFFER_TYPE";
			case EGL_RENDERABLE_TYPE:
				return "EGL_RENDERABLE_TYPE";
			case EGL_MATCH_NATIVE_PIXMAP:
				return "EGL_MATCH_NATIVE_PIXMAP";
			case EGL_CONFORMANT:
				return "EGL_CONFORMANT";
			default:
				return "UNKNOWN_ATTRIBUTE";
			}
		}

		bool eglChechError() {
			EGLint error = eglGetError();
			if (error != EGL_SUCCESS) {
				LOGI("Last EGL error: %s", eglErrorString(error));
				return true;
			}
			return false;
		}

		void info(EGLRenderContext& rc) {

			LOGI("==== Common info ====");
			LOGI("EGL Version : %d.%d", rc.eglMajorVersion, rc.eglMinorVersion);
			LOGI("EGL Vendor \"%s\"", eglQueryString(rc.eglDisplay, EGL_VENDOR));
			LOGI("EGL Client API \"%s\"", eglQueryString(rc.eglDisplay, EGL_CLIENT_APIS));

			LOGI("==== EGL Extentions ====");
			LOGI("EGL Extensions \"%s\"", eglQueryString(rc.eglDisplay, EGL_EXTENSIONS));

			EGLint attrs[] = {
			EGL_BUFFER_SIZE,
			EGL_RED_SIZE,
			EGL_GREEN_SIZE,
			EGL_BLUE_SIZE,
			EGL_ALPHA_SIZE,
			EGL_DEPTH_SIZE,
			EGL_STENCIL_SIZE,
			EGL_CONFIG_CAVEAT,
			EGL_CONFIG_ID,
			EGL_LEVEL,
			EGL_MAX_PBUFFER_HEIGHT,
			EGL_MAX_PBUFFER_PIXELS,
			EGL_MAX_PBUFFER_WIDTH,
			EGL_NATIVE_RENDERABLE,
			EGL_NATIVE_VISUAL_ID,
			EGL_NATIVE_VISUAL_TYPE,
			EGL_SAMPLES,
			EGL_SAMPLE_BUFFERS,
			EGL_SURFACE_TYPE,
			EGL_TRANSPARENT_TYPE,
			EGL_TRANSPARENT_BLUE_VALUE,
			EGL_TRANSPARENT_GREEN_VALUE,
			EGL_TRANSPARENT_RED_VALUE,
			EGL_BIND_TO_TEXTURE_RGB,
			EGL_BIND_TO_TEXTURE_RGBA,
			EGL_MIN_SWAP_INTERVAL,
			EGL_MAX_SWAP_INTERVAL,
			EGL_LUMINANCE_SIZE,
			EGL_ALPHA_MASK_SIZE,
			EGL_COLOR_BUFFER_TYPE,
			EGL_RENDERABLE_TYPE,
			EGL_CONFORMANT,
			EGL_NONE };

			LOGI("==== EGL config info ====");

			EGLint* key = attrs;
			EGLint value;
			while (*key != EGL_NONE) {
				if (!eglGetConfigAttrib(rc.eglDisplay, rc.eglConfig, *key, &value)) {
					eglChechError();
					LOGE("Can't get attribute \"%s\"", eglAttributeString(*key));
					return;
				}
				LOGI("%s : %d", eglAttributeString(*key), value);
				key++;
			}
		}

		bool eglExtension(EGLRenderContext& rc, const char* ext) {
			const char* extStr = eglQueryString(rc.eglDisplay, EGL_EXTENSIONS);
			if (extStr == nullptr) {
				eglChechError();
				LOGE("Can't get extension list");
				return false;
			}
			return strstr(extStr, ext);
		}

	} // namespace eglutils

} // namespace gbox

#endif /* GBOX_UTILS_EGLUTILS_H_ */
