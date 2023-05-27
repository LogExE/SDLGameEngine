
#pragma once

struct SDL_Event;

class EventObserver
{
private:
    /* data */
public:
    EventObserver(/* args */);
    virtual ~EventObserver();

    virtual void notify(SDL_Event ev) = 0;
};