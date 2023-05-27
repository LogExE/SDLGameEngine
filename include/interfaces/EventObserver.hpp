
#pragma once

struct SDL_Event;

class EventObserver
{
private:
public:
    EventObserver();
    virtual ~EventObserver();

    virtual void notify(SDL_Event ev) = 0;
};