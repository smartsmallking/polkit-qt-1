prefix=@CMAKE_INSTALL_PREFIX@
exec_prefix=@CMAKE_INSTALL_PREFIX@
libdir=@LIB_INSTALL_DIR@
includedir=@CMAKE_INSTALL_PREFIX@/include

Name: Polkit-qt-1
Description: Convenience library for using PolicyKit with a Qt-styled API, non-GUI functions
Version: @POLKIT_QT_VERSION_STRING@
Requires: QtCore
Libs: -L${libdir} -lpolkit-qt-core-1
Cflags: -I${includedir}