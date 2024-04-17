#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

class PolarPoint {
private:
    double angle;  // �Ƕȣ����ȣ�
    double radius; // �뾶

public:
    PolarPoint(double a, double r) : angle(a), radius(r) {}

    double getAngle() const {
        return angle;
    }

    double getRadius() const {
        return radius;
    }
};

void drawPolarPoint(sf::RenderWindow& window, const PolarPoint& polarPoint, const sf::Vector2f& origin) {
    // ��������ת��Ϊ�ѿ�������
    float x = polarPoint.getRadius() * cos(polarPoint.getAngle()) + origin.x;
    float y = polarPoint.getRadius() * sin(polarPoint.getAngle()) + origin.y;

    // ʹ�õѿ���������Ƶ�
    sf::CircleShape point(2);
    point.setFillColor(sf::Color::Red);
    point.setPosition(x, y);
    window.draw(point);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Polar Coordinates Example");

    PolarPoint polarPoint(M_PI / 4, 100); // �Ƕ�Ϊ pi/4���뾶Ϊ 100
    sf::Vector2f origin(400, 300); // ԭ��λ��

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // ���Ƽ������
        drawPolarPoint(window, polarPoint, origin);

        window.display();
    }

    return 0;
}

