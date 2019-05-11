/*
 *  GLWorldViewer.cpp
 *  3DChallenge
 *
 *  Created by PRoTeW on 13/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "GLWorldViewer.h"
#include "GLWorldWidget.h"

VEC2* GLWorldViewer ::QTtoOpenGL( VEC2* coord )
{
	//TRANSFORMA COORD QT -> OPENGL
	double wx = coord->x;
	double vxmax = (double) xview + width;
	double vxmin = (double) xview;
	double wxmax = (double) width;
	double wxmin = (double) 0;
	//
	double wy = coord->y;
	double vymax = (double) yview;
	double vymin = (double) yview + height;
	double wymax = (double) height;
	double wymin = (double) 0;
	
	VEC2 *result = new VEC2;
	result->x = ( ( vxmax - vxmin )/( wxmax - wxmin ) ) * ( wx - wxmin ) + vxmin;
	result->y = ( ( vymax - vymin )/( wymax - wymin ) ) * ( wy - wymin ) + vymin;
	return result;
}
GLWorldViewer :: GLWorldViewer( QWidget *parent, double W, double H ) 
: QGLWidget( parent )
{	
	node_ray = 20;
	
	width = W;
	height = H;
	
	quick_active = true;
	follow_active = true;
	
	xview = yview = 1000 * node_ray;
	
	setFormat( QGLFormat( QGL::DoubleBuffer | QGL::DepthBuffer ) );
	setFixedSize( width, height );
	//
	createImages();
	setFocus();
}
void GLWorldViewer :: createImages( void )
{
    img_left_rot	= new QImage( ":/images/left_rotation.png" );
    img_right_rot	= new QImage( ":/images/right_rotation.png" );
    img_find		= new QImage( ":/images/find.png" );
    img_already		= new QImage( ":/images/already.png" );
}
QImage * GLWorldViewer :: getImageByType( DISPLAY_TYPE display_type )
{
	switch ( display_type ) {
		case LEFT_ROT:
			return img_left_rot;
		case RIGHT_ROT:
			return img_right_rot;
		case FIND:
			return img_find;
		case ALREADY:
			return img_already;
	}
    return nullptr;
}
double GLWorldViewer :: getNodeRay( void )
{
	return node_ray;
}
bool GLWorldViewer :: isFollowing( void )
{
	return follow_active;
}
//SLOTS
void GLWorldViewer :: quickActive( int )
{
	quick_active = !quick_active;
	setFocus();
}
void GLWorldViewer :: followActive( int )
{
	follow_active = !follow_active;
	setFocus();
}
void GLWorldViewer :: setNodeRay( int value )
{
	node_ray = value;
	tree->arrange( tree->getRoot(), 0 );
	updateGL();
	setFocus();
}
void GLWorldViewer :: Insert( int value )
{
	tree->clearRotationDisplayList();
	tree->setRoot( tree->Insert( value, tree->getRoot() ) );
	tree->arrange( tree->getRoot(), 0 );
	updateGL();
	setFocus();
}
void GLWorldViewer :: Find( int value )
{
	tree->clearRotationDisplayList();
	tree->Find( value, tree->getRoot() );
	tree->arrange( tree->getRoot(), 0 );
	updateGL();
	setFocus();
}
void GLWorldViewer :: Delete( int value )
{
	tree->clearRotationDisplayList();
	tree->setRoot( tree->Delete( value, tree->getRoot() ) );
	tree->arrange( tree->getRoot(), 0 );
	updateGL();
	setFocus();
	std::cout << tree->countNodes( tree->getRoot() ) << std::endl;
}
void GLWorldViewer :: ClearAll( void )
{
	tree->clearRotationDisplayList();
	VEC2 *base_position = new VEC2;
	base_position->x = 1000 * node_ray + width/2;
	base_position->y = ( 1000 * node_ray + height/2 );
	
	tree = new AvlTree( this, base_position, node_ray );
	updateGL();
	setFocus();
}
bool GLWorldViewer :: isQuick( void )
{
	return quick_active;
}
void GLWorldViewer :: initializeGL( void )
{
	//PRERROGATIVAS OPENGL
	
	glViewport( 0, 0, width, height );
	
	glMatrixMode ( GL_PROJECTION );
	glLoadIdentity ();
	
	gluOrtho2D( xview, xview + width, yview, yview + height );
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glShadeModel (GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);                 
	glEnable(GL_NORMALIZE);
	glEnable( GL_TEXTURE_2D );
	glEnable(GL_COLOR_MATERIAL);
	
	glShadeModel (GL_SMOOTH);
	
	VEC2 *base_position = new VEC2;
	base_position->x = 1000 * node_ray + width/2;
	base_position->y = ( 1000 * node_ray + height/2 );
	
	tree = new AvlTree( this, base_position, node_ray );
	//value = rand() % 100;
}
void GLWorldViewer :: resizeGL( int w, int h )
{
	width = w;
	height = h;
	
	glViewport( 0, 0, width, height );
	
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	
	gluOrtho2D( xview, xview + width, yview, yview + height );
	
	glMatrixMode ( GL_MODELVIEW );
	glLoadIdentity ();
}
VEC2* circlePoint( float angle, VEC2 *center, float ray )
{
	VEC2 * result;
    result->x = cos( angle ) * ray + center->x;
	result->y = sin( angle ) * ray + center->y;
	return result;
}
/*
 std::list<RotationDisplay*>::iterator rot_it;
 for ( object_it = objects.begin(); object_it != objects.end(); object_it++ )
 {
 if( ( ( Object* ) *object_it )->getFixture()->TestPoint( point ) )
 {
 std::cout << "ACERTOU :" << typeid(**object_it).name() << std::endl;
 return ( ( Object* ) *object_it );
 }
 }*/
void GLWorldViewer :: paintGL() 
{
	glClearColor ( 0.5, 0.5, 0.5, 1.0);
	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
	glEnable( GL_BLEND );
	glEnable( GL_ALPHA_TEST );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	glPushMatrix();
	//
	if( tree )
		tree->draw();
	//
	for ( size_t rid = 0; rid < tree->GetRotationDisplayList().size(); rid++ )
	{
		tree->GetRotationDisplayList()[rid]->draw();
	}
	//
	glPopMatrix();
	glDisable( GL_BLEND );
}
void GLWorldViewer :: projection( double xv, double yv )
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	xview = xv - width/2;
	yview = yv - height/2;
	gluOrtho2D( xview, xview + width, yview, yview + height );
	
	glMatrixMode ( GL_MODELVIEW );
	glLoadIdentity ();
}
void GLWorldViewer :: keyPressEvent( QKeyEvent * event )
{
	switch( event->key() )
	{
			//ESC
		case 16777216:  
			exit(0);
		case 27:
			break;
		case 32:  
			break;
		case '-':
			//camera_distance += 10;
			break;
		case '=':
			//camera_distance -= 10;
			break;
		case '1': 
			//if( vehicle )
			//vehicle->crash();
			break;
		case '2': 
			break;
		case '3': 
			break;
		case '4': 
			break;
		case '5': 
			break;
		case '6': 
			break;
		case '7': 
			break;
		case '8': 
			break;
		case '9': 
			break;
		case '0': 
			break;
		case 'a':
		case 'A': 
			//addBase();
			break;
		case 'b':
		case 'B': 
			break;
		case 'c':
		case 'C': 
			break;
		case 'd':
		case 'D': 
			tree->clearRotationDisplayList();
			if( tree->getRoot() )
				tree->setRoot( tree->Delete( tree->getRoot()->value, tree->getRoot() ) );
			tree->arrange( tree->getRoot(), 0 );
			updateGL();
			break;
		case 'e':
		case 'E': 
			break;
		case 'f':
		case 'F': 
			for( int i = 0; i <= 100; i++ )
				Insert( i );
			break;
		case 'g':
		case 'G':
			break;
		case 'h':
		case 'H':
			break;
		case 'i':
		case 'I':
			break;
		case 'j':
		case 'J':
			break;
		case 'k':
		case 'K':
			break;
		case 'l':
		case 'L':
			break;
		case 'm':
		case 'M':
			break;
		case 'n':
		case 'N':
			break;
		case 'o':
		case 'O':
			break;
		case 'p':
		case 'P':
			break;
		case 'q':
		case 'Q':
			break;
		case 'r':
		case 'R':
			break;
		case 's':
		case 'S':
			break;
		case 't':
		case 'T':
			break;
		case 'u':
		case 'U':
			break;
		case 'v':
		case 'V':
			break;
		case 'w':
		case 'W':
			break;
		case 'x':
		case 'X':
			break;
		case 'y':
		case 'Y':
			break;
		case 'z':
		case 'Z':
			break;
			//RIGHT
		case 16777236:
			projection( (xview + 10) + width/2, yview + height/2 );
			break;
			//LEFT
		case 16777234:
			projection( ( xview - 10 ) + width/2, yview + height/2 );
			break;
			//UP
		case 16777235:
			projection( xview + width/2, ( yview + 10 ) + height/2 );
			break;
			//DOWN
		case 16777237:
			projection( xview + width/2, ( yview - 10 ) + height/2 );
			break;
	}
	updateGL();
}

void GLWorldViewer :: mouseAction( QMouseEvent * event ) 
{
	event->accept();
	updateGL();
}

void GLWorldViewer :: mousePressEvent( QMouseEvent * event ) 
{
	//quick_active = true;
	VEC2 * touch = new VEC2;
	touch->x = event->x();
	touch->y = event->y();
	
	tree->markCollided( tree->getRoot(), QTtoOpenGL( touch ) );
	
	updateGL();
} 
void GLWorldViewer :: mouseMoveEvent( QMouseEvent * event ) 
{
	event->accept();
	updateGL();
} 
void GLWorldViewer :: mouseReleaseEvent( QMouseEvent * event )
{
	event->accept();
	updateGL();
}
