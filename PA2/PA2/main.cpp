#include "AVLTree.h"
using namespace std;


int main() 
{
    const int arraySize = 50;
    int array1[arraySize];
    int array2[arraySize];
    int array3[arraySize];
    int x = 0;
    bool TorF;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();// https://cplusplus.com/reference/algorithm/shuffle/ to figure out how to use unsigned seed for the shuffle function
    AVLTree<int>* tree1 = new AVLTree<int>();
    AVLTree<int>* tree2 = new AVLTree<int>();
    AVLTree<int>* tree3 = new AVLTree<int>();
    // filling in first array with odd numbers (ascending)
    for (int i = 1; i < 100; i += 2)
    {
        array1[x] = i;
        x++;
    }   
    x = 0;
    // filling in second array with odd numbers (descending)
    for (int i = 99; i > 0; i -= 2)
    {
        array2[x] = i;
        x++;
    }
    x = 0;
    // filling in third array with odd numbers (randomly)
    for (int i = 1; i < 100; i += 2)
    {
        array3[x] = i;
        x++;
    }
    // shuffles array, I used this website https://cplusplus.com/reference/algorithm/shuffle/ to figure out how to use the shuffle function
    std::shuffle(array3, array3 + arraySize, std::default_random_engine(seed));
    //

    // printing AVL tree 1
    std::cout << "AVL tree 1:" << std::endl;

    for (int i = 0; i < 50; i++)
    {
        tree1->insert(array1[i]);
    }

    for (int i = 1; i <= 100; i++)
    {
        TorF = tree1->contains(i);
        if (TorF == true)
        {
            std::cout << i << " Yes " << std::endl;
        }
        else
        {
            std::cout << i << " No " << std::endl;
        }
    }

    std::cout << "Height of tree 1: " << tree1->height() << endl;
    std::cout << "Tree1 VALIDATING:" << tree1->validate() << endl;


    // printing AVL tree 2
    std::cout << "AVL tree2: \n";

    for (int i = 0; i < 50; i++)
    {
        tree2->insert(array2[i]);
    }

    for (int i = 1; i <= 100; i++)
    {
        TorF = tree2->contains(i);
        if (TorF == true)
        {
            std::cout << i << " Yes " << std::endl;
        }
        else
        {
            std::cout << i << " No " << std::endl;
        }
    }
    cout << "Height of tree2: " << tree2->height() << endl;
    cout << "Tree2 VALIDATING: " << tree2->validate() << endl;



    // printing AVL tree 3
    cout << "AVL tree3: \n";

    for (int i = 0; i < 50; i++)
    {
        tree3->insert(array3[i]);
    }

    for (int i = 1; i <= 100; i++)
    {
        TorF = tree3->contains(i);
        if (TorF == true)
        {
            std::cout << i << " Yes " << std::endl;
        }
        else
        {
            std::cout << i << " No " << std::endl;
        }
    }
    cout << "Height of tree3: " << tree3->height() << endl;
    cout << "Tree3 VALIDATING: " << tree3->validate() << endl;
    return 0;
}