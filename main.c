#include <IOKit/hidsystem/IOHIDLib.h>
#include <IOKit/hidsystem/IOHIDParameter.h>
#include <IOKit/hidsystem/event_status_driver.h>

int main()
{
    double trackpadAcceleration;

    NXEventHandle eventHandle = NXOpenEventStatus();

    IOHIDGetAccelerationWithKey(eventHandle,
                                CFSTR(kIOHIDTrackpadAccelerationType),
                                &trackpadAcceleration);

    IOHIDSetAccelerationWithKey(eventHandle,
                                CFSTR(kIOHIDMouseAccelerationType),
                                65535.0);

    IOHIDSetAccelerationWithKey(eventHandle,
                                CFSTR(kIOHIDTrackpadAccelerationType),
                                trackpadAcceleration);

    return 0;
}
