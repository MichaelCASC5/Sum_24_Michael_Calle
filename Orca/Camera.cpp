#include "pch.h"
#include "Camera.h"
#define PI 3.1415926535897932384626433832795

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

	void Camera::setPosition(double a, double b, double c)
	{
		position[0] = a;
		position[1] = b;
		position[2] = c;
	}

	void Camera::setRotation(double a, double b, double c)
	{
		rotation[0] = a;
		rotation[1] = b;
		rotation[2] = c;
	}

	void Camera::reset()
	{
		for (int i = 0; i < 3; i++)
		{
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

		// Fancy movements
		
		//// If the camera is looking over its back, invert the yaw direction (between 270 and 90)
		//if (cos(getPitch() * (PI / 180)) < 0)
		//{
		//	n = -n;
		//}

		//rotation[0] += n * cos(getRoll() * (PI / 180));
		//rotation[1] += n * sin(getRoll() * (PI / 180));
	}

	void Camera::pitch(double n)
	{
		rotation[1] += n;

		if (rotation[1] > 90)
		{
			rotation[1] = 90;
		}
		else if (rotation[1] < -90)
		{
			rotation[1] = -90;
		}

		// Fancy movements

		/*rotation[0] -= n * sin(getRoll() * (PI / 180));
		rotation[1] += n * cos(getRoll() * (PI / 180));*/
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

	void Camera::forward(double n)
	{
		position[0] += n * sin(getYaw() * (PI / 180)) * cos(getPitch() * (PI / 180));
		// position[1] += n * sin(getPitch() * (PI / 180));	// Fancy movement
		position[2] += n * cos(getYaw() * (PI / 180)) * cos(getPitch() * (PI / 180));
	}

	void Camera::left(double n)
	{
		position[0] += n * cos(getYaw() * (PI / 180));
		position[2] -= n * sin(getYaw() * (PI / 180));
	}
}
