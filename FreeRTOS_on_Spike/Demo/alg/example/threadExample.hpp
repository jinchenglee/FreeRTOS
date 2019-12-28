#ifndef __THREADBASE_INC
#define __THREADBASE_INC

#include "FreeRTOS.h"
#include "task.h"

#include "threadBase.hpp"

namespace alg
{
class threadExample : public threadBase
{
public:
    threadExample( 
                unsigned portSHORT _stackDepth, 
                UBaseType_t _priority,
                const char* _name = "",

                uint32_t _ticks
              ) : threadBase{_stackDepth, _priority, _name}, ticks {_ticks}
    {
    }

    virtual void threadTask() override
    {
        while(1)
        {
            printf("Task - threadTask()\r\n");
            vTaskDelay(100);
        }
    }

private:

    uint32_t ticks;

}; // class threadExample
} // namespace alg
#endif

