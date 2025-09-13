class Node final {
public:
  Node(Node *parent, int value) : value(value) {};
  Node(Node &) = delete;

  int value;
  Node *left = nullptr;
  Node *right = nullptr;
};

class BinarySearchTree final {
public:
  BinarySearchTree() {};
  BinarySearchTree(BinarySearchTree &) = delete;

  Node *find(int value) { return _find(value, root); };

  void append(int value) {
    if (root == nullptr) {
      root = new Node(root, value);
      return;
    }

    _append(value, root);
  };

private:
  void _append(int value, Node *node) {
    if (node->value == value)
      return;

    if (node->value > value) {
      if (node->left) {
        _append(value, node->left);
      }

      else {
        node->left = new Node(node, value);
      }
    }

    if (node->value < value) {
      if (node->right) {
        _append(value, node->right);
      }

      else {
        node->right = new Node(node, value);
      }
    }
  };

  Node *_find(int value, Node *node) {
    if (node->value == value) {
      return node;
    }

    if (node->left) {
      Node *left = _find(value, node->left);

      if (left)
        return left;
    }

    if (node->right) {
      Node *right = _find(value, node->right);

      if (right)
        return right;
    }

    return nullptr;
  };

  Node *root = nullptr;
};

int main() {
  BinarySearchTree tree;

  tree.append(3);
  tree.append(6);
  tree.append(1);
  tree.append(4);
}
