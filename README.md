# Draw-with-render-area---QT-c-
A Modified example for drawARC.

I just modified the xample (QPainter Class) for drawing the items on an area.

Usage:

    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::red);
    outlinePen.setWidth(6);
    
    renderArea = new RenderArea;
    renderArea->setArcStartAngle(90*16);
    renderArea->setArcSpanAngle(-30*16);
    renderArea->setShape(RenderArea::Arc);

    renderArea->setBrush(blueBrush);
    renderArea->setPen(outlinePen);
    ui->mainLayout->addWidget(renderArea, 0, 0, 1, 4);
