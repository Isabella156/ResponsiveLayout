/*
 * @Author: your name
 * @Date: 2021-11-07 16:06:43
 * @LastEditTime: 2021-11-15 16:19:58
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \responsive\responsive_window.cpp
 */
//
// Created by twak on 14/10/2019.
//

#include "responsive_window.h"
#include "responsive_layout.h"
#include "screenshot.h"
#include "searchresultswidget.h"
#include <iostream>
#include <QApplication>
#include <QScrollArea>




ResponsiveWindow::ResponsiveWindow() {

    setWindowTitle("2811 coursework 2: responsive layouts");
    setMinimumSize(320, 320);
    setMaximumSize(1280, 720);

    createWidgets();
}

void ResponsiveWindow::createWidgets() {   
   QScrollArea *scrollArea = new QScrollArea();
   scrollArea->setWidgetResizable(true);

   ResponsiveLayout * rl = new ResponsiveLayout();
    rl->setSizeConstraint(QLayout::SetMinAndMaxSize);

   SearchResultsWidget *searchResults = new SearchResultsWidget();
   searchResults->setMinimumSize(minimumSize());
   searchResults->setMaximumSize(1280, 720);
   searchResults->initWidget(rl);

   searchResults->setLayout(rl);
   scrollArea->setWidget(searchResults);
    // note that later widgets are drawn on top of earlier widgets

    ResponsiveLayout *mainLayout = new ResponsiveLayout();
    mainLayout->addWidget(scrollArea);
//// first row
//    mainLayout->addWidget(new ResponsiveLabel(kMenu));
//    mainLayout->addWidget(new ResponsiveLabel(kHomeLink));
//    mainLayout->addWidget(new ResponsiveLabel(kSQuery));
//    mainLayout->addWidget(new ResponsiveLabel(kSButton));
////     second row
//    mainLayout->addWidget(new ResponsiveLabel(kAdvert));
//    mainLayout->addWidget(new ResponsiveLabel(kSOptions));
    setLayout(rl);

}


