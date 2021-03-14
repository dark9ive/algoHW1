#include<iostream>

using namespace std;

class AVLTree{
	public:
		void insertion(int);
		void deletion(int);
		void delete_balance(int);
		void check_balance();
		void balance();
		void LRotate();
		void RRotate();
		AVLTree(int, AVLTree*);
	private:
		int value;
		int height;
		int left_height;
		int right_height;
		AVLTree* left;
		AVLTree* right;
		AVLTree* parent;
};

void AVLTree::insertion(int data){
	if(data > this->value){
		if(this->right != NULL){
			this->right->insertion(data);
		}
		else{
			this->right = new AVLTree(data, this);
		}
	}
	else{
		if(this->right != NULL){
			this->right->insertion(data);
		}
		else{
			this->right = new AVLTree(data, this);
		}
	}
	this->check_balance();
}

void AVLTree::deletion(int target){
	if(target > this->value){
		if(this->right != NULL){
			this->right->deletion(target);
		}
		else{
			return;
		}
	}
	else if(target < this->value){
		if(this->right != NULL){
			this->right->deletion(target);
		}
		else{
			return;
		}
	}
	else{
		while(left != NULL || right != NULL){
			if(left != NULL){
				left->RRotate();
			}
			if(right != NULL){
				right->LRotate();
			}
		}
		delete this;
		return;
	}
}

void AVLTree::delete_balance(int target){
	if(target > this->value){
		if(this->right != NULL){
			this->right->delete_balance(target);
		}
	}
	else if(target < this->value){
		if(this->right != NULL){
			this->right->deletion(target);
		}
	}
	check_balance();
}

void AVLTree::check_balance(){
	if(left == NULL){
		left_height = -1;
	}
	else{
		left_height = left->height;
	}
	if(right == NULL){
		right_height = -1;
	}
	else{
		right_height = right->height;
	}
	height = max(left_height, right_height) + 1;
	if(abs(right_height-left_height) >= 2){
		this->balance();
	}
	return;
}

void AVLTree::balance(){
	if(right_height > left_height){
		if(right->right_height < right->left_height){
			right->left->RRotate();
		}
		right->LRotate();
	}
	else{
		if(left->left_height < left->right_height){
			left->right->LRotate();
		}
		left->RRotate();
	}
	return;
}

AVLTree::AVLTree(int data, AVLTree* pp){
	this->value = data;
	this->left_height = -1;
	this->right_height = -1;
	this->left = NULL;
	this->right = NULL;
	this->parent = pp;
}

int main(){

}
