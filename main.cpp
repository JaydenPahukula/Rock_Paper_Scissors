#include <SFML/Graphics.hpp>
using namespace sf;

#include <string>

int main() {

    int width = 640;
    int height = 640;

    std::string s = "hello";

    RenderWindow window(VideoMode(width, height), "rps");

    Event event;
    View view = window.getDefaultView();
    Font myFont;
    if(!myFont.loadFromFile("data/arial.ttf"))
        return -1;

    while( window.isOpen() ) {
        window.clear();

        //background
        RectangleShape bkg;
        bkg.setSize(Vector2f(width, height));
        bkg.setPosition(0,0);
        bkg.setFillColor(Color(255,255,255));
        window.draw(bkg);

        //text
        Text wtext;
        wtext.setFont(myFont);
        wtext.setString(std::to_string(width));
        wtext.setPosition(50, 50);
        wtext.setFillColor(Color::Black);
        window.draw(wtext);
        Text htext;
        htext.setFont(myFont);
        htext.setString(std::to_string(height));
        htext.setPosition(50, 100);
        htext.setFillColor(Color::Black);
        window.draw(htext); 


        window.display();

        while( window.pollEvent(event) ) {
            if(event.type == Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::Resized) {
                view.setSize({static_cast<float>(event.size.width), static_cast<float>(event.size.height)});
                width = event.size.width;
                height = event.size.height;
                window.setView(view);
            }
        }
    }

    return 0;
}