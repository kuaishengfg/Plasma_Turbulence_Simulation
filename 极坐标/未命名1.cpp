#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

// 定义极坐标点的结构体
struct PolarPoint {
    float angle; // 极角
    float radius; // 极径
};

int main() {
    // 创建窗口
    sf::RenderWindow window(sf::VideoMode(800, 800), "Polar Coordinate Plot");

    // 设置极坐标点数据（示例数据）
    std::vector<PolarPoint> polarPoints = {
        {30, 100},
        {60, 150},
        {120, 80},
        {180, 120},
        {240, 90},
        {300, 140}
    };

    // 设置极坐标原点
    sf::Vector2f origin(400, 400);

    // 主循环
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        // 绘制极坐标点
        for (const auto& point : polarPoints) {
            float x = origin.x + point.radius * std::cos(point.angle * 3.14159265f / 180);
            float y = origin.y - point.radius * std::sin(point.angle * 3.14159265f / 180);

            sf::CircleShape shape(5);
            shape.setFillColor(sf::Color::Red);
            shape.setPosition(x, y);
            window.draw(shape);
        }

        window.display();
    }

    return 0;
}

