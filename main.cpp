#include <SFML/Graphics.hpp>
#include <vector>
#include <string> 

using namespace sf;

int generateEatPos(){
    return rand()%500+200;
}

int main()
{

    int width = 1280;
    int height = 720;

    int speed = 5;
    int segments = 2;
    Vector2f direction;
    Vector2f cp;
    RectangleShape eat (Vector2f(20,20));
    Vector2f eatPosition(100,100);

    std::vector<RectangleShape> snake;
    std::vector<Vector2f> positions;

    RenderWindow window (sf::VideoMode(width,height), "Snake");

    window.setFramerateLimit(60);

    for(int i = 0; i < segments; i++){
        positions.push_back(Vector2f(10,10));
    }

        for(int i = 0; i < segments; i++){
            RectangleShape s(Vector2f(30,30));
            s.setFillColor(Color::Blue);
            snake.push_back(s);
        }

    while(window.isOpen()){
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // std::vector<RectangleShape> snake;

        // for(int i = 0; i < segments; i++){
        //     RectangleShape s(Vector2f(30,30));
        //     s.setFillColor(Color::Blue);
        //     snake.push_back(s);
        // }

////
        if (Keyboard::isKeyPressed(Keyboard::S)){
            direction.x = 0;
            direction.y = speed;
        }

        if (Keyboard::isKeyPressed(Keyboard::W)){
            direction.x = 0;
            direction.y = -speed;
        }

        if (Keyboard::isKeyPressed(Keyboard::D)){
            direction.x = speed;
            direction.y = 0;
        }        
        if (Keyboard::isKeyPressed(Keyboard::A)){
            direction.x = -speed;
            direction.y = 0;
        }        
/////

        for(int i = 0; i < segments; i++){
            snake[0].setPosition(cp.x+direction.x, cp.y+direction.y);
            if (i != 0){
                snake[i].setPosition(positions[i-1]);
            }     
        }

        if (eat.getGlobalBounds().intersects(snake[0].getGlobalBounds())){
            eatPosition.x = generateEatPos();
            eatPosition.y = generateEatPos();
            segments += 1;

            positions.push_back(Vector2f(10,10));
            RectangleShape s(Vector2f(30,30));
            s.setFillColor(Color::Blue);
            snake.push_back(s);
        }

        eat.setPosition(eatPosition.x,eatPosition.y);

///////

        Text text;

        Font font;
        font.loadFromFile("impact2.ttf");
        text.setFont(font);
        text.setString(std::to_string(segments));
        text.setCharacterSize(24);
        text.setFillColor(Color::Red);
        text.setPosition(1000,100);
//////
        window.clear();
        window.draw(text);
        window.draw(eat);

        for(std::vector<sf::RectangleShape>::iterator it = snake.begin() ; it != snake.end(); ++it){
            window.draw(*it);
        }
        window.display();        



        for(int i = 0; i < segments; i++){
            cp = snake[0].getPosition();
            positions[i] = snake[i].getPosition(); 
        }

        cp = snake[0].getPosition();
        if (cp.x > width){cp.x = 0;};
        if (cp.x < 0){cp.x = width;};
        if (cp.y > height){cp.y = 0;};
        if (cp.y < 0){cp.y = height;};
    }

    return 0;
}
