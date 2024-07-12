#include "pch.h"
#include "Camera.h"

namespace Orca
{
	Orca::Camera::Camera()
	{
		position = { 0, 0, 0 };
	}

	Camera::Camera(double x, double y, double z)
	{
		position = { x, y, z };
	}

	Camera::~Camera()
	{
	}

	double Camera::getX()
	{
		return position[0];
	}

	double Camera::getY()
	{
		return position[1];
	}

	double Camera::getZ()
	{
		return position[2];
	}

	void Camera::updateXBy(double n)
	{
		position[0] += n;
	}

	void Camera::updateYBy(double n)
	{
		position[1] += n;
	}

	void Camera::updateZBy(double n)
	{
		position[2] += n;
	}
}
