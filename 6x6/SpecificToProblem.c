/*
    These functions are compulsory for search algorithms but they are specific
    to problems. More clearly, you must must update their blocks but do not change
    their input and output parameters.

    Also, you can add new functions at the end of file by declaring them in GRAPH_SEARCH.h
*/

#include "GRAPH_SEARCH.h"
#include "data_types.h"
#include <stdio.h>
#include <stdlib.h>


//______________________________________________________________________________
State* Create_State()
{
    State* state = (State*)malloc(sizeof(State));
    if (state == NULL)
        Warning_Memory_Allocation();

    for (state->city = A1; state->city <= F6; state->city++)
    {
        printf("%d --> ", state->city);
        Print_State(state);
        printf("\n");
    }

    do
    {
        printf("Enter the code of the state: ");
        scanf("%d", &state->city);
    } while (state->city < 0 && state->city >= CITY_NUMBER);

    return state;
}

//______________________________________________________________________________
void Print_State(const State* const state)
{
    switch (state->city)
    {
    case A1:
        printf("A1");
        break;
    case B1:
        printf("B1");
        break;
    case C1:
        printf("C1");
        break;
    case D1:
        printf("D1");
        break;
    case E1:
        printf("E1");
        break;
    case F1:
        printf("F1");
        break;
    case A2:
        printf("A2");
        break;
    case B2:
        printf("B2");
        break;
    case C2:
        printf("C2");
        break;
    case D2:
        printf("D2");
        break;
    case E2:
        printf("E2");
        break;
    case F2:
        printf("F2");
        break;
    case A3:
        printf("A3");
        break;
    case B3:
        printf("B3");
        break;
    case C3:
        printf("C3");
        break;
    case D3:
        printf("D3");
        break;
    case E3:
        printf("E3");
        break;
    case F3:
        printf("F3");
        break;
    case A4:
        printf("A4");
        break;
    case B4:
        printf("B4");
        break;
    case C4:
        printf("C4");
        break;
    case D4:
        printf("D4");
        break;
    case E4:
        printf("E4");
        break;
    case F4:
        printf("F4");
        break;
    case A5:
        printf("A5");
        break;
    case B5:
        printf("B5");
        break;
    case C5:
        printf("C5");
        break;
    case D5:
        printf("D5");
        break;
    case E5:
        printf("E5");
        break;
    case F5:
        printf("F5");
        break;
    case A6:
        printf("A6");
        break;
    case B6:
        printf("B6");
        break;
    case C6:
        printf("C6");
        break;
    case D6:
        printf("D6");
        break;
    case E6:
        printf("E6");
        break;
    case F6:
        printf("F6");
        break;
    }
}

//______________________________________________________________________________
void Print_Action(const enum ACTIONS action)
{
    switch (action)
    {
    case Go_A1:
        printf("Go_A1");
        break;
    case Go_B1:
        printf("Go_B1");
        break;
    case Go_C1:
        printf("Go_C1");
        break;
    case Go_D1:
        printf("Go_D1");
        break;
    case Go_E1:
        printf("Go_E1");
        break;
    case Go_F1:
        printf("Go_F1");
        break;
    case Go_A2:
        printf("Go_A2");
        break;
    case Go_B2:
        printf("Go_B2");
        break;
    case Go_C2:
        printf("Go_C2");
        break;
    case Go_D2:
        printf("Go_D2");
        break;
    case Go_E2:
        printf("Go_E2");
        break;
    case Go_F2:
        printf("Go_F2");
        break;
    case Go_A3:
        printf("Go_A3");
        break;
    case Go_B3:
        printf("Go_B3");
        break;
    case Go_C3:
        printf("Go_C3");
        break;
    case Go_D3:
        printf("Go_D3");
        break;
    case Go_E3:
        printf("Go_E3");
        break;
    case Go_F3:
        printf("Go_F3");
        break;
    case Go_A4:
        printf("Go_A4");
        break;
    case Go_B4:
        printf("Go_B4");
        break;
    case Go_C4:
        printf("Go_C4");
        break;
    case Go_D4:
        printf("Go_D4");
        break;
    case Go_E4:
        printf("Go_E4");
        break;
    case Go_F4:
        printf("Go_F4");
        break;
    case Go_A5:
        printf("Go_A5");
        break;
    case Go_B5:
        printf("Go_B5");
        break;
    case Go_C5:
        printf("Go_C5");
        break;
    case Go_D5:
        printf("Go_D5");
        break;
    case Go_E5:
        printf("Go_E5");
        break;
    case Go_F5:
        printf("Go_F5");
        break;
    case Go_A6:
        printf("Go_A6");
        break;
    case Go_B6:
        printf("Go_B6");
        break;
    case Go_C6:
        printf("Go_C6");
        break;
    case Go_D6:
        printf("Go_D6");
        break;
    case Go_E6:
        printf("Go_E6");
        break;
    case Go_F6:
        printf("Go_F6");
        break;
    }
}
//______________________________________________________________________________
int Result(const State *const parent_state, const enum ACTIONS action, Transition_Model *const trans_model)
{
    State new_state;
    const int PATH_COSTS[CITY_NUMBER][ACTIONS_NUMBER] =
//   Gidilecek noktalar
//   A1 B1 C1 D1 E1 F1 A2 B2 C2 D2 E2 F2 A3 B3 C3 D3 E3 F3 A4 B4 C4 D4 E4 F4 A5 B5 C5 D5 E5 F5 A6 B6 C6 D6 E6 F6

    {0, 3, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},   // A1
    { 1, 0, -9, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },   // B1
    { -1, -9, 0, -9, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },  // C1
    { -1, -1, -9, 0, 1, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },   // D1
    { -1, -1, -1, 1, 0, 1, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },    // E1
    { -1, -1, -1, -1, 1, 0, 1, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },     // F1

//   A1 B1 C1 D1 E1 F1 A2 B2 C2 D2 E2 F2 A3 B3 C3 D3 E3 F3 A4 B4 C4 D4 E4 F4 A5 B5 C5 D5 E5 F5 A6 B6 C6 D6 E6 F6

    {0, 3, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},   // A2
    { 1, 0, -9, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },   // B2
    { -1, -9, 0, -9, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },  // C2
    { -1, -1, -9, 0, 1, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },   // D2
    { -1, -1, -1, 1, 0, 1, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },    // E2
    { -1, -1, -1, -1, 1, 0, 1, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },     // F2
//   A1 B1 C1 D1 E1 F1 A2 B2 C2 D2 E2 F2 A3 B3 C3 D3 E3 F3 A4 B4 C4 D4 E4 F4 A5 B5 C5 D5 E5 F5 A6 B6 C6 D6 E6 F6

    {0, 3, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},   // A3
    { 1, 0, -9, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },   // B3
    { -1, -9, 0, -9, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },  // C3
    { -1, -1, -9, 0, 1, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },   // D3
    { -1, -1, -1, 1, 0, 1, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },    // E3
    { -1, -1, -1, -1, 1, 0, 1, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },     // F3
//   A1 B1 C1 D1 E1 F1 A2 B2 C2 D2 E2 F2 A3 B3 C3 D3 E3 F3 A4 B4 C4 D4 E4 F4 A5 B5 C5 D5 E5 F5 A6 B6 C6 D6 E6 F6

    {0, 3, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},   // A4
    { 1, 0, -9, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },   // B4
    { -1, -9, 0, -9, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },  // C4
    { -1, -1, -9, 0, 1, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },   // D4
    { -1, -1, -1, 1, 0, 1, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },    // E4
    { -1, -1, -1, -1, 1, 0, 1, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },     // F4
//   A1 B1 C1 D1 E1 F1 A2 B2 C2 D2 E2 F2 A3 B3 C3 D3 E3 F3 A4 B4 C4 D4 E4 F4 A5 B5 C5 D5 E5 F5 A6 B6 C6 D6 E6 F6

    {0, 3, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},   // A5
    { 1, 0, -9, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },   // B5
    { -1, -9, 0, -9, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },  // C5
    { -1, -1, -9, 0, 1, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },   // D5
    { -1, -1, -1, 1, 0, 1, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },    // E5
    { -1, -1, -1, -1, 1, 0, 1, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },     // F5
//   A1 B1 C1 D1 E1 F1 A2 B2 C2 D2 E2 F2 A3 B3 C3 D3 E3 F3 A4 B4 C4 D4 E4 F4 A5 B5 C5 D5 E5 F5 A6 B6 C6 D6 E6 F6

    {0, 3, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},   // A6
    { 1, 0, -9, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },   // B6
    { -1, -9, 0, -9, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },  // C6
    { -1, -1, -9, 0, 1, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },   // D6
    { -1, -1, -1, 1, 0, 1, -1, -1, -1, -1, -1, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },    // E6
    { -1, -1, -1, -1, 1, 0, 1, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },     // F6
        };

   

   

    if (PATH_COSTS[parent_state->city][action] <= 0)
        return FALSE;
    else
    {
        new_state.city = action;
        trans_model->new_state = new_state;
        trans_model->step_cost = PATH_COSTS[parent_state->city][action];
    }
    return TRUE;
}

//______________________________________________________________________________
float Compute_Heuristic_Function(const State *const state, const State *const goal)
{
    const float SLD[CITY_NUMBER][CITY_NUMBER] = 
                // CALCULATED ROUGHLY!!!
            //   Gidilecek noktalar
        //   A1   B1   C1   D1   E1   F1   A2   B2   C2   D2   E2   F2  A3   B3   C3   D3   E3   F3   A4   B4   C4   D4   E4   F4   A5   B5   C5   D5   E5   F5   A6   B6   C6   D6   E6   F6     //BAŞLANGIÇ NOKTASI
        {
            {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 1.0, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 7.1, 2.0, 2.2, 2.8, 3.6, 4.5, 5.4, 6.3, 7.3, 3.0, 3.1, 3.6, 4.2, 5.0, 5.8, 6.7, 7.6, 4.0, 4.1, 4.5, 5.0}, // A1
            {1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 1.4, 1.0, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 2.2, 2.0, 2.2, 2.8, 3.6, 4.5, 5.4, 6.3, 3.1, 3.0, 3.1, 3.6, 4.2, 5.0, 5.8, 6.7, 4.1, 4.0, 4.1, 4.5}, // B1
            {2.0, 1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 2.2, 1.4, 1.0, 1.4, 2.2, 3.1, 4.1, 5.1, 2.8, 2.2, 2.0, 2.2, 2.8, 3.6, 4.5, 5.4, 3.6, 3.1, 3.0, 3.1, 3.6, 4.2, 5.0, 5.8, 4.5, 4.1, 4.0, 4.1}, // C1
            {3.0, 2.0, 1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 3.1, 2.2, 1.4, 1.0, 1.4, 2.2, 3.1, 4.1, 3.6, 2.8, 2.2, 2.0, 2.2, 2.8, 3.6, 4.5, 4.2, 3.6, 3.1, 3.0, 3.1, 3.6, 4.2, 5.0, 5.0, 4.5, 4.1, 4.0}, // D1
            {4.0, 3.0, 2.0, 1.0, 0.0, 1.0, 2.0, 3.0, 4.1, 3.1, 2.2, 1.4, 1.0, 1.4, 2.2, 3.1, 4.5, 3.6, 2.8, 2.2, 2.0, 2.2, 2.8, 3.6, 5.0, 4.2, 3.6, 3.1, 3.0, 3.1, 3.6, 4.2, 5.7, 5.0, 4.5, 4.1}, // E1
            {5.0, 4.0, 3.0, 2.0, 1.0, 0.0, 1.0, 2.0, 5.1, 4.1, 3.1, 2.2, 1.4, 1.0, 1.4, 2.2, 5.4, 4.5, 3.6, 2.8, 2.2, 2.0, 2.2, 2.8, 5.8, 5.0, 4.2, 3.6, 3.1, 3.0, 3.1, 3.6, 6.4, 5.7, 5.0, 4.5}, // F1
            
        //   A1   B1   C1   D1   E1   F1   A2   B2   C2   D2   E2   F2  A3   B3   C3   D3   E3   F3   A4   B4   C4   D4   E4   F4   A5   B5   C5   D5   E5   F5   A6   B6   C6   D6   E6   F6
            {1.0, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 7.1, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 1.0, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 7.1, 2.0, 2.2, 2.8, 3.6, 4.5, 5.4, 6.3, 7.3, 3.0, 3.1, 3.6, 4.2}, // A2
            {1.4, 1.0, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 1.4, 1.0, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 2.2, 2.0, 2.2, 2.8, 3.6, 4.5, 5.4, 6.3, 3.1, 3.0, 3.1, 3.6}, // B2
            {2.2, 1.4, 1.0, 1.4, 2.2, 3.1, 4.1, 5.1, 2.0, 1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 2.2, 1.4, 1.0, 1.4, 2.2, 3.1, 4.1, 5.1, 2.8, 2.2, 2.0, 2.2, 2.8, 3.6, 4.5, 5.4, 3.6, 3.1, 3.0, 3.1}, // C2
            {3.1, 2.2, 1.4, 1.0, 1.4, 2.2, 3.1, 4.1, 3.0, 2.0, 1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 3.1, 2.2, 1.4, 1.0, 1.4, 2.2, 3.1, 4.1, 3.6, 2.8, 2.2, 2.0, 2.2, 2.8, 3.6, 4.5, 4.2, 3.6, 3.1, 3.0}, // D2
            {4.1, 3.1, 2.2, 1.4, 1.0, 1.4, 2.2, 3.1, 4.0, 3.0, 2.0, 1.0, 0.0, 1.0, 2.0, 3.0, 4.1, 3.1, 2.2, 1.4, 1.0, 1.4, 2.2, 3.1, 4.5, 3.6, 2.8, 2.2, 2.0, 2.2, 2.8, 3.6, 5.0, 4.2, 3.6, 3.1}, // E2
            {5.1, 4.1, 3.1, 2.2, 1.4, 1.0, 1.4, 2.2, 5.0, 4.0, 3.0, 2.0, 1.0, 0.0, 1.0, 2.0, 5.1, 4.1, 3.1, 2.2, 1.4, 1.0, 1.4, 2.2, 5.4, 4.5, 3.6, 2.8, 2.2, 2.0, 2.2, 2.8, 5.8, 5.0, 4.2, 3.6}, // F2
           
        //   A1   B1   C1   D1   E1   F1   A2   B2   C2   D2   E2   F2  A3   B3   C3   D3   E3   F3   A4   B4   C4   D4   E4   F4   A5   B5   C5   D5   E5   F5   A6   B6   C6   D6   E6   F6
            {2, 2.2, 2.8, 3.6, 5.1, 5.4, 6.3, 7.3, 1, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 7.1, 0, 1, 2, 3, 4, 5, 6, 7, 1, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 7.1, 2, 2.2, 2.8, 3.6},  // A3
            {2.2, 2, 2.2, 2.8, 3.6, 5.1, 5.4, 6.3, 1.4, 1, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 1, 0, 1, 2, 3, 4, 5, 6, 1.4, 1, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 2.2, 2, 2.2, 2.8}, // B3
            {2.8, 2.2, 2, 2.2, 2.8, 3.6, 5.1, 5.4, 2.2, 1.4, 1, 1.4, 2.2, 3.1, 4.1, 5.1, 2, 1, 0, 1, 2, 3, 4, 5, 2.2, 1.4, 1, 1.4, 2.2, 3.1, 4.1, 5.1, 2.8, 2.2, 2, 2.2}, // C3
            {3.6, 2.8, 2.2, 2, 2.2, 2.8, 3.6, 5.1, 3.1, 2.2, 1.4, 1, 1.4, 2.2, 3.1, 4.1, 3, 2, 1, 0, 1, 2, 3, 4, 3.1, 2.2, 1.4, 1, 1.4, 2.2, 3.1, 4.1, 3.6, 2.8, 2.2, 2},   // D3
            {5.1, 3.6, 2.8, 2.2, 2, 2.2, 2.8, 3.6, 4.1, 3.1, 2.2, 1.4, 1, 1.4, 2.1, 3.1, 4, 3, 2, 1, 0, 1, 2, 3, 4.1, 3.1, 2.2, 1.4, 1, 1.4, 2.2, 3.1, 5.1, 3.6, 2.8, 2.2},   // E3
            {5.4, 5.1, 3.6, 2.8, 2.2, 2, 2.2, 2.8, 5.1, 4.1, 3.1, 2.2, 1.4, 1, 1.4, 2.2, 5, 4, 3, 2, 1, 0, 1, 2, 5.1, 4.1, 3.1, 2.2, 1.4, 1, 1.4, 2.2, 5.4, 5.1, 3.6, 2.8}, // F3
           
       //   A1   B1   C1   D1   E1   F1   A2   B2  C2   D2  E2   F2  A3   B3   C3   D3   E3  F3   A4   B4   C4   D4   E4   F4   A5   B5   C5   D5   E5   F5   A6   B6   C6   D6   E6   F6
            {3, 3.1, 3.6, 4.2, 5.3, 5.8, 6.7, 7.6, 2, 2.2, 2.8, 3.6, 5.1, 5.4, 6.3, 7.3, 1, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 7.1, 0, 1, 2, 3, 4, 5, 6, 7, 1, 1.4, 2.2, 3.1},   // A4
            {3.1, 3, 3.1, 3.6, 4.2, 5.3, 5.8, 6.7, 2.2, 2, 2.2, 2.8, 3.6, 5.1, 5.4, 6.3, 1.4, 1, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 1, 0, 1, 2, 3, 4, 5, 6, 1.4, 1, 1.4, 2.2}, // B4
            {3.6, 3.1, 3, 3.1, 3.6, 4.2, 5.3, 5.8, 2.8, 2.2, 2, 2.2, 2.8, 3.6, 5.1, 5.4, 2.2, 1.4, 1, 1.4, 2.2, 3.1, 4.1, 5.1, 2, 1, 0, 1, 2, 3, 4, 5, 2.2, 1.4, 1, 1.4}, // C4
            {4.2, 3.6, 3.1, 3, 3.1, 3.6, 4.2, 5.3, 3.6, 2.8, 2.2, 2, 2.2, 2.8, 3.6, 5.1, 3.1, 2.2, 1.4, 1, 1.4, 2.2, 3.1, 4.1, 3, 2, 1, 0, 1, 2, 3, 4, 3.1, 2.2, 1.4, 1},   // D4
            {5, 4.2, 3.6, 3.1, 3, 3.1, 3.6, 4.2, 5.1, 3.6, 2.8, 2.2, 2, 2.2, 2.8, 3.6, 4.1, 3.1, 2.2, 1.4, 1, 1.4, 2.2, 3.1, 4, 3, 2, 1, 0, 1, 2, 3, 4.1, 3.1, 2.2, 1.4},     // E4
            {5.8, 5.4, 4.2, 3.6, 3.1, 3, 3.1, 3.6, 5.4, 5.1, 3.6, 2.8, 2.2, 2, 2.2, 2.8, 5.1, 4.1, 3.1, 2.2, 1.4, 1, 1.4, 2.2, 5, 4, 3, 2, 1, 0, 1, 2, 5.1, 4.1, 3.1, 2.2}, // F4
           
        //   A1   B1   C1   D1   E1   F1   A2   B2   C2   D2   E2   F2  A3   B3   C3   D3   E3   F3   A4   B4   C4   D4   E4   F4   A5   B5   C5   D5   E5   F5   A6   B6   C6   D6   E6   F6
            {4.0, 4.1, 4.5, 5.0, 5.7, 6.4, 7.2, 8.0, 3.0, 3.1, 3.6, 4.2, 5.0, 5.8, 6.7, 7.6, 2.0, 2.2, 2.8, 3.6, 4.5, 5.4, 6.3, 7.3, 1.0, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 7.1, 0.0, 1.0, 2.0, 3.0}, // A5
            {4.1, 4.0, 4.1, 4.5, 5.0, 5.7, 6.4, 7.2, 3.1, 3.0, 3.1, 3.6, 4.2, 5.0, 5.8, 6.7, 2.2, 2.0, 2.2, 2.8, 3.6, 4.5, 5.4, 6.3, 1.4, 1.0, 1.4, 2.2, 3.1, 4.1, 5.1, 6.1, 1.0, 0.0, 1.0, 2.0}, // B5
            {4.5, 4.1, 4.0, 4.1, 4.5, 5.0, 5.7, 6.4, 3.6, 3.1, 3.0, 3.1, 3.6, 4.2, 5.0, 5.8, 2.8, 2.2, 2.0, 2.2, 2.8, 3.6, 4.5, 5.4, 2.2, 1.4, 1.0, 1.4, 2.2, 3.1, 4.1, 5.1, 2.0, 1.0, 0.0, 1.0}, // C5
            {5.0, 4.5, 4.1, 4.0, 4.1, 4.5, 5.0, 5.7, 4.2, 3.6, 3.1, 3.0, 3.1, 3.6, 4.2, 5.0, 3.6, 2.8, 2.2, 2.0, 2.2, 2.8, 3.6, 4.5, 3.1, 2.2, 1.4, 1.0, 1.4, 2.2, 3.1, 4.1, 3.0, 2.0, 1.0, 0.0}, // D5
            {5.7, 5.0, 4.5, 4.1, 4.0, 4.1, 4.5, 5.0, 5.0, 4.2, 3.6, 3.1, 3.0, 3.1, 3.6, 4.2, 4.5, 3.6, 2.8, 2.2, 2.0, 2.2, 2.8, 3.6, 4.1, 3.1, 2.2, 1.4, 1.0, 1.4, 2.2, 3.1, 4.0, 3.0, 2.0, 1.0}, // E5
            {6.4, 5.7, 5.0, 4.5, 4.1, 4.0, 4.1, 4.5, 5.8, 5.0, 4.2, 3.6, 3.1, 3.0, 3.1, 3.6, 5.4, 4.5, 3.6, 2.8, 2.2, 2.0, 2.2, 2.8, 5.1, 4.1, 3.1, 2.2, 1.4, 1.0, 1.4, 2.2, 5.0, 4.0, 3.0, 2.0}, // F5
           
        //   A1   B1   C1   D1   E1   F1   A2   B2   C2   D2   E2   F2  A3   B3   C3   D3   E3   F3   A4   B4   C4   D4   E4   F4   A5   B5   C5   D5   E5   F5   A6   B6   C6   D6   E6   F6
            {5.0, 5.1, 5.4, 5.8, 6.4, 7.1, 7.8, 8.6, 4.0, 4.1, 4.5, 5.0, 5.7, 6.4, 7.2, 8.0, 3.0, 3.1, 3.6, 4.2, 5.0, 5.8, 6.7, 7.6, 2.0, 2.2, 2.8, 3.6, 4.5, 5.4, 6.3, 7.3, 1.0, 1.4, 2.2, 3.1}, // A5
            {5.1, 5.0, 5.1, 5.4, 5.8, 6.4, 7.1, 7.8, 4.1, 4.0, 4.1, 4.5, 5.0, 5.7, 6.4, 7.2, 3.1, 3.0, 3.1, 3.6, 4.2, 5.0, 5.8, 6.7, 2.2, 2.0, 2.2, 2.8, 3.6, 4.5, 5.4, 6.3, 1.4, 1.0, 1.4, 2.2}, // B5
            {5.4, 5.1, 5.0, 5.1, 5.4, 5.8, 6.4, 7.1, 4.5, 4.1, 4.0, 4.1, 4.5, 5.0, 5.7, 6.4, 3.6, 3.1, 3.0, 3.1, 3.6, 4.2, 5.0, 5.8, 2.8, 2.2, 2.0, 2.2, 2.8, 3.6, 4.5, 5.4, 2.2, 1.4, 1.0, 1.4}, // C5
            {5.8, 5.4, 5.1, 5.0, 5.1, 5.4, 5.8, 6.4, 5.0, 4.5, 4.1, 4.0, 4.1, 4.5, 5.0, 5.7, 4.2, 3.6, 3.1, 3.0, 3.1, 3.6, 4.2, 5.0, 3.6, 2.8, 2.2, 2.0, 2.2, 2.8, 3.6, 4.5, 3.1, 2.2, 1.4, 1.0}, // D5
            {6.4, 5.8, 5.4, 5.1, 5.0, 5.1, 5.4, 5.8, 5.7, 5.0, 4.5, 4.1, 4.0, 4.1, 4.5, 5.0, 5.0, 4.2, 3.6, 3.1, 3.0, 3.1, 3.6, 4.2, 4.5, 3.6, 2.8, 2.2, 2.0, 2.2, 2.8, 3.6, 4.1, 3.1, 2.2, 1.4}, // E5
            {7.1, 6.4, 5.8, 5.4, 5.1, 5.0, 5.1, 5.4, 6.4, 5.7, 5.0, 4.5, 4.1, 4.0, 4.1, 4.5, 5.8, 5.0, 4.2, 3.6, 3.1, 3.0, 3.1, 3.6, 5.4, 4.5, 3.6, 2.8, 2.2, 2.0, 2.2, 2.8, 5.1, 4.1, 3.1, 2.2}, // F5
            
        };
    return SLD[state->city][goal->city];
}

//_______________ Update if your goal state is not determined initially ___________________________________
int Goal_Test(const State *const state, const State *const goal_state)
{
    if (PREDETERMINED_GOAL_STATE)
        return Compare_States(state, goal_state);
    else
        return 1;
}

// ==================== WRITE YOUR OPTIONAL FUNCTIONS (IF REQUIRED) ==========================
