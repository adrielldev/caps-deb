#include <stdio.h>
#include <stdlib.h>
#include <X11/XKBlib.h>

int main(void)
{
    Display *display;
    Status status;
    unsigned state;

    

    display = XOpenDisplay(getenv("DISPLAY"));
        return 1;

    if (XkbGetIndicatorState(display, XkbUseCoreKbd, &state) != Success)
        return 2;

    while (1)
    {
        XkbGetIndicatorState(display, XkbUseCoreKbd, &state);
        if (state & 1) {
            system("notify-send Capslock \"Activated\"");
        } else {
            system("notify-send Capslock \"Deactivated\"");
        }
            
        
    }

    return 0;
}