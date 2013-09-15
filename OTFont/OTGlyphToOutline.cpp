/*
	(c) Copyright 2002, 2003 Rogier van Dalen
	(R.C.van.Dalen@umail.leidenuniv.nl for any comments, questions or bugs)

	This file is part of my OpenType/TrueType Font Tools.

	The OpenType/TrueType Font Tools is free software; you can redistribute
	it and/or modify it under the terms of the GNU General Public License as
	published by the Free Software Foundation; either version 2 of the
	License, or (at your option) any later version.

	The OpenType/TrueType Font Tools is distributed in the hope that it will
	be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
	Public License for more details.

	You should have received a copy of the GNU General Public License
	along with the OpenType/TrueType Font Tools; if not, write to the Free
	Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "OTGlyphToOutline.h"

namespace OpenType {

/*** ContourOutlineIterator ***/

ContourOutlineIterator::ContourOutlineIterator (const Contour::const_iterator & _i)
	: i (_i)
{
	if (!validPosition (i))
		i ++;
}

ContourOutlineIterator::ContourOutlineIterator (const ContourOutlineIterator & o)
	: i (o.i)
{
	assert (validPosition (i));
}

size_t ContourOutlineIterator::getNextStepSize() const {
	if (!i->onCurve)
		return 1;
	else {
		Contour::const_iterator next = i;
		++ next;
		if (next->onCurve)
			return 1;
		else
			return 2;
	}
}

ContourOutlineIterator & ContourOutlineIterator::operator ++ () {
	if (!i->onCurve)
		++ i;
	else {
		++ i;
		if (!i->onCurve)
			++ i;
	}
	return *this;
}

} // namespace OpenType
