#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(QPYTHONDOCX_LIB)
#  define QPYTHONDOCX_EXPORT Q_DECL_EXPORT
# else
#  define QPYTHONDOCX_EXPORT Q_DECL_IMPORT
# endif
#else
# define QPYTHONDOCX_EXPORT
#endif
