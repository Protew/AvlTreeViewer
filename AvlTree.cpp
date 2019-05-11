/*
 *  AvlTree.cpp
 *  AVL_Tree_View_1
 *
 *  Created by PRoTeW on 31/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "AvlTree.h"
#include "GLWorldViewer.h"

AvlTree :: AvlTree( QGLWidget * canvas, VEC2 * base_position, double node_ray )
{
    srand( time( nullptr ) );
    this->base_position = base_position;
    this->canvas = canvas;
    root = nullptr;
    this->node_ray = node_ray;
}
void AvlTree :: markCollided( AvlNode * node, VEC2 * touch )
{
	if( node ){
		markCollided( node->left, touch );
		markCollided( node->right, touch );
		
		if( node->collidesWith( touch ) )
		{
			//node->setSelected( !node->isSelected() );
			rotations.clear();
			root = Delete( node->value, root );
			arrange( root, 0 );
			std::cout << countNodes(root) << std::endl;
			return;
		}
	}
}
//GETS
std::vector<RotationDisplay*> AvlTree :: GetRotationDisplayList( void )
{
	return rotations;
}
void AvlTree :: clearRotationDisplayList( void )
{
	rotations.clear();
}
void AvlTree :: arrange( AvlNode * node, int side )
{
	if( node ){
		node->SetRGB( 0.0, 1.0, 0.0 );
		if( side == 2 )
		{
			VEC2 * node_position = new VEC2;
			VEC2 * parent_position = node->node_parent->GetPosition();
			node_position->x = parent_position->x - pow( 2, Height( node->node_parent ) ) * (node_ray/2);
			node_position->y = parent_position->y - 5 * node_ray;
			node->SetPosition( node_position );
		}
		else if( side == 1 )
		{
			VEC2 * node_position = new VEC2;
			VEC2 * parent_position = node->node_parent->GetPosition();
			node_position->x = parent_position->x + pow( 2, Height( node->node_parent ) ) * (node_ray/2);
			node_position->y = parent_position->y - 5 * node_ray;
			node->SetPosition( node_position );
		}
        else if( node->node_parent == nullptr )
		{
			node->SetPosition( base_position );
		}
		arrange( node->right, 1 );
		arrange( node->left, 2 );
	}
}
//GETS
void AvlTree :: setRoot( AvlNode * node )
{
	root = node;
}
AvlNode * AvlTree :: getRoot( void )
{
	return root;
}
int AvlTree :: countNodes( AvlNode * node ){
    if( node )
        return 1 + countNodes( node->left ) + countNodes( node->right );
	else
        return 0;
}
AvlNode * AvlTree :: MakeEmpty( AvlNode * node )
{
	if( node )
	{
		MakeEmpty( node->left );
		MakeEmpty( node->right );
		free( node );
	}
    return nullptr;
}
AvlNode * AvlTree :: Find( int value, AvlNode * node )
{
	if( !( ( GLWorldViewer * ) canvas )->isQuick() )
        sleep( 1 );
    if( node == nullptr )
        return nullptr;
	else
	{
		if( ( ( GLWorldViewer * ) canvas )->isFollowing() )
			( ( GLWorldViewer * ) canvas )->projection( node->GetPosition()->x, node->GetPosition()->y );
		node->SetRGB( 1, 0, 0 );
	}
	( ( GLWorldViewer * ) canvas )->updateGL();
	if( value < node->value )
	{
		if( node->left )
			( ( GLWorldViewer * ) canvas )->projection( node->left->GetPosition()->x, node->left->GetPosition()->y );
		return Find( value, node->left );
	}
	else if( value > node->value )
	{
		if( node->right )
			( ( GLWorldViewer * ) canvas )->projection( node->right->GetPosition()->x, node->right->GetPosition()->y );
		return Find( value, node->right );
	}
	else
	{
		RotationDisplay * find = new RotationDisplay( node, FIND );
		rotations.push_back( find );
		return node;
	}
}
AvlNode * AvlTree :: FindMin( AvlNode * node )
{
	if( node )
	{
		if( node->left )
			return FindMin( node->left );
		else
			return node;
	}
	else
        return nullptr;
}
AvlNode * AvlTree :: FindMax( AvlNode * node )
{
	if( node )
	{
		if( node->right )
		{
			return FindMax( node->right );
		}
		else
			return node;
	}
	else
        return nullptr;
}
int AvlTree :: Height( AvlNode * node )
{
	if( node )
		return node->height;
	return -1;
}
int AvlTree :: Max( int left, int right )
{
	return left > right ? left : right;
}
AvlNode * AvlTree :: SingleLeftRotation( AvlNode * target )
{
	std::cout << "\nSL" << std::endl;
	RotationDisplay * rotation = new RotationDisplay( target, RIGHT_ROT );
	rotations.push_back( rotation );
	
	AvlNode * auxiliar;
	
	//1
	auxiliar = target->left;
	//2
	target->left = auxiliar->right;
	if( auxiliar->right )
		auxiliar->right->node_parent = target;
	auxiliar->node_parent = target->node_parent;
	
	//3
	auxiliar->right = target;
	target->node_parent = auxiliar;
	
	target->height		= Max( Height( target->left ), Height( target->right ) ) + 1;
	auxiliar->height	= Max( Height( auxiliar->left ), target->height ) + 1;
	
	return auxiliar;
}
AvlNode * AvlTree :: SingleRightRotation( AvlNode * target )
{
	std::cout << "\nSR" << std::endl;
	RotationDisplay * rotation = new RotationDisplay( target, LEFT_ROT );
	rotations.push_back( rotation );
	
	AvlNode * auxiliar;
	
	//1
	auxiliar = target->right;
	
	//2
	target->right = auxiliar->left;
	if( auxiliar->left )
		auxiliar->left->node_parent = target;
	auxiliar->node_parent = target->node_parent;
	
	//3
	auxiliar->left = target;
	target->node_parent = auxiliar;
	
	target->height		= Max( Height( target->left ), Height( target->right ) ) + 1;
	auxiliar->height	= Max( Height( auxiliar->right ), target->height ) + 1;
	
	return auxiliar;  /* New root */
}
AvlNode * AvlTree :: DoubleLeftRotation( AvlNode * left_target )
{
	std::cout << "DL" << std::endl;
	left_target->left = SingleRightRotation( left_target->left );
	return SingleLeftRotation( left_target );
}
AvlNode * AvlTree :: DoubleRightRotation( AvlNode * right_target )
{
	std::cout << "DR" << std::endl;
	right_target->right = SingleLeftRotation( right_target->right );
	return SingleRightRotation( right_target );
}
AvlNode * AvlTree :: Insert( int value, AvlNode * node )
{
	if( !( ( GLWorldViewer * ) canvas )->isQuick() )
		sleep( 1 );
	//getchar();
	if( node )
	{
		if( ( ( GLWorldViewer * ) canvas )->isFollowing() )
			( ( GLWorldViewer * ) canvas )->projection( node->GetPosition()->x, node->GetPosition()->y );
		node->SetRGB( 1.0, 0.0, 0.0 );
		( ( GLWorldViewer * ) canvas )->updateGL();
		if( value < node->value )
		{
			node->left = Insert( value, node->left );
			node->left->node_parent = node;
			if( Height( node->left ) - Height( node->right ) == 2 )
				if( value < node->left->value )
					node = SingleLeftRotation( node );
				else
					node = DoubleLeftRotation( node );
		}
		else if( value > node->value )
		{
			node->right = Insert( value, node->right );
			node->right->node_parent = node;
			if( Height( node->right ) - Height( node->left ) == 2 )
				if( value > node->right->value )
					node = SingleRightRotation( node );
				else
					node = DoubleRightRotation( node );
		}
		else {
			RotationDisplay * rotation = new RotationDisplay( node, FIND );
			rotations.push_back( rotation );
		}

	}
	else
	{
		node = new AvlNode( canvas, value, node_ray, base_position );
		if( node )
		{
			node->value = value; 
			node->height = 0;
            node->left = node->right = NULL;
		}
	}
	/* Else value is in the tree already; we'll do nothing */
	node->height = Max( Height( node->left ), Height( node->right ) ) + 1;
	return node;
}
AvlNode * AvlTree :: Delete( int value, AvlNode * node  )
{
	if( !( ( GLWorldViewer * ) canvas )->isQuick() )
		sleep( 1 );
	//getchar();
	if( node )
	{
		if( ( ( GLWorldViewer * ) canvas )->isFollowing() )
			( ( GLWorldViewer * ) canvas )->projection( node->GetPosition()->x, node->GetPosition()->y );
		node->SetRGB( 1.0, 0.0, 0.0 );
		( ( GLWorldViewer * ) canvas )->updateGL();
		if( value < node->value )
		{
			node->left = Delete( value, node->left );
			
			if( Height( node->right ) - Height( node->left ) >= 2 )
				if( node->right->value > FindMin( node->right )->value  )
					node = DoubleRightRotation( node );
				else
					node = SingleRightRotation( node );
		}
		else if( value > node->value )
		{
			node->right = Delete( value, node->right );
			
			if( Height( node->left ) - Height( node->right ) >= 2 )
				if( node->left->value < FindMax( node->left )->value  )
					node = DoubleLeftRotation( node );
				else
					node = SingleLeftRotation( node );
		}
		else {
			//SE TEM OS DOIS FILHOS
			if( node->left && node->right )
			{
				// ESCOLHE FILHO COM MAIOR ALTURA
				//ALTURAS IGUAIS E ESQUERDO
				if( Height( node->left ) >= Height( node->right ) )
				{
					AvlNode * substitute = FindMax( node->left );
					if( substitute == node->left )
					{
						node->right->node_parent = substitute;
						substitute->right = node->right;
					}
					else {
						root = Delete( substitute->value, root );
						if( substitute->left )
							substitute->left->node_parent = substitute->node_parent;
						substitute->node_parent->right = substitute->left;
						node->right->node_parent = substitute;
						substitute->right = node->right;
						node->left->node_parent = substitute;
						substitute->left = node->left;
					}
					substitute->node_parent = node->node_parent;
					node = substitute;
				}
				//DIREITO
				else if( Height( node->right ) > Height( node->left ) )
				{
					AvlNode * substitute = FindMin( node->right );
					if( substitute == node->right )
					{
						node->left->node_parent = substitute;
						substitute->left = node->left;
						
					}
					else {
						root = Delete( substitute->value, root );
						if( substitute->right )
							substitute->right->node_parent = substitute->node_parent;
						substitute->node_parent->left = substitute->right;
						node->left->node_parent = substitute;
						substitute->left = node->left;
						node->right->node_parent = substitute;
						substitute->right = node->right;
					}
					substitute->node_parent = node->node_parent;
					node = substitute;
				}
			}
			//SE TEM APENAS O FILHO ESQUERDO
			else if( node->left )
			{
				node->left->node_parent = node->node_parent;
				node = node->left;
			}
			//SE TEM APENAS O FILHO DIREITO
			else if( node->right )
			{
				node->right->node_parent = node->node_parent;
				node = node->right;
			}
			//SE NAO TEM FILHOS
			else
			{
                node = nullptr;
			}
		}
	}
	if( node )
		node->height = Max( Height( node->left ), Height( node->right ) ) + 1;
	return node;
}
void AvlTree :: drawNodes( AvlNode * node )
{
    if( node != nullptr ){
		drawNodes( node->left );
		node->draw();
		drawNodes( node->right );
	}
}
void AvlTree :: drawLinks( AvlNode * node )
{
    if( node != nullptr ){
		drawLinks( node->left );
		if( node->node_parent )
		{
			glLineWidth( 5 );
			glColor4f( 1, 1, 1, 1 );
			glBegin( GL_LINES );
			glVertex2f( node->GetPosition()->x, node->GetPosition()->y );
			glVertex2f( node->node_parent->GetPosition()->x, node->node_parent->GetPosition()->y );
			glEnd();
			glLineWidth( 1 );
		}
		drawLinks( node->right );
	}
}
void AvlTree :: draw( void )
{
	if( root )
	{
        drawNodes( root );
        drawLinks( root );
	}
}
AvlTree :: ~AvlTree( void )
{
	MakeEmpty( root );
}
