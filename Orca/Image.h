#pragma once

#include "pch.h"
#include "Utilities.h"

namespace Orca
{
	class ORCA_API Image
	{
	public:
		Image(const std::string& fileName);
		Image(std::string&& fileName);
	private:
	};
}
