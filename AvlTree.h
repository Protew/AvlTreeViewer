/*
 *  AvlTree.h
 *  AVL_Tree_View_1
 *
 *  Created by PRoTeW on 31/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef AVLTREE_H
#define AVLTREE_H

#include "AvlNode.h"
#include "RotationDisplay.h"
#include <vector>
#include <cstdlib>
#include <unistd.h>

class AvlTree
{
	AvlNode		*root;
	QGLWidget	*canvas;
	VEC2		*base_position;
	double		node_ray;
	//
	std::vector<RotationDisplay*> rotations;
public:
	AvlTree( QGLWidget *, VEC2 *, double );
	//GETS
	void markCollided( AvlNode * node, VEC2 * touch );
	std::vector<RotationDisplay*> GetRotationDisplayList( void );
	void clearRotationDisplayList( void );
	void arrange( AvlNode *, int );
	int countNodes( AvlNode * );
	AvlNode * MakeEmpty( AvlNode * );
	AvlNode * Find( int, AvlNode * );
	AvlNode * FindMin( AvlNode * );
	AvlNode * FindMax( AvlNode * );
	AvlNode * getRoot( void );
	void setRoot( AvlNode * );
	AvlNode * Insert( int, AvlNode * );
	AvlNode * Delete( int, AvlNode * );
	static int Height( AvlNode * );
	static int Max( int, int );
	AvlNode * SingleLeftRotation( AvlNode * );
	AvlNode * SingleRightRotation( AvlNode * );
	AvlNode * DoubleLeftRotation( AvlNode * );
	AvlNode * DoubleRightRotation( AvlNode * );
	void drawNodes( AvlNode * );
	void drawLinks( AvlNode * );
	void draw( void );
	~AvlTree( void );
};

#endif 
