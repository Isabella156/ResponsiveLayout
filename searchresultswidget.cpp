#include "searchresultswidget.h"

SearchResultsWidget::SearchResultsWidget(QWidget *parent): QWidget(parent)
{
    image1 = new ResponsiveLabel(kSResultImage);
    image2 = new ResponsiveLabel(kSResultImage);
    image3 = new ResponsiveLabel(kSResultImage);
    image4 = new ResponsiveLabel(kSResultImage);
    image5 = new ResponsiveLabel(kSResultImage);
    image6 = new ResponsiveLabel(kSResultImage);
    image7 = new ResponsiveLabel(kSResultImage);
    text1 = new ResponsiveLabel(kSResultText);
    text2 = new ResponsiveLabel(kSResultText);
    text3 = new ResponsiveLabel(kSResultText);
    text4 = new ResponsiveLabel(kSResultText);
    text5 = new ResponsiveLabel(kSResultText);
    text6 = new ResponsiveLabel(kSResultText);
    text7 = new ResponsiveLabel(kSResultText);
}

//void SearchResultsWidget::initWidget(QLayout *layout){
//    // add search results
//    for(int i = 0; i < 17; i ++){
//            layout->addWidget(new ResponsiveLabel(kSResultImage));
//            layout->addWidget(new ResponsiveLabel(kSResultText));
//    }
//    this->setLayout(layout);
//}
