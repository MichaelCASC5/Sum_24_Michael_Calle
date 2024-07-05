#include "pch.h"
#include "Events.h"

namespace Orca
{
    KeyPressedEvent::KeyPressedEvent(int keyCode): mKeyCode(keyCode)
    {

    }
    int Orca::KeyPressedEvent::GetKey() const
    {
        return mKeyCode;
    }

    KeyReleasedEvent::KeyReleasedEvent(int keyCode): mKeyCode(keyCode)
    {

    }

    int KeyReleasedEvent::GetKey() const
    {
        return mKeyCode;
    }

}
