template <class Entry>
struct Binary_node
{
	Entry data;
	Binary_node<Entry> *left;
	Binary_node<Entry> *right;
	Binary_node();
	Binary_node(const Entry &x);
};

template <class Entry>
class Binary_tree
{
public:
	Binary_tree();
	Binary_tree(const Binary_tree<Entry> &original);
	bool empty()const;
	void preorder(void(*visit)(Entry &));
	void inorder(void(*visit)(Entry &));
	void postorder(void(*visit)(Entry &));
	void NoRePreorder();
	void NoReInorder();
	int size() const;
	int leaf_count() const;
	int height() const;
	void clear();
	void insert(const Entry &);
	~Binary_tree();
	Binary_tree & operator =(const Binary_tree<Entry> &original);
	void level_traverse(void(*visit)(Entry &));
	Binary_node<Entry>* createBiTree(Entry *pre, Entry *in, int n);

protected:
	Binary_node<Entry> *root;

	int recursive_leaf_count(Binary_node<Entry> *sub_root) const;
	void recursive_preorder(Binary_node<Entry> *, void(*visit)(Entry &));
	void recursive_inorder(Binary_node<Entry> *, void(*visit)(Entry &));
	void recursive_postorder(Binary_node<Entry> *, void(*visit)(Entry &));
	int recursive_size(Binary_node<Entry> *sub_root) const;
	int recursive_height(Binary_node<Entry> *sub_root) const;
	void recursive_clear(Binary_node<Entry> *&sub_root);
	void recursive_insert(Binary_node<Entry> *&sub_root, const Entry &x);
	Binary_node<Entry> *recursive_copy(Binary_node<Entry> *sub_root);
};