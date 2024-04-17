#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

class PolarPoint {
private:
    double angle;  // 角度（弧度）
    double radius; // 半径

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
    // 将极坐标转换为笛卡尔坐标
    float x = polarPoint.getRadius() * cos(polarPoint.getAngle()) + origin.x;
    float y = polarPoint.getRadius() * sin(polarPoint.getAngle()) + origin.y;

    // 使用笛卡尔坐标绘制点
    sf::CircleShape point(2);
    point.setFillColor(sf::Color::Red);
    point.setPosition(x, y);
    window.draw(point);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Polar Coordinates Example");

    PolarPoint polarPoint(M_PI / 4, 100); // 角度为 pi/4，半径为 100
    sf::Vector2f origin(400, 300); // 原点位置

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // 绘制极坐标点
        drawPolarPoint(window, polarPoint, origin);

        window.display();
    }

    return 0;
}

