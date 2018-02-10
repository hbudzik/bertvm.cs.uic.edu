

This directory contains source code for a C VERSION of the
spring 2018 CS251 prog1 assignment (in C++).

While the functionality of the two code bases is not exactly 
the same, in most cases, there is a clear mapping between the
C++ VERSION and the C VERSION.

So... if you have mostly a C programming background it might be
useful to examine this code base and map functions/structures to
their equivalent functions/classes/structures in the C++ code base.

****************************************************************

Below you will find:

    (1) A sequence of examples making analogies between the C and
        C++ versions.

        All of these analogies use list POINTERS in both the C and
        C++ examples.

    (2) A discussion of object/instance pointers vs non-pointers
        in C++.

    (3) A discussion of templates and the typedef for ElemType
        in the C-version.

****************************************************************

****************************************************************
*
*   (1)  BEGIN EXAMPLES BY ANALOGY
*
*        NOTE:  ALL EXAMPLES BELOW ARE FOR int LISTS.
*               WHEREVER YOU SEE ElemType IN A C-EXAMPLE
*               ASSUME IT IS EQUIVALENT TO THE C TYPE int.
*
****************************************************************

    The linked list nodes themselves.

        C VERSION:  
             typedef for NODE (lines 9-12 of llist.c)
        C++ VERSION:
             struct Node in List.h (lines 14-22).  Note
             that the function init() is private and defined
             near the end of the file List.h

****************************************************************

    The top-level list object/structure/thing:

        C VERSION:  
             struct list_struct in llist.c (line 15) and
             typedef on line 15 of list.h

        C++ VERSION:
             the private data members of the List class specified
             near the bottom of List.h (starting from line 660).

****************************************************************

    EXAMPLE:  Creating an empty list:

        C VERSION:  
             lst_create() function (line 24 of llist.c)
        C++ VERSION:
             List() constructor (line 27 of List.h)

        Client code analagous examples:

             // C VERSION
             LIST *my_list;
                 my_list = lst_create();;

             // C++ VERSION
             List<int> *my_list;
                 my_list = new List<int>();



    Destroying a dynamically allocated list:
        C VERSION:  
             lst_free(LIST *) function (line 32 of llist.c)
        C++ VERSION:
             ~List() destructor (line 31 of List.h)

        Client code analagous examples:

             // C VERSION
             LIST *my_list;
                 my_list = lst_create();;
                 
                   // bunch of operations on my_list
                   // now we no longer want my_list
                   
                   lst_free(my_lst);


             // C++ VERSION
             List<int> *my_list;
                 my_list = new List<int>();

                   // bunch of operations on my_list
                   // now we no longer want my_list
                   
                   delete my_lst;  // implicitly calls destructor

****************************************************************

    EXAMPLE:  The push_front operation

        C VERSION:  
             lst_push_front(LIST *l, ElemType val) function 
                  (line 81 of llist.c)
        C++ VERSION:
             push_front(const T & data) member function 
                (line 119 of List.h)

        Client code analagous examples:

             // C VERSION
             LIST *my_list;
                 my_list = lst_create();;
                 
                 lst_push_front(my_list, 99);


             // C++ VERSION
             List<int> *my_list;
                 my_list = new List<int>();

                   
                 my_list->push_front(99);

****************************************************************

    EXAMPLE:  testing if two lists are equal

        C VERSION:  
             lst_are_equal(LIST *lst1, LIST *lst2) function 
                  ("stub" starts on line 64 of llist.c)
        C++ VERSION:
             equal_to(const List<T> &other) member function 
                (stub on line 242 of List.h)

        Client code analagous examples:

             // C VERSION
             LIST *lstA, *lstB;
                 lstA = lst_create();;
                 lstB = lst_create();;

                 // sequence of operations modifying lstA
                 //    and lstB

                 // Let's see if they are the same...  
                 
                 if(lst_are_equal(lstA, lstB) ) {
                      printf("EQUAL!\n");
                 else
                      printf("NOT EQUAL!\n");


             // C++ VERSION
             List<int> *lstA, *lstB;
                 lstlA = new List<int>();
                 lstlB = new List<int>();

                 // sequence of operations modifying lstA
                 //    and lstB

                 // Let's see if they are the same...  
                   
                 if(lstA->equal_to(*lstB) )
                      cout << "EQUAL!\n";
                 else
                      cout << "NOT EQUAL!\n";



****************************************************************

    EXAMPLE:  reversing a list and printing it

        C VERSIONS:  
            lst_reverse(LIST *l) function 
                  ("stub" starts on line 244 of llist.c)
            
              AND

            lst_print(LIST *l) function (line 45 of llist.c)

        C++ VERSIONS:
             reverse() member function 
                (stub on line 270 of List.h)

              AND

            print() member function (line 108 of List.h)

        Client code analagous examples:

             // C VERSION
             LIST *my_lst;
                 my_lst = lst_create();;

                 // sequence of operations modifying my_list
                 //  ....

                 //  display before reversal
                 printf("before reversal:\n");
                 lst_print(my_lst);

                 //  let's reverse it
                 lst_reverse(my_lst);

                 //  display after reversal
                 printf("after reversal:\n");
                 lst_print(my_lst);

                 //  let's reverse it again!
                 lst_reverse(my_lst);

                 //  display after double reversal
                 printf("after two reversals:\n");
                 lst_print(my_lst);

                 // ...

             // C++ VERSION
             List<int> *my_lst;
                 my_lst = new List<int>();

                 // sequence of operations modifying my_list
                 //  ....

                 //  display before reversal
                 cout << "before reversal:\n";
                 my_lst->print();

                 //  let's reverse it
                 my_lst->reverse();

                 //  display after reversal
                 cout << "after reversal:\n";
                 my_lst->print();

                 //  let's reverse it again!
                 my_lst->reverse();

                 //  display after double reversal
                 cout << "after two reversals:\n";
                 my_lst->print();

                 // ...

****************************************************************
*
*   END EXAMPLES BY ANALOGY
*
****************************************************************

****************************************************************
*
*   (2)  BEGIN   POINTERS VS NON-POINTERS DISCUSSION
*
****************************************************************


    In the C version, an application/client program a list is
    ALWAYS A POINTER and ALL memory associated with a list
    is dynamically allocated from the heap.

    However, in the C++ version, a List object ("instance") may
    be dynamically allocated from the heap OR it can be stack
    allocated -- well, at least the "top-level" object containing
    the front and back pointers; the Node structures are always
    heap allocated.

       // Heap vs. stack allocated List example
       void foo(){
          int x;
          List<int> obj;  // NON-POINTER
          List<int> *ptr;    // POINTER

          // at this point, one List object actually exists: obj.
          // 
          // The constructor List<int>() is implicitly invoked
          //   to initialize lst_object to an empty list.
          //
          //   The actual memory for obj come the call
          //   stack -- front and back pointers are stored on
          //   the call stack just like any other local variable
          //   (for example the int x).
          //
          // On the other hand, ptr is just an uninitialized pointer 
          //   at this point in the code.  Let's allocate and 
          //   initialize it on the next line:
          
          ptr = new List<int>();

          // now we have two List instances.  The List instance
          //    pointed to by ptr is completely heap allocated
          //    (the storage for its front and back fields were
          //    allocated from the heap).
          //
          //  suppose we want to push an 88 onto the front of 
          //    each of these lists.
          //
          //  Think of lst_object like a struct.  To access a field
          //    of a struct we use the DOT (".") operator right?
          //
          //    Now, think of the "member functions" in the list
          //    class also like "fields".  To call the push_front
          //    function on lst_object, we do this:
          //
          
          obj.push_front(88);

          // On the other hand, lst_ptr is a pointer to a List 
          //   instance.  So, to push an 88 on the front of THAT
          //   list, we do this:

          ptr->push_front(88);

          // blah blah blah... function foo() does some stuff

          // foo() is now about done.  Since foo() does not 
          //   return anything and does not have any parameters
          //   (reference or otherwise), both of our list objects
          //   must have served their purposes.
          //
          // In the case of ptr, we MUST explicitly deallocate it
          // like this:

          delete ptr;  // this results in the destructor being
                       //   called on *ptr (which results in the
                       //   individual Nodes being deallocated) AND
                       //   it deallocates the "top-level" storage
                       //   (where front and back are stored).

          // if we forget the above statement, we have a MEMORY
          // LEAK!
          //
          // On the other hand since obj is stack allocated what
          // happens is:
          //
          //     right before the function returns, all local variables
          //     are "cleaned up" because the are going "out of scope".
          //     For non-object local variables (like ints, pointers,
          //     etc.) there is really nothing to clean-up.
          //
          //     But for local variables which are objects like 
          //     obj in our example, the "cleanup" step IMPLICITLY
          //     invokes the descructor.
          //     
          //     Thus, the Nodes themselves (which are always heap
          //     allocated DO get deleted through this process).
          //     
          //     Punchline:  we do not explicitly delete
          //     stack allocate objects like obj in this example.
          //     In fact, you shouldn't even try!
          //
          //     RULE:  only introduce a "delete" statement when you
          //     hae a corresponding "new" statement.


NOTE:  under Prog1/sandbox you will find a program called
       Scope.cpp and a slightly modified List.h which demonstrates 
       the above behavior (implicit invocation of destructors).



****************************************************************
*
*   END POINTERS VS NON-POINTERS DISCUSSION
*
****************************************************************

****************************************************************
*
*   (3)  BEGIN  TEMPLATES / ElemType DISCUSSION
*
****************************************************************

In List.h, the C++ template feature is used so we can make our
List class "generic"  

This capability is probably one of the most powerful features in
C++:

   We write our List class using a generic placeholder (we used T)
   for the type of things being stored in the list.

   Then, when an application program decides they want a List of
   integers, they use the template notation like this:

        List<int> int_list;

   Here the variable is named int_list and its type is List<int> (or
   "list of integers").

   Similarly, if we also want a list of doubles, we can do this:

        List<double> d_list;

Very handy!

One way to think about what is really going on is to remember
the meaning of "template".  Technically List.h does not specify a
C++ class, but a "template" for many C++ classes.

When a client/application program has something like this:

        List<int>    int_list;
        List<double> d_list;

the compiler says 

        I need to generate the class List<int> using
         the template for List, and then I need to generate 
         the class for List<double>, again using the same 
         template.

         How do I do this?  

         More-or-less, by giving each of these classes their own 
         weird names that will not conflict with anything else and 
         generate the actual class bodies, again more-or-less, by 
         doing a find-and-replace on the placeholder T and the 
         desired type in <>.
         
Net result (mostly invisible to the programmer unless they really
do some exploring):

         One distinct class is generated for each unique 
         type specified (in the example above, one for <int> and
         one for <double>.

         This also means that a distinct version of each member
         function is also generated, and so on.

****************************************************************

CAN WE DO SOMETHING LIKE THIS (templates) IN C ??


    Not quite, but the given C linked list code (list.h and llist.c)
    employs kind of a poor-man's / poor-person's version of generic
    element types via the typedef for ElemType (and FORMAT_STRING).

    Not nearly as powerful as C++ templates, but at least by 
    changing just a couple of lines in list.h, we can switch from
    a list of integers to a list of doubles or some other type.

    Anyhow, that is what the type ElemType in list.h and llist.c
    is all about in case you were wondering.

 
