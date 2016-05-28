#include "BLinkedList.h"

BLList::BLList()
{
	this->root = NULL;

}
BLList::~BLList()
{


}


void BLList::midorder(BLNode* root)
{
	if(root->left != NULL)
	{
		midorder(root->left);
	}
	std::cout << root->data << std::endl;
	if(root->right != NULL)
	{
		midorder(root->right);
	}
}
bool BLList::print_list()
{
	if(this->root != NULL)
	{
		midorder(this->root);
	}
	return true;

}
//	virtual bool make_null();
BLNode* BLList::find(element_type data)
{
	return NULL;
}

bool BLList::insert(BLNode* root, element_type data)
{
	 if(data < root->data)
	{
		if(root->left != NULL)
		{
			insert(root->left,data);
		}
		else
		{
			BLNode* newnode = new BLNode(data);
			root->left = newnode;
			return true;
		}

	}
	else if(data > root->data)
	{
		if(root->right != NULL)
		{
			insert(root->right,data);
		}
		else
		{
			BLNode* newnode = new BLNode(data);
			root->right = newnode;
			return true;
		}
	}
	return false;
}

bool BLList::insert(element_type data)
{
	if(this->root == NULL)
	{
		BLNode* newnode = new BLNode(data);
		this->root = newnode;
	}
	else
	{
		insert(this->root,data);
	}
	return true;
}

//	virtual bool delete_key(element_type data);
//	virtual element_type delete_kth(int position);
//	virtual bool is_empty();




