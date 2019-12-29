#ifndef __THREADEXAMPLE_INC
#define __THREADEXAMPLE_INC

#include "FreeRTOS.h"
#include "task.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "clib.h"	// For printf().
#ifdef __cplusplus
}
#endif

#include "alg/common/threadBase.hpp"

namespace alg
{
class threadExample : public threadBase
{
public:
    threadExample( 
                unsigned portSHORT _stackDepth, 
                UBaseType_t _priority,
                const char* _name = "",

                uint32_t _ticks = 150
              ) : threadBase{_stackDepth, _priority, _name}, ticks {_ticks}, name {_name}
    {
    }

    virtual void threadTask() override
    {
        while(1)
        {
            printf("%s\r\n", name);
            vTaskDelay(ticks);
        }
    }

private:

    uint32_t ticks;
    const char* name;

}; // class threadExample
} // namespace alg
#endif

