#include "searchresultswidget.h"

SearchResultsWidget::SearchResultsWidget(QWidget *parent): QWidget(parent)
{

}

void SearchResultsWidget::initWidget(QLayout *layout){
    // add search results
    for(int i = 0; i < 17; i ++){
            layout->addWidget(new ResponsiveLabel(kSResultImage));
            layout->addWidget(new ResponsiveLabel(kSResultText));
    }
    this->setLayout(layout);
}
