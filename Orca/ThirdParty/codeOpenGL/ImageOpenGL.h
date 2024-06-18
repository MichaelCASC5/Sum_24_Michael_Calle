#pragma once

#include "../../ImageImplementation.h"

namespace Orca
{
	class ImageOpenGL : public ImageImplementation
	{
	public:
		ImageOpenGL(const std::string& fileName);
		ImageOpenGL(std::string&& fileName);
		~ImageOpenGL();

		virtual void Bind() override;
		virtual void GetWidth() override;
		virtual void GetHeight() override;

	public:
		unsigned int mTexture{ 0 };
		int mWidth{ 0 };
		int hHeight{ 0 };
		int mNumOfChannnels{ 0 };
	};
}
