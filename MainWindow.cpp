/*
 *  MainWindow.cpp
 *  PDBQuickViewer_04
 *
 *  Created by PRoTeW on 26/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include <QtGui>

#include "MainWindow.h"

MainWindow :: MainWindow( QWidget * parent )
:QTabWidget( parent )
{
	initWidgets();
	setWindowTitle( tr( " AVL TREE " ) );
	//setFixedSize(sizeHint().width(), sizeHint().height());
}
void MainWindow::initWidgets( void )
{
	base_buttons_layout = new QHBoxLayout;
	
	world_widget = new GLWorldWidget( this );
	
	//
	//MAIN LAYOUT
	//
	main_layout = new QVBoxLayout;
	//base_buttons_layout->addWidget( btn_load_protein );
	main_layout->addWidget( world_widget );
	//main_layout->addLayout( base_buttons_layout );
	setLayout( main_layout );
}