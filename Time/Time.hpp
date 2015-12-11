#ifndef _TIME_HPP
#define _TIME_HPP

#include <cstdint>

/**
 * Base class for getting time.
 */
class Time{
public:
    /** Get current time */
    virtual uint64_t getTime() = 0;
};

#endif
