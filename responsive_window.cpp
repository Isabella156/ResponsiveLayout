/*
 * @Author: your name
 * @Date: 2021-11-07 16:06:43
 * @LastEditTime: 2021-11-19 11:34:29
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \responsive\responsive_window.cpp
 */
//
// Created by twak on 14/10/2019.
//

#include "responsive_window.h"

#include "screenshot.h"
#include "searchresultswidget.h"
#include "scroll_layout.h"
#include <iostream>
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>




ResponsiveWindow::ResponsiveWindow() {

    setWindowTitle("2811 coursework 2: responsive layouts");
    setMinimumSize(320, 320);
    setMaximumSize(1280, 720);

    createWidgets();
}

void ResponsiveWindow::resizeEvent(QResizeEvent *event){
    int areaX, areaY, areaWidth, areaHeight;
    int scrollX, scrollY, scrollWidth, scrollHeight;
    int spacing = 0.01 * this->geometry().width();
    int column, squareWidth;

    if(this->geometry().width() < 620){
        column = 2;
        areaX = scrollX = 0;
        areaY = 70 + 0.02 * this->geometry().width();
        areaWidth = this->geometry().width();
        areaHeight = this->geometry().height() - 100;
        scrollY = 100;
        scrollWidth = areaWidth - 40;
        scrollHeight = scrollWidth * 4.6;
        squareWidth = this->geometry().width() / column;
        // horizontal layout
        if(areaHeight < squareWidth){
            areaX = scrollX = 80 + spacing * 2;
            areaY = scrollY = 0;
            areaHeight = this->geometry().height();
            areaWidth = this->geometry().width() - areaX;
            scrollWidth = areaWidth - 40;
            scrollHeight = scrollWidth * 4.6;
        }
        // QScrollArea
        scrollArea->setGeometry(areaX, areaY, areaWidth, areaHeight);
        // QWidget
        scroll->setGeometry(scrollX, scrollY, scrollWidth, scrollHeight);
    }
    if(this->geometry().width() > 620){
        scrollArea->setGeometry(0, 150 + 0.03 * this->geometry().width(), this->geometry().width(), this->geometry().height() - 200);
        if(this->geometry().width() < 660){
            scrollHeight = (this->geometry().width() - 40) * 4.6;
        }else if(this->geometry().width() >= 660 && this->geometry().width() < 930){
            scrollHeight = (this->geometry().width() - 40) * 2.1;
        }else{
            scrollHeight = (this->geometry().width() - 40) * 1.3;
        }
        scroll->setGeometry(0, 150, this->geometry().width() - 40, scrollHeight);
    }
    printf("width: %i\n, height: %i\n", this->geometry(). width(), this->geometry().height());
}

void ResponsiveWindow::addScroll(){

}


void ResponsiveWindow::createWidgets() {   
    ResponsiveLayout * rl = new ResponsiveLayout(this);

    scrollArea = new QScrollArea(this);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scroll = new QWidget(scrollArea);
    scrollArea->setWidget(scroll);
//    scrollArea->setWidgetResizable(true);

    ResponsiveLayout* sl = new ResponsiveLayout(scroll);

    for(int i = 0; i < 17; i ++){
        sl->addWidget(new ResponsiveLabel(kSResultImage));
        sl->addWidget(new ResponsiveLabel(kSResultText));
    }
    sl->addWidget(new ResponsiveLabel(kSForward));
    sl->addWidget(new ResponsiveLabel(kSBackward));
    sl->setGeometry(scroll->rect());

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

}


