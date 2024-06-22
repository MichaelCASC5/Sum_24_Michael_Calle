#pragma once

#include "../../include/ImageImplementation.h"

namespace Orca
{
	class ImageOpenGL : public ImageImplementation
	{
	public:
		ImageOpenGL(const std::string& fileName);
		ImageOpenGL(std::string&& fileName);
		~ImageOpenGL();

		virtual void Bind() override;
		virtual int GetWidth() override;
		virtual int GetHeight() override;

	public:
		unsigned int mTexture{ 0 };
		int mWidth{ 0 };
		int mHeight{ 0 };
		int mNumOfChannels{ 0 };
	};
}
