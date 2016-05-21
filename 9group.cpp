#include <iostream>
#include <string>
#include <vector>
using namespace std;
//节点定义
template<class T>
class htree_node{
public:
	typedef htree_node<T> node_type;
	htree_node():parent(0){}
	htree_node(const T& x):name(x), parent(0){}
	~htree_node(){}

	T name;//节点值
	node_type *parent;//父节点指针
	std::vector<node_type*> children;//子节点
};
//树定义
template<class T, class Container = htree_node<T> >
class htree{
protected:
	typedef Container tree_node;
public:
	htree():root(0){ }
	htree(tree_node *node):root(node){  }
	~htree(){destroy(root);}
	//前序迭代器
	class iterator{
	public:
		iterator()
			: _node(0)
			, skip_current_children_(false)
		{
			skip_children();
		}
		iterator(tree_node *node)
			: _node(node)
			, skip_current_children_(false)
		{
			skip_children();
		}
		~iterator()
		{}
		T& operator*() const
		{
			return _node->name;
		}
		T* operator->() const
		{
			return &(_node->name);
		}
		tree_node* get()
		{
			return _node;
		}
		iterator begin() const
		{
			return iterator(_node);
		}
		iterator end() const
		{
			return iterator( _find_end(_node) );
		}

		tree_node *_node;
	protected:
		bool skip_current_children_;
		void         skip_children()
		{
			skip_current_children_=true;
		}
		tree_node* _find_end(tree_node* current) const
		{
			int pos = current->children.size()-1;
			if( pos<0 )
				return (current);
			else
				_find_end(current->children[pos]);
		}
	};
	iterator add(iterator& k, const T& v)//add函数
	{
		tree_node *tmp = new tree_node(v);
		k._node->children.push_back(tmp);
		tmp->parent = k._node;
		return iterator(tmp);
	}
	std::vector<tree_node*> get(iterator& k)//get函数
        {
                return k._node->children;
        }
	tree_node *root;
private:
	void destroy(tree_node *some)//销毁内存空间
	{
	        #define SAFE_DELETE(p) {if(p){delete p; p=NULL;}}
		for (unsigned i = 0; i < some->children.size(); i++)
			destroy(some->children[i]);
		SAFE_DELETE(some);
	}
};
int main()
{
	typedef htree_node<string> node_type;
	typedef htree<string> tree_type;
	node_type *one = new node_type("360");

	tree_type::iterator iter(one);
	tree_type tr1(one);
	tree_type::iterator two = tr1.add(iter, "360企业");
	tree_type::iterator three = tr1.add(iter, "360个人");
	tr1.add(two, "360天擎");
	tr1.add(two, "360天眼");
	tr1.add(three, "360安全卫士");
	tr1.add(three, "360杀毒");
	tr1.add(three, "360驱动大师");
	cout<<"树结构定义"<<endl<<"根节点：360"<<endl<<"一层节点：360企业\t\t360个人"<<endl<<"二层节点：360天擎,360天眼\t360安全卫士,360杀毒,360驱动大师"<<endl;
	cout<<endl<<"get根节点结果:"<<endl;
    	std::vector<node_type*> children = tr1.get(iter);
	for (int i = 0; i < children.size(); i++)
	{
		cout<<children[i]->name<<" ";;
	}
	cout<<endl<<endl<<"get360个人节点结果:"<<endl;
	children = tr1.get(three);
	for (int i = 0; i < children.size(); i++)
	{
		cout<<children[i]->name<<" ";;
	}
	cout<<endl;
	return 0;
}
