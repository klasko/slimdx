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
#include <d3d9.h>
#include <d3dx9.h>

#include "AttributeWeights.h"

using namespace System;

namespace SlimDX
{
namespace Direct3D9
{
	bool AttributeWeights::operator == ( AttributeWeights left, AttributeWeights right )
	{
		return AttributeWeights::Equals( left, right );
	}

	bool AttributeWeights::operator != ( AttributeWeights left, AttributeWeights right )
	{
		return !AttributeWeights::Equals( left, right );
	}

	int AttributeWeights::GetHashCode()
	{
		return Position.GetHashCode() + Boundary.GetHashCode() + Normal.GetHashCode()
			 + Diffuse.GetHashCode() + Specular.GetHashCode() + TextureCoordinate1.GetHashCode()
			 + TextureCoordinate2.GetHashCode() + TextureCoordinate3.GetHashCode() + TextureCoordinate4.GetHashCode()
			 + TextureCoordinate5.GetHashCode() + TextureCoordinate6.GetHashCode() + TextureCoordinate7.GetHashCode()
			 + TextureCoordinate8.GetHashCode() + Tangent.GetHashCode() + Binormal.GetHashCode();
	}

	bool AttributeWeights::Equals( Object^ value )
	{
		if( value == nullptr )
			return false;

		if( value->GetType() != GetType() )
			return false;

		return Equals( safe_cast<AttributeWeights>( value ) );
	}

	bool AttributeWeights::Equals( AttributeWeights value )
	{
		return ( Position == value.Position && Boundary == value.Boundary && Normal == value.Normal
			 && Diffuse == value.Diffuse && Specular == value.Specular && TextureCoordinate1 == value.TextureCoordinate1
			 && TextureCoordinate2 == value.TextureCoordinate2 && TextureCoordinate3 == value.TextureCoordinate3 && TextureCoordinate4 == value.TextureCoordinate4
			 && TextureCoordinate5 == value.TextureCoordinate5 && TextureCoordinate6 == value.TextureCoordinate6 && TextureCoordinate7 == value.TextureCoordinate7
			 && TextureCoordinate8 == value.TextureCoordinate8 && Tangent == value.Tangent && Binormal == value.Binormal );
	}

	bool AttributeWeights::Equals( AttributeWeights% value1, AttributeWeights% value2 )
	{
		return ( value1.Position == value2.Position && value1.Boundary == value2.Boundary && value1.Normal == value2.Normal
			 && value1.Diffuse == value2.Diffuse && value1.Specular == value2.Specular && value1.TextureCoordinate1 == value2.TextureCoordinate1
			 && value1.TextureCoordinate2 == value2.TextureCoordinate2 && value1.TextureCoordinate3 == value2.TextureCoordinate3 && value1.TextureCoordinate4 == value2.TextureCoordinate4
			 && value1.TextureCoordinate5 == value2.TextureCoordinate5 && value1.TextureCoordinate6 == value2.TextureCoordinate6 && value1.TextureCoordinate7 == value2.TextureCoordinate7
			 && value1.TextureCoordinate8 == value2.TextureCoordinate8 && value1.Tangent == value2.Tangent && value1.Binormal == value2.Binormal );
	}
}
}