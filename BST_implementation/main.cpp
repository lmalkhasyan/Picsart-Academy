#include "BST.h"
#include <cassert>

void testBST()
{
    // Create an instance of BST
    BST<int> bst;

    // Test empty function
    assert(bst.empty());
    assert(bst.size() == 0);

    // Test insert function
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    assert(!bst.empty());
    assert(bst.size() == 7);

    // Test find function
    assert(bst.find(6));
    assert(!bst.find(2));

    // Test search_iterative function
    assert(bst.search_iterative(6));
    assert(!bst.search_iterative(2));

    // Test getHeight function
    assert(bst.getHeight() == 3);

    // Test preorder traversal
    std::cout << "Preorder traversal: ";
    bst.preorder();
    std::cout << std::endl;

    // Test inorder traversal
    std::cout << "Inorder traversal: ";
    bst.inorder();
    std::cout << std::endl;

    // Test postorder traversal
    std::cout << "Postorder traversal: ";
    bst.postorder();
    std::cout << std::endl;

    // Test erase function
    bst.erase(5);
    assert(!bst.contains(5));
    assert(bst.size() == 6);

    // Test swap function
    BST<int> bst2;
    bst2.insert(100);
    bst2.insert(200);
    std::cout << "BST2 before swap: ";
    bst2.inorder();
    std::cout << std::endl;
    swap(bst, bst2);
    std::cout << "BST after swap: ";
    bst.inorder();
    std::cout << std::endl;
    std::cout << "BST2 after swap: ";
    bst2.inorder();
    std::cout << std::endl;

    // Test contains function
    assert(!bst.contains(3));
    assert(!bst.contains(5));

    // Test copy constructor
    BST<int> bstCopy(bst);
    assert(bstCopy.size() == bst.size());
    assert(bstCopy.contains(100));
    assert(bstCopy.contains(200));

    // Test move constructor
    BST<int> bstMove(std::move(bst));
    assert(bstMove.size() == bstCopy.size());
    assert(bstMove.contains(100));
    assert(bstMove.contains(200));\
    std::cout << "bstmove : ";
    bstMove.inorder();
    std::cout << std::endl;

    // Test assignment operator
    bst = bstCopy;
    assert(bst.size() == bstCopy.size());
    assert(bst.contains(100));
    assert(!bst.contains(3));

    // Test move assignment operator
    bst = std::move(bstMove);
    assert(bst.size() == bstCopy.size());
    assert(bst.contains(200));
    assert(!bst.contains(5));

    // Test clear function
    bst.clear();
    assert(bst.empty());
    assert(bst.size() == 0);
}

int main()
{
    BST<int> test_obj;
    if(test_obj.empty())
        std::cout << "BST is empty!" << std::endl;
    
    std::cout <<"SIZE = " << test_obj.size() << std::endl;

    std::cout <<"height = " << test_obj.getHeight() << std::endl;

    std::cout << "Contains 0 ? : " <<std::boolalpha <<test_obj.contains(0) << std::endl;

    std::cout << "inserting (0): " << test_obj.insert(0) << std::endl;

    std::cout << "Contains 0 ? : " <<std::boolalpha <<test_obj.contains(0) << std::endl;

    std::cout << "deleting 0" << std::endl;
    test_obj.erase(0);
    std::cout << "Contains 0 ? : " <<std::boolalpha <<test_obj.contains(0) << std::endl;

    test_obj.insert(100);
    test_obj.insert(150);
    test_obj.insert(50);
    test_obj.insert(25);
    test_obj.insert(75);
    test_obj.insert(175);
    test_obj.insert(125);

    std::cout << "preorder: ";
    test_obj.preorder();
    std::cout << std::endl;

    std::cout << "inorder: ";
    test_obj.inorder();
    std::cout << std::endl;

    std::cout << "postorder: ";
    test_obj.postorder();
    std::cout << std::endl;

    testBST();
    return 0;
}
