/*
 *  GLWorldWidget.h
 *  3DChallenge
 *
 *  Created by PRoTeW on 15/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GLWORLDWIDGET_H
#define GLWORLDWIDGET_H

#include <QtGui> 
#include <iostream>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QSlider>

#include "GLWorldViewer.h"

class GLWorldWidget : public QWidget
{
	Q_OBJECT
	
	//BUTTONS
	QCheckBox		*	cb_option_random;
	QCheckBox		*	cb_option_quick;
	QCheckBox		*	cb_option_follow;
	QLineEdit		*	te_value;
	QLabel			*	lbl_value;
	QPushButton		*	btn_insert;
	QPushButton		*	btn_find;
	QPushButton		*	btn_delete;
	QPushButton		*	btn_clear;
	QSlider			*	sld_node_ray;
	
	bool aleatory_value;
	
	//VIEWER
	GLWorldViewer	*	world_viewer;
	
	//LAYOUTS
	QVBoxLayout		*	buttons_layout;
	QHBoxLayout		*	main_layout;

public slots:
	void btnInsertClicked( void );
	void btnFindClicked( void );
	void btnDeleteClicked( void );
	void randomActive( int );
signals:
	void insertOnTree( int );
	void findOnTree( int );
	void deleteOnTree( int );
	
public:
	GLWorldWidget( QWidget* );
	void initComponents( void );
};

#endif
