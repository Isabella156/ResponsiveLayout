//
// Created by twak on 14/10/2019.
//

#include "responsive_window.h"
#include "screenshot.h"
#include <iostream>
#include <QApplication>


ResponsiveWindow::ResponsiveWindow() {

    setWindowTitle("2811 coursework 2: responsive layouts");
    setMinimumSize(320, 320);
    setMaximumSize(1280, 720);
    createWidgets();
}

// set scroll area geomeotry for horizontal layout
void ResponsiveWindow::horizontalScroll(double &areaX, double &areaY, double &areaWidth, double &areaHeight, \
double &scrollX, double &scrollY, double &scrollWidth, double &scrollHeight, double spacing, \
double width, double height, int column){
    areaX = scrollX = 180 + 2 * spacing;
    areaY = 0;
    areaWidth = width - areaX;
    areaHeight = height;
    scrollY = areaY;
    scrollWidth = areaWidth - 40;
    scrollHeight = (scrollWidth / column) * (16 / column + 1) + 0.1 * scrollWidth;
}

// set scroll area geometry for the first vertical layout 
void ResponsiveWindow::verticalOneScroll(double &areaX, double &areaY, double &areaWidth, \
double &areaHeight, double &scrollX, double &scrollY, double &scrollWidth, \
double &scrollHeight, double width, double height){
    areaX = scrollX = 0;
    areaY = 145 + 0.02 * width;
    areaWidth = width;
    areaHeight = height - areaY;
    scrollY = areaY;
    scrollWidth = areaWidth - 40;
    scrollHeight = scrollWidth * 4.6;
}

// set scroll area geometry for the second vertical layout
void ResponsiveWindow::verticalTwoScroll(double &areaX, double &areaY, double &areaWidth, \
double &areaHeight, double &scrollX, double &scrollY, double &scrollWidth, \
double &scrollHeight, double width, double height){
    areaX = scrollX = 0;
    areaY = 210 + 0.03 * width;
    areaWidth = width;
    areaHeight = height - areaY;
    scrollY = areaY;
    scrollWidth = areaWidth - 40;
    scrollHeight = scrollWidth * 4.6;
}

// set scroll area geometry for the thrid and fourth layout
void ResponsiveWindow::verticalThreeScroll(double &areaX, double &areaY, double &areaWidth, \
double &areaHeight, double &scrollX, double &scrollY, double &scrollWidth, \
double width, double height){
    areaX = scrollX = 0;
    areaY = 270 + 0.04 * width;
    areaWidth = width;
    areaHeight = height - areaY;
    scrollY = areaY;
    scrollWidth = areaWidth - 40;
}

// change the geometry for scroll area and scroll when resizing the window
void ResponsiveWindow::resizeEvent(QResizeEvent *event){
    int width = this->geometry().width(), height = this->geometry().height(), column;
    double areaX, areaY, areaWidth, areaHeight,scrollX, scrollY, scrollWidth, scrollHeight;
    double spacing = 0.01 * width;
    double squareWidth;

    if(width < 428)
        verticalOneScroll(areaX, areaY, areaWidth, areaHeight, scrollX, \
        scrollY, scrollWidth, scrollHeight, width, height);
    else if(width >= 428 && width <= 620){
        column = 2;
        squareWidth = width / column;
        if(height - 210 < squareWidth)
            horizontalScroll(areaX, areaY, areaWidth, areaHeight, \
            scrollX, scrollY, scrollWidth, scrollHeight, spacing ,width, height, column);
        else
            verticalTwoScroll(areaX, areaY, areaWidth, areaHeight, scrollX, \
            scrollY, scrollWidth, scrollHeight, width, height);
    }else{
        if(width < 890)
            column = 3;
        else
            column = 4;
        squareWidth = width / column;
        if(height - 270 < squareWidth){
            areaWidth = width - 180 - 2 * spacing;
            if(areaWidth < 660)
                column = 2;
            else if(areaWidth >= 660 && areaWidth < 930)
                column = 3;
            else
                column = 4;
            horizontalScroll(areaX, areaY, areaWidth, areaHeight, \
            scrollX, scrollY, scrollWidth, scrollHeight, spacing ,width, height, column);
        }else{
            verticalThreeScroll(areaX, areaY, areaWidth, areaHeight, scrollX, \
            scrollY, scrollWidth, width, height);
            if(width < 660)
                scrollHeight = scrollWidth * 4.55;
            else if(width >= 660 && width < 930)
                scrollHeight = scrollWidth * 2.05;
            else
                scrollHeight = scrollWidth * 1.3;
        }
    }
    // QWidget
    scroll->setGeometry(scrollX, scrollY, scrollWidth, scrollHeight);
    // QScrollArea
    scrollArea->setGeometry(areaX, areaY, areaWidth, areaHeight);
    
}


void ResponsiveWindow::createWidgets() {
    // layout for the window   
    ResponsiveLayout * rl = new ResponsiveLayout(this);

    // scroll area
    scrollArea = new QScrollArea(this);
    scrollArea->setFrameShape(QFrame::NoFrame);
//    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll = new QWidget(scrollArea);
    scrollArea->setWidget(scroll);

    // layout for scroll area
    ResponsiveLayout* sl = new ResponsiveLayout(scroll);
    // add widget for scroll area
    for(int i = 0; i < 17; i ++){
        sl->addWidget(new ResponsiveLabel(kSResultImage));
        sl->addWidget(new ResponsiveLabel(kSResultText));
    }
    sl->addWidget(new ResponsiveLabel(kSForward));
    sl->addWidget(new ResponsiveLabel(kSBackward));
    sl->setGeometry(scroll->rect());

    // add widget for window
    rl->addWidget(new ResponsiveLabel(kHomeLink));
    rl->addWidget(new ResponsiveLabel(kShoppingBasket));
    rl->addWidget(new ResponsiveLabel(kSignIn));
    rl->addWidget(new ResponsiveLabel(kMenu));
    rl->addWidget(new ResponsiveLabel(kNavTabs));
    rl->addWidget(new ResponsiveLabel(kAdvert));
    rl->addWidget(new ResponsiveLabel(kSButton));
    rl->addWidget(new ResponsiveLabel(kSQuery));
    rl->addWidget(new ResponsiveLabel(kSOptions));
    rl->addWidget(new ResponsiveLabel(kSOrders));
    rl->addWidget(new ResponsiveLabel(kSLocation));
}


