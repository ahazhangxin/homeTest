#pragma once
#include"pHuffmanTree.hpp"

typedef long long LongType;
struct CharInfo
{
	char _ch;
	LongType _count;
	string _code;
	bool operator!=(const CharInfo& info)
	{
		return _count != info._count;
	}
	CharInfo operator+(const CharInfo& info)
	{
		CharInfo ret;
		ret._count = _count + info._count;
		return ret;
	}
	bool operator>(const CharInfo& info) const
	{
		return _count > info._count;
	}
};
class FileCompress
{
	typedef HuffmanTreeNode<CharInfo> Node;

public:
	struct ConfigInfo
	{
		char _ch;
		LongType _count;
	};
	FileCompress()
	{
		for (int i = 0; i < 256; ++i)
		{
			_hashInfos[i]._ch = i;
			_hashInfos[i]._count = 0;
		}
	}
	void Compress(const char* file)
	{
		//1.统计字符个数
		ifstream ifs(file, ios_base::in | ios_base::binary);
		char ch;
		while (ifs.get(ch))
		{
			_hashInfos[(unsigned char)ch]._count++;
		}
		//2.生成Huffman树
		CharInfo invalid;
		invalid._count = 0;
		HuffmanTree<CharInfo> tree(_hashInfos, 256, invalid);
		//3.生成Huffman code
		GenerateHuffmanCode(tree.GetRoot());
		//4.压缩
		string compressfile = file;
		compressfile += ".compress";
		ofstream ofs(compressfile.c_str(), ios_base::out | ios_base::binary);
		//4.1压缩前写入字符次数，方便解压缩时构建Huffman树
		for (int i = 0; i < 256; ++i)
		{
			if (_hashInfos[i]._count > 0)
			{
				ConfigInfo info;
				info._ch = _hashInfos[i]._ch;
				info._count = _hashInfos[i]._count;
				ofs.write((char*)&info, sizeof(ConfigInfo));
			}
		}
		ConfigInfo end;
		end._count = 0;
		ofs.write((char*)&end, sizeof(ConfigInfo));

		//4.2进行压缩
		char value = 0;
		int pos = 0;
		ifs.clear();
		ifs.seekg(0);
		while (ifs.get(ch))
		{
			string& code = _hashInfos[(unsigned char)ch]._code;
			for (size_t i = 0; i < code.size(); ++i)
			{
				if (code[i] == '0')
				{
					value &= (~(1 << pos));
				}
				else if (code[i] == '1')
				{
					value |= (1 << pos);
				}
				else
				{
					assert(false);
				}
				++pos;
				if (pos == 8)
				{
					ofs.put(value);
					//printf("%x ", value);
					pos = 0;
					value = 0;
				}
			}
		}
		if (pos > 0)
		{
			//printf("%x ", value);
			ofs.put(value);
		}
	}
	void GenerateHuffmanCode(Node* root)
	{
		if (root == NULL)
			return;
		if (root->_left == NULL&&root->_right == NULL)
		{
			_hashInfos[(unsigned char)root->_w._ch]._code = root->_w._code;
		}
		if (root->_left != NULL)
		{
			root->_left->_w._code = root->_w._code + '0';
			GenerateHuffmanCode(root->_left);
		}
		if (root->_right != NULL)
		{
			root->_right->_w._code = root->_w._code + '1';
			GenerateHuffmanCode(root->_right);
		}
	}
	void UnCompress(const char* file)
	{
		//1.打开压缩文件
		ifstream ifs(file, ios_base::in | ios_base::binary);

		string uncompressfile = file;
		size_t pos = uncompressfile.rfind('.');
		assert(pos != string::npos);
		uncompressfile.erase(pos);//缺省值为npos
#ifdef _DEBUG
		uncompressfile += ".uncompress";
#endif
		ofstream ofs(uncompressfile.c_str(), ios_base::out | ios_base::binary);

		//2.重建Huffman树

		while (1)
		{
			ConfigInfo info;
			ifs.read((char*)&info, sizeof(ConfigInfo));
			if (info._count > 0)
			{
				_hashInfos[(unsigned char)info._ch]._count = info._count;
			}
			else
			{
				break;
			}
		}


		CharInfo invalid;
		invalid._count = 0;
		HuffmanTree<CharInfo> tree(_hashInfos, 256, invalid);

		//3.解压缩
		Node* root = tree.GetRoot();
		LongType filecount = root->_w._count;
		Node* cur = root;
		char ch;
		while (ifs.get(ch))
		{
			for (size_t pos = 0; pos < 8; ++pos)
			{
				if (ch&(1 << pos))//1
				{
					cur = cur->_right;
				}
				else//0
				{
					cur = cur->_left;
				}
				if (cur->_left == NULL&&cur->_right == NULL)
				{
					ofs.put(cur->_w._ch);
					cur = root;
					if (--filecount == 0)
					{
						break;
					}
				}
			}
		}

	}
private:
	CharInfo _hashInfos[256];
};
void TestCompress()
{
	FileCompress fc;
	fc.Compress("input.txt");
}
void TestUncompress()
{
	FileCompress fc;
	fc.UnCompress("input.txt.compress");
}
