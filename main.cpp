//
//  main.cpp
//  Discrete Project #2
//  Copyright (c) 2014 Evan Chipps. All rights reserved.
//

#include <iostream>
#include <algorithm>


using namespace std;


    int incidentmatrix[15][21]= {{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1}};

    double roadinfo[21][3]= {{50, .05, 00},
                             {70, .20, 10},
                             {25, .10, 00},
                             {100, .05, 00},
                             {61, .10, 10},
                             {51, .10, 00},
                             {41, .05, 10},
                             {59, .10, 00},
                             {54, .10, 10},
                             {63, .25, 00},
                             {35, .01, 00},
                             {50, .95, 00},
                             {50, .95, 00},
                             {80, .20, 00},
                             {35, .10, 00},
                             {135, .00, 00},
                             {40, .05, 00},
                             {35, .02, 00},
                             {15, .05, 00},
                             {30, .03, 00},
                             {34, .10, 00}};
double getDistance(int road);
double getDanger(int road);
double getToll(int road);
void getNode(int node, int (&adjacent)[6]);
int getRoad(int a, int b);
int nodedistance[21];
double minFunction( double a, double b);
int minDistance(int nodeFrom, int nodeTo);
double minDanger(int nodeFrom, int nodeTo);
int allDistance(int nodeFrom, int nodeTo);
int minCost(int nodeFrom, int nodeTo);

int main(int argc, const char * argv[])
{
    
    
//   Problem 1
    
      int distance=0;
    distance = minDistance(7, 9);
    cout << "Problem 1: " << endl << endl;
    cout << "The Shortest Distance is equal to : " << distance << endl << endl;
    
//   Problem 2
    
    double danger =0;
    
    danger = minDanger(7, 9);
    cout << "Problem 2: " << endl << endl;
    cout << "The least danger is equal to : " << danger << endl << endl;
    
    
//   Problem 3
    
    distance = minCost(9, 1);
    cout << "Problem 3: " << endl << endl;
    cout << "The Shortest Distance under 10 dollars is equal to : " << distance << endl << endl;
    
    
//   Problem 4
    
    distance = minDistance(1, 12);
    cout << "Problem 4: " << endl << endl;
    cout << "The Shortest Distance is equal to : " << distance << endl << endl;
    

//   Problem 5
    distance = allDistance(12,4);
    cout << "Problem 5: " << endl << endl;
    cout << "The Shortest Distance while traversing all the nodes is equal to : " << distance << endl << endl;
    
    
   
    return 0;
}


double getDistance(int road){
    
    road--;
    
    return roadinfo[road][0];
};

double getDanger(int road){
  
    road--;
    
    return roadinfo[road][1];
};

double getToll(int road){
  
    road--;
    
    return roadinfo[road][2];
};

double minFunction( double a, double b){
  if (a < b)
      return a;
  else
      return b;
};

void getNode(int node, int (&adjacent)[6]){
  
    int length=0;
    for (int i=0; i < 21; i++)
    {
        if (incidentmatrix[node][i] == 1){
            for (int j=0; j<15; j++){
                if (incidentmatrix[j][i] == 1 && j!= node)
                {
                  adjacent[length]=j;
                    length++;
                }
            }
        }
    }
};

int getRoad(int a, int b){
    for (int i=0; i<21; i++){
        if (incidentmatrix[a][i]==1 && incidentmatrix[b][i]==1){
            return i+1;
        }
    }
    return NULL;
};

int minDistance(int nodeFrom, int nodeTo){
    
    int distance =0;
    
    if (nodeTo != nodeFrom){
        
        
        int L[15]; // length matrix
        int adjacent[6]={-1,-1,-1,-1,-1,-1};
        int v=0;
        int location =0;
        int sizeofT=15;
        int T[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}; // node matrix
        int check = 1;
        for (int i=0; i<15; i++)
            {L[i]=2500;}
        
        L[nodeFrom]=0;
        
        // while z is an element in T
        while (check == 1){
            
            //Choose v as an element of T with minimum L(v)
            v=T[0];
            location=0;
            for (int i=0; i < sizeofT; i++)
            {
                //cout << endl << "i : " << i << "  L[T[i]]: " << L[T[i]] << "  v: " << v << endl;
                if (L[T[i]] < L[v] ){
                    v= T[i];
                    location = i;
                }
            }
            
            ///////////////////////////   TEST /////////////////////////////////////
//            cout << "V:  " << v << endl << endl;
//            cout << "location = " << location<< endl;
//            
            ///////////////////////////   TEST /////////////////////////////////////
            
            
            // T = T - {v}
           while (location != sizeofT)
           {
               T[location] = T[location+1];
               location++;
           }
            sizeofT--;
            
            ///////////////////////////   TEST /////////////////////////////////////
//            cout << " T after deleting v" << endl;
//            for (int i=0; i< sizeofT; i++)
//            {
//                cout << T[i] << ", ";
//            }
//            cout << endl;
            ///////////////////////////   TEST /////////////////////////////////////

            
            //find array of adjacent x's as elements of T
            getNode( v , adjacent);
            
            ///////////////////////////   TEST /////////////////////////////////////
//            cout << " adjacent after Get Node Call:" << endl;
//            for (int i=0; i< 6; i++)
//            {
//                cout << adjacent[i] << ", ";
//            }
//            cout << endl;
            ///////////////////////////   TEST /////////////////////////////////////
            
            
            
            
            //for each of those adjacent x's, L(x) = min{L(x),L(v)+w(v,x)}
            for (int i=0; i<6; i++){
                if (adjacent[i] != -1){
                    L[adjacent[i]] = minFunction( (L[adjacent[i]]) , (L[v]+ getDistance(getRoad(adjacent[i], v))) );
                    ///////////////////////////   TEST /////////////////////////////////////
//                    cout <<   "Road from: " << adjacent[i] << " and " << v << " equals: " << getRoad(adjacent[i],v) << endl << endl;
//                    cout <<  "Distance of " << adjacent[i] << " equals: " << L[adjacent[i]] << endl << endl;
                    ///////////////////////////   TEST /////////////////////////////////////
                }
            }
            
            ///////////////////////////   TEST /////////////////////////////////////
//            cout << " L is equal to:" << endl;
//            for (int i=0; i< 15; i++)
//            {
//                cout << L[i] << ", ";
//            }
//            cout << endl << endl << endl;
            ///////////////////////////   TEST /////////////////////////////////////
            
            
            // Check if z is in T
            check = 0;
            for (int i=0; i<sizeofT; i++)
            {
                if (T[i] == nodeTo){
                    check = 1;
                    break;
                }
            }
            for (int i=0; i<6; i++){
                adjacent[i]=-1;
            }
            
        }
        distance = L[nodeTo];
    }
    
    return distance;
    
};


int allDistance(int nodeFrom, int nodeTo){
    
    int distance =0;
    bool nodeCheck;
        
    int L[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // length matrix
    int adjacent[6]={-1,-1,-1,-1,-1,-1};
    int c = nodeFrom;
    int adDistance, nextNode = -1, Lcheck;
    
    int check = 1;
    for (int i=0; i<15; i++)
    {L[i]=0;}
    
    L[c] =5;
    L[nodeTo]=1;
    L[13]=1;
    
    // while L contains a 0 (an un-traversed node)
    while (check == 1){
        
        // Get Adjacent Nodes
        adDistance = 2500;
        getNode(c, adjacent);
        Lcheck=10;
        nodeCheck =true;

        ///////////////////////////   TEST /////////////////////////////////////
//       cout << "Current Node " << c +1 << endl << endl;
//        cout << "adjacent = ";
//        for (int i=0; i<6; i++)
//        {
//            cout << adjacent[i] << ", ";
//        }
//        cout << endl <<  "L = ";
//        for (int i=0; i<15; i++)
//        {
//            cout << L[i] << ", ";
//        }
//        cout << endl << endl;
        ///////////////////////////   TEST /////////////////////////////////////
        
        // Pick Node to move to
        for (int i=0; i<6; i++){
            if (adjacent[i] != -1)
            {
                nodeCheck = true;
                for (int j=0; j<6; j++){
                    if (j != i && adjacent[i] != -1 && adjacent[j] != -1){
                        //cout << "i= " << i << "  j= " << j << endl<< endl;
                        if( L[adjacent[i]] >= L[adjacent[j]]){
                            nodeCheck = false;
                        }
                    }
                    if ( adjacent[j] != -1 && L[adjacent[j]] < Lcheck)
                    {
                        //cout << "L[Adjacent[" << j << "]] = " << L[adjacent[j]]<< endl;
                        Lcheck = L[adjacent[j]];
                    }
                }
                //cout << " L Check = " << Lcheck << endl;
                if (nodeCheck == true)
                    nextNode = adjacent[i];
                else if (getDistance(getRoad(adjacent[i],c)) <= adDistance && L[adjacent[i]] == Lcheck) {
                    adDistance = getDistance(getRoad(adjacent[i],c));
//                    cout << "distance = " << adDistance << endl;
//                    cout << "Road = " << getRoad(adjacent[i],c) << endl;
                    nextNode = adjacent[i];
                }
//                cout << "nextNode = " << nextNode << endl;
            }
        }
        
        
        
        // Move current node to NextNode
        if (nextNode == -1)
        {
            cout << "error NextNode = -1 " << endl << endl;
            break;
        }
        distance += getDistance(getRoad(nextNode,c));
//        cout << "Distance= " << distance << endl;
        L[c]++;
        c = nextNode;
        
        
        
        // Check if L for 0
        check = 0;
        for (int i=0; i<15; i++)
        {
            if (L[i] == 0){
                check = 1;
            }
        }
        for (int i=0; i<6; i++){
            adjacent[i]=-1;
        }
        
    }
    
    
    
    return distance;
    
};


double minDanger(int nodeFrom, int nodeTo){
    
    double danger= 0;
    
    if (nodeTo != nodeFrom){
        
        
        double L[15]; // danger matrix
        int adjacent[6]={-1,-1,-1,-1,-1,-1};
        int v=0;
        double dangerNum;
        double inverseA, inverseB;
        int location =0;
        int sizeofT=15;
        int T[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}; // node matrix
        int check = 1;
        for (int i=0; i<15; i++)
        {L[i]=100.0;}
        
        L[nodeFrom]=0.0;
        
        // while z is an element in T
        while (check == 1){
            
            //Choose v as an element of T with minimum L(v)
            v=T[0];
            location=0;
            for (int i=0; i < sizeofT; i++)
            {
                //cout << endl << "i : " << i << "  L[T[i]]: " << L[T[i]] << "  v: " << v << endl;
                if (L[T[i]] < L[v] ){
                    v= T[i];
                    location = i;
                }
            }
            
            ///////////////////////////   TEST /////////////////////////////////////
//                        cout << "V:  " << v << endl << endl;
//                        cout << "location = " << location<< endl;
            ///////////////////////////   TEST /////////////////////////////////////
            
            
            // T = T - {v}
            while (location != sizeofT)
            {
                T[location] = T[location+1];
                location++;
            }
            sizeofT--;
            
            ///////////////////////////   TEST /////////////////////////////////////
            //            cout << " T after deleting v" << endl;
            //            for (int i=0; i< sizeofT; i++)
            //            {
            //                cout << T[i] << ", ";
            //            }
            //            cout << endl;
            ///////////////////////////   TEST /////////////////////////////////////
            
            
            //find array of adjacent x's as elements of T
            getNode( v , adjacent);
            
            ///////////////////////////   TEST /////////////////////////////////////
            //            cout << " adjacent after Get Node Call:" << endl;
            //            for (int i=0; i< 6; i++)
            //            {
            //                cout << adjacent[i] << ", ";
            //            }
            //            cout << endl;
            ///////////////////////////   TEST /////////////////////////////////////
            
            
            
            
            //for each of those adjacent x's, L(x) = min{L(x),L(v)+w(v,x)}
            for (int i=0; i<6; i++){
                if (adjacent[i] != -1){
                    if (L[v] == 0){
                        dangerNum = getDanger(getRoad(adjacent[i], v));
                        L[adjacent[i]] = minFunction( (L[adjacent[i]]) , dangerNum );}
                    else{
                        dangerNum = getDanger(getRoad(adjacent[i], v));
                        inverseA = 1 - L[v];
                        inverseB = 1 - dangerNum;
                        dangerNum = 1 - (inverseA * inverseB);
                    L[adjacent[i]] = minFunction( (L[adjacent[i]]) , dangerNum );

                    }
                    
                    ///////////////////////////   TEST /////////////////////////////////////
//                                        cout <<   "Road from: " << adjacent[i] << " and " << v << " equals: " << getRoad(adjacent[i],v) << endl << endl;
//                                        cout <<  "Danger of " << adjacent[i] << " equals: " << L[adjacent[i]] << endl << endl;
                    ///////////////////////////   TEST /////////////////////////////////////
                }
            }
            
            ///////////////////////////   TEST /////////////////////////////////////
//                        cout << " L is equal to:" << endl;
//                        for (int i=0; i< 15; i++)
//                        {
//                            cout << L[i] << ", ";
//                        }
//                        cout << endl << endl << endl;
            ///////////////////////////   TEST /////////////////////////////////////
            
            
            // Check if z is in T
            check = 0;
            for (int i=0; i<sizeofT; i++)
            {
                if (T[i] == nodeTo){
                    check = 1;
                    break;
                }
            }
            for (int i=0; i<6; i++){
                adjacent[i]=-1;
            }
            
        }
        danger = L[nodeTo];
    }
    
    return danger;
    
};

int minCost(int nodeFrom, int nodeTo){
    
    int distance =0;
    
    if (nodeTo != nodeFrom){
        
        
        int L[15]; // length matrix
        int adjacent[6]={-1,-1,-1,-1,-1,-1};
        int v=0;
        int location =0;
        int sizeofT=15;
        int T[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}; // node matrix
        int check = 1;
        for (int i=0; i<15; i++)
        {L[i]=2500;}
        
        L[nodeFrom]=0;
        
        // while z is an element in T
        while (check == 1){
            
            //Choose v as an element of T with minimum L(v)
            v=T[0];
            location=0;
            for (int i=0; i < sizeofT; i++)
            {
                //cout << endl << "i : " << i << "  L[T[i]]: " << L[T[i]] << "  v: " << v << endl;
                if (L[T[i]] < L[v] ){
                    v= T[i];
                    location = i;
                }
            }
            
            ///////////////////////////   TEST /////////////////////////////////////
            //            cout << "V:  " << v << endl << endl;
            //            cout << "location = " << location<< endl;
            //
            ///////////////////////////   TEST /////////////////////////////////////
            
            
            // T = T - {v}
            while (location != sizeofT)
            {
                T[location] = T[location+1];
                location++;
            }
            sizeofT--;
            
            ///////////////////////////   TEST /////////////////////////////////////
            //            cout << " T after deleting v" << endl;
            //            for (int i=0; i< sizeofT; i++)
            //            {
            //                cout << T[i] << ", ";
            //            }
            //            cout << endl;
            ///////////////////////////   TEST /////////////////////////////////////
            
            
            //find array of adjacent x's as elements of T
            getNode( v , adjacent);
            
            ///////////////////////////   TEST /////////////////////////////////////
            //            cout << " adjacent after Get Node Call:" << endl;
            //            for (int i=0; i< 6; i++)
            //            {
            //                cout << adjacent[i] << ", ";
            //            }
            //            cout << endl;
            ///////////////////////////   TEST /////////////////////////////////////
            
            
            
            
            //for each of those adjacent x's, L(x) = min{L(x),L(v)+w(v,x)}
            for (int i=0; i<6; i++){
                if (adjacent[i] != -1){
                    if (getToll(i)<11){
                        L[adjacent[i]] = minFunction( (L[adjacent[i]]) , (L[v]+ getDistance(getRoad(adjacent[i], v))) );
                        ///////////////////////////   TEST /////////////////////////////////////
                        //                    cout <<   "Road from: " << adjacent[i] << " and " << v << " equals: " << getRoad(adjacent[i],v) << endl << endl;
                        //                    cout <<  "Cost of " << adjacent[i] << " equals: " << L[adjacent[i]] << endl << endl;
                        ///////////////////////////   TEST /////////////////////////////////////
                    }
                }
            }
            
            ///////////////////////////   TEST /////////////////////////////////////
            //            cout << " L is equal to:" << endl;
            //            for (int i=0; i< 15; i++)
            //            {
            //                cout << L[i] << ", ";
            //            }
            //            cout << endl << endl << endl;
            ///////////////////////////   TEST /////////////////////////////////////
            
            
            // Check if z is in T
            check = 0;
            for (int i=0; i<sizeofT; i++)
            {
                if (T[i] == nodeTo){
                    check = 1;
                    break;
                }
            }
            for (int i=0; i<6; i++){
                adjacent[i]=-1;
            }
            
        }
        distance = L[nodeTo];
    }
    
    return distance;
    
};




