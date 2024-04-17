
#include <SFML/Graphics.hpp>
#include <cmath>
//���弫������ࣺ����һ����������࣬���ڴ洢���Ǻͼ�����
class PolarPoint {
private:
    double angle;  // ����
    double radius; // ����

public:
    PolarPoint(double a, double r) : angle(a), radius(r) {}

    double getAngle() const {
        return angle;
    }

    double getRadius() const {
        return radius;
    }
};
//���Ƽ�����ͼ����д���Ƽ�����ͼ�ĺ������������Ƽ�������ͱ�ȡ�
void drawPolarChart(sf::RenderWindow& window, const sf::Vector2f& center, float maxRadius) {
    // ���Ƽ�������
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(center.x - maxRadius, center.y);
    xAxis[1].position = sf::Vector2f(center.x + maxRadius, center.y);
    xAxis[0].color = sf::Color::Black;
    xAxis[1].color = sf::Color::Black;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(center.x, center.y - maxRadius);
    yAxis[1].position = sf::Vector2f(center.x, center.y + maxRadius);
    yAxis[0].color = sf::Color::Black;
    yAxis[1].color = sf::Color::Black;

    // ���Ʊ��
    for (int i = 10; i <= maxRadius; i += 10) {
        sf::CircleShape circle(i);
        circle.setFillColor(sf::Color::Transparent);
        circle.setOutlineColor(sf::Color::Black);
        circle.setOutlineThickness(1);
        circle.setPosition(center.x - i, center.y - i);
        window.draw(circle);
    }

    window.draw(xAxis);
    window.draw(yAxis);
}
//���������������ж�ȡ���Ǻͼ�����Ȼ����Ƽ�����ͼ��
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Polar Chart");

    sf::Vector2f center(400, 300); // ���ĵ�����
    float maxRadius = 200; // ��󼫾�

    PolarPoint polarPoint(M_PI / 4, 100); // ����Ϊ pi/4������Ϊ 100

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        // ���Ƽ�����ͼ
        drawPolarChart(window, center, maxRadius);

        // ���������ת��Ϊ�ѿ������겢����
        float x = polarPoint.getRadius() * cos(polarPoint.getAngle()) + center.x;
        float y = polarPoint.getRadius() * sin(polarPoint.getAngle()) + center.y;

        sf::CircleShape point(5);
        point.setFillColor(sf::Color::Red);
        point.setPosition(x, y);
        window.draw(point);

        window.display();
    }

    return 0;
}

