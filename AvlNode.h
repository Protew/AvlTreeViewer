/*
 *  AvlNode.h
 *  AVL_Tree_View_1
 *
 *  Created by PRoTeW on 01/06/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef AVLNODE_H
#define AVLNODE_H

struct VEC2
{
	double x;
	double y;
};

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <QGLWidget>
#include <glut.h>


class AvlNode : public QWidget
{
	//DISPLAY
	QGLWidget		*canvas;
	GLuint			display_list;
	double			rgb[3];
	//LOGIC
	VEC2			*position;
	double			ray;
	//
	bool selected;

public:
	//TREE
	int value;
	int height;
	AvlNode			*node_parent;
	AvlNode			*left;
	AvlNode			*right;
	//
	//GETS
	bool collidesWith( VEC2 * );
	VEC2 * GetPosition( void );
	double getRay( void );
	QGLWidget * GetCanvas( void );
	bool isSelected( void );
	//SETS
	void SetPosition( VEC2 * );
	void SetRGB( double, double, double );
	void setSelected( bool );
	//
	AvlNode( QGLWidget *, int, double, VEC2 * );
    VEC2 * circlePoint( double angle, VEC2 *center, double ray );
	void draw( void );


};

#endif
