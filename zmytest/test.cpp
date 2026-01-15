
#include <iostream>

#include "../zlasdtest/container/container.hpp"
#include "../zlasdtest/container/testable.hpp"
#include "../zlasdtest/container/dictionary.hpp"
#include "../zlasdtest/container/traversable.hpp"
#include "../zlasdtest/container/mappable.hpp"
#include "../zlasdtest/container/linear.hpp"
#include "../zlasdtest/vector/vector.hpp"
#include "../zlasdtest/list/list.hpp"
#include "../zlasdtest/set/set.hpp"
#include "../zlasdtest/heap/heap.hpp"
#include "../heap/heap.hpp"
#include "../heap/vec/heapvec.hpp"
#include "../zlasdtest/pq/pq.hpp"
#include "../pq/heap/pqheap.hpp"

using namespace std;

void myTestVector(uint&, uint&);
void myTestVectorInt(uint&, uint&);
void myTestVectorDouble(uint&, uint&);
void myTestVectorString(uint&, uint&);

void myTestList(uint&, uint&);
void myTestListInt(uint&, uint&);
void myTestListDouble(uint&, uint&);
void myTestListString(uint&, uint&);

void myTestSetVec(uint&, uint&);
void myTestSetVecInt(uint&, uint&);
void myTestSetVecDouble(uint&, uint&);
void myTestSetVecString(uint&, uint&);

void myTestSetList(uint&, uint&);
void myTestSetListInt(uint&, uint&);
void myTestSetListDouble(uint&, uint&);
void myTestSetListString(uint&, uint&);

void myTestHeapVec(uint&, uint&);
void myTestHeapVecInt(uint&, uint&);
void myTestHeapVecDouble(uint&, uint&);
void myTestHeapVecString(uint&, uint&);

void myTestHeapVec(uint&, uint&);
void myTestHeapVecInt(uint&, uint&);
void myTestHeapVecDouble(uint&, uint&);
void myTestHeapVecString(uint&, uint&);

void myTestPQHeap(uint&, uint&);
void myTestPQHeapInt(uint&, uint&);
void myTestPQHeapDouble(uint&, uint&);
void myTestPQHeapString(uint&, uint&);




void mytest() 
{    
    cout << "\n\n\n\n" << "~*~#~*~ Welcome to the LASD MyTest Suite ~*~#~*~ " << "\n\n";
    
    uint loctestnum, loctesterr;
    uint mytestnum = 0, mytesterr = 0;

    int choice;
    do 
    {
        cout << "\nChoose the test you want to run:\n";
        cout << "1 - Vector test\n";
        cout << "2 - List test\n";
        cout << "3 - SetVec test\n";
        cout << "4 - SetList test\n";
        cout << "5 - HeapVec test\n";
        cout << "6 - PQHeap test\n";
        cout << "7 - All the tests\n";
        cout << "0 - Exit (and show the final result)\n";
        cout << "\nChoice: ";
        cin >> choice;

        switch(choice) 
        {
            case 1:
                loctestnum = 0; loctesterr = 0;
                myTestVector(loctestnum, loctesterr);
                mytestnum += loctestnum; mytesterr += loctesterr;
                break;


            case 2:
                loctestnum = 0; loctesterr = 0;
                myTestList(loctestnum, loctesterr);
                mytestnum += loctestnum; mytesterr += loctesterr;  
                break;


            case 3:
                loctestnum = 0; loctesterr = 0;
                myTestSetVec(loctestnum, loctesterr);
                mytestnum += loctestnum; mytesterr += loctesterr;  
                break;


            case 4:
                cout << "\n\nI'm sorry, but the SetList's test suite isn't ready yet...\n\n";
/*                 
                loctestnum = 0; loctesterr = 0;
                myTestSetList(loctestnum, loctesterr);
                mytestnum += loctestnum; mytesterr += loctesterr;  */
                break;


            case 5:
                loctestnum = 0; loctesterr = 0;
                myTestHeapVec(loctestnum, loctesterr);
                mytestnum += loctestnum; mytesterr += loctesterr;  
                break;


            case 6:
                loctestnum = 0; loctesterr = 0;
                myTestPQHeap(loctestnum, loctesterr);
                mytestnum += loctestnum; mytesterr += loctesterr;  
                break;


            case 7:
                cout << "\n\n********** RUNNING ALL THE TESTS **********\n";

                loctestnum = 0; loctesterr = 0;
                myTestVector(loctestnum, loctesterr);
                mytestnum += loctestnum; mytesterr += loctesterr;

                loctestnum = 0; loctesterr = 0;
                myTestList(loctestnum, loctesterr);
                mytestnum += loctestnum; mytesterr += loctesterr;   

                loctestnum = 0; loctesterr = 0;
                myTestSetVec(loctestnum, loctesterr);
                mytestnum += loctestnum; mytesterr += loctesterr;    

/*              loctestnum = 0; loctesterr = 0;
                myTestSetList(loctestnum, loctesterr);
                mytestnum += loctestnum; mytesterr += loctesterr;   */

                loctestnum = 0; loctesterr = 0;
                myTestHeapVec(loctestnum, loctesterr);
                mytestnum += loctestnum; mytesterr += loctesterr; 

                loctestnum = 0; loctesterr = 0;
                myTestPQHeap(loctestnum, loctesterr);
                mytestnum += loctestnum; mytesterr += loctesterr;  
                break;


            case 0:
                cout << "Exiting from MyTest Suite..." << endl;
                break;


            default:
                cout << "Invalid choice" << endl;
        }
    } while(choice != 0);


    cout << "\n\n********** MyTest - Total Results: (Errors/Tests: " << mytesterr << "/" << mytestnum << ") **********\n";
    cout << "Goodbye\n";
}





void myTestVector(uint& testnum, uint& testerr)
{
    cout << "\n\n******** MY TEST - VECTOR ********" << endl;

    uint loctestnum = 0, loctesterr = 0;

    myTestVectorInt(loctestnum, loctesterr);
    myTestVectorDouble(loctestnum, loctesterr);
    myTestVectorString(loctestnum, loctesterr);

    testnum += loctestnum;
    testerr += loctesterr; 

    cout << endl << "***** MyTest Vector - Results: (Errors/Tests: " << loctesterr << "/" << loctestnum << ") *****" << endl;
}



void myTestList(uint& testnum, uint& testerr)
{
    cout << "\n\n******** MY TEST - LIST ********" << endl;

    uint loctestnum = 0, loctesterr = 0;

    myTestListInt(loctestnum, loctesterr);
    myTestListDouble(loctestnum, loctesterr);
    myTestListString(loctestnum, loctesterr);

    testnum += loctestnum;
    testerr += loctesterr; 

    cout << endl << "***** MyTest List - Results: (Errors/Tests: " << loctesterr << "/" << loctestnum << ") *****" << endl;
}



void myTestSetVec(uint& testnum, uint& testerr)
{
    cout << "\n\n******** MY TEST - SET VEC ********" << endl;

    uint loctestnum = 0, loctesterr = 0;

    myTestSetVecInt(loctestnum, loctesterr);
    myTestSetVecDouble(loctestnum, loctesterr);
    myTestSetVecString(loctestnum, loctesterr);

    testnum += loctestnum;
    testerr += loctesterr; 

    cout << endl << "***** MyTest SetVec - Results: (Errors/Tests: " << loctesterr << "/" << loctestnum << ") *****" << endl;
}



void myTestSetList(uint& testnum, uint& testerr)
{
    cout << "\n\n******** MY TEST - SET LIST ********" << endl;

    uint loctestnum = 0, loctesterr = 0;

    myTestSetListInt(loctestnum, loctesterr);
    myTestSetListDouble(loctestnum, loctesterr);
    myTestSetListString(loctestnum, loctesterr);

    testnum += loctestnum;
    testerr += loctesterr; 

    cout << endl << "***** MyTest SetList - Results: (Errors/Tests: " << loctesterr << "/" << loctestnum << ") *****" << endl;
}



void myTestHeapVec(uint& testnum, uint& testerr)
{
    cout << "\n\n******** MY TEST - HEAP VEC ********" << endl;

    uint loctestnum = 0, loctesterr = 0;

    myTestHeapVecInt(loctestnum, loctesterr);
    myTestHeapVecDouble(loctestnum, loctesterr);
    myTestHeapVecString(loctestnum, loctesterr);

    testnum += loctestnum;
    testerr += loctesterr; 

    cout << endl << "***** MyTest HeapVec - Results: (Errors/Tests: " << loctesterr << "/" << loctestnum << ") *****" << endl;
}



void myTestPQHeap(uint& testnum, uint& testerr)
{
    cout << "\n\n******** MY TEST - PQ HEAP ********" << endl;

    uint loctestnum = 0, loctesterr = 0;

    myTestPQHeapInt(loctestnum, loctesterr);
    myTestPQHeapDouble(loctestnum, loctesterr);
    myTestPQHeapString(loctestnum, loctesterr);

    testnum += loctestnum;
    testerr += loctesterr; 

    cout << endl << "***** MyTest PQHeap - Results: (Errors/Tests: " << loctesterr << "/" << loctestnum << ") *****" << endl;
}





void myTestVectorInt(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of Vector<int> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        // EMPTY VECTOR - BASIC OPERATIONS
        {
            lasd::SortableVector<int> emptyVec1;
            lasd::SortableVector<int> emptyVec2;

            Empty(loctestnum, loctesterr, emptyVec1, true);
            Size(loctestnum, loctesterr, emptyVec1, true, 0);
            
            GetFront(loctestnum, loctesterr, emptyVec1, false, 0);
            GetBack(loctestnum, loctesterr, emptyVec1, false, 0);
            SetAt(loctestnum, loctesterr, emptyVec1, false, 1, 0);
            GetAt(loctestnum, loctesterr, emptyVec1, false, 3, 0);
            
            Exists(loctestnum, loctesterr, emptyVec1, false, 2);
            
            TraversePreOrder(loctestnum, loctesterr, emptyVec1, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, emptyVec1, true, &TraversePrint<int>);
            
            FoldPreOrder(loctestnum, loctesterr, emptyVec1, true, &FoldAdd<int>, 0, 0);
            FoldPostOrder(loctestnum, loctesterr, emptyVec1, true, &FoldAdd<int>, 0, 0);

            Size(loctestnum, loctesterr, emptyVec2, true, 0);
            EqualVector(loctestnum, loctesterr, emptyVec1, emptyVec2, true);
        }



        // N ELEMENTS VECTOR - BASIC OPERATIONS
        {
            lasd::SortableVector<int> nVec1(5);
            Empty(loctestnum, loctesterr, nVec1, false);
            Size(loctestnum, loctesterr, nVec1, true, 5);

            SetAt(loctestnum, loctesterr, nVec1, true, 0, 10);
            SetAt(loctestnum, loctesterr, nVec1, true, 1, 4);
            SetAt(loctestnum, loctesterr, nVec1, true, 2, 5);
            SetAt(loctestnum, loctesterr, nVec1, true, 3, 2);
            SetAt(loctestnum, loctesterr, nVec1, true, 4, 1);

            TraversePreOrder(loctestnum, loctesterr, nVec1, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, nVec1, true, &TraversePrint<int>);

            GetFront(loctestnum, loctesterr, nVec1, true, 10);
            GetBack(loctestnum, loctesterr, nVec1, true, 1);

            FoldPreOrder(loctestnum, loctesterr, nVec1, true, &FoldAdd<int>, 0, 22);
            FoldPostOrder(loctestnum, loctesterr, nVec1, true, &FoldAdd<int>, 0, 22);

            nVec1.Sort();

            TraversePreOrder(loctestnum, loctesterr, nVec1, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, nVec1, true, &TraversePrint<int>);

            GetFront(loctestnum, loctesterr, nVec1, true, 1);
            GetBack(loctestnum, loctesterr, nVec1, true, 10);


            lasd::SortableVector<int> nVec2(2);
            Empty(loctestnum, loctesterr, nVec2, false);
            Size(loctestnum, loctesterr, nVec2, true, 2);

            SetAt(loctestnum, loctesterr, nVec2, true, 0, 3);
            SetAt(loctestnum, loctesterr, nVec2, true, 1, 6);

            TraversePreOrder(loctestnum, loctesterr, nVec2, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, nVec2, true, &TraversePrint<int>);

            FoldPreOrder(loctestnum, loctesterr, nVec2, true, &FoldAdd<int>, 0, 9);
            FoldPostOrder(loctestnum, loctesterr, nVec2, true, &FoldAdd<int>, 0, 9);

            EqualVector(loctestnum, loctesterr, nVec1, nVec2, false);   
        }



        // VECTOR - RESIZE, CLEAR, CONSTRUCTOR, ASSIGNMENT AND OTHER...
        {
            lasd::SortableVector<int> vec;
            vec.Resize(3);

            SetAt(loctestnum, loctesterr, vec, true, 0, 4);
            SetAt(loctestnum, loctesterr, vec, true, 1, 3);
            SetAt(loctestnum, loctesterr, vec, true, 2, 1);

            GetFront(loctestnum, loctesterr, vec, true, 4);
            GetBack(loctestnum, loctesterr, vec, true, 1);
            
            SetFront(loctestnum, loctesterr, vec, true, 5);
            SetBack(loctestnum, loctesterr, vec, true, 4);
            GetBack(loctestnum, loctesterr, vec, true, 4);

            Size(loctestnum, loctesterr, vec, true, 3);

            vec.Resize(2);
            
            Size(loctestnum, loctesterr, vec, true, 2);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

            vec.Resize(5);
            SetAt(loctestnum, loctesterr, vec, true, 2, 10);
            SetAt(loctestnum, loctesterr, vec, true, 3, 32);
            SetAt(loctestnum, loctesterr, vec, true, 4, -1);
            
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            vec.Sort();
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            Size(loctestnum, loctesterr, vec, true, 5);


            lasd::SortableVector<int> vec2(std::move(vec));
            Size(loctestnum, loctesterr, vec, true, 0);
            Size(loctestnum, loctesterr, vec2, true, 5);
            TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<int>);

            vec2 = std::move(vec);
            Size(loctestnum, loctesterr, vec, true, 5);
            Size(loctestnum, loctesterr, vec2, true, 0);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<int>);

            lasd::List<int> lst;
            InsertAtFront(loctestnum, loctesterr, lst, true, 6);
            InsertAtBack(loctestnum, loctesterr, lst, true, 3);
            InsertAtFront(loctestnum, loctesterr, lst, true, 9);
            InsertAtBack(loctestnum, loctesterr, lst, true, 2);
            InsertAtFront(loctestnum, loctesterr, lst, true, 3);
            InsertAtBack(loctestnum, loctesterr, lst, true, 1);

            lasd::SortableVector<int> copyVec(lst);
            TraversePreOrder(loctestnum, loctesterr, copyVec, true, &TraversePrint<int>);
            EqualLinear(loctestnum, loctesterr, copyVec, lst, true);

            lasd::SortableVector<int> moveVec(std::move(lst));
            Size(loctestnum, loctesterr, moveVec, true, 6);
            TraversePreOrder(loctestnum, loctesterr, moveVec, true, &TraversePrint<int>);
            Traverse(loctestnum, loctesterr, lst, true, TraversePrint<int>);
            
            lasd::Vector<int> dimVec(2);
            SetAt(loctestnum, loctesterr, dimVec, true, 0, 2);
            SetAt(loctestnum, loctesterr, dimVec, true, 1, 11);
            SetAt(loctestnum, loctesterr, dimVec, false, 2, 7);
            MapPostOrder(loctestnum, loctesterr, dimVec, true, MapIncrement<int>);
            Traverse(loctestnum, loctesterr, dimVec, true, TraversePrint<int>);

            dimVec.Clear();
            moveVec.Clear();
            copyVec.Clear();
            Size(loctestnum, loctesterr, moveVec, true, 0);
            Empty(loctestnum, loctesterr, moveVec, true);
            Size(loctestnum, loctesterr, copyVec, true, 0);
            Empty(loctestnum, loctesterr, copyVec, true);
            Size(loctestnum, loctesterr, dimVec, true, 0);
            Empty(loctestnum, loctesterr, dimVec, true);
        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of Vector<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestVectorDouble(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of Vector<double> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        // EMPTY VECTOR - BASIC OPERATIONS
        {
            lasd::SortableVector<double> emptyVec1;
            lasd::SortableVector<double> emptyVec2;

            Empty(loctestnum, loctesterr, emptyVec1, true);
            Size(loctestnum, loctesterr, emptyVec1, true, 0);
            
            GetFront(loctestnum, loctesterr, emptyVec1, false, 0.0);
            GetBack(loctestnum, loctesterr, emptyVec1, false, 0.0);
            SetAt(loctestnum, loctesterr, emptyVec1, false, 1, 2.3);
            GetAt(loctestnum, loctesterr, emptyVec1, false, 3, 4.56);
            
            Exists(loctestnum, loctesterr, emptyVec1, false, 2.21);
            
            TraversePreOrder(loctestnum, loctesterr, emptyVec1, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, emptyVec1, true, &TraversePrint<double>);
            
            FoldPreOrder(loctestnum, loctesterr, emptyVec1, true, &FoldAdd<double>, 0.0, 0.0);
            FoldPostOrder(loctestnum, loctesterr, emptyVec1, true, &FoldAdd<double>, 0.0, 0.0);

            Size(loctestnum, loctesterr, emptyVec2, true, 0);
            EqualVector(loctestnum, loctesterr, emptyVec1, emptyVec2, true);
        }



        // N ELEMENTS VECTOR - BASIC OPERATIONS
        {
            lasd::SortableVector<double> nVec1(5);
            Empty(loctestnum, loctesterr, nVec1, false);
            Size(loctestnum, loctesterr, nVec1, true, 5);

            SetAt(loctestnum, loctesterr, nVec1, true, 0, 20.1);
            SetAt(loctestnum, loctesterr, nVec1, true, 1, 4.9);
            SetAt(loctestnum, loctesterr, nVec1, true, 2, 5.5);
            SetAt(loctestnum, loctesterr, nVec1, true, 3, 2.3);
            SetAt(loctestnum, loctesterr, nVec1, true, 4, 1.2);

            TraversePreOrder(loctestnum, loctesterr, nVec1, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, nVec1, true, &TraversePrint<double>);

            GetFront(loctestnum, loctesterr, nVec1, true, 20.1);
            GetBack(loctestnum, loctesterr, nVec1, true, 1.2);

            FoldPreOrder(loctestnum, loctesterr, nVec1, true, &FoldAdd<double>, 0.0, 34.0);
            FoldPostOrder(loctestnum, loctesterr, nVec1, true, &FoldAdd<double>, 0.0, 34.0);

            nVec1.Sort();

            TraversePreOrder(loctestnum, loctesterr, nVec1, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, nVec1, true, &TraversePrint<double>);

            GetFront(loctestnum, loctesterr, nVec1, true, 1.2);
            GetBack(loctestnum, loctesterr, nVec1, true, 20.1);


            lasd::SortableVector<double> nVec2(2);
            Empty(loctestnum, loctesterr, nVec2, false);
            Size(loctestnum, loctesterr, nVec2, true, 2);

            SetAt(loctestnum, loctesterr, nVec2, true, 0, 12.1);
            SetAt(loctestnum, loctesterr, nVec2, true, 1, 5.9);

            TraversePreOrder(loctestnum, loctesterr, nVec2, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, nVec2, true, &TraversePrint<double>);

            FoldPreOrder(loctestnum, loctesterr, nVec2, true, &FoldAdd<double>, 0.0, 18.0);
            FoldPostOrder(loctestnum, loctesterr, nVec2, true, &FoldAdd<double>, 0.0, 18.0);

            EqualVector(loctestnum, loctesterr, nVec1, nVec2, false);   
        }



        // VECTOR - RESIZE, CLEAR, CONSTRUCTOR, ASSIGNMENT AND OTHER...
        {
            lasd::SortableVector<double> vec;
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            vec.Resize(4);
            SetAt(loctestnum, loctesterr, vec, true, 0, 1e308);
            SetAt(loctestnum, loctesterr, vec, true, 1, -1e308); 

            GetFront(loctestnum, loctesterr, vec, true, 1e308);

            Exists(loctestnum, loctesterr, vec, true, 1e308);
            Exists(loctestnum, loctesterr, vec, true, -1e308);

            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            vec.Sort();
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

            lasd::SortableVector<double> vec2(std::move(vec));
            Size(loctestnum, loctesterr, vec, true, 0);
            Size(loctestnum, loctesterr, vec2, true, 4);
            TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<double>);

            vec2 = std::move(vec);
            Size(loctestnum, loctesterr, vec, true, 4);
            Size(loctestnum, loctesterr, vec2, true, 0);

            vec2 = vec2;
            Size(loctestnum, loctesterr, vec2, true, 0);
            TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<double>);

            vec2 = vec;
            Size(loctestnum, loctesterr, vec2, true, 4);
            EqualVector(loctestnum, loctesterr, vec, vec2, true);
            NonEqualVector(loctestnum, loctesterr, vec, vec2, false);

            GetAt(loctestnum, loctesterr, vec, false, -1, 1.5);
            GetAt(loctestnum, loctesterr, vec, false, 5, 2.0);

            lasd::List<double> lst;
            InsertAtFront(loctestnum, loctesterr, lst, true, 3.22);
            InsertAtBack(loctestnum, loctesterr, lst, true, 5.718);
            InsertAtFront(loctestnum, loctesterr, lst, true, -1e300);
            InsertAtBack(loctestnum, loctesterr, lst, true, 9.1);

            lasd::Vector<double> copyVec(lst);
            TraversePreOrder(loctestnum, loctesterr, copyVec, true, &TraversePrint<double>);
            EqualLinear(loctestnum, loctesterr, copyVec, lst, true);

            lasd::Vector<double> moveVec(std::move(lst));
            Size(loctestnum, loctesterr, moveVec, true, 4);
            TraversePreOrder(loctestnum, loctesterr, moveVec, true, &TraversePrint<double>);
            Traverse(loctestnum, loctesterr, lst, true, TraversePrint<double>);

            lasd::Vector<double> dimVec(2);
            SetAt(loctestnum, loctesterr, dimVec, true, 0, 102.456);
            SetAt(loctestnum, loctesterr, dimVec, true, 1, -12.321);
            SetAt(loctestnum, loctesterr, dimVec, false, 2, 4.0);
            Traverse(loctestnum, loctesterr, dimVec, true, TraversePrint<double>);

            dimVec.Clear();
            moveVec.Clear();
            copyVec.Clear();
            Size(loctestnum, loctesterr, moveVec, true, 0);
            Empty(loctestnum, loctesterr, moveVec, true);
            Size(loctestnum, loctesterr, copyVec, true, 0);
            Empty(loctestnum, loctesterr, copyVec, true);
            Size(loctestnum, loctesterr, dimVec, true, 0);
            Empty(loctestnum, loctesterr, dimVec, true);
        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of Vector<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestVectorString(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of Vector<string> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        // EMPTY VECTOR - BASIC OPERATIONS
        {
            lasd::SortableVector<string> emptyVec;

            Empty(loctestnum, loctesterr, emptyVec, true);
            Size(loctestnum, loctesterr, emptyVec, true, 0);
            
            GetFront(loctestnum, loctesterr, emptyVec, false, string("front"));
            GetBack(loctestnum, loctesterr, emptyVec, false, string("back"));
            SetAt(loctestnum, loctesterr, emptyVec, false, 1, string("prova"));
            GetAt(loctestnum, loctesterr, emptyVec, false, 3, string("prova"));
            
            Exists(loctestnum, loctesterr, emptyVec, false, string("non esiste"));
            
            TraversePreOrder(loctestnum, loctesterr, emptyVec, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, emptyVec, true, &TraversePrint<string>);
            
            FoldPreOrder(loctestnum, loctesterr, emptyVec, true, &FoldStringConcatenate, string("Y"), string("Y"));
            FoldPostOrder(loctestnum, loctesterr, emptyVec, true, &FoldStringConcatenate,  string("Y"), string("Y"));
            
            TraversePreOrder(loctestnum, loctesterr, emptyVec, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, emptyVec, true, &TraversePrint<string>);
        }



        // N ELEMENTS VECTOR - BASIC OPERATIONS
        {
            lasd::SortableVector<string> nVec1(4);
            
            Empty(loctestnum, loctesterr, nVec1, false);
            Size(loctestnum, loctesterr, nVec1, true, 4);

            SetAt(loctestnum, loctesterr, nVec1, true, 0, string("Totti"));
            SetAt(loctestnum, loctesterr, nVec1, true, 1, string("Del Piero"));
            SetAt(loctestnum, loctesterr, nVec1, true, 2, string("Baggio"));
            SetAt(loctestnum, loctesterr, nVec1, true, 3, string("Vieri"));
            SetAt(loctestnum, loctesterr, nVec1, false, 4, string("Inzaghi"));

            GetFront(loctestnum, loctesterr, nVec1, true, string("Totti"));
            GetBack(loctestnum, loctesterr, nVec1, true, string("Vieri"));

            Exists(loctestnum, loctesterr, nVec1, true, string("Totti"));
            Exists(loctestnum, loctesterr, nVec1, false, string("Mazzola"));

            TraversePreOrder(loctestnum, loctesterr, nVec1, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, nVec1, true, &TraversePrint<string>);

            MapPreOrder(loctestnum, loctesterr, nVec1, true, [](string& str) { MapStringAppend(str, string("!")); });
            
            TraversePreOrder(loctestnum, loctesterr, nVec1, true, &TraversePrint<string>);

            FoldPreOrder(loctestnum, loctesterr, nVec1, true, &FoldStringConcatenate, string("1 "), string("1 Totti!Del Piero!Baggio!Vieri!"));
            FoldPostOrder(loctestnum, loctesterr, nVec1, true, &FoldStringConcatenate, string("2 "), string("2 Vieri!Baggio!Del Piero!Totti!"));  
        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of Vector<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestListInt(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of List<int> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        // EMPTY LIST - BASIC OPERATIONS
        {
            lasd::List<int> emptyList;
            Empty(loctestnum, loctesterr, emptyList, true);
            Size(loctestnum, loctesterr, emptyList, true, 0);

            GetFront(loctestnum, loctesterr, emptyList, false, 0);
            GetBack(loctestnum, loctesterr, emptyList, false, 0);

            Exists(loctestnum, loctesterr, emptyList, false, 0);

            TraversePreOrder(loctestnum, loctesterr, emptyList, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, emptyList, true, &TraversePrint<int>);

            FoldPreOrder(loctestnum, loctesterr, emptyList, true, &FoldAdd<int>, 0, 0);
            FoldPostOrder(loctestnum, loctesterr, emptyList, true, &FoldAdd<int>, 0, 0);

            RemoveFromFront(loctestnum, loctesterr, emptyList, false);
            FrontNRemove(loctestnum, loctesterr, emptyList, false, 0);

            RemoveFromBack(loctestnum, loctesterr, emptyList, false);
            BackNRemove(loctestnum, loctesterr, emptyList, false, 0);

            Exists(loctestnum, loctesterr, emptyList, false, 0);
        }



        // N ELEMENTS LIST - BASIC OPERATIONS
        {
            lasd::List<int> nList;
            
            InsertAtFront(loctestnum, loctesterr, nList, true, 10);
            InsertAtFront(loctestnum, loctesterr, nList, true, 33);
            InsertAtFront(loctestnum, loctesterr, nList, true, 3);
            InsertAtFront(loctestnum, loctesterr, nList, true, 8);
            InsertAtFront(loctestnum, loctesterr, nList, true, -1);
            InsertAtBack(loctestnum, loctesterr, nList, true, 33);
            InsertAtBack(loctestnum, loctesterr, nList, true, -15);
            InsertAtBack(loctestnum, loctesterr, nList, true, 21);

            GetFront(loctestnum, loctesterr, nList, true, -1);
            GetBack(loctestnum, loctesterr, nList, true, 21);

            SetFront(loctestnum, loctesterr, nList, true, 12);
            SetBack(loctestnum, loctesterr, nList, true, 0);

            GetAt(loctestnum, loctesterr, nList, true, 2, 3);
            SetAt(loctestnum, loctesterr, nList, true, 2, 17);

            GetFront(loctestnum, loctesterr, nList, true, 12);
            GetBack(loctestnum, loctesterr, nList, true, 0);
            Exists(loctestnum, loctesterr, nList, true, 33);
            Exists(loctestnum, loctesterr, nList, false, 999);

            TraversePreOrder(loctestnum, loctesterr, nList, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, nList, true, &TraversePrint<int>);

            FoldPreOrder(loctestnum, loctesterr, nList, true, &FoldAdd<int>, 0, 98);
            FoldPostOrder(loctestnum, loctesterr, nList, true, &FoldMultiply<int>, 1, 0);

            RemoveFromFront(loctestnum, loctesterr, nList, true);
            FrontNRemove(loctestnum, loctesterr, nList, true, 8);
            FoldPostOrder(loctestnum, loctesterr, nList, true, &FoldAdd<int>, 0, 78);
        }



        // LIST - CONSTRUCTOR, ASSIGNMENT AND OTHER...
        {
            lasd::List<int> nList;
            
            InsertAtFront(loctestnum, loctesterr, nList, true, -7);
            InsertAtFront(loctestnum, loctesterr, nList, true, 14);
            InsertAtFront(loctestnum, loctesterr, nList, true, 3);
            InsertAtFront(loctestnum, loctesterr, nList, true, 8);
            InsertAtFront(loctestnum, loctesterr, nList, true, -1);
            InsertAtBack(loctestnum, loctesterr, nList, true, 42);
            InsertAtBack(loctestnum, loctesterr, nList, true, -5);
            InsertAtBack(loctestnum, loctesterr, nList, true, 19);

            SetFront(loctestnum, loctesterr, nList, true, 0);
            SetBack(loctestnum, loctesterr, nList, true, 100);

            SetAt(loctestnum, loctesterr, nList, true, 2, -99);

            GetFront(loctestnum, loctesterr, nList, true, 0);
            GetBack(loctestnum, loctesterr, nList, true, 100);
            Exists(loctestnum, loctesterr, nList, true, 42);

            RemoveFromFront(loctestnum, loctesterr, nList, true);
            FrontNRemove(loctestnum, loctesterr, nList, true, 8);

            lasd::List<int> copyList(nList);
            EqualList(loctestnum, loctesterr, nList, copyList, true);
            EqualLinear(loctestnum, loctesterr, nList, copyList, true);

            MapPreOrder(loctestnum, loctesterr, nList, true, &MapIncrement<int>);
            TraversePreOrder(loctestnum, loctesterr, nList, true, &TraversePrint<int>);
            NonEqualList(loctestnum, loctesterr, nList, copyList, true);

            InsertAtFront(loctestnum, loctesterr, nList, true, -99);
            InsertAtBack(loctestnum, loctesterr, nList, true, 77);

            TraversePostOrder(loctestnum, loctesterr, nList, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, copyList, true, &TraversePrint<int>);

            copyList = nList;
            EqualList(loctestnum, loctesterr, nList, copyList, true);
            EqualLinear(loctestnum, loctesterr, nList, copyList, true);

            MapPreOrder(loctestnum, loctesterr, nList, true, &MapIncrement<int>);
            NonEqualList(loctestnum, loctesterr, nList, copyList, true);

            FrontNRemove(loctestnum, loctesterr, nList, true, -98);
            TraversePostOrder(loctestnum, loctesterr, nList, true, &TraversePrint<int>);

            lasd::List<int> copyList2(copyList);
            copyList2.Clear();
            copyList2 = nList;
            EqualList(loctestnum, loctesterr, nList, copyList2, true);

            copyList2 = copyList;
            GetBack(loctestnum, loctesterr, copyList2, true, 77);
            SetBack(loctestnum, loctesterr, copyList2, true, -77);
            TraversePostOrder(loctestnum, loctesterr, copyList2, true, &TraversePrint<int>);

            FoldPreOrder(loctestnum, loctesterr, nList, true, &FoldAdd<int>, 0, 135);

            copyList = std::move(nList);
            FoldPreOrder(loctestnum, loctesterr, nList, true, &FoldAdd<int>, 0, 29);
            TraversePostOrder(loctestnum, loctesterr, nList, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, copyList, true, &TraversePrint<int>);

            nList = copyList;
            TraversePostOrder(loctestnum, loctesterr, nList, true, &TraversePrint<int>);

            lasd::List<int> movlst(std::move(nList));
            FoldPreOrder(loctestnum, loctesterr, movlst, true, &FoldAdd<int>, 0, 135);
            FrontNRemove(loctestnum, loctesterr, movlst, true, -97);

            InsertAtBack(loctestnum, loctesterr, nList, true, 88);
            MapPreOrder(loctestnum, loctesterr, nList, true, &TraversePrint<int>);
        }



        // LIST - CONSTRUCTOR, ASSIGNMENT AND OTHER...
        {
            lasd::List<int> list;
            Empty(loctestnum, loctesterr, list, true);
            Size(loctestnum, loctesterr, list, true, 0);

            GetFront(loctestnum, loctesterr, list, false, 0);
            GetBack(loctestnum, loctesterr, list, false, 0);
            GetAt(loctestnum, loctesterr, list, false, 2, 0);
            Exists(loctestnum, loctesterr, list, false, 0);
            TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);

            lasd::List<int> copyList(list);
            Empty(loctestnum, loctesterr, copyList, true);
            Size(loctestnum, loctesterr, copyList, true, 0);
            InsertAtFront(loctestnum, loctesterr, copyList, true, 1);
            InsertAtFront(loctestnum, loctesterr, copyList, true, 2);
            TraversePreOrder(loctestnum, loctesterr, copyList, true, &TraversePrint<int>);

            lasd::List<int> copyList2(copyList);
            Empty(loctestnum, loctesterr, copyList2, false);
            Size(loctestnum, loctesterr, copyList2, true, 2);
            TraversePreOrder(loctestnum, loctesterr, copyList2, true, &TraversePrint<int>);

            lasd::List<int> moveList(std::move(copyList2));
            Empty(loctestnum, loctesterr, copyList2, true);
            Size(loctestnum, loctesterr, copyList2, true, 0);
            Empty(loctestnum, loctesterr, moveList, false);
            Size(loctestnum, loctesterr, moveList, true, 2);
            TraversePreOrder(loctestnum, loctesterr, copyList2, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, moveList, true, &TraversePrint<int>);

            NonEqualList(loctestnum, loctesterr, moveList, copyList2, true);
        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of List<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestListDouble(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of List<double> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        // EMPTY LIST - BASIC OPERATIONS
        {
            lasd::List<double> emptyList;
            Empty(loctestnum, loctesterr, emptyList, true);
            Size(loctestnum, loctesterr, emptyList, true, 0);

            GetFront(loctestnum, loctesterr, emptyList, false, 0.0);
            GetBack(loctestnum, loctesterr, emptyList, false, 0.0);

            Exists(loctestnum, loctesterr, emptyList, false, 0.0);

            TraversePreOrder(loctestnum, loctesterr, emptyList, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, emptyList, true, &TraversePrint<int>);

            FoldPreOrder(loctestnum, loctesterr, emptyList, true, &FoldAdd<int>, 0.0, 0.0);
            FoldPostOrder(loctestnum, loctesterr, emptyList, true, &FoldAdd<int>, 0.0, 0.0);

            RemoveFromFront(loctestnum, loctesterr, emptyList, false);
            FrontNRemove(loctestnum, loctesterr, emptyList, false, 0.0);

            RemoveFromBack(loctestnum, loctesterr, emptyList, false);
            BackNRemove(loctestnum, loctesterr, emptyList, false, 0.0);

            Exists(loctestnum, loctesterr, emptyList, false, 0.0);
        }



        // N ELEMENTS LIST - BASIC OPERATIONS
        {
            lasd::List<double> nList;
            
            InsertAtFront(loctestnum, loctesterr, nList, true, 2.2);
            InsertAtFront(loctestnum, loctesterr, nList, true, 4.6);
            InsertAtFront(loctestnum, loctesterr, nList, true, 3.1);
            InsertAtFront(loctestnum, loctesterr, nList, true, 16.4);
            InsertAtFront(loctestnum, loctesterr, nList, true, 120.9);
            InsertAtBack(loctestnum, loctesterr, nList, true, 15.5);
            InsertAtBack(loctestnum, loctesterr, nList, true, 100.6);

            GetFront(loctestnum, loctesterr, nList, true, 120.9);
            GetBack(loctestnum, loctesterr, nList, true, 100.6);

            SetFront(loctestnum, loctesterr, nList, true, 44.1);
            SetBack(loctestnum, loctesterr, nList, true, 0.0);

            GetAt(loctestnum, loctesterr, nList, true, 2, 3.1);
            SetAt(loctestnum, loctesterr, nList, true, 2, 11.2);

            GetFront(loctestnum, loctesterr, nList, true, 44.1);
            GetBack(loctestnum, loctesterr, nList, true, 0.0);
            Exists(loctestnum, loctesterr, nList, true, 4.6);
            Exists(loctestnum, loctesterr, nList, false, 19.7);

            TraversePreOrder(loctestnum, loctesterr, nList, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, nList, true, &TraversePrint<double>);

            FoldPreOrder(loctestnum, loctesterr, nList, true, &FoldAdd<int>, 0, 92);
            FoldPostOrder(loctestnum, loctesterr, nList, true, &FoldMultiply<int>, 1, 0);

            RemoveFromFront(loctestnum, loctesterr, nList, true);
            FrontNRemove(loctestnum, loctesterr, nList, true, 16.4);
            FoldPostOrder(loctestnum, loctesterr, nList, true, &FoldAdd<int>, 0, 32);
        }



        // LIST - CONSTRUCTOR, ASSIGNMENT AND OTHER...
        {
            lasd::List<double> nList;
            
            InsertAtFront(loctestnum, loctesterr, nList, true, 2.2);
            InsertAtFront(loctestnum, loctesterr, nList, true, 4.6);
            InsertAtFront(loctestnum, loctesterr, nList, true, 3.1);
            InsertAtFront(loctestnum, loctesterr, nList, true, 16.4);
            InsertAtFront(loctestnum, loctesterr, nList, true, 120.9);
            InsertAtBack(loctestnum, loctesterr, nList, true, 15.5);
            InsertAtBack(loctestnum, loctesterr, nList, true, 100.6);

            SetFront(loctestnum, loctesterr, nList, true, 44.1);
            SetBack(loctestnum, loctesterr, nList, true, 0.0);

            SetAt(loctestnum, loctesterr, nList, true, 2, 11.2);

            RemoveFromFront(loctestnum, loctesterr, nList, true);
            FrontNRemove(loctestnum, loctesterr, nList, true, 16.4);

            lasd::List<double> copyList(nList);
            EqualList(loctestnum, loctesterr, nList, copyList, true);
            EqualLinear(loctestnum, loctesterr, nList, copyList, true);

            MapPreOrder(loctestnum, loctesterr, nList, true, &MapIncrement<double>);
            TraversePreOrder(loctestnum, loctesterr, nList, true, &TraversePrint<double>);
            NonEqualList(loctestnum, loctesterr, nList, copyList, true);

            InsertAtFront(loctestnum, loctesterr, nList, true, 21.1);
            InsertAtBack(loctestnum, loctesterr, nList, true, 19.5);

            TraversePostOrder(loctestnum, loctesterr, nList, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, copyList, true, &TraversePrint<int>);

            copyList = nList;
            EqualList(loctestnum, loctesterr, nList, copyList, true);
            EqualLinear(loctestnum, loctesterr, nList, copyList, true);

            MapPreOrder(loctestnum, loctesterr, nList, true, &MapIncrement<double>);
            NonEqualList(loctestnum, loctesterr, nList, copyList, true);

            FrontNRemove(loctestnum, loctesterr, nList, true, 22.1);
            TraversePostOrder(loctestnum, loctesterr, nList, true, &TraversePrint<int>);

            lasd::List<double> copyList2(copyList);
            copyList2.Clear();
            copyList2 = nList;
            EqualList(loctestnum, loctesterr, nList, copyList2, true);

            copyList2 = copyList;
            GetBack(loctestnum, loctesterr, copyList2, true, 19.5);
            SetBack(loctestnum, loctesterr, copyList2, true, 14.5);
            TraversePostOrder(loctestnum, loctesterr, copyList2, true, &TraversePrint<double>);

            FoldPreOrder(loctestnum, loctesterr, nList, true, &FoldAdd<int>, 0, 62);

            copyList = std::move(nList);
            FoldPreOrder(loctestnum, loctesterr, nList, true, &FoldAdd<int>, 0, 77);
            TraversePostOrder(loctestnum, loctesterr, nList, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, copyList, true, &TraversePrint<int>);

            nList = copyList;
            TraversePostOrder(loctestnum, loctesterr, nList, true, &TraversePrint<int>);

            lasd::List<double> movlst(std::move(nList));
            FoldPreOrder(loctestnum, loctesterr, movlst, true, &FoldAdd<int>, 0, 62);
            FrontNRemove(loctestnum, loctesterr, movlst, true, 13.2);

            InsertAtBack(loctestnum, loctesterr, nList, true, 120.2);
            MapPreOrder(loctestnum, loctesterr, nList, true, &TraversePrint<int>);
        }



        // LIST - CONSTRUCTOR, ASSIGNMENT AND OTHER...
        {
            lasd::List<double> list;
            lasd::List<double> copyList(list);
            Empty(loctestnum, loctesterr, copyList, true);
            Size(loctestnum, loctesterr, copyList, true, 0);
            InsertAtFront(loctestnum, loctesterr, copyList, true, 1.0);
            InsertAtFront(loctestnum, loctesterr, copyList, true, 2.0);
            TraversePreOrder(loctestnum, loctesterr, copyList, true, &TraversePrint<double>);

            lasd::List<double> copyList2(copyList);
            Empty(loctestnum, loctesterr, copyList2, false);
            Size(loctestnum, loctesterr, copyList2, true, 2);
            TraversePreOrder(loctestnum, loctesterr, copyList2, true, &TraversePrint<double>);

            lasd::List<double> moveList(std::move(copyList2));
            Empty(loctestnum, loctesterr, copyList2, true);
            Size(loctestnum, loctesterr, copyList2, true, 0);
            Empty(loctestnum, loctesterr, moveList, false);
            Size(loctestnum, loctesterr, moveList, true, 2);
            TraversePreOrder(loctestnum, loctesterr, copyList2, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, moveList, true, &TraversePrint<double>);

            NonEqualList(loctestnum, loctesterr, moveList, copyList2, true);
            lasd::List<double> listT = copyList2;
            InsertAtBack(loctestnum, loctesterr, listT, true, 2.0);
            InsertAtBack(loctestnum, loctesterr, listT, true, 1.0);
            EqualLinear(loctestnum, loctesterr, moveList, listT, true);
            EqualList(loctestnum, loctesterr, moveList, listT, true);
            RemoveFromFront(loctestnum, loctesterr, listT, true);
            FrontNRemove(loctestnum , loctesterr, listT, true , 1.0);
            RemoveFromFront(loctestnum, loctesterr, listT, false);
            RemoveFromBack(loctestnum, loctesterr, moveList, true);
            BackNRemove(loctestnum, loctesterr, moveList, true , 2.0);
            RemoveFromBack(loctestnum, loctesterr, moveList, false);

            Size(loctestnum, loctesterr, listT, true, 0);
            Empty(loctestnum, loctesterr, listT, true);
            Size(loctestnum, loctesterr, moveList, true, 0);
            Empty(loctestnum, loctesterr, moveList, true);
        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of List<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestListString(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of List<string> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        // EMPTY LIST - BASIC OPERATIONS
        {
            lasd::List<string> emptyList;

            Empty(loctestnum, loctesterr, emptyList, true);
            Size(loctestnum, loctesterr, emptyList, true, 0);

            TraversePreOrder(loctestnum, loctesterr, emptyList, true, &TraversePrint<string>);
            FoldPreOrder(loctestnum, loctesterr, emptyList, true, &FoldStringConcatenate, string("Z"), string("Z"));
            FoldPostOrder(loctestnum, loctesterr, emptyList, true, &FoldStringConcatenate, string("Z"), string("Z"));

            RemoveFromFront(loctestnum, loctesterr, emptyList, false);
            RemoveFromBack(loctestnum, loctesterr, emptyList, false);
            FrontNRemove(loctestnum, loctesterr, emptyList, false, string("Z"));
            BackNRemove(loctestnum, loctesterr, emptyList, false, string("Z"));

            GetFront(loctestnum, loctesterr, emptyList, false, string("Z"));
            GetBack(loctestnum, loctesterr, emptyList, false, string("Z"));
        }



        // N ELEMENTS LIST - BASIC OPERATIONS
        {
            lasd::List<string> nList;

            InsertAtFront(loctestnum, loctesterr, nList, true, string("DO"));
            InsertAtBack(loctestnum, loctesterr, nList, true, string("RE"));
            InsertAtFront(loctestnum, loctesterr, nList, true, string("MI"));
            InsertAtBack(loctestnum, loctesterr, nList, true, string("FA"));
            InsertAtFront(loctestnum, loctesterr, nList, true, string("SOL"));

            FrontNRemove(loctestnum, loctesterr, nList, true, string("SOL"));
            GetFront(loctestnum, loctesterr, nList, true, string("MI"));
            InsertAtFront(loctestnum, loctesterr, nList, true, string("LA"));

            BackNRemove(loctestnum, loctesterr, nList, true, string("FA"));
            GetBack(loctestnum, loctesterr, nList, true, string("RE"));
            InsertAtBack(loctestnum, loctesterr, nList, true, string("SI"));

            Size(loctestnum, loctesterr, nList, true, 5);
            GetFront(loctestnum, loctesterr, nList, true, string("LA"));
            GetBack(loctestnum, loctesterr, nList, true, string("SI"));
            Exists(loctestnum, loctesterr, nList, true, string("DO"));
            Exists(loctestnum, loctesterr, nList, false, string("LOL"));

            MapPreOrder(loctestnum, loctesterr, nList, true, [](string & str) { MapStringAppend(str, "_"); });
            TraversePreOrder(loctestnum, loctesterr, nList, true, &TraversePrint<string>);
            FoldPreOrder(loctestnum, loctesterr, nList, true, &FoldStringConcatenate, string(">"), string(">LA_MI_DO_RE_SI_"));
            FoldPostOrder(loctestnum, loctesterr, nList, true, &FoldStringConcatenate, string(">"), string(">SI_RE_DO_MI_LA_"));
        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of List<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestSetVecInt(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of SetVec<int> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        lasd::Vector<int> vec(0);
        lasd::SetVec<int> setVec(vec);
        lasd::Vector<int> vec2(0);
        lasd::SetVec<int> setVec2(vec2);

        EqualSetVec(loctestnum, loctestnum, setVec, setVec2, true);
        Empty(loctestnum, loctesterr, setVec, true);

        InsertC(loctestnum, loctesterr, setVec, true, 4);

        EqualSetVec(loctestnum, loctesterr, setVec, setVec2, false);
        NonEqualSetVec(loctestnum, loctesterr, setVec, setVec2, true);

        InsertC(loctestnum, loctesterr, setVec, true, 10);
        InsertC(loctestnum, loctesterr, setVec, true, 3);

        InsertC(loctestnum, loctesterr, setVec2, true, 10);
        InsertC(loctestnum, loctesterr, setVec2, true, 3);
        InsertC(loctestnum, loctesterr, setVec2, true, 4);
        EqualSetVec(loctestnum, loctesterr, setVec, setVec2, true);
        NonEqualSetVec(loctestnum, loctesterr, setVec, setVec2, false);

        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<int>);
        Min(loctestnum, loctesterr, setVec, true, 3);
        Max(loctestnum, loctesterr, setVec, true, 10);

        InsertC(loctestnum, loctesterr, setVec, true, 13);
        InsertC(loctestnum, loctesterr, setVec, true, -10);

        Min(loctestnum, loctesterr, setVec, true, -10);
        Max(loctestnum, loctesterr, setVec, true, 13);

        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<int>);

        MinNRemove(loctestnum, loctesterr, setVec, true, -10);
        MinNRemove(loctestnum, loctesterr, setVec, true, 3);

        InsertC(loctestnum, loctesterr, setVec, false, 10);
        InsertC(loctestnum, loctesterr, setVec, true, 12);
        InsertC(loctestnum, loctesterr, setVec, true, 15);
        InsertC(loctestnum, loctesterr, setVec, true, 7); 

        Exists(loctestnum, loctesterr, setVec, false, 5);

        InsertC(loctestnum, loctesterr, setVec, true, 8);

        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<int>);

        InsertC(loctestnum, loctesterr, setVec, true, 16);

        Exists(loctestnum, loctesterr, setVec, true, 8);
        Exists(loctestnum, loctesterr, setVec, false, 5);

        Remove(loctestnum, loctesterr, setVec, true, 8);
        Remove(loctestnum, loctesterr, setVec, false, 5);

        Exists(loctestnum, loctesterr, setVec, true, 16);
        Exists(loctestnum, loctesterr, setVec, false, 20);

        Remove(loctestnum, loctesterr, setVec, true, 16);
        Remove(loctestnum, loctesterr, setVec, false, 20);

        Exists(loctestnum, loctesterr, setVec, true, 4);
        Exists(loctestnum, loctesterr, setVec, false, -20);
        Remove(loctestnum, loctesterr, setVec, true, 4);
        Remove(loctestnum, loctesterr, setVec, false, -20);

        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<int>);

        Predecessor(loctestnum, loctesterr, setVec, false, 6, 0);
        RemovePredecessor(loctestnum, loctesterr, setVec, false, 6);
        Predecessor(loctestnum, loctesterr, setVec, true, 11, 10);
        RemovePredecessor(loctestnum, loctesterr, setVec, true, 11);

        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<int>);

        Successor(loctestnum, loctesterr, setVec, false, 16, 17);
        RemoveSuccessor(loctestnum, loctesterr, setVec, false, 16);
        Successor(loctestnum, loctesterr, setVec, true, 12, 13);
        RemoveSuccessor(loctestnum, loctesterr, setVec, true, 12);

        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<int>);

        lasd::SetVec<int> moveSetVec(move(setVec));

        TraversePreOrder(loctestnum, loctesterr, moveSetVec, true, &TraversePrint<int>);

        InsertM(loctestnum, loctesterr, moveSetVec, false, 12);
        InsertM(loctestnum, loctesterr, moveSetVec, true, 23);
        InsertM(loctestnum, loctesterr, moveSetVec, true, -14);
        InsertM(loctestnum, loctesterr, moveSetVec, true, 10); 

        TraversePreOrder(loctestnum, loctesterr, moveSetVec, true, &TraversePrint<int>);
        RemoveSuccessor(loctestnum, loctesterr, moveSetVec, true, 16);
        TraversePreOrder(loctestnum, loctesterr, moveSetVec, true, &TraversePrint<int>);

        Size(loctestnum,loctesterr, setVec, true,0);
        setVec2.Clear();
        Empty(loctestnum, loctesterr, setVec2, true);
        Size(loctestnum,loctesterr, setVec2, true,0); 
        setVec = std::move(moveSetVec);

        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<int>);
        TraversePreOrder(loctestnum, loctesterr, moveSetVec, true, &TraversePrint<int>);

        moveSetVec = setVec;
        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<int>);
        TraversePreOrder(loctestnum, loctesterr, moveSetVec, true, &TraversePrint<int>);

        setVec.Clear();
        moveSetVec.Clear();

        Empty(loctestnum, loctesterr, setVec, true);
        Size(loctestnum,loctesterr, setVec, true,0);
        Empty(loctestnum, loctesterr, moveSetVec, true);
        Size(loctestnum,loctesterr, moveSetVec, true,0);

        lasd::Vector<int> mappableVec(3);
        SetAt(loctestnum, loctesterr, mappableVec, true, 0, 3);
        SetAt(loctestnum, loctesterr, mappableVec, true, 1, 1);
        SetAt(loctestnum, loctesterr, mappableVec, true, 2, 6);

        lasd::SetVec<int> mappableSetVec(std::move(mappableVec));
        TraversePreOrder(loctestnum, loctesterr, mappableSetVec, true, &TraversePrint<int>);
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of SetVec<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestSetVecDouble(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of SetVec<double> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        lasd::Vector<double> vec(0);
        lasd::SetVec<double> setVec(vec);
        lasd::Vector<double> vec2(0);
        lasd::SetVec<double> setVec2(vec2);

        EqualSetVec(loctestnum, loctesterr, setVec, setVec2, true);
        Empty(loctestnum, loctesterr, setVec, true);

        InsertC(loctestnum, loctesterr, setVec, true, 4.1);
        GetAt(loctestnum, loctesterr, setVec, false, 7, 0.0);

        EqualSetVec(loctestnum, loctesterr, setVec, setVec2, false);
        NonEqualSetVec(loctestnum, loctesterr, setVec, setVec2, true);

        InsertC(loctestnum, loctesterr, setVec, true, 10.5);

        InsertC(loctestnum, loctesterr, setVec2, true, 10.5);
        InsertC(loctestnum, loctesterr, setVec2, true, 3.3);
        EqualSetVec(loctestnum, loctesterr, setVec, setVec2, false);
        InsertC(loctestnum, loctesterr, setVec, true, 3.3);

        InsertC(loctestnum, loctesterr, setVec2, true, 4.1);
        EqualSetVec(loctestnum, loctesterr, setVec, setVec2, true);
        NonEqualSetVec(loctestnum, loctesterr, setVec, setVec2, false);

        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<double>);
        Min(loctestnum, loctesterr, setVec, true, 3.3);
        Max(loctestnum, loctesterr, setVec, true, 10.5);

        InsertC(loctestnum, loctesterr, setVec, true, 13.7);
        InsertC(loctestnum, loctesterr, setVec, true, -10.9);
        Min(loctestnum, loctesterr, setVec, true, -10.9);
        Max(loctestnum, loctesterr, setVec, true, 13.7);
        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<double>);

        MinNRemove(loctestnum, loctesterr, setVec, true, -10.9);
        MinNRemove(loctestnum, loctesterr, setVec, true, 3.3);

        InsertC(loctestnum, loctesterr, setVec, false, 10.5);
        InsertC(loctestnum, loctesterr, setVec, true, 12.4);
        InsertC(loctestnum, loctesterr, setVec, true, 15.0);
        InsertC(loctestnum, loctesterr, setVec, true, 7.2);

        Exists(loctestnum, loctesterr, setVec, false, 5.5);
        InsertC(loctestnum, loctesterr, setVec, true, 8.8);
        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<double>);
        InsertC(loctestnum, loctesterr, setVec, true, 16.1);

        Exists(loctestnum, loctesterr, setVec, true, 8.8);
        Exists(loctestnum, loctesterr, setVec, false, 5.5);

        Remove(loctestnum, loctesterr, setVec, true, 8.8);
        Remove(loctestnum, loctesterr, setVec, false, 5.5);

        Exists(loctestnum, loctesterr, setVec, true, 16.1);
        Exists(loctestnum, loctesterr, setVec, false, 20.0);
        Remove(loctestnum, loctesterr, setVec, true, 16.1);
        Remove(loctestnum, loctesterr, setVec, false, 20.0);

        Exists(loctestnum, loctesterr, setVec, true, 4.1);
        Exists(loctestnum, loctesterr, setVec, false, -20.5);
        Remove(loctestnum, loctesterr, setVec, true, 4.1);
        Remove(loctestnum, loctesterr, setVec, false, -20.5);

        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<double>);

        Predecessor(loctestnum, loctesterr, setVec, false, 6.6, 0.0);
        RemovePredecessor(loctestnum, loctesterr, setVec, false, 6.6);

        Predecessor(loctestnum, loctesterr, setVec, true, 11.0, 10.5);
        RemovePredecessor(loctestnum, loctesterr, setVec, true, 11.0);
        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<double>);

        Successor(loctestnum, loctesterr, setVec, false, 16.1, 17.0);
        RemoveSuccessor(loctestnum, loctesterr, setVec, false, 16.1);

        Successor(loctestnum, loctesterr, setVec, true, 12.4, 13.7);
        RemoveSuccessor(loctestnum, loctesterr, setVec, true, 12.4);
        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<double>);

        lasd::SetVec<double> moveSetVec(std::move(setVec));
        
        InsertM(loctestnum, loctesterr, moveSetVec, false, 12.4);
        InsertM(loctestnum, loctesterr, moveSetVec, true, 23.3);
        InsertM(loctestnum, loctesterr, moveSetVec, true, -14.2);
        InsertM(loctestnum, loctesterr, moveSetVec, true, 10.5);
        
        RemoveSuccessor(loctestnum, loctesterr, moveSetVec, true, 16.1);

        Size(loctestnum, loctesterr, setVec, true, 0);
        setVec2.Clear();

        Min(loctestnum, loctesterr, setVec, false, -10.9);
        Max(loctestnum, loctesterr, setVec, false, -10.9);

        Predecessor(loctestnum, loctesterr, setVec, false, -10.9,-10.8);
        Successor(loctestnum, loctesterr, setVec, false, -10.9,-10.10);

        Empty(loctestnum, loctesterr, setVec2, true);
        Size(loctestnum, loctesterr, setVec2, true, 0);

        setVec = std::move(moveSetVec);
        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<double>);

        moveSetVec = setVec;
        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<double>);

        setVec.Clear();
        moveSetVec.Clear();

        Empty(loctestnum, loctesterr, setVec, true);
        Size(loctestnum, loctesterr, setVec, true, 0);
        Empty(loctestnum, loctesterr, moveSetVec, true);
        Size(loctestnum, loctesterr, moveSetVec, true, 0);

        lasd::Vector<double> mappableVec(3);
        SetAt(loctestnum, loctesterr, mappableVec, true, 0, 3.5);
        SetAt(loctestnum, loctesterr, mappableVec, true, 1, 1.1);
        SetAt(loctestnum, loctesterr, mappableVec, true, 2, 6.6);

        lasd::SetVec<double> mappableSetVec(std::move(mappableVec));
        TraversePreOrder(loctestnum, loctesterr, mappableSetVec, true, &TraversePrint<double>);
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of SetVec<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestSetVecString(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of SetVec<string> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        lasd::Vector<std::string> vec(0);
        lasd::SetVec<std::string> setVec(vec);
        lasd::Vector<std::string> vec2(0);
        lasd::SetVec<std::string> setVec2(vec2);

        EqualSetVec(loctestnum, loctesterr, setVec, setVec2, true);
        Empty(loctestnum, loctesterr, setVec, true);

        InsertC(loctestnum, loctesterr, setVec, true, std::string("delta"));

        EqualSetVec(loctestnum, loctesterr, setVec, setVec2, false);
        NonEqualSetVec(loctestnum, loctesterr, setVec, setVec2, true);

        InsertC(loctestnum, loctesterr, setVec, true, std::string("kilo"));
        InsertC(loctestnum, loctesterr, setVec, true, std::string("bravo"));

        InsertC(loctestnum, loctesterr, setVec2, true, std::string("kilo"));
        InsertC(loctestnum, loctesterr, setVec2, true, std::string("bravo"));
        InsertC(loctestnum, loctesterr, setVec2, true, std::string("delta"));

        EqualSetVec(loctestnum, loctesterr, setVec, setVec2, true);
        NonEqualSetVec(loctestnum, loctesterr, setVec, setVec2, false);

        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<std::string>);
        Min(loctestnum, loctesterr, setVec, true, std::string("bravo"));
        Max(loctestnum, loctesterr, setVec, true, std::string("kilo"));

        InsertC(loctestnum, loctesterr, setVec, true, std::string("zulu"));
        InsertC(loctestnum, loctesterr, setVec, true, std::string("alpha"));
        Min(loctestnum, loctesterr, setVec, true, std::string("alpha"));
        Max(loctestnum, loctesterr, setVec, true, std::string("zulu"));
        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<std::string>);
        MinNRemove(loctestnum, loctesterr, setVec, true, std::string("alpha"));
        MinNRemove(loctestnum, loctesterr, setVec, true, std::string("bravo"));

        InsertC(loctestnum, loctesterr, setVec, false, std::string("kilo"));
        InsertC(loctestnum, loctesterr, setVec, true, std::string("lima"));
        InsertC(loctestnum, loctesterr, setVec, true, std::string("papa"));
        InsertC(loctestnum, loctesterr, setVec, true, std::string("hotel"));

        Exists(loctestnum, loctesterr, setVec, false, std::string("echo"));
        InsertC(loctestnum, loctesterr, setVec, true, std::string("india"));
        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<std::string>);
        InsertC(loctestnum, loctesterr, setVec, true, std::string("yankee"));

        Exists(loctestnum, loctesterr, setVec, true, std::string("india"));
        Exists(loctestnum, loctesterr, setVec, false, std::string("echo"));
        Remove(loctestnum, loctesterr, setVec, true, std::string("india"));
        Remove(loctestnum, loctesterr, setVec, false, std::string("echo"));

        Exists(loctestnum, loctesterr, setVec, true, std::string("yankee"));
        Exists(loctestnum, loctesterr, setVec, false, std::string("zzzz"));
        Remove(loctestnum, loctesterr, setVec, true, std::string("yankee"));
        Remove(loctestnum, loctesterr, setVec, false, std::string("zzzz"));

        Exists(loctestnum, loctesterr, setVec, true, std::string("delta"));
        Exists(loctestnum, loctesterr, setVec, false, std::string("aaaa"));
        Remove(loctestnum, loctesterr, setVec, true, std::string("delta"));
        Remove(loctestnum, loctesterr, setVec, false, std::string("aaaa"));

        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<std::string>);

        Predecessor(loctestnum, loctesterr, setVec, false, std::string("foxtrot"), std::string(""));
        RemovePredecessor(loctestnum, loctesterr, setVec, false, std::string("foxtrot"));

        Predecessor(loctestnum, loctesterr, setVec, true, std::string("lima"), std::string("kilo"));
        RemovePredecessor(loctestnum, loctesterr, setVec, true, std::string("lima"));

        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<std::string>);

        Successor(loctestnum, loctesterr, setVec, false, std::string("zulu"), std::string(""));
        RemoveSuccessor(loctestnum, loctesterr, setVec, false, std::string("zulu"));

        Successor(loctestnum, loctesterr, setVec, true, std::string("lima"), std::string("papa"));
        RemoveSuccessor(loctestnum, loctesterr, setVec, true, std::string("lima"));
        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<std::string>);

        lasd::SetVec<std::string> moveSetVec(std::move(setVec));

        TraversePreOrder(loctestnum, loctesterr, moveSetVec, true, &TraversePrint<std::string>);

        InsertM(loctestnum, loctesterr, moveSetVec, false, std::string("lima"));
        InsertM(loctestnum, loctesterr, moveSetVec, true, std::string("victor"));
        InsertM(loctestnum, loctesterr, moveSetVec, true, std::string("beta"));
        InsertM(loctestnum, loctesterr, moveSetVec, true, std::string("kilo"));

        TraversePreOrder(loctestnum, loctesterr, moveSetVec, true, &TraversePrint<std::string>);

        RemoveSuccessor(loctestnum, loctesterr, moveSetVec, false, std::string("zulu"));
        TraversePreOrder(loctestnum, loctesterr, moveSetVec, true, &TraversePrint<std::string>);

        Size(loctestnum, loctesterr, setVec, true, 0);

        setVec2.Clear();

        Empty(loctestnum, loctesterr, setVec2, true);
        Size(loctestnum, loctesterr, setVec2, true, 0);

        setVec = std::move(moveSetVec);
        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<std::string>);
        TraversePreOrder(loctestnum, loctesterr, moveSetVec, true, &TraversePrint<std::string>);

        moveSetVec = setVec;
        TraversePreOrder(loctestnum, loctesterr, setVec, true, &TraversePrint<std::string>);
        TraversePreOrder(loctestnum, loctesterr, moveSetVec, true, &TraversePrint<std::string>);

        setVec.Clear();
        moveSetVec.Clear();

        Empty(loctestnum, loctesterr, setVec, true);
        Size(loctestnum, loctesterr, setVec, true, 0);
        Empty(loctestnum, loctesterr, moveSetVec, true);
        Size(loctestnum, loctesterr, moveSetVec, true, 0);

        lasd::Vector<std::string> mappableVec(3);
        SetAt(loctestnum, loctesterr, mappableVec, true, 0, std::string("uno"));
        SetAt(loctestnum, loctesterr, mappableVec, true, 1, std::string("due"));
        SetAt(loctestnum, loctesterr, mappableVec, true, 2, std::string("tre"));

        lasd::SetVec<std::string> mappableSetVec(std::move(mappableVec));
        TraversePreOrder(loctestnum, loctesterr, mappableSetVec, true, &TraversePrint<std::string>);
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of SetVec<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestSetListInt(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of SetList<int> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of SetList<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestSetListDouble(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of SetList<double> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of SetList<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestSetListString(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of SetList<string> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of SetList<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestHeapVecInt(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of HeapVec<int> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        // EMPTY HEAPVEC - BASIC OPERATIONS
        {
            lasd::Vector<int> emptyVec;
            lasd::HeapVec<int> emptyHeapVec(emptyVec);
            Empty(loctestnum, loctesterr, emptyHeapVec, true);
            Size(loctestnum, loctesterr, emptyHeapVec, true, 0);

            Traverse(loctestnum, loctesterr, emptyHeapVec, true, &TraversePrint<int>);
            IsHeap(loctestnum, loctesterr, emptyHeapVec, true);

            FoldPreOrder(loctestnum, loctesterr, emptyHeapVec, true, &FoldAdd<int>, 0, 0);

            emptyHeapVec.Heapify();
            Traverse(loctestnum, loctesterr, emptyHeapVec, true, &TraversePrint<int>);

            FoldPreOrder(loctestnum, loctesterr, emptyHeapVec, true, &FoldAdd<int>, 0, 0);
        }



        // N ELEMENTS HEAPVEC - BASIC OPERATIONS
        {
            lasd::Vector<int> nVec(4);
            SetAt(loctestnum, loctesterr, nVec, true, 0, 10);
            SetAt(loctestnum, loctesterr, nVec, true, 1, 7);
            SetAt(loctestnum, loctesterr, nVec, true, 2, 3);
            SetAt(loctestnum, loctesterr, nVec, true, 3, 5);

            lasd::HeapVec<int> nHeapVec(nVec);
            Size(loctestnum, loctesterr, nHeapVec, true, 4);
            IsHeap(loctestnum, loctesterr, nHeapVec, true);
            TraversePreOrder(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<int>);
            FoldPreOrder(loctestnum, loctesterr, nHeapVec, true, &FoldAdd<int>, 0, 25);

            nHeapVec.Sort();
            IsHeap(loctestnum, loctesterr, nHeapVec, false);
            TraversePreOrder(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<int>);

            nHeapVec.Heapify();
            IsHeap(loctestnum, loctesterr, nHeapVec, true);
            Traverse(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<int>);

            nHeapVec[0] = 5;
            IsHeap(loctestnum, loctesterr, nHeapVec, false);
            Traverse(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<int>);
            FoldPreOrder(loctestnum, loctesterr, nHeapVec, true, &FoldAdd<int>, 0, 20);

            nHeapVec.Heapify();
            IsHeap(loctestnum, loctesterr, nHeapVec, true);

            Traverse(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<int>);
        }



        // HEAPVEC - CONSTRUCTOR, ASSIGNMENT AND OTHER...
        {
            lasd::Vector<int> vec(7);
            SetAt(loctestnum, loctesterr, vec, true, 0, 2);
            SetAt(loctestnum, loctesterr, vec, true, 1, 15);
            SetAt(loctestnum, loctesterr, vec, true, 2, 13);
            SetAt(loctestnum, loctesterr, vec, true, 3, 8);
            SetAt(loctestnum, loctesterr, vec, true, 4, 4);
            SetAt(loctestnum, loctesterr, vec, true, 5, 10);
            SetAt(loctestnum, loctesterr, vec, true, 6, 20);

            lasd::HeapVec<int> heapVec1(vec);

            IsHeap(loctestnum, loctesterr, heapVec1, true);
            Empty(loctestnum, loctesterr, heapVec1, false);
            Size(loctestnum, loctesterr, heapVec1, true, 7);

            GetFront(loctestnum, loctesterr, heapVec1, true, 20); 
            GetBack(loctestnum, loctesterr, heapVec1, true, 2); 

            GetAt(loctestnum, loctesterr, heapVec1, true, 0, 20);
            GetAt(loctestnum, loctesterr, heapVec1, true, 1, 15);
            GetAt(loctestnum, loctesterr, heapVec1, true, 2, 13);

            Traverse(loctestnum, loctesterr, heapVec1, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, heapVec1, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, heapVec1, true, &TraversePrint<int>);


            lasd::HeapVec<int> heapVec2(heapVec1); 
            EqualLinear(loctestnum, loctesterr, heapVec1, heapVec2, true);
            NonEqualLinear(loctestnum, loctesterr, heapVec1, heapVec2, false);

            lasd::HeapVec<int> heapVec3(std::move(heapVec2));
            EqualLinear(loctestnum, loctesterr, heapVec1, heapVec3, true);
            EqualLinear(loctestnum, loctesterr, heapVec1, heapVec2, false); 
            Empty(loctestnum, loctesterr, heapVec2, true);
            Size(loctestnum, loctesterr, heapVec2, true, 0);

            heapVec2 = heapVec3; 
            EqualLinear(loctestnum, loctesterr, heapVec2, heapVec3, true);
            Empty(loctestnum, loctesterr, heapVec2, false);

            lasd::HeapVec<int> heapVec4;
            heapVec4 = std::move(heapVec2);
            EqualLinear(loctestnum, loctesterr, heapVec3, heapVec4, true);
            Empty(loctestnum, loctesterr, heapVec2, true);

            lasd::HeapVec<int> heapToSort(heapVec1);
            IsHeap(loctestnum, loctesterr, heapToSort, true);
            heapToSort.Sort();
            IsHeap(loctestnum, loctesterr, heapToSort, false);

            heapToSort.Heapify();
            IsHeap(loctestnum, loctesterr, heapToSort, true);

            FoldPreOrder(loctestnum, loctesterr, heapVec1, true, &FoldAdd<int>, 0, 72);
            FoldPostOrder(loctestnum, loctesterr, heapVec1, true, &FoldAdd<int>, 0, 72);


            lasd::HeapVec<int> heapToMap(heapVec1);
            MapPreOrder(loctestnum, loctesterr, heapToMap, true, [](int& x) { x += 2; });
            heapToMap.Heapify();
            Traverse(loctestnum, loctesterr, heapToMap, true, &TraversePrint<int>);
            IsHeap(loctestnum, loctesterr, heapToMap, true); 

            GetAt(loctestnum, loctesterr, heapVec1, false, 100, 0);
            GetAt(loctestnum, loctesterr, heapVec1, false, -1, 0); 

            SetAt(loctestnum, loctesterr, heapVec1, true, 0, 12);
            GetAt(loctestnum, loctesterr, heapVec1, true, 0, 12);
            IsHeap(loctestnum, loctesterr, heapVec1, false); 

            heapVec1.Heapify();
            IsHeap(loctestnum, loctesterr, heapVec1, true);


            lasd::Vector<int> vec2(5);
            SetAt(loctestnum, loctesterr, vec2, true, 0, 6);
            SetAt(loctestnum, loctesterr, vec2, true, 1, 6);
            SetAt(loctestnum, loctesterr, vec2, true, 2, 3);
            SetAt(loctestnum, loctesterr, vec2, true, 3, 3);
            SetAt(loctestnum, loctesterr, vec2, true, 4, 2);

            lasd::HeapVec<int> duplicatedHeapVec(vec2);
            IsHeap(loctestnum, loctesterr, duplicatedHeapVec, true);
            GetFront(loctestnum, loctesterr, duplicatedHeapVec, true, 6);

            duplicatedHeapVec.Sort();
            GetAt(loctestnum, loctesterr, duplicatedHeapVec, true, 0, 2);
            GetAt(loctestnum, loctesterr, duplicatedHeapVec, true, 4, 6);
        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of HeapVec<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestHeapVecDouble(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of HeapVec<double> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        // EMPTY HEAPVEC - BASIC OPERATIONS
        {
            lasd::Vector<double> emptyVec;
            lasd::HeapVec<double> emptyHeapVec(emptyVec);
            Empty(loctestnum, loctesterr, emptyHeapVec, true);
            Size(loctestnum, loctesterr, emptyHeapVec, true, 0);
            Traverse(loctestnum, loctesterr, emptyHeapVec, true, &TraversePrint<double>);
            IsHeap(loctestnum, loctesterr, emptyHeapVec, true);

            FoldPreOrder(loctestnum, loctesterr, emptyHeapVec, true, &FoldAdd<double>, 0., 0.);

            emptyHeapVec.Heapify();
            Traverse(loctestnum, loctesterr, emptyHeapVec, true, &TraversePrint<double>);

            FoldPreOrder(loctestnum, loctesterr, emptyHeapVec, true, &FoldAdd<double>, 0., 0.);
        }



        // N ELEMENTS HEAPVEC - BASIC OPERATIONS
        {
            lasd::Vector<double> nVec(4);
            SetAt(loctestnum, loctesterr, nVec, true, 0, 5.3);
            SetAt(loctestnum, loctesterr, nVec, true, 1, 4.7);
            SetAt(loctestnum, loctesterr, nVec, true, 2, 3.8);
            SetAt(loctestnum, loctesterr, nVec, true, 3, 1.2);

            lasd::HeapVec<double> nHeapVec(nVec);
            Size(loctestnum, loctesterr, nHeapVec, true, 4);
            IsHeap(loctestnum, loctesterr, nHeapVec, true);
            TraversePreOrder(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<double>);

            nHeapVec.Sort();
            IsHeap(loctestnum, loctesterr, nHeapVec, false);
            TraversePreOrder(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<double>);

            nHeapVec.Heapify();
            IsHeap(loctestnum, loctesterr, nHeapVec, true);
            Traverse(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<double>);

            nHeapVec[0] = 2.1;
            IsHeap(loctestnum, loctesterr, nHeapVec, false);
            Traverse(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<double>);
            FoldPreOrder(loctestnum, loctesterr, nHeapVec, true, &FoldAdd<double>, 0., 11.8);

            nHeapVec.Heapify();
            IsHeap(loctestnum, loctesterr, nHeapVec, true);

            Traverse(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<double>);
        }



        // HEAPVEC - CONSTRUCTOR, ASSIGNMENT AND OTHER...
        {
            lasd::Vector<double> vec(5);
            SetAt(loctestnum, loctesterr, vec, true, 0, 11.5);
            SetAt(loctestnum, loctesterr, vec, true, 1, 8.9);
            SetAt(loctestnum, loctesterr, vec, true, 2, 7.2);
            SetAt(loctestnum, loctesterr, vec, true, 3, 1.8);
            SetAt(loctestnum, loctesterr, vec, true, 4, 3.4);
        
            lasd::HeapVec<double> heapVec1(vec);
            IsHeap(loctestnum, loctesterr, heapVec1, true);
            Size(loctestnum, loctesterr, heapVec1, true, 5);
            GetFront(loctestnum, loctesterr, heapVec1, true, 11.5);
    
        
            lasd::HeapVec<double> heapVec2(heapVec1);
            EqualLinear(loctestnum, loctesterr, heapVec2, heapVec1, true);
        

            lasd::HeapVec<double> heapVec3(std::move(heapVec2)); 
            EqualLinear(loctestnum, loctesterr, heapVec1, heapVec3, true);
            EqualLinear(loctestnum, loctesterr, heapVec1, heapVec2, false); 
            Empty(loctestnum, loctesterr, heapVec2, true);
            Size(loctestnum, loctesterr, heapVec2, true, 0);

            heapVec2 = heapVec3; 
            EqualLinear(loctestnum, loctesterr, heapVec2, heapVec3, true);
            Empty(loctestnum, loctesterr, heapVec2, false);

            lasd::HeapVec<double> heapVec4;
            heapVec4 = std::move(heapVec2); 
            EqualLinear(loctestnum, loctesterr, heapVec3, heapVec4, true);
            Empty(loctestnum, loctesterr, heapVec2, true); 


            TraversePreOrder(loctestnum, loctesterr, heapVec1, true, &TraversePrint<double>);
    
            heapVec1.Sort();
            IsHeap(loctestnum, loctesterr, heapVec1, false);
        
            TraversePreOrder(loctestnum, loctesterr, heapVec1, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, heapVec1, true, &TraversePrint<double>);


            FoldPreOrder(loctestnum, loctesterr, heapVec1, true, &FoldAdd<int>, 0, 30);
            FoldPostOrder(loctestnum, loctesterr, heapVec1, true, &FoldAdd<int>, 0, 30); 


            MapPreOrder(loctestnum, loctesterr, heapVec1, true, [](double & x) { x *= 3.0; });
            Traverse(loctestnum, loctesterr, heapVec1, true, &TraversePrint<double>);
            GetFront(loctestnum, loctesterr, heapVec1, true, 5.4);
            heapVec1.Heapify();
            IsHeap(loctestnum, loctesterr, heapVec1, true);
        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of HeapVec<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestHeapVecString(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of HeapVec<string> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        // EMPTY HEAPVEC - BASIC OPERATIONS
        {
            lasd::Vector<string> emptyVec(0);
            lasd::HeapVec<string> emptyHeapVec(emptyVec);

            TraversePreOrder(loctestnum, loctesterr, emptyHeapVec, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, emptyHeapVec, true, &TraversePrint<string>);

            FoldPreOrder(loctestnum, loctesterr, emptyHeapVec, true, &FoldStringConcatenate, string("!"), string("!"));
            FoldPostOrder(loctestnum, loctesterr, emptyHeapVec, true, &FoldStringConcatenate, string("!"), string("!"));

            MapPreOrder(loctestnum, loctesterr, emptyHeapVec, true, [](string & str) { MapStringAppend(str, "*"); });
            MapPostOrder(loctestnum, loctesterr, emptyHeapVec, true, [](string & str) { MapStringAppend(str, "*"); });
        }



        // N ELEMENTS HEAPVEC - BASIC OPERATIONS
        {
            lasd::Vector<string> nVec(5);
            SetAt(loctestnum, loctesterr, nVec, true, 0, string("A"));
            SetAt(loctestnum, loctesterr, nVec, true, 1, string("B"));
            SetAt(loctestnum, loctesterr, nVec, true, 2, string("C"));
            SetAt(loctestnum, loctesterr, nVec, true, 3, string("D"));
            SetAt(loctestnum, loctesterr, nVec, true, 4, string("E"));

            lasd::HeapVec<string> nHeapVec(nVec);
            Empty(loctestnum, loctesterr, nHeapVec, false);
            Size(loctestnum, loctesterr, nHeapVec, true, 5);

            TraversePreOrder(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<string>);

            MapPreOrder(loctestnum, loctesterr, nHeapVec, true, [](string & str) { MapStringAppend(str, "*"); });
            FoldPostOrder(loctestnum, loctesterr, nHeapVec, true, &FoldStringConcatenate, string("!"), string("!B*A*C*D*E*"));

            nHeapVec.Sort();

            TraversePreOrder(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<string>);
            FoldPreOrder(loctestnum, loctesterr, nHeapVec, true, &FoldStringConcatenate, string("?"), string("?A*B*C*D*E*"));

            nHeapVec.Heapify();

            TraversePostOrder(loctestnum, loctesterr, nHeapVec, true, &TraversePrint<string>);
            FoldPostOrder(loctestnum, loctesterr, nHeapVec, true, &FoldStringConcatenate, string("?"), string("?B*A*C*D*E*"));
        }



        // HEAPVEC - CONSTRUCTOR, ASSIGNMENT AND OTHER...
        {
            lasd::Vector<string> vec(4);
            SetAt(loctestnum, loctesterr, vec, true, 0, string("Lemon"));
            SetAt(loctestnum, loctesterr, vec, true, 1, string("Kiwi"));
            SetAt(loctestnum, loctesterr, vec, true, 2, string("Banana"));
            SetAt(loctestnum, loctesterr, vec, true, 3, string("Apple"));

            lasd::HeapVec<string> heapVec1(vec);
            IsHeap(loctestnum, loctesterr, heapVec1, true);
            Size(loctestnum, loctesterr, heapVec1, true, 4);

            GetFront(loctestnum, loctesterr, heapVec1, true, string("Lemon"));


            lasd::HeapVec<string> heapVec2(heapVec1);
            EqualLinear(loctestnum, loctesterr, heapVec2, heapVec1, true);

            lasd::HeapVec<string> heapVec3(std::move(heapVec2));
            EqualLinear(loctestnum, loctesterr, heapVec1, heapVec3, true);
            Empty(loctestnum, loctesterr, heapVec2, true);

            TraversePreOrder(loctestnum, loctesterr, heapVec1, true, &TraversePrint<string>);

            MapPreOrder(loctestnum, loctesterr, heapVec1, true, [](string & str) { MapStringAppend(str, string("*")); });
            TraversePreOrder(loctestnum, loctesterr, heapVec1, true, &TraversePrint<string>);
            IsHeap(loctestnum, loctesterr, heapVec1, true); 

            MapPreOrder(loctestnum, loctesterr, heapVec1, true, [](string & str) { MapStringAppend(str, string(" ")); });
            TraversePreOrder(loctestnum, loctesterr, heapVec1, true, &TraversePrint<string>);

            heapVec1.Sort();
            IsHeap(loctestnum, loctesterr, heapVec1, false);
            TraversePreOrder(loctestnum, loctesterr, heapVec1, true, &TraversePrint<string>);

            heapVec1.Heapify();
            IsHeap(loctestnum, loctesterr, heapVec1, true);
            TraversePreOrder(loctestnum, loctesterr, heapVec1, true, &TraversePrint<string>);


            lasd::Vector<string> vec2(3);
            SetAt(loctestnum, loctesterr, vec2, true, 0, 
                    string("This is a very long string to test heap behavior with lengthy text"));
            SetAt(loctestnum, loctesterr, vec2, true, 1, 
                    string("Another long string that should be compared lexicographically"));
            SetAt(loctestnum, loctesterr, vec2, true, 2, 
                    string("Zebra - this should be the maximum due to starting with Z"));

            lasd::HeapVec<string> heapVec4(vec2);
            IsHeap(loctestnum, loctesterr, heapVec4, true);
            GetFront(loctestnum, loctesterr, heapVec4, true, 
                        string("Zebra - this should be the maximum due to starting with Z"));

            GetAt(loctestnum, loctesterr, heapVec4, false, 100, string(""));
            GetAt(loctestnum, loctesterr, heapVec4, false, -1, string(""));


            lasd::Vector<std::string> vec3(3);
            vec3[0] = "abc\n";
            vec3[1] = "abc\t";
            vec3[2] = "abc ";
            lasd::HeapVec<std::string> heapVec5(vec3);
            IsHeap(loctestnum, loctesterr, heapVec5, true);

        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of HeapVec<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestPQHeapInt(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of PQHeap<int> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        // EMPTY PQHEAP - BASIC OPERATIONS
        {
            lasd::PQHeap<int> emptyPQHeap;

            Empty(loctestnum, loctesterr, emptyPQHeap, true);
            Size(loctestnum, loctesterr, emptyPQHeap, true, 0);

            RemoveTip(loctestnum, loctesterr, emptyPQHeap, false);
            Tip(loctestnum, loctesterr, emptyPQHeap, false, 0);
            TipNRemove(loctestnum, loctesterr, emptyPQHeap, false, 0);

            Exists(loctestnum, loctesterr, emptyPQHeap, false, 1);
            GetAt(loctestnum, loctesterr, emptyPQHeap, false, 0, 0);

            Traverse(loctestnum, loctesterr, emptyPQHeap, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, emptyPQHeap, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, emptyPQHeap, true, &TraversePrint<int>);

            FoldPreOrder(loctestnum, loctesterr, emptyPQHeap, true, &FoldAdd<int>, 0, 0);
            FoldPostOrder(loctestnum, loctesterr, emptyPQHeap, true, &FoldAdd<int>, 0, 0);
        }



        // N ELEMENTS PQHEAP - BASIC OPERATIONS
        {
            lasd::Vector<int> vec(5);
            SetAt(loctestnum, loctesterr, vec, true, 0, 8);
            SetAt(loctestnum, loctesterr, vec, true, 1, 3);
            SetAt(loctestnum, loctesterr, vec, true, 2, 5);
            SetAt(loctestnum, loctesterr, vec, true, 3, 7);
            SetAt(loctestnum, loctesterr, vec, true, 4, 9);
            
            lasd::PQHeap<int> nPQHeap(vec);

            Traverse(loctestnum, loctesterr, nPQHeap, true, &TraversePrint<int>);
            
            Empty(loctestnum, loctesterr, nPQHeap, false);
            Size(loctestnum, loctesterr, nPQHeap, true, 5);

            Tip(loctestnum, loctesterr, nPQHeap, true, 9);
            TipNRemove(loctestnum, loctesterr, nPQHeap, true, 9);
            TipNRemove(loctestnum, loctesterr, nPQHeap, true, 8);
            TipNRemove(loctestnum, loctesterr, nPQHeap, true, 7);
            
            Insert(loctestnum, loctesterr, nPQHeap, 12);
            Insert(loctestnum, loctesterr, nPQHeap, 4);
            
            TraversePreOrder(loctestnum, loctesterr, nPQHeap, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, nPQHeap, true, &TraversePrint<int>);
            
            Change(loctestnum, loctesterr, nPQHeap, true, 0, 0);
            Change(loctestnum, loctesterr, nPQHeap, true, 1, 7);
            
            FoldPreOrder(loctestnum, loctesterr, nPQHeap, true, &FoldAdd<int>, 0, 15);
            FoldPostOrder(loctestnum, loctesterr, nPQHeap, true, &FoldAdd<int>, 0, 15);
            
            Size(loctestnum, loctesterr, nPQHeap, true, nPQHeap.Size());   
        }



        // PQHEAP - CONSTRUCTOR, ASSIGNMENT AND OTHER...
        {
            lasd::Vector<int> vec(10);
            SetAt(loctestnum, loctesterr, vec, true, 0, 20);
            SetAt(loctestnum, loctesterr, vec, true, 1, 15);
            SetAt(loctestnum, loctesterr, vec, true, 2, 18);
            SetAt(loctestnum, loctesterr, vec, true, 3, 10);
            SetAt(loctestnum, loctesterr, vec, true, 4, 12);
            SetAt(loctestnum, loctesterr, vec, true, 5, 25);
            SetAt(loctestnum, loctesterr, vec, true, 6, 17);
            SetAt(loctestnum, loctesterr, vec, true, 7, 5);
            SetAt(loctestnum, loctesterr, vec, true, 8, 8);
            SetAt(loctestnum, loctesterr, vec, true, 9, 30);

            lasd::PQHeap<int> PQHeap1(vec);
            

            lasd::PQHeap<int> PQHeap2(PQHeap1);
            Size(loctestnum, loctesterr, PQHeap2, true, PQHeap1.Size());
            Tip(loctestnum, loctesterr, PQHeap2, true, 30);

            lasd::PQHeap<int> PQHeap3(std::move(PQHeap1));
            EqualLinear(loctestnum, loctesterr, PQHeap2, PQHeap3, true);
            EqualLinear(loctestnum, loctesterr, PQHeap1, PQHeap3, false); 
            Empty(loctestnum, loctesterr, PQHeap1, true);
            Size(loctestnum, loctesterr, PQHeap1, true, 0);

            PQHeap2 = PQHeap3; 
            EqualLinear(loctestnum, loctesterr, PQHeap2, PQHeap3, true);
            Empty(loctestnum, loctesterr, PQHeap2, false);

            lasd::PQHeap<int> PQHeap4;
            PQHeap4 = std::move(PQHeap2);
            EqualLinear(loctestnum, loctesterr, PQHeap3, PQHeap4, true);
            Empty(loctestnum, loctesterr, PQHeap2, true);


            for(int i = 0; i < 10; i++)
                Insert(loctestnum, loctesterr, PQHeap1, 100 + i);

            Size(loctestnum, loctesterr, PQHeap1, true, 10);

            for(int i = 0; i < 10; i++) 
            {
                int expectedTip = PQHeap1.Tip(); 
                TipNRemove(loctestnum, loctesterr, PQHeap1, true, expectedTip);
            }
        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of PQheap<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestPQHeapDouble(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of PQHeap<double> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {

        // EMPTY PQHEAP - BASIC OPERATIONS
        {
            lasd::PQHeap<double> emptyPQHeap;

            Empty(loctestnum, loctesterr, emptyPQHeap, true);
            Size(loctestnum, loctesterr, emptyPQHeap, true, 0);

            RemoveTip(loctestnum, loctesterr, emptyPQHeap, false);
            Tip(loctestnum, loctesterr, emptyPQHeap, false, 0.0);
            TipNRemove(loctestnum, loctesterr, emptyPQHeap, false, 0.0);

            Exists(loctestnum, loctesterr, emptyPQHeap, false, 1.1);
            GetAt(loctestnum, loctesterr, emptyPQHeap, false, 0, 0.0);

            Traverse(loctestnum, loctesterr, emptyPQHeap, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, emptyPQHeap, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, emptyPQHeap, true, &TraversePrint<double>);

            FoldPreOrder(loctestnum, loctesterr, emptyPQHeap, true, &FoldAdd<double>, 0.0, 0.0);
            FoldPostOrder(loctestnum, loctesterr, emptyPQHeap, true, &FoldAdd<double>, 0.0, 0.0);
        }



        // N ELEMENTS PQHEAP
        {
            lasd::Vector<double> vec(7);
            SetAt(loctestnum, loctesterr, vec, true, 0, 4.3);
            SetAt(loctestnum, loctesterr, vec, true, 1, 11.2);
            SetAt(loctestnum, loctesterr, vec, true, 2, 13.9);
            SetAt(loctestnum, loctesterr, vec, true, 3, 0.3);
            SetAt(loctestnum, loctesterr, vec, true, 4, 2.4);
            SetAt(loctestnum, loctesterr, vec, true, 5, 9.5);
            SetAt(loctestnum, loctesterr, vec, true, 6, 0.6);

            lasd::PQHeap<double> PQHeap1(vec);

            Traverse(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<double>);

            Empty(loctestnum, loctesterr, PQHeap1, false);
            Size(loctestnum, loctesterr, PQHeap1, true, 7);

            Tip(loctestnum, loctesterr, PQHeap1, true, 13.9);
            TipNRemove(loctestnum, loctesterr, PQHeap1, true, 13.9);
            TipNRemove(loctestnum, loctesterr, PQHeap1, true, 11.2);
            TipNRemove(loctestnum, loctesterr, PQHeap1, true, 9.5);

            Insert(loctestnum, loctesterr, PQHeap1, 3.1);
            Insert(loctestnum, loctesterr, PQHeap1, 16.7);

            TraversePreOrder(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<double>);

            Change(loctestnum, loctesterr, PQHeap1, true, 0, 0.0);
            Change(loctestnum, loctesterr, PQHeap1, true, 1, 4.7);

            TraversePreOrder(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<double>);

            FoldPreOrder(loctestnum, loctesterr, PQHeap1, true, &FoldAdd<double>, 0.0, 12.3);
            FoldPostOrder(loctestnum, loctesterr, PQHeap1, true, &FoldAdd<double>, 0.0, 12.3);

            Size(loctestnum, loctesterr, PQHeap1, true, PQHeap1.Size());


            lasd::PQHeap<double> PQHeap2;
            Insert(loctestnum, loctesterr, PQHeap2, 11.2);
            Insert(loctestnum, loctesterr, PQHeap2, 20.9);
            Insert(loctestnum, loctesterr, PQHeap2, 3.3);
            Size(loctestnum, loctesterr, PQHeap2, true, 3);

            lasd::PQHeap<double> PQHeap3(PQHeap2);
            EqualLinear(loctestnum, loctesterr, PQHeap3, PQHeap2, true);
            Size(loctestnum, loctesterr, PQHeap3, true, 3);

            lasd::PQHeap<double> PQHeap4(std::move(PQHeap3));
            Empty(loctestnum, loctesterr, PQHeap3, true);
            Size(loctestnum, loctesterr, PQHeap4, true, 3);

            Insert(loctestnum, loctesterr, PQHeap4, 14.8);
            EqualLinear(loctestnum, loctesterr, PQHeap2, PQHeap4, false);

            PQHeap2 = PQHeap4;
            EqualLinear(loctestnum, loctesterr, PQHeap2, PQHeap4, true);
        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of PQheap<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void myTestPQHeapString(uint& testnum, uint& testerr)
{
    cout << endl << "*** Begin of PQHeap<string> Test: ***" << endl;
    
    uint loctestnum = 0, loctesterr = 0;

    try 
    {
        // EMPTY PQHEAP - BASIC OPERATIONS
        {
            lasd::PQHeap<string> emptyPQHeap;

            Empty(loctestnum, loctesterr, emptyPQHeap, true);
            Size(loctestnum, loctesterr, emptyPQHeap, true, 0);

            RemoveTip(loctestnum, loctesterr, emptyPQHeap, false);
            Tip(loctestnum, loctesterr, emptyPQHeap, false, string(""));
            TipNRemove(loctestnum, loctesterr, emptyPQHeap, false, string(""));

            Exists(loctestnum, loctesterr, emptyPQHeap, false, string("X"));
            GetAt(loctestnum, loctesterr, emptyPQHeap, false, 0, string(""));

            Traverse(loctestnum, loctesterr, emptyPQHeap, true, &TraversePrint<string>);
            TraversePreOrder(loctestnum, loctesterr, emptyPQHeap, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, emptyPQHeap, true, &TraversePrint<string>);

            FoldPreOrder(loctestnum, loctesterr, emptyPQHeap, true, &FoldStringConcatenate, string("!"), string("!"));
            FoldPostOrder(loctestnum, loctesterr, emptyPQHeap, true, &FoldStringConcatenate, string("!"), string("!"));

        }



        // N ELEMENTS PQHEAP
        {
            lasd::Vector<string> vec(8);
            SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
            SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));
            SetAt(loctestnum, loctesterr, vec, true, 2, string("C"));
            SetAt(loctestnum, loctesterr, vec, true, 3, string("D"));
            SetAt(loctestnum, loctesterr, vec, true, 4, string("E"));
            SetAt(loctestnum, loctesterr, vec, true, 5, string("F"));
            SetAt(loctestnum, loctesterr, vec, true, 6, string("G"));
            SetAt(loctestnum, loctesterr, vec, true, 7, string("H"));
        
            lasd::PQHeap<string> PQHeap1(vec);
        
            TraversePreOrder(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<string>);
        
            FoldPreOrder(loctestnum, loctesterr, PQHeap1, true, &FoldStringConcatenate, string("#"), string("#HEGDAFCB"));
            FoldPostOrder(loctestnum, loctesterr, PQHeap1, true, &FoldStringConcatenate, string("#"), string("#BCFADGEH"));
        
            Tip(loctestnum, loctesterr, PQHeap1, true, string("H"));
            RemoveTip(loctestnum, loctesterr, PQHeap1, true);
        
            TraversePreOrder(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<string>);
        
            Tip(loctestnum, loctesterr, PQHeap1, true, string("G"));
            RemoveTip(loctestnum, loctesterr, PQHeap1, true);

            Insert(loctestnum, loctesterr, PQHeap1, string("I"));
            Insert(loctestnum, loctesterr, PQHeap1, string("J"));

            TipNRemove(loctestnum, loctesterr, PQHeap1, true, string("J"));
            TipNRemove(loctestnum, loctesterr, PQHeap1, true, string("I"));
            TipNRemove(loctestnum, loctesterr, PQHeap1, true, string("F"));
        
            TraversePreOrder(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<string>);
        
            FoldPreOrder(loctestnum, loctesterr, PQHeap1, true, &FoldStringConcatenate, string("'"), string("'EDCBA"));
            FoldPostOrder(loctestnum, loctesterr, PQHeap1, true, &FoldStringConcatenate, string("'"), string("'ABCDE"));
        
            Change(loctestnum, loctesterr, PQHeap1, true, 4, string("X"));
        
            TraversePreOrder(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<string>);
        
            FoldPreOrder(loctestnum, loctesterr, PQHeap1, true, &FoldStringConcatenate, string("?"), string("?XECBD"));
            FoldPostOrder(loctestnum, loctesterr, PQHeap1, true, &FoldStringConcatenate, string("?"), string("?DBCEX"));
        
            Change(loctestnum, loctesterr, PQHeap1, true, 1, string("Y"));
        
            TraversePreOrder(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, PQHeap1, true, &TraversePrint<string>);
        
            FoldPreOrder(loctestnum, loctesterr, PQHeap1, true, &FoldStringConcatenate, string("&"), string("&YXCBD"));
            FoldPostOrder(loctestnum, loctesterr, PQHeap1, true, &FoldStringConcatenate, string("&"), string("&DBCXY"));
        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << "*** End of PQheap<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ") ***" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}
