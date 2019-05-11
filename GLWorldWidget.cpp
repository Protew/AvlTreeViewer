/*
 *  GLWorldWidget.cpp
 *  3DChallenge
 *
 *  Created by PRoTeW on 13/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "GLWorldWidget.h"

GLWorldWidget :: GLWorldWidget( QWidget * parent )
:QWidget( parent )
{
	aleatory_value = true;
	initComponents();
	///setMinimumSize( 1200, 600 );
	//setFixedSize( sizeHint().width(), sizeHint().height() );
}
//SLOTS
void GLWorldWidget :: randomActive( int value )
{
	aleatory_value = !aleatory_value;
	if( aleatory_value )
	{
		value = rand() % 100;
		char str_value[100];
		sprintf( str_value, "%d", value );
		te_value->setText( str_value );
	}
	else
		te_value->setText( "0" );
}
void GLWorldWidget :: btnInsertClicked( void )
{
	int value = atoi( te_value->text().toStdString().c_str() );
	if( aleatory_value )
	{
		int value = rand() % 100;
		char str_value[100];
		sprintf( str_value, "%d", value );
		te_value->setText( str_value );
	}
	emit insertOnTree( value );
}
void GLWorldWidget :: btnFindClicked( void )
{
	int value = atoi( te_value->text().toStdString().c_str() );
	if( aleatory_value )
	{
		int value = rand() % 100;
		char str_value[100];
		sprintf( str_value, "%d", value );
		te_value->setText( str_value );
	}
	emit findOnTree( value );
}
void GLWorldWidget :: btnDeleteClicked( void )
{
	int value = atoi( te_value->text().toStdString().c_str() );
	if( aleatory_value )
	{
		int value = rand() % 100;
		char str_value[100];
		sprintf( str_value, "%d", value );
		te_value->setText( str_value );
	}
	emit deleteOnTree( value );
}
void GLWorldWidget :: initComponents()
{
	//WORLD VIEWER
    world_viewer	= new GLWorldViewer( this, 1100, 600 );
	connect( this, SIGNAL( insertOnTree( int ) ), world_viewer, SLOT( Insert( int ) ) );
	connect( this, SIGNAL( findOnTree( int ) ), world_viewer, SLOT( Find( int ) ) );
	connect( this, SIGNAL( deleteOnTree( int ) ), world_viewer, SLOT( Delete( int ) ) );
	//
	//BUTTONS LAYOUT
	buttons_layout	= new QVBoxLayout;
	//LABEL VALUE CHOOSEN
	lbl_value = new QLabel( "none" );
	buttons_layout->addWidget( lbl_value );
	//NODE RAY SLIDER
	sld_node_ray = new QSlider;
	sld_node_ray->setMinimum( 1 );
	sld_node_ray->setMaximum( 200 );
	sld_node_ray->setValue( 20 );
	connect( sld_node_ray, SIGNAL( valueChanged( int ) ), world_viewer, SLOT( setNodeRay( int ) ) );
	buttons_layout->addWidget( sld_node_ray );
	//TEXT EDIT VALUE SETTER
	te_value = new QLineEdit;
	buttons_layout->addWidget( te_value );
	//RANDOM OPTION
	cb_option_random = new QCheckBox("Random");
	cb_option_random->setChecked( true );
	connect( cb_option_random, SIGNAL( stateChanged( int ) ), this, SLOT( randomActive( int ) ) );
	buttons_layout->addWidget( cb_option_random );
	//QUICK OPTION
	cb_option_quick = new QCheckBox("Quick");
	cb_option_quick->setChecked( true );
	connect( cb_option_quick, SIGNAL( stateChanged( int ) ), world_viewer, SLOT( quickActive( int ) ) );
	buttons_layout->addWidget( cb_option_quick );
	//QUICK OPTION
	cb_option_follow = new QCheckBox("Follow");
	cb_option_follow->setChecked( true );
	connect( cb_option_follow, SIGNAL( stateChanged( int ) ), world_viewer, SLOT( followActive( int ) ) );
	buttons_layout->addWidget( cb_option_follow );
	//PUSH BUTTON INSERT
	btn_insert = new QPushButton( tr( "&INSERT") );
	btn_insert->setToolTip("INSERT NODE ESPECIFIED");
	connect( btn_insert, SIGNAL( clicked() ), this, SLOT( btnInsertClicked() ) );
	buttons_layout->addWidget( btn_insert );
	//PUSH BUTTON FIND
	btn_find = new QPushButton("FIND");
	btn_find->setToolTip("FIND NODE ESPECIFIED");
	connect( btn_find, SIGNAL( clicked() ), this, SLOT( btnFindClicked() ) );
	buttons_layout->addWidget( btn_find );
	//PUSH BUTTON DELETE
	btn_delete = new QPushButton("DELETE");
	btn_delete->setToolTip("DELETE NODE ESPECIFIED");
	connect( btn_delete, SIGNAL( clicked() ), this, SLOT( btnDeleteClicked() ) );
	buttons_layout->addWidget( btn_delete );
	//PUSH BUTTON CLEAR
	btn_clear = new QPushButton("CLEAR");
	btn_clear->setToolTip("CLEAR ALL");
	connect( btn_clear, SIGNAL( clicked() ), world_viewer, SLOT( ClearAll() ) );
	buttons_layout->addWidget( btn_clear );
	//
	//MAIN LAYOUT
	main_layout		= new QHBoxLayout;
	main_layout->addLayout( buttons_layout );
	main_layout->addWidget( world_viewer );
	this->setLayout( main_layout );
}

