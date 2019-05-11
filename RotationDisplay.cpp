/*
 *  RotationDisplay.cpp
 *  AVL_Tree_View_2
 *
 *  Created by PRoTeW on 02/06/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "RotationDisplay.h"
#include "GLWorldViewer.h"

RotationDisplay :: RotationDisplay( AvlNode * T, DISPLAY_TYPE DT )
{
	target = T;
	display_type = DT;
	px = target->GetPosition()->x - 2*target->getRay();
	PX = target->GetPosition()->x + 2*target->getRay();
	py = target->GetPosition()->y - 2*target->getRay();
	PY = target->GetPosition()->y + 2*target->getRay();
}
void RotationDisplay :: draw( void )
{
	glEnable( GL_TEXTURE_2D );
	target->GetCanvas()->bindTexture( *( ( GLWorldViewer* ) target->GetCanvas() )->getImageByType( display_type ) );
	glBegin( GL_POLYGON );
	glTexCoord2i( 0, 0 );
	glVertex2d( target->GetPosition()->x - 2*target->getRay(), target->GetPosition()->y - 2*target->getRay());
	glTexCoord2i( 1, 0 );
	glVertex2d( target->GetPosition()->x + 2*target->getRay(), target->GetPosition()->y - 2*target->getRay() );
	glTexCoord2i( 1, 1 );
	glVertex2d( target->GetPosition()->x + 2*target->getRay(), target->GetPosition()->y + 2*target->getRay() );
	glTexCoord2i( 0, 1 );
	glVertex2d( target->GetPosition()->x - 2*target->getRay(), target->GetPosition()->y + 2*target->getRay() );
	glEnd();
	glDisable( GL_TEXTURE_2D );
}