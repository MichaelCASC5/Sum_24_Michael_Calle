#pragma once

#include "Utilities.h"

namespace Orca
{
	class ORCA_API KeyPressedEvent
	{
	public:
		KeyPressedEvent(int keyCode);
		int GetKey() const;
	private:
		int mKeyCode{ -1 };
	};

	class ORCA_API KeyReleasedEvent
	{
	public:
		KeyReleasedEvent(int keyCode);
		int GetKey() const;
	private:
		int mKeyCode{ -1 };
	};

	class ORCA_API WindowCloseEvent
	{

	};
}
