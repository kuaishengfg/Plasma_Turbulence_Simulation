#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

// ���弫�����Ľṹ��
struct PolarPoint {
    float angle; // ����
    float radius; // ����
};

int main() {
    // ��������
    sf::RenderWindow window(sf::VideoMode(800, 800), "Polar Coordinate Plot");

    // ���ü���������ݣ�ʾ�����ݣ�
    std::vector<PolarPoint> polarPoints = {
        {30, 100},
        {60, 150},
        {120, 80},
        {180, 120},
        {240, 90},
        {300, 140}
    };

    // ���ü�����ԭ��
    sf::Vector2f origin(400, 400);

    // ��ѭ��
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        // ���Ƽ������
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

