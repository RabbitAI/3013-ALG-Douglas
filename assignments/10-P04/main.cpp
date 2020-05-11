#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

//A vertice has a name, and a bit that tells it whether or not
//it's been visited
struct vert
{
    char name;
    bool visited;
    int degree;
    vector<vert> edge[];
    vert() { name = 'x'; visited = 0; degree = 1; edge[degree]; }
};

int main()
{
    int index = 0;
    char pair[2];
    vert bigNode, v1, v2;             //bigNode is the largest node in the graph
    vector<vert,vert> vVect;               //v holds the pairs after bigNode
    int graphNum,                     //number of graphs given by the input
        subMax;                       //Maximal subgraphs, accumulater

    cin >> graphNum;
    for(int i = 0; i < graphNum; i++)
    {   
        cin >> bigNode.name;
        bigNode.visited = 1;

        while(cin.getline (pair, 2))
        {
            v1.name = pair[0];
            v2.name = pair[1];
            vVect[index].push_back();
            if(v1.name == bigNode.name)
            {
                bigNode.edge[0] = v1.edge[0]; 
            }
            else if(v2.name == bigNode.name)
            {
                bigNode.edge[0] = v2.edge[0]; 
            }
        }
         
    }

    return 0;
}