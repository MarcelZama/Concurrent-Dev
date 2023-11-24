/**
 * @file SafeBuffer.cpp
 * @brief Header file for the Event class.
 *
 * This file defines the Event class, which represents an event with a numerical value.
 * It provides methods to initialize an event and consume it.
 *
 * @author Joseph Kehoe
 * @editor Marcel Zama
 * @date 14/11/2023
 * @license GPL-3.0 (See LICENSE text for the full LICENSE)
 * @link https://github.com/MarcelZama/Concurrent-Dev/tree/main
 */

#ifndef EVENT_H
#define EVENT_H

/**
 * @class Event
 * @brief A class representing an event with a numerical value.
 */
class Event {
private:
    int number; /**< The numerical value associated with the event. */

public:
    /**
     * @brief Constructor for the Event class.
     * @param num The numerical value to initialize the event with.
     */
    Event(int num);

    /**
     * @brief Consumes the event.
     * @return The numerical value of the consumed event.
     */
    int consume();
};

#endif
