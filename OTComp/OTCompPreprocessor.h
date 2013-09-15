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

/**
	\file OTCompPreprocessor takes care of things specific to the OT Compiler.
*/

#ifndef OTCOMPPREPROCESSOR_H
#define OTCOMPPREPROCESSOR_H

#include "../Util/Preprocessor.h"

using util::String;

class OTCompPreprocessor: public Preprocessor {
	String inputFileName;
	String outputFileName;

protected:
	virtual void addOption (String option, String param, PreprocessorPosition &pos);
	virtual bool isSpecialToken (char firstChar, char secondChar);
public:
	OTCompPreprocessor (String aFileName);
	~OTCompPreprocessor();

	String getInputFileName();
	String getOutputFileName();
};

#endif // OTCOMPPREPROCESSOR_H
