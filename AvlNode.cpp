/*
 *  AvlNode.cpp
 *  AVL_Tree_View_1
 *
 *  Created by PRoTeW on 01/06/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "AvlNode.h"
#include "GLWorldViewer.h"

AvlNode :: AvlNode( QGLWidget * canvas, int value, double ray, VEC2 * position )
{	
    node_parent     = nullptr;
    this->canvas	= canvas;
    this->position	= position;
    this->ray		= ray;
    this->value		= value;
	rgb[0]		= 0.0;
	rgb[1]		= 1.0;
	rgb[2]		= 0.0;
	//
    selected = false;
}
bool AvlNode :: collidesWith( VEC2 * target )
{
	if( target->x >= this->position->x - ( ( GLWorldViewer * ) canvas )->getNodeRay() && target->x <= position->x + ( ( GLWorldViewer * ) canvas )->getNodeRay() &&
	   target->y >= this->position->y - ( ( GLWorldViewer * ) canvas )->getNodeRay()  && target->y <= position->y + ( ( GLWorldViewer * ) canvas )->getNodeRay() )
	{
		return true;
	}
	return false;
}
//GETS
bool AvlNode :: isSelected( void )
{
	return selected;
}
VEC2 * AvlNode :: GetPosition( void )
{
	return position;
}
double AvlNode :: getRay( void )
{
	return ray;
}
QGLWidget * AvlNode :: GetCanvas( void )
{
	return canvas;
}
//SETS
void AvlNode :: SetPosition( VEC2 * value )
{
	position = value;
}
void AvlNode :: SetRGB( double R, double G, double B )
{
	rgb[0] = R;
	rgb[1] = G;
	rgb[2] = B;
}
void AvlNode :: setSelected( bool value )
{
	selected = value;
}
VEC2 * AvlNode :: circlePoint( double angle, VEC2 *center, double ray )
{
	VEC2 * result = new VEC2;
	result->x = cos( angle ) * ray + center->x;
	result->y = sin( angle ) * ray + center->y;
	return result;
}
void drawstr( GLuint x, GLuint y, char* format, ... )
{
    GLvoid *font_style = GLUT_BITMAP_HELVETICA_18;
    va_list args;
    char buffer[255], *s;
    
    va_start( args, format );
    vsprintf( buffer, format, args );
    va_end( args );
    
    glRasterPos2i( x, y );
    for ( s = buffer; *s; s++ )
        glutBitmapCharacter( font_style, *s );
}
void AvlNode :: draw( void )
{
    //
    //VALUE
    glColor4f( 0, 0, 0, 1 );
    char number[20];
    sprintf( number, "%d", value );
    drawstr( position->x - 2*( ( GLWorldViewer * ) canvas )->getNodeRay()/3,  position->y - ( ( GLWorldViewer * ) canvas )->getNodeRay()/3, number );
    //
    //
    VEC2 * vertex;
    //
    //PERIMETER
    glBegin( GL_LINE_LOOP );
    for ( int i = 0; i < 359; i++) {
        vertex = circlePoint( i, position, ( ( GLWorldViewer * ) canvas )->getNodeRay() );
        glVertex2f( vertex->x, vertex->y );
    }
    glEnd();
    //INSIDE
    ( selected ) ? glColor4f( 1, 1, 0, 0.2f ) : glColor4f( rgb[0], rgb[1], rgb[2], 0.2f );
    glBegin( GL_POLYGON );
    for ( int i = 0; i < 359; i++) {
        vertex = circlePoint( i, position, ( ( GLWorldViewer * ) canvas )->getNodeRay() );
        glVertex2f( vertex->x, vertex->y );
    }
    glEnd();
    glFlush();
}
