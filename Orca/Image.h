#pragma once

#include "pch.h"
#include "Utilities.h"
#include "ImageImplementation.h"

namespace Orca
{
	class ORCA_API Image
	{
	public:
		Image(const std::string& fileName);
		Image(std::string&& fileName);

		void Bind();
		int GetWidth() const;
		int GetHeight() const;
	private:
		std::unique_ptr<ImageImplementation> mImplementation;
	};
}
