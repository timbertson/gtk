/* GDK - The GIMP Drawing Kit
 *
 * gdkglcontextprivate.h: GL context abstraction
 * 
 * Copyright © 2014  Emmanuele Bassi
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GDK_GL_CONTEXT_PRIVATE_H__
#define __GDK_GL_CONTEXT_PRIVATE_H__

#include "gdkglcontext.h"

G_BEGIN_DECLS

#define GDK_GL_CONTEXT_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), GDK_TYPE_GL_CONTEXT, GdkGLContextClass))
#define GDK_IS_GL_CONTEXT_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), GDK_TYPE_GL_CONTEXT))
#define GDK_GL_CONTEXT_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), GDK_TYPE_GL_CONTEXT, GdkGLContextClass))

typedef struct _GdkGLContextClass       GdkGLContextClass;

struct _GdkGLContext
{
  GObject parent_instance;
};

struct _GdkGLContextClass
{
  GObjectClass parent_class;

  void (* set_window)      (GdkGLContext *context,
                            GdkWindow    *window);
  void (* update_viewport) (GdkGLContext *context,
                            GdkWindow    *window,
                            int           width,
                            int           height);
  void (* flush_buffer)    (GdkGLContext *context);
};

gboolean        gdk_gl_context_get_swap_interval        (GdkGLContext *context);
gboolean        gdk_gl_context_needs_update             (GdkGLContext *context);
void            gdk_gl_context_update_viewport          (GdkGLContext *context,
                                                         GdkWindow    *window,
                                                         int           width,
                                                         int           height);

G_END_DECLS

#endif /* __GDK_GL_CONTEXT_PRIVATE_H__ */