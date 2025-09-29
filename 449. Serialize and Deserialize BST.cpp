class Codec {
public:
    void serializeHelper(TreeNode* root, ostringstream& out) {
        if (nullptr == root) {
            out << "#,";
            return;
        }

        out << root->val << ",";
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    }

    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    TreeNode* deserializeHelper(istringstream& in) {
        string token;
        if (!getline(in, token, ',')) {
            return nullptr;
        }

        if (token == "#") {
            return nullptr;
        }

        int val = stoi(token);
        TreeNode* node = new TreeNode(val);
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);

        return node;
    }

    TreeNode* deserialize(const string& data) {
        istringstream in(data);
        return deserializeHelper(in);
    }
};
