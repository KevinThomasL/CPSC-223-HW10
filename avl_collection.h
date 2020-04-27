
//----------------------------------------------------------------------
// Author: ...
// Course: CPSC 223, Spring 2020
// Assign: 10
// File:   avl_collection.h
// ...
//----------------------------------------------------------------------


#ifndef AVL_COLLECTION_H
#define AVL_COLLECTION_H

#include <vector>
#include <algorithm>
#include <string>               // for testing
#include "collection.h"


template<typename K, typename V>
class AVLCollection : public Collection<K,V>
{
public:

  // create an empty tree
  AVLCollection();
  
  // tree copy constructor
  AVLCollection(const AVLCollection<K,V>& rhs);

  // tree assignment operator
  AVLCollection<K,V>& operator=(const AVLCollection<K,V>& rhs);

  // delete a tree
  ~AVLCollection();
  
  // add a new key-value pair into the collection 
  void add(const K& a_key, const V& a_val);

  // remove a key-value pair from the collectiona
  void remove(const K& a_key);

  // find and return the value associated with the key
  bool find(const K& search_key, V& the_val) const;

  // find and return the values with keys >= to k1 and <= to k2 
  void find(const K& k1, const K& k2, std::vector<V>& vals) const;
  
  // return all of the keys in the collection 
  void keys(std::vector<K>& all_keys) const;

  // return all of the keys in ascending (sorted) order
  void sort(std::vector<K>& all_keys_sorted) const;

  // return the number of key-value pairs in the collection
  int size() const;

  // return the height of the tree
  int height() const;
  
private:
  
  // avl tree node structure
  struct Node {
    K key;
    V value;
    int height;
    Node* left;
    Node* right;
  };

  // helper to empty entire tree
  void make_empty(Node* subtree_root);
  
  // helper to build sorted list of keys (used by keys and sort)
  void inorder(const Node* subtree_root, std::vector<K>& keys) const;

  // helper to recursively find range of keys
  void range_search(const Node* subtree_root, const K& k1, const K& k2,
                    std::vector<V>& keys) const;

  // recursively (deep) copy ancestors of src to dst
  void preorder_copy(const Node* subtree_root_src, Node* subtree_root_dst);

  // helper function to remove a node recursively
  Node* remove(const K& key, Node* subtree_root);

  // recursive add helper
  Node* add(Node* subtree_root, const K& a_key, const V& a_val);
  
  // rotate right helper
  Node* rotate_right(Node* k2);

  // rotate left helper
  Node* rotate_left(Node* k2);

  // rebalance the subtree rooted at subtree_root
  Node* rebalance(Node* subtree_root);
  
  // number of k-v pairs in the collection
  int tree_size; 

  // root node of tree
  Node* root;

  // for testing only: "pretty" prints a tree with node heights
  void print_tree(std::string indent, Node* subtree_root);
};


// TODO: implement the above functions here ...


// NOTE: some examples given below ...


// to see how height should work
template<typename K, typename V> 
int AVLCollection<K,V>::height() const
{
  if (!root)
    return 0;
  return root->height;
}


// from class
template<typename K, typename V>
typename AVLCollection<K,V>::Node*
AVLCollection<K,V>::rotate_right(Node* k2)
{
  // fill in here
}

// from class
template<typename K, typename V>
typename AVLCollection<K,V>::Node*
AVLCollection<K,V>::rotate_left(Node* k2)
{
  // fill in here
}

template<typename K, typename V>
void AVLCollection<K,V>::add(const K& a_key, const V& a_val)
{
  // to build in the height and rebalance, this must be a recursive
  // function!
  root = add(root, a_key, a_val);
  // print_tree("", root); // for debugging
}

template<typename K, typename V>
typename AVLCollection<K,V>::Node*
AVLCollection<K,V>::rebalance(Node* subtree_root)
{
  // fill in here
}

template<typename K, typename V>
typename AVLCollection<K,V>::Node*
AVLCollection<K,V>::add(Node* subtree_root, const K& a_key, const V& a_val)
{
  // fill in here
}  


template <typename K, typename V>
void AVLCollection<K,V>::remove(const K& a_key)
{
  root = remove(a_key, root);
  // print_tree("", root); // for debugging
}

template <typename K, typename V>
typename AVLCollection<K,V>::Node*
AVLCollection<K,V>::remove(const K& key, Node* subtree_root)
{
  // fill in here
}

template<typename K, typename V>
void AVLCollection<K,V>::print_tree(std::string indent, Node* subtree_root)
{
  if (!subtree_root)
    return;
  std::cout << indent << subtree_root->key << " (h="
            << subtree_root->height << ")" << std::endl;
  print_tree(indent + "  ", subtree_root->left);
  print_tree(indent + "  ", subtree_root->right);
}


#endif
