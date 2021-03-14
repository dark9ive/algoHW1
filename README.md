# algoHW1

AVL Tree  
Code is not completed, hopefully it can shows the algorithm correctly.

## functions explanation

### insertion

insertion(int) insert an int under a tree node.  
Check every passed node after insertion since they all have a chance to be rebalanced.  
Time complexity = O(logN), because the average height is about logN.  

### deletion

deletion(int) search and delete an int under a node.  
Do Right rotation and/or Left retation until target node becomes a leaf node.  
After that, you have to call delete\_balance to rebalance passed nodes.  
Similarly to insertion, time complexity = O(logN), because the average height is about logN.  

### check\_balance

check\_balance() checks if the node itself needs to be rebalanced.  
If true, call balance() to determine which rotation method (R, L , RL, LR) does it need.  

### RRotate / LRotate (not implement)

Should be doing Right/Left Rotation, which rotates itself one level higher, and put its Right/Left child to previous parent's Left/Right child.  
May have to handle the height variables, since it changes the structure.  
Not currently inplemented in this code.  

### main

Nothing here(currently), you may fill with some Tree initialize or other testing functions.  
