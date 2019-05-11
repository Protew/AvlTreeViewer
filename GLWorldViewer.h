/*
 *  GLWorldViewer.h
 *  3DChallenge
 *
 *  Created by PRoTeW on 13/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GLWORLDVIEWER_H
#define GLWORLDVIEWER_H

#include "AvlTree.h"
#include <QGLWidget>
#include <QMouseEvent>
#include <QKeyEvent>

class GLWorldViewer : public QGLWidget {
	
	Q_OBJECT
	
	AvlTree * tree;
	double node_ray;
	//
	bool quick_active;
	bool follow_active;
	//
	double xview;
	double yview;
	double width;
	double height;
	//
	//IMAGES
	//
	QImage * img_left_rot;
	QImage * img_right_rot;
	QImage * img_find;
	QImage * img_already;
	//
	public slots:
	void quickActive( int );
	void followActive( int );
	void setNodeRay( int );
	void Insert( int );
	void Find( int );
	void Delete( int );
	void ClearAll( void );

public: 
	GLWorldViewer( QWidget *, double, double );
	//GETS
	bool isQuick( void );
	bool isFollowing( void );
	double getNodeRay( void );
	//
	void createImages( void );
	QImage * getImageByType( DISPLAY_TYPE );
	//
	void projection( double, double );
	void drawTemporary( void );
	//
	void mousePress( int, int, int ); 
	void mouseMotion( int, int );
	//
	VEC2* QTtoOpenGL( VEC2* );
	VEC2* OpenGltoBox2d( VEC2* );
	//
	void mouseAction( QMouseEvent * );
	
protected: 
	void initializeGL( void ); 
	void resizeGL( int, int ); 
	void paintGL( void ); 
	void keyPressEvent( QKeyEvent * );
	void mousePressEvent( QMouseEvent * ); 
	void mouseMoveEvent( QMouseEvent * ); 
	void mouseReleaseEvent( QMouseEvent * );
	//void mouseDoubleClickEvent(QMouseEvent *);
	void initComponents( void );
};

#endif