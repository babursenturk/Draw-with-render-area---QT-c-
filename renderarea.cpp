/****************************************************************************
 **
 ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 ** Contact: http://www.qt-project.org/legal
 **
 ** This file is part of the examples of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:BSD$
 ** You may use this file under the terms of the BSD license as follows:
 **
 ** "Redistribution and use in source and binary forms, with or without
 ** modification, are permitted provided that the following conditions are
 ** met:
 **   * Redistributions of source code must retain the above copyright
 **     notice, this list of conditions and the following disclaimer.
 **   * Redistributions in binary form must reproduce the above copyright
 **     notice, this list of conditions and the following disclaimer in
 **     the documentation and/or other materials provided with the
 **     distribution.
 **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
 **     of its contributors may be used to endorse or promote products derived
 **     from this software without specific prior written permission.
 **
 **
 ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 **
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

 #include <QtGui>

 #include "renderarea.h"

 RenderArea::RenderArea(QWidget *parent)
     : QWidget(parent)
 {
     shape = Polygon;
     antialiased = false;
     transformed = false;
     //pixmap.load(":/images/qt-logo.png");

     setBackgroundRole(QPalette::Base);
     //setAutoFillBackground(true);
 }

 QSize RenderArea::minimumSizeHint() const
 {
     return QSize(100, 100);
 }

 QSize RenderArea::sizeHint() const
 {
     return QSize(400, 200);
 }

 void RenderArea::setArcStartAngle(int startAngle)
 {
     this->strAngle = startAngle;
     update();
 }

 void RenderArea::setArcSpanAngle(int spanAngle)
 {
     this->spnAngle = spanAngle;
     update();
 }

 void RenderArea::setShape(Shape shape)
 {
     this->shape = shape;
     update();
 }

 void RenderArea::setPen(const QPen &pen)
 {
     this->pen = pen;
     update();
 }

 void RenderArea::setBrush(const QBrush &brush)
 {
     this->brush = brush;
     update();
 }

 void RenderArea::setAntialiased(bool antialiased)
 {
     this->antialiased = antialiased;
     update();
 }

 void RenderArea::setTransformed(bool transformed)
 {
     this->transformed = transformed;
     update();
 }


 void RenderArea::paintEvent(QPaintEvent * /* event */)
 {
     /*static const QPoint points[4] = {
         QPoint(10, 80),
         QPoint(20, 10),
         QPoint(80, 30),
         QPoint(90, 70)
     };*/

     QRect rect(20, 20, 250, 250);

   /*  QPainterPath path;
     path.moveTo(20, 80);
     path.lineTo(20, 30);
     path.cubicTo(80, 0, 50, 50, 80, 80);
*/


     QPainter painter(this);
     painter.setPen(pen);
     painter.setBrush(brush);

     painter.setRenderHint(QPainter::Antialiasing, true);

     switch (shape) {
     case Line:
         painter.drawLine(rect.bottomLeft(), rect.topRight());
         break;
     case Points:
         //painter.drawPoints(points, 4);
         break;
     case Polyline:
         //painter.drawPolyline(points, 4);
         break;
     case Polygon:
         //painter.drawPolygon(points, 4);
         break;
     case Rect:
         painter.drawRect(rect);
         break;
     case RoundedRect:
         painter.drawRoundedRect(rect, 25, 25, Qt::RelativeSize);
         break;
     case Ellipse:
         painter.drawEllipse(rect);
         break;
     case Arc:
         painter.drawArc(rect, strAngle, spnAngle);
         break;
     case Chord:
         painter.drawChord(rect, strAngle, spnAngle);
         break;
     case Pie:
         painter.drawPie(rect, strAngle, spnAngle);
         break;
     case Path:
         //painter.drawPath(path);
         break;
     case Text:
         painter.drawText(rect, Qt::AlignCenter, tr("Qt by\nNokia"));
         break;
     //case Pixmap:
       //  painter.drawPixmap(10, 10, pixmap);
     }
         //painter.restore();


     painter.setRenderHint(QPainter::Antialiasing, true);
     painter.setPen(palette().dark().color());
     painter.setBrush(Qt::NoBrush);
 }
