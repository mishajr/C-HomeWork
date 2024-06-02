#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;








class TreeNode {

    string name;
    vector<unique_ptr<TreeNode>> children;

public:
    TreeNode(string name) : name(name) {}

    void addChild(unique_ptr<TreeNode> child) {
        children.push_back(move(child));
    }

    void traversePreOrder() const {
        cout << name << " ";
        for (const auto& child : children) {
            child->traversePreOrder();
        }
    }

    void traverseInOrder() const {
        if (!children.empty()) {
            children.front()->traverseInOrder();
        }
        cout << name << " ";
        for (size_t i = 1; i < children.size(); ++i) {
            children[i]->traverseInOrder();
        }
    }



    void traversePostOrder() const {
        for (const auto& child : children) {
            child->traversePostOrder();
        }
        cout << name << " ";
    }



    TreeNode* findNode(const string& searchName) {
        if (name == searchName) {
            return this;
        }
        for (const auto& child : children) {
            TreeNode* result = child->findNode(searchName);
            if (result) {
                return result;
            }
        }
        return nullptr;
    }




};









class ComplexNode : public enable_shared_from_this<ComplexNode> {

    string name;
    vector<shared_ptr<ComplexNode>> children;

public:

    ComplexNode(string name) : name(name) {}

    void addChild(shared_ptr<ComplexNode> child) {
        children.push_back(child);
    }

    void traverse() const {
        cout << name << " ";

        for (const auto& child : children) {
            child->traverse();
        }
    }

    ComplexNode* findNode(const string& searchName) {
        if (name == searchName) {
            return this;
        }
        for (const auto& child : children) {
            ComplexNode* result = child->findNode(searchName);
            if (result) {
                return result;
            }
        }
        return nullptr;
    }

    size_t useCount() const {
        return shared_from_this().use_count();
    }



};

class ProjectManager {
    unordered_map<string, unique_ptr<TreeNode>> trees;
    unordered_map<string, shared_ptr<ComplexNode>> complexStructures;
public:
    void addTree(const string& projectName, unique_ptr<TreeNode> tree) {
        trees[projectName] = move(tree);
    }
    void addComplexStructure(const string& projectName, shared_ptr<ComplexNode> complexStructure) {
        complexStructures[projectName] = complexStructure;
    }
    TreeNode* getTree(const string& projectName) {
        return trees.count(projectName) ? trees[projectName].get() : nullptr;
    }
    shared_ptr<ComplexNode> getComplexStructure(const string& projectName) {
        return complexStructures.count(projectName) ? complexStructures[projectName] : nullptr;
    }
    void removeTree(const string& projectName) {
        trees.erase(projectName);
    }
    void removeComplexStructure(const string& projectName) {
        complexStructures.erase(projectName);
    }



};

void demonstrateTree(ProjectManager& pm) {
    auto tree = make_unique<TreeNode>("RootTree");
    tree->addChild(make_unique<TreeNode>("ChildTree"));
    pm.addTree("Project1", move(tree));
    TreeNode* treeFromPM = pm.getTree("Project1");
    if (treeFromPM) {
        cout << "Project1 Tree Pre-Order: " << endl;
        treeFromPM->traversePreOrder();
        cout << endl;
        cout << "Project1 Tree In-Order: " << endl;
        treeFromPM->traverseInOrder();
        cout << endl;
        cout << "Project1 Tree Post-Order: " << endl;
        treeFromPM->traversePostOrder();
        cout << endl;
    }
}

void demonstrateComplexStructure(ProjectManager& pm) {
    auto complex = make_shared<ComplexNode>("RootComplex");
    complex->addChild(make_shared<ComplexNode>("ChildComplex"));
    pm.addComplexStructure("Project2", complex);
    auto complexFromPM = pm.getComplexStructure("Project2");
    if (complexFromPM) {
        cout << "Project2 Complex Structure: ";
        complexFromPM->traverse();
        cout << endl;
        cout << "Use Count for RootComplex: " << complexFromPM->useCount() << endl;
    }
}

int main() {
    ProjectManager pm;
    demonstrateTree(pm);
    demonstrateComplexStructure(pm);
}
