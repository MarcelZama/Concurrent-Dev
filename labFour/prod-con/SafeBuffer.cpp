//Author: Joseph Kehoe
//Edited by:
//Name: Marcel Zama
//College ID: C00260146
//Date: 14/11/2023
//License: GPL-3.0 (See LICENSE text for the full LICENSE)
//GitHub Link:https://github.com/MarcelZama/Concurrent-Dev/tree/main

#ifndef EVENT_H
#define EVENT_H 

class Event {
    private:
        int number;

    public:
        Event(int num);
        int consume();
        

};

#endif
