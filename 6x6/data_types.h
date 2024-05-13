#ifndef DATA_TYPES_H
#define DATA_TYPES_H

// ==================== WRITE YOUR OPTIONAL DATA TYPES IF YOU NEED =============

enum CITIES 
{
	A1, B1, C1, D1, E1, F1,
	A2, B2, C2, D2, E2, F2,
	A3, B3, C3, D3, E3, F3,
	A4, B4, C4, D4, E4, F4,
	A5, B5, C5, D5, E5, F5,
	A6, B6, C6, D6, E6, F6
};


// ====== WRITE YOUR COMPULSORY (BUT SPECIFIC TO THE PROBLEM) DATA TYPES =======

enum ACTIONS // All possible actions
{
	Go_A1, Go_A2, Go_A3, Go_A4, Go_A5, Go_A6,
	Go_B1, Go_B2, Go_B3, Go_B4, Go_B5, Go_B6,
	Go_C1, Go_C2, Go_C3, Go_C4, Go_C5, Go_C6,
	Go_D1, Go_D2, Go_D3, Go_D4, Go_D5, Go_D6,
	Go_E1, Go_E2, Go_E3, Go_E4, Go_E5, Go_E6,
	Go_F1, Go_F2, Go_F3, Go_F4, Go_F5, Go_F6
};

typedef struct State  
{
    enum CITIES city;
    float h_n;   // Heuristic function
      
}State;

// ================== YOU DO NOT NEED TO CHANGE THIS PART ======================

enum METHODS
{
	BreastFirstSearch = 1,   UniformCostSearch = 2,        DepthFirstSearch = 3,    
	DepthLimitedSearch= 4,   IterativeDeepeningSearch = 5, GreedySearch = 6,
    AStarSearch = 7, GeneralizedAStarSearch = 8  
};

// This struct is used to determine a new state and action in transition model
typedef struct Transition_Model
{
    State new_state;
    float step_cost;
}Transition_Model;

typedef struct Node
{
    State state;
    float path_cost;
    enum ACTIONS action; //The action applied to the parent to generate this node
    struct Node *parent;
    int Number_of_Child; // required for depth-first search algorithms
}Node;

typedef struct Queue  // Used for frontier
{
    Node *node;
    struct Queue *next;
}Queue;


#endif
