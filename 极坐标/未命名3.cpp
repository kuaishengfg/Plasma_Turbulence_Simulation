
#include <SFML/Graphics.hpp>
#include <cmath>
//定义极坐标点类：创建一个极坐标点类，用于存储极角和极径。
class PolarPoint {
private:
    double angle;  // 极角
    double radius; // 极径

public:
    PolarPoint(double a, double r) : angle(a), radius(r) {}

    double getAngle() const {
        return angle;
    }

    double getRadius() const {
        return radius;
    }
};
//绘制极坐标图：编写绘制极坐标图的函数，包括绘制极坐标轴和标度。
void drawPolarChart(sf::RenderWindow& window, const sf::Vector2f& center, float maxRadius) {
    // 绘制极坐标轴
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

    // 绘制标度
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
//主程序：在主程序中读取极角和极径，然后绘制极坐标图。
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Polar Chart");

    sf::Vector2f center(400, 300); // 中心点坐标
    float maxRadius = 200; // 最大极径

    PolarPoint polarPoint(M_PI / 4, 100); // 极角为 pi/4，极径为 100

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        // 绘制极坐标图
        drawPolarChart(window, center, maxRadius);

        // 将极坐标点转换为笛卡尔坐标并绘制
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

