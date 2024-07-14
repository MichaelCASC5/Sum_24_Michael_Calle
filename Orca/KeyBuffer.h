#pragma once
#include "pch.h"
#include "Utilities.h"

namespace Orca
{
	class ORCA_API KeyBuffer
	{
	public:
		/*
		* CONSTRUCTORS
		*/

		KeyBuffer();
		~KeyBuffer();

		/*
		* Set keys
		*/
		void setW(bool b);
		void setA(bool b);
		void setS(bool b);
		void setD(bool b);

		void setLeftArrow(bool b);
		void setRightArrow(bool b);
		void setUpArrow(bool b);
		void setDownArrow(bool b);

		void setSpace(bool b);
		void setCtrl(bool b);

		/*
		* Get keys
		*/
		bool getW();
		bool getA();
		bool getS();
		bool getD();

		bool getLeftArrow();
		bool getRightArrow();
		bool getUpArrow();
		bool getDownArrow();

		bool getSpace();
		bool getCtrl();

	private:
		bool w, a, s, d, L, R, U, D, space, ctrl;
	};
}
