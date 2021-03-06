/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  Copyright (C) 2004,2005 Johan Dahlin
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef NAUTILUS_PYTHON_H
#define NAUTILUS_PYTHON_H

#include <glib-object.h>
#include <glib/gprintf.h>
#include <Python.h>

#if PY_VERSION_HEX < 0x02050000 && !defined(PY_SSIZE_T_MIN)
typedef int Py_ssize_t;
#define PY_SSIZE_T_MAX INT_MAX
#define PY_SSIZE_T_MIN INT_MIN
#endif

typedef enum {
    NAUTILUS_PYTHON_DEBUG_MISC = 1 << 0,
} NautilusPythonDebug;

extern NautilusPythonDebug nautilus_python_debug;

#define debug(x) { if (nautilus_python_debug & NAUTILUS_PYTHON_DEBUG_MISC) \
                       g_printf( "nautilus-python:" x "\n"); }
#define debug_enter()  { if (nautilus_python_debug & NAUTILUS_PYTHON_DEBUG_MISC) \
                             g_printf("%s: entered\n", __FUNCTION__); }
#define debug_enter_args(x, y) { if (nautilus_python_debug & NAUTILUS_PYTHON_DEBUG_MISC) \
                                     g_printf("%s: entered " x "\n", __FUNCTION__, y); }

PyTypeObject *_PyGtkWidget_Type;
#define PyGtkWidget_Type (*_PyGtkWidget_Type)

PyTypeObject *_PyNautilusColumn_Type;
#define PyNautilusColumn_Type (*_PyNautilusColumn_Type)

PyTypeObject *_PyNautilusColumnProvider_Type;
#define PyNautilusColumnProvider_Type (*_PyNautilusColumnProvider_Type)

PyTypeObject *_PyNautilusInfoProvider_Type;
#define PyNautilusInfoProvider_Type (*_PyNautilusInfoProvider_Type)

PyTypeObject *_PyNautilusLocationWidgetProvider_Type;
#define PyNautilusLocationWidgetProvider_Type (*_PyNautilusLocationWidgetProvider_Type)

PyTypeObject *_PyNautilusMenu_Type;
#define PyNautilusMenu_Type (*_PyNautilusMenu_Type)

PyTypeObject *_PyNautilusMenuItem_Type;
#define PyNautilusMenuItem_Type (*_PyNautilusMenuItem_Type)

PyTypeObject *_PyNautilusMenuProvider_Type;
#define PyNautilusMenuProvider_Type (*_PyNautilusMenuProvider_Type)

PyTypeObject *_PyNautilusPropertyPage_Type;
#define PyNautilusPropertyPage_Type (*_PyNautilusPropertyPage_Type)

PyTypeObject *_PyNautilusPropertyPageProvider_Type;
#define PyNautilusPropertyPageProvider_Type (*_PyNautilusPropertyPageProvider_Type)

PyTypeObject *_PyNautilusOperationHandle_Type;
#define PyNautilusOperationHandle_Type (*_PyNautilusOperationHandle_Type)

#endif /* NAUTILUS_PYTHON_H */
