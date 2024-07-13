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
		Camera(double x, double y, double z, double a, double b, double c);
		~Camera();

		void updateXBy(double n);
		void updateYBy(double n);
		void updateZBy(double n);

		double getX();
		double getY();
		double getZ();

		void yaw(double n);
		void pitch(double n);
		void roll(double n);

		double getYaw();
		double getPitch();
		double getRoll();

	private:
		std::vector<double> position;
		std::vector<double> rotation;
	};
}
