//
// Created by Oghenemarho Orukele on 16/12/2025.
//

#include "include/widget.h"

class widget::impl
{
    int n; // private data
public:
    void draw(const widget& w) const
    {
        if (w.shown()) // call to public member function requires back-reference
        {
            std::cout << "drawing a const widget" << n << std::endl;
        }
    }

    void draw(const widget& w)
    {
        if (w.shown())
        {
            std::cout << "drawing a non-const widget" << n << std::endl;
        }
    }

    // ctor for impl class
    impl(int n) : n(n) {}
};

// implementation of class with ctor
// ---------------------------------
widget::widget() = default;

widget::widget(int n) : pImpl{std::make_unique<impl>(n)}
{
}

widget::widget(widget&&) = default;

widget::~widget() = default;

widget& widget::operator=(widget&&) = default;

void widget::draw() const
{
    pImpl->draw(*this);
}

void widget::draw()
{
    pImpl->draw(*this);
}
int main()
{
    widget w(7);
    const widget w2(8);
    w.draw();
    w2.draw();
}