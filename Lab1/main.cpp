#include <SFML/Graphics.hpp>

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    // ��������� ����
    sf::RenderWindow window(sf::VideoMode(800, 600), L"���������� ��'����");

    // ��������� ��������� ��������
    std::vector<sf::RectangleShape> rectangles;
    std::vector<sf::CircleShape> circles;

    // ��������� ������������
    for (int i = 0; i < 10; ++i)
    {
        sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
        rectangle.setPosition(i * 60.f, 100.f);
        rectangle.setFillColor(sf::Color::Red);
        rectangles.push_back(rectangle);
    }

    // ��������� ����
    for (int i = 0; i < 10; ++i)
    {
        sf::CircleShape circle(25.f);
        circle.setPosition(i * 60.f, 300.f);
        circle.setFillColor(sf::Color::Blue);
        circles.push_back(circle);
    }

    // �������� ���� ��������
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // �������� ����
        window.clear();

        // ³���������� ������������
        for (const auto& rectangle : rectangles)
            window.draw(rectangle);

        // ³���������� ����
        for (const auto& circle : circles)
            window.draw(circle);

        // ��������� ����
        window.display();
    }

    return 0;
}