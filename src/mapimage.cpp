#include "mapimage.hpp"
#include "src/position_aeronef.hpp"

MapImage::MapImage(QWidget *parent) : QWidget(parent)
{
    /*std::cout << "image" << std::endl;

    this->setGeometry(0, 0, 300, 100);

    QPalette pal = QPalette();

    pal.setColor(QPalette::Window, "#51555b");

    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->show();*/
    Images();
}

void MapImage::Images()
{

    Position_Aeronef Position;

    ImagePosition(m_showImage_Istre, QPoint(640, 360), CAPTURE_ISTRE(this->Altitude)); // bien verifier cette valeur
    [this](double* position) { ImagePosition(m_showImage_Istre, QPoint(position[0], position[1]), CAPTURE_ISTRE(this->Altitude));}(Position.GeoToCartosienne("N43°36'32' 'E3°52'58")); // c'est censé etre au millieux

    [this](double* position) { ImagePosition(m_showImage_Montpellier, QPoint(position[0],position[1]), CAPTURE_MONTPELLIER(this->Altitude)); }(Position.GeoToCartosienne("N43°36'32' 'E3°52'58"));

    [this](double* position) { ImagePosition(m_showImage_Narbonne, QPoint(position[0],position[1]), CAPTURE_NARBONNE(this->Altitude));} (Position.GeoToCartosienne("N43°11'3.397' 'E3°0'11.081")); // En haut à droite
    [this](double* position) { ImagePosition(m_showImage_Sainte_baume, QPoint(position[0], position[1]), CAPTURE_SAINT_BAUME(this->Altitude));} (Position.GeoToCartosienne("N43°27'8.989' 'E5°51'50.414")); // En bas à gauche
    [this](double* position) { ImagePosition(m_showImage_Vitrolles, QPoint(position[0], position[1]), CAPTURE_VITROLLE(this->Altitude));} (Position.GeoToCartosienne("N43°27'30.953' 'E5°14'58.931"));  // En bas à droite

    [this](double* position) {ImagePosition(m_showImage_Ventoux, QPoint(position[0],position[1]), CAPTURE_VENTOUX(this->Altitude));}  (Position.GeoToCartosienne("N44°10'24' 'E5°16'43"));// En haut au centre
    [this](double* position) { ImagePosition(m_showImage_Salon, QPoint(position[0],position[1]), CAPTURE_SALON(this->Altitude));}  (Position.GeoToCartosienne("N43°38'24.716' 'E5°5'49.279")); // En bas au centre
}

void MapImage::ImagePosition(ShowImage *image, const QPoint& position, QString Url)
{
    QLabel *redPoint = new QLabel(this);
    redPoint->setFixedSize(10, 10);
    redPoint->setAutoFillBackground(true);
    redPoint->setStyleSheet("background-color: red; border-radius: 5px;");
    redPoint->move(position);

    QLabel *nameLabel = new QLabel(this);
    nameLabel->setText(Url.right(38));
    nameLabel->setAlignment(Qt::AlignHCenter);
    int nameLabelWidth = nameLabel->fontMetrics().boundingRect(Url.right(10)).width();
    nameLabel->move(position - QPoint(nameLabelWidth / 2, 20)); // Position au-dessus du point

    // ...
}


void MapImage::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Images();
}


