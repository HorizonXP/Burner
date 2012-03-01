QMAKE_LFLAGS += '-Wl,-rpath,\'./app/native/lib\''

SOURCES += src/main.cpp \
           src/widget.cpp\
           src/Burner.cpp

HEADERS += include/Burner.h \
           include/widget.h
INCLUDEPATH += include

package.target = $${TARGET}.bar
package.depends = $$TARGET
package.commands = blackberry-nativepackager \
    -devMode -debugToken ~/debugToken.bar \
    -package $${TARGET}.bar -arg -platform -arg blackberry \
    blackberry-tablet.xml $$TARGET \
    -e res/icon.png res/icon.png \
    -e res/splashscreen.png res/splashscreen.png \
    -e $$[QT_INSTALL_LIBS]/libQtCore.so.4 lib/libQtCore.so.4 \
    -e $$[QT_INSTALL_LIBS]/libQtGui.so.4 lib/libQtGui.so.4 \
    -e $$[QT_INSTALL_LIBS]/libQtOpenGL.so.4 lib/libQtOpenGL.so.4 \
    -e $$[QT_INSTALL_LIBS]/libQtNetwork.so.4 lib/libQtNetwork.so.4 \
    -e $$[QT_INSTALL_PLUGINS]/platforms/libblackberry.so lib/platforms/libblackberry.so

QMAKE_EXTRA_TARGETS += package
