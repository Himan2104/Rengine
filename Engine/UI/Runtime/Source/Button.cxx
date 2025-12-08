#include "Rengine/ui/Button.hxx"
#include "SFML/Graphics/Text.hxx"
#include <cstdint>

Ren::ui::Button::Button(sf::Font& font, sf::Vector2f size, std::string ButtonText)
    : text(font)
{
    box.setSize(size);
    text.setFont(font);
    text.setString(ButtonText);
    box.setOrigin(box.getGlobalBounds().getCenter());

    adjustText();

    box.setFillColor(sf::Color::Magenta);
    text.setFillColor(sf::Color::White);
}

void Ren::ui::Button::setTextStyle(std::uint32_t style)
{
    text.setStyle(style);
    adjustText();
}

void Ren::ui::Button::setColor(sf::Color BoxColor, sf::Color TextColor)
{
    box.setFillColor(BoxColor);
    text.setFillColor(TextColor);
}

void Ren::ui::Button::setPosition(const sf::Vector2f& pos)
{
    box.setPosition(pos);
    adjustText();
}

sf::Vector2f Ren::ui::Button::getSize() const { return box.getSize(); }

void Ren::ui::Button::setFunction(std::function<void(void)> ButtonFunction) { this->ButtonFunction = ButtonFunction; }

void Ren::ui::Button::render(sf::RenderTarget& renderTarget)
{
    renderTarget.draw(box);
    renderTarget.draw(text);
}

void Ren::ui::Button::EventHandler(sf::Event e, const sf::RenderWindow& window)
{
    sf::Vector2f m_pos = sf::Vector2f(sf::Mouse::getPosition(window));

    if (e.is< == sf::Event::MouseButtonPressed)
        if (e.mouseButton.button == sf::Mouse::Left)
            if (box.getGlobalBounds().contains(m_pos)) ButtonFunction();
}

Ren::ui::Button::~Button() {}

void Ren::ui::Button::adjustText()
{
    text.setCharacterSize(int(box.getGlobalBounds().height / 2.0f));
    text.setOrigin(text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().height / 2.0f);
    while (text.getGlobalBounds().left < box.getGlobalBounds().left ||
           text.getGlobalBounds().left + text.getGlobalBounds().width >
               box.getGlobalBounds().left + box.getGlobalBounds().width ||
           text.getGlobalBounds().top < box.getGlobalBounds().top ||
           text.getGlobalBounds().top + text.getGlobalBounds().height >
               box.getGlobalBounds().top + box.getGlobalBounds().height)
    {
        text.setCharacterSize(text.getCharacterSize() - 1);
        text.setOrigin(text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().height / 2.0f);
        text.setPosition(box.getPosition() - sf::Vector2f(0.0f, text.getGlobalBounds().height / 2.0f));
    }
}
