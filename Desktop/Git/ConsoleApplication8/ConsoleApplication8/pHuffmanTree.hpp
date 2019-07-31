#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include<assert.h>
#include<queue>
#include<vector>
#include<string>



//HuffmanTree的节点构造


template<class W>
//W是模板参数
//类模板Stack
struct HuffmanTreeNode
{
	HuffmanTreeNode<W>* _root;
	//模板的
	HuffmanTreeNode<W>* _left;
	HuffmanTreeNode<W>* _right;
	W _w;
	HuffmanTreeNode(const W& w)
		:_root(NULL)
		, _left(NULL)
		, _right(NULL)
		, _w(w)
	{}

};

template<class W>
class HuffmanTree
{
	typedef HuffmanTreeNode<W> Node;
public:
	HuffmanTree()
		:_root(NULL)
	{}
	struct NodeCompare
	{
		bool operator()(const Node* left, const Node* right)
		{
			return left->_w > right->_w;
		}

	};
	HuffmanTree(W* w, size_t n, const W& invalid)
	{
		//构建Huffman树优先级队列
		priority_queue<Node*, vector<Node*>, NodeCompare> minheap;
		for (size_t i = 0; i < n; ++i)
		{
			if (w[i] != invalid)
			{
				minheap.push(new Node(w[i]));
			}
		}
		while (minheap.size()>1)
		{
			Node* left = minheap.top();
			minheap.pop();
			Node* right = minheap.top();
			minheap.pop();
			Node* parent = new Node(left->_w + right->_w);
			parent->_left = left;
			parent->_right = right;
			minheap.push(parent);
		}
		_root = minheap.top();
	}
	~HuffmanTree()
	{
		Destory(_root);
		_root = NULL;
	}
	void Destory(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}
	Node* GetRoot()
	{
		return _root;
	}
private://防拷贝
	HuffmanTree(const HuffmanTree<W>& w)
	{}
	HuffmanTree<W>& operator=(const HuffmanTree<W>& w)
	{}

private:
	Node* _root;
};
