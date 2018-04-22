


Name: hubert budzik

-----------------------------------------------

Please confirm that you compiled your solution with test cases exercising ALL
functions using g++ -std=c++11.  Confirm this statement by typing YES below.
(If you did not do this, compilation errors may result in an overall grade of
zero!)
yes





Describe what augmentations to the bst data structures you made to complete the 
project -- i.e., what types / data members did you change and why?


i modified my bst class and added few new variables:
int size:	to keep measure the size of my bst
int min and int max: 	to keep minimum and maximum elements of my bst

int my bsd_node struct i added two new variables
int leftCount and int rightCount	: they contain number of children on the left side of the tree and on the right side 





-----------------------------------------------
Which functions did you need to modify as a result of the augmentations from the previous
question?  

bool insert(T & x)
static bst_node * _insert(bst_node *r, T & x, bool &success)
bool remove(T & x)
static bst_node * _remove(bst_node *r, T & x, bool &success)





-----------------------------------------------
For each function from the previous question, how did you ensure that the (assymptotic) runtime 
remained the same?









-----------------------------------------------
For each of the assigned functions, tell us how far you got using the choices 0-5 and
answer the given questions.  


0:  didn't get started
1:  started, but far from working
2:  have implementation but only works for simple cases
3:  finished and I think it works most of the time but not sure the runtime req is met. 
4:  finished and I think it works most of the time and I'm sure my design leads to 
       the correct runtime (even if I still have a few bugs).
5:  finished and confident on correctness and runtime requirements


to_vector level of completion:  ______1_____  


-----------------------------------------------
get_ith level of completion:  _______1____  

    How did you ensure O(h) runtime?

    ANSWER:

-----------------------------------------------
num_geq level of completion:  _______5____  

    How did you ensure O(h) runtime?

    ANSWER:

-----------------------------------------------
num_leq level of completion:  _______5_____

    How did you ensure O(h) runtime?

    ANSWER:

-----------------------------------------------
num_range level of completion:  _____1_______

    How did you ensure O(h) runtime?

    ANSWER:

-----------------------------------------------
Implementation of size-balanced criteria according to 
the given guidelines (including bst_sb_work):

    Level of completion: ____1_______


Write a few sentences describing how you tested your solutions.  Are there
any tests that in retrospect you wish you'd done?











