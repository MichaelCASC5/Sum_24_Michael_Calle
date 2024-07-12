#pragma once
#include "pch.h"
#include "Utilities.h"

namespace Orca
{
	class ORCA_API Camera
	{
	public:
		Camera();
		Camera(double x, double y, double z);
		~Camera();

		double getX();
		double getY();
		double getZ();

		void updateXBy(double n);
		void updateYBy(double n);
		void updateZBy(double n);

	private:
		std::vector<double> position;
	};
}
