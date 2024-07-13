#include "pch.h"
#include "Camera.h"

namespace Orca
{
	Orca::Camera::Camera()
	{
		position = { 0, 0, 0 };
		rotation = { 0, 0, 0 };
	}

	Camera::Camera(double x, double y, double z)
	{
		position = { x, y, z };
	}

	Camera::Camera(double x, double y, double z, double a, double b, double c)
	{
		position = { x, y, z };
		rotation = { a, b, c };
	}

	Camera::~Camera()
	{
	}

	void Camera::reset()
	{
		for (int i = 0; i < 3; i++)
		{
			position[i] = fmod(position[i], 360);
			rotation[i] = fmod(rotation[i], 360);
		}
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

	void Camera::yaw(double n)
	{
		rotation[0] += n;
	}

	void Camera::pitch(double n)
	{
		rotation[1] += n;
	}

	void Camera::roll(double n)
	{
		rotation[2] += n;
	}

	double Camera::getYaw()
	{
		return rotation[0];
	}

	double Camera::getPitch()
	{
		return rotation[1];
	}

	double Camera::getRoll()
	{
		return rotation[2];
	}
}
