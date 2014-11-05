HEADERS += \
    simpleViewer.h

SOURCES += \
    simpleViewer.cpp \
    main.cpp

INCLUDEPATH +=  /usr/include/qt4/QtCore     \
                 /usr/include/qt4/QtGui      \
                 /usr/include/qt4/QtOpenGL    \
                 /usr/include/qt4             \
                 /usr/include/qt3/          \
                 /usr/include/qt4/QtXml/

LIBS  +=    -L/usr/X11R6/lib64 -lQtOpenGL -lQtGui -lQtCore  -lpthread\
             -lQGLViewer  -lglut  -lGL  -lGLU

