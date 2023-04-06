#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include <numbers>


using namespace std;

const double PI = 3.141592653589793;

int winXsize = 900;
int winYsize = 900;

int inputInt(string massage, int min, int max)
{
    int value = 0;
    cout << massage;
    if ((!(cin >> value)) | value < min || value > max)
    {
        cout << "ѕеременна€ введена некорректно!\n";
        cin.clear();
  
    }
    else return value;
}

void DrawNode(sf::RenderWindow& window, double X, double Y, double L, int N)
{
    if (N < 0)
    {
        return;
    }

    double X_1 = X - L * cos((45.0 * PI) / 180.0);
    double Y_1 = Y + L * sin((45.0 * PI) / 180.0);
    sf::Vertex line_l[] =
    {
        sf::Vertex(sf::Vector2f(X, Y)),
        sf::Vertex(sf::Vector2f(X_1, Y_1))
    };
    window.draw(line_l, 2, sf::Lines);

    double X_2 = X + L * cos((45.0 * PI) / 180.0);
    double Y_2 = Y + L * sin((45.0 * PI) / 180.0);
    sf::Vertex line_r[] =
    {
        sf::Vertex(sf::Vector2f(X, Y)),
       sf::Vertex(sf::Vector2f(X_2, Y_2))
    };
    window.draw(line_r, 2, sf::Lines);

    double x_1 = X - ((2.0f / 3.0f * L) * cos((45.0f * PI) / 180.0f));
    double y_1 = Y + ((2.0f / 3.0f * L) * sin((45.0f * PI) / 180.0f));
    DrawNode(window, x_1, y_1, L / 3, N - 1);

    double x_2 = X + (2.0f / 3.0f * L) * cos((45.0f * PI) / 180.0f);
    double y_2 = Y + (2.0f / 3.0f * L) * sin((45.0f * PI) / 180.0f);
    DrawNode(window, x_2, y_2, L / 3, N - 1);

    return;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_CTYPE, "Russian");

    int L = inputInt("¬ведите длину линии в пиксел€х (10-500): ", 10, 500);
    int N = inputInt("¬ведите количество уровней (1 - 10): ", 1, 10);

    sf::RenderWindow window(sf::VideoMode(winXsize, winYsize), "Bruh");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        double X = winXsize / 2;
        double Y = 0.0f;
        DrawNode(window, X, Y, L, N);

        window.display();
    }

    cout << "¬ведите любую клавишу дл€ завершени€ программы ... ";
    _getch();
    return 0;
}
