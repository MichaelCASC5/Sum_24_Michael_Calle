#pragma once

#include "pch.h"
#include "Utilities.h"
#include "RendererImplementation.h"
#include "Image.h"
#include "Shaders.h"

namespace Orca
{
	class ORCA_API Renderer
	{
	public:
		static void Init();
		static std::shared_ptr<Renderer> Get();

		void Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders);
		void Draw(Image& pic, int xCoord, int yCoord);
		void ClearScreen();

	private:
		std::unique_ptr<RendererImplementation> mImplementation;

		inline static std::shared_ptr<Renderer> mInstance;
		Renderer();

		Shaders mDefaultShaders{
			"../Table/Assets/Shaders/defaultVertex.glsl",
			"../Table/Assets/Shaders/defaultFragment.glsl" };
	};
}
