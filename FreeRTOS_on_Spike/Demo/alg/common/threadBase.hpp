#ifndef __THREADBASE_INC
#define __THREADBASE_INC

#include "FreeRTOS.h"
#include "task.h"

namespace alg
{
class threadBase
{
public:
    threadBase( 
                unsigned portSHORT _stackDepth, 
                UBaseType_t _priority,
                const char* _name = ""
              )
    {
        xTaskCreate(task, _name, _stackDepth, this, _priority, &this->taskHandle);
    }

    virtual void threadTask() = 0;

protected:

    static void task(void* _params)
    {
        threadBase *p = static_cast<threadBase*>(_params);
        p->threadTask();
    }

    TaskHandle_t taskHandle;

}; // class threadBase
} // namespace alg
#endif

