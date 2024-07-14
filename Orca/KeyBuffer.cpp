#include "pch.h"
#include "KeyBuffer.h"

namespace Orca
{
	Orca::KeyBuffer::KeyBuffer()
	{
		w = false;
		a = false;
		s = false;
		d = false;
		L = false;
		R = false;
		U = false;
		D = false;
		space = false;
		ctrl = false;
	}
	KeyBuffer::~KeyBuffer()
	{
	}

	/*
	* SET KEYS
	*/

	void KeyBuffer::setW(bool b)
	{
		w = b;
	}

	void KeyBuffer::setA(bool b)
	{
		a = b;
	}

	void KeyBuffer::setS(bool b)
	{
		s = b;
	}

	void KeyBuffer::setD(bool b)
	{
		d = b;
	}


	void KeyBuffer::setLeftArrow(bool b)
	{
		L = b;
	}

	void KeyBuffer::setRightArrow(bool b)
	{
		R = b;
	}

	void KeyBuffer::setUpArrow(bool b)
	{
		U = b;
	}

	void KeyBuffer::setDownArrow(bool b)
	{
		D = b;
	}


	void KeyBuffer::setSpace(bool b)
	{
		space = b;
	}

	void KeyBuffer::setCtrl(bool b)
	{
		ctrl = b;
	}

	/*
	* GET KEYS
	*/
	bool KeyBuffer::getW()
	{
		return w;
	}

	bool KeyBuffer::getA()
	{
		return a;
	}

	bool KeyBuffer::getS()
	{
		return s;
	}

	bool KeyBuffer::getD()
	{
		return d;
	}


	bool KeyBuffer::getLeftArrow()
	{
		return L;
	}

	bool KeyBuffer::getRightArrow()
	{
		return R;
	}

	bool KeyBuffer::getUpArrow()
	{
		return U;
	}

	bool KeyBuffer::getDownArrow()
	{
		return D;
	}


	bool KeyBuffer::getSpace()
	{
		return space;
	}

	bool KeyBuffer::getCtrl()
	{
		return ctrl;
	}

}
