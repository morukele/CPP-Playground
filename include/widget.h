//
// Created by Oghenemarho Orukele on 16/12/2025.
//

#ifndef CPP_PLAYGROUND_WIDGET_H
#define CPP_PLAYGROUND_WIDGET_H

#include <experimental/propagate_const>
#include <iostream>
#include <memory>

class widget
{
    class impl;
    std::experimental::propagate_const<std::unique_ptr<impl>> pImpl;

public:
    void draw() const; // public API that will be forwarded to the implementation
    void draw();
    bool shown() const {return true;} // public API that implementation has to call

    widget(); // NOTE: calling draw() on default constructed object is UB
    explicit widget(int);
    ~widget();
    widget(widget&&); // move ctor
    widget& operator=(widget&&); // copy ctor
    widget& operator=(const widget&) = delete;
};

#endif //CPP_PLAYGROUND_WIDGET_H