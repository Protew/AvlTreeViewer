/*
 *  RotationDisplay.h
 *  AVL_Tree_View_2
 *
 *  Created by PRoTeW on 02/06/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ROTATIONDISPLAY_H
#define ROTATIONDISPLAY_H

#include "AvlNode.h"

enum DISPLAY_TYPE{ LEFT_ROT, RIGHT_ROT, FIND, ALREADY };

class RotationDisplay
{
	AvlNode *target;
	double px, PX, py, PY;
	QImage	*image;
	DISPLAY_TYPE display_type;

public:
	RotationDisplay( AvlNode *, DISPLAY_TYPE );
	//GETS
	VEC2 * GetPosition( void );
	//SETS
	void SetPosition( VEC2 * );
	//
	void draw( void );
};

#endif