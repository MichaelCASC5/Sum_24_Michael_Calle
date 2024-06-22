#pragma once

namespace Orca
{
	class ImageImplementation
	{
	public:
		virtual void Bind() = 0;
		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;

		virtual ~ImageImplementation() {};
	};
}
