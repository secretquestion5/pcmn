#include <SFML/Graphics.hpp>

using namespace sf;

int generateEatPos(){
    return rand()%500+200;
}

int main()
{
    float speed = 5;
    int segments = 0;
    Vector2f currentPosition;
    Vector2f direction;
    Vector2f eatPosition(100,100);

    
    RectangleShape eat (Vector2f(20,20));
    eat.setFillColor(Color(255,0,0));

    RenderWindow window (sf::VideoMode(1280,720), "Pcmn");
    window.setFramerateLimit(60);
    while(window.isOpen()){
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        RectangleShape rect(Vector2f(20,20));

        rect.setFillColor(Color(100,100,100));
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

        rect.setPosition(currentPosition.x+direction.x, currentPosition.y+direction.y);
/////

        if (eat.getGlobalBounds().intersects(rect.getGlobalBounds())){
            eatPosition.x = generateEatPos();
            eatPosition.y = generateEatPos();
            segments += 1;
        }

        eat.setPosition(eatPosition.x,eatPosition.y);
//////  

        window.clear();
        window.draw(eat);
        window.draw(rect);

        window.display();
        currentPosition = rect.getPosition();

    }

    return 0;
}
