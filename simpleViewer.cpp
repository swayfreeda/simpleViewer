/****************************************************************************

 Copyright (C) 2002-2014 Gilles Debunne. All rights reserved.

 This file is part of the QGLViewer library version 2.5.3.

 http://www.libqglviewer.com - contact@libqglviewer.com

 This file may be used under the terms of the GNU General Public License 
 versions 2.0 or 3.0 as published by the Free Software Foundation and
 appearing in the LICENSE file included in the packaging of this file.
 In addition, as a special exception, Gilles Debunne gives you certain 
 additional rights, described in the file GPL_EXCEPTION in this package.

 libQGLViewer uses dual licensing. Commercial/proprietary software must
 purchase a libQGLViewer Commercial License.

 This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

*****************************************************************************/

#include "simpleViewer.h"

using namespace std;

// Draws a spiral
void Viewer::draw()
{
  const float nbSteps = 200.0;

  glBegin(GL_QUAD_STRIP);
  for (int i=0; i<nbSteps; ++i)
	{
	  const float ratio = i/nbSteps;
	  const float angle = 21.0*ratio;
	  const float c = cos(angle);
	  const float s = sin(angle);
	  const float r1 = 1.0 - 0.8f*ratio;
	  const float r2 = 0.8f - 0.8f*ratio;
	  const float alt = ratio - 0.5f;
	  const float nor = 0.5f;
	  const float up = sqrt(1.0-nor*nor);
	  glColor3f(1.0-ratio, 0.2f , ratio);
	  glNormal3f(nor*c, up, nor*s);
	  glVertex3f(r1*c, alt, r1*s);
	  glVertex3f(r2*c, alt+0.05f, r2*s);
	}
  glEnd();


  drawWordAxises();

}

void  Viewer::drawWordAxises()
{
    glEnable(GL_LINE_SMOOTH);

    glLineWidth(1.0);

    glBegin(GL_LINES);
    {
        // qglColor(Qt::red);

        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(1.0, 0.0, 0.0);
    }
    glEnd();

    glBegin(GL_LINES);
    {
        //qglColor(Qt::green);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 1.0, 0.0);
    }
    glEnd();


    glBegin(GL_LINES);
    {
        //qglColor(Qt::blue);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 1.0);
    }
    glEnd();

    glLineWidth(1.0);;
    glDisable(GL_LINE_SMOOTH);

    //qglColor(Qt::red);
    glColor3f(1.0, 0.0, 0.0);
    renderText(1.0, 0.0, 0.0, "X", QFont("helvetica", 12, QFont::Bold, TRUE));

    //qglColor(Qt::green);
    glColor3f(0.0, 1.0, 0.0);
    renderText(0.0, 1.0, 0.0, "Y", QFont("helvetica", 12, QFont::Bold, TRUE));

    //qglColor(Qt::blue);
    glColor3f(0.0, 0.0, 1.0);
    renderText(0.0, 0.0, 1.0, "Z", QFont("helvetica", 12, QFont::Bold, TRUE));
}
void Viewer::init()
{
  // Restore previous viewer state.
  //restoreStateFromFile();

  // Opens help window
 // help();
}

QString Viewer::helpString() const
{
  QString text("<h2>S i m p l e V i e w e r</h2>");
  text += "Use the mouse to move the camera around the object. ";
  text += "You can respectively revolve around, zoom and translate with the three mouse buttons. ";
  text += "Left and middle buttons pressed together rotate around the camera view direction axis<br><br>";
  text += "Pressing <b>Alt</b> and one of the function keys (<b>F1</b>..<b>F12</b>) defines a camera keyFrame. ";
  text += "Simply press the function key again to restore it. Several keyFrames define a ";
  text += "camera path. Paths are saved when you quit the application and restored at next start.<br><br>";
  text += "Press <b>F</b> to display the frame rate, <b>A</b> for the world axis, ";
  text += "<b>Alt+Return</b> for full screen mode and <b>Control+S</b> to save a snapshot. ";
  text += "See the <b>Keyboard</b> tab in this window for a complete shortcut list.<br><br>";
  text += "Double clicks automates single click actions: A left button double click aligns the closer axis with the camera (if close enough). ";
  text += "A middle button double click fits the zoom of the camera and the right button re-centers the scene.<br><br>";
  text += "A left button double click while holding right button pressed defines the camera <i>Revolve Around Point</i>. ";
  text += "See the <b>Mouse</b> tab and the documentation web pages for details.<br><br>";
  text += "Press <b>Escape</b> to exit the viewer.";
  return text;
}

void Viewer::mousePressEvent(QMouseEvent *e)
{
    QGLViewer::mousePressEvent(e);
}
void Viewer::mouseReleaseEvent(QMouseEvent *e)
{
    QGLViewer::mouseReleaseEvent(e);
}
void Viewer::mouseMoveEvent(QMouseEvent *e)
{
   QGLViewer::mouseMoveEvent(e);
}
void Viewer::wheelEvent(QWheelEvent *e)
{
   QGLViewer::wheelEvent(e);
}
void Viewer::keyPressEvent(QKeyEvent *e)
{
   QGLViewer::keyPressEvent(e);
}
