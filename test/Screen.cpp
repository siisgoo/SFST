#include <gtest/gtest.h>

#include <cmath>

#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector3.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Sleep.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>

//SFST
#include "../include/SFST/Math.hpp"
#include "../include/SFST/Screen.hpp"
#include "../include/SFST/TRS.hpp"

float
degree2rad(float d) {
    return d * M_PI / 180;
}

float
rad2degree(float r) {
    return r * 180 / M_PI;
}

void
drawBoxRotation(sfst::Screen& win, sf::FloatRect& drawArea, int prevD, bool horiz)
{
    win.updateWindowState();

    if (horiz) {
        sf::RectangleShape box;
        box.setSize({drawArea.width/2, drawArea.height/2});
        box.setFillColor(sf::Color::Blue);

        box.setOrigin({box.getSize().x/2, box.getSize().y/2});
        box.setPosition({drawArea.width/2 + drawArea.left, drawArea.height/2 + drawArea.top});
        box.setRotation(prevD);

        win.Draw(box);
    } else {
        sf::VertexArray rect(sf::Quads, 4);

        for (int i = 0; i < 4; ++i) {
            rect[i].color = sf::Color::Blue;
        }

        // 0--->1
        // ^    |
        // |    |
        // |    v
        // 3<---2

        sfst::Trs2D trs;

        sf::Vector2f size(drawArea.width/2, drawArea.height/2);
        sfst::Vectorf coube2d[4] {
            { (drawArea.width/2 - size.x/2) + drawArea.left, (drawArea.height/2 - size.y/2) + drawArea.top, 1 }, //a
            { (drawArea.width/2 + size.x/2) + drawArea.left, (drawArea.height/2 - size.y/2) + drawArea.top, 1 }, //b
            { (drawArea.width/2 + size.x/2) + drawArea.left, (drawArea.height/2 + size.y/2) + drawArea.top, 1 }, //c
            { (drawArea.width/2 - size.x/2) + drawArea.left, (drawArea.height/2 + size.y/2) + drawArea.top, 1 }, //d
        };

        trs.applyRotation(degree2rad(300));
        std::cout << trs << std::endl;
        for (int i = 0; i < 4; ++i) {
            std::cout << coube2d[i] << std::endl;
            trs.applyToVector(coube2d[i]);
            rect[i].position = { coube2d[i](0), coube2d[i](1) };
            std::cout << coube2d[i] << std::endl;
        }

        win.Draw(rect);
    }
}

TEST(Coubes, Rotation) {
    sfst::Screen sc1("TEST (BOX IN THE SCREEN)", {200, 300});
    sc1.setFramerateLimit(60);

    sf::FloatRect da1(0, 0, sc1.getSize().x/2, sc1.getSize().x/2),
        da2(sc1.getSize().x/2, 0, sc1.getSize().x/2, sc1.getSize().x/2);
    sf::ContextSettings cs;
    int prevDegree = 0;
    bool anti_aliased = false;

    sf::Clock clock;
    while (sc1.isOpen()) {
        sf::Event e;
        while (sc1.pollEvent(e)) {
            if (e.type == sf::Event::Resized) {
                sc1.updateWindowState();
                da1 = sf::FloatRect(0, 0, sc1.getSize().x/2, sc1.getSize().x/2);
                da2 = sf::FloatRect(sc1.getSize().x/2, 0, sc1.getSize().x/2, sc1.getSize().x/2);
            }
            if (e.type == sf::Event::KeyReleased) {
                if (e.key.code == sf::Keyboard::Key::A) {
                    if (!anti_aliased) {
                        sc1.setTitle("TEST (ANTI-ALIAS ON)");
                        cs.antialiasingLevel = 16;
                        sc1.setSettings(cs);
                        sc1.applyStyle();
                    } else {
                        sc1.setTitle("TEST (ANTI-ALIAS OFF)");
                        cs.antialiasingLevel = 0;
                        sc1.setSettings(cs);
                        sc1.applyStyle();
                    }
                    anti_aliased = !anti_aliased;
                }
            }
        }

        sc1.BeginDraw();
        drawBoxRotation(sc1, da1, prevDegree, false);
        drawBoxRotation(sc1, da2, prevDegree, true);
        sc1.EndDraw();
        ++prevDegree;

        if (clock.getElapsedTime() >= sf::milliseconds(5000)) {
            sc1.Close();
        } else {
            sf::sleep(sf::milliseconds(1000.f / 5)); // 10 HZ 
        }
    }

    EXPECT_EQ(1, 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
