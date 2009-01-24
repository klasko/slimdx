/*
* Copyright (c) 2007-2009 SlimDX Group
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#include "Rational.h"

using namespace System;

namespace SlimDX
{
	/// 
	Rational::Rational( int numerator, int denominator ) : numerator( numerator), denominator( denominator )
	{
	}
	
	///
	int Rational::Numerator::get()
	{
		return numerator;
	}
	
	///
	void Rational::Numerator::set( int value )
	{
		numerator = value;
	}
	
	///
	int Rational::Denominator::get()
	{
		return denominator;
	}
	
	///
	void Rational::Denominator::set( int value )
	{
		denominator = value;
	}

	bool Rational::operator == ( Rational left, Rational right )
	{
		return Rational::Equals( left, right );
	}

	bool Rational::operator != ( Rational left, Rational right )
	{
		return !Rational::Equals( left, right );
	}

	int Rational::GetHashCode()
	{
		return numerator.GetHashCode() + denominator.GetHashCode();
	}

	bool Rational::Equals( Object^ value )
	{
		if( value == nullptr )
			return false;

		if( value->GetType() != GetType() )
			return false;

		return Equals( safe_cast<Rational>( value ) );
	}

	bool Rational::Equals( Rational value )
	{
		return ( numerator == value.numerator && denominator == value.denominator );
	}

	bool Rational::Equals( Rational% value1, Rational% value2 )
	{
		return ( value1.numerator == value2.numerator && value1.denominator == value2.denominator );
	}
}