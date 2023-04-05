#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "graph.h"

using namespace std;

void printGraph(Graph<int>& graph)
{
    cout << "------------------------------------------------------" << endl;
    for (auto iter = graph.getAdjList().begin(); iter != graph.getAdjList().end(); iter++)
    {
        string nodes = "(";
        for (const auto& edge : iter->second)
        {
            nodes += to_string(edge) + " ";
        }
        nodes += ")";
        cout << iter->first << " --> " << nodes << endl;
    }

    cout << "------------------------------------------------------" << endl;
};

void printGraph(Graph<string>& graph)
{
    cout << "------------------------------------------------------" << endl;
    for (auto iter = graph.getAdjList().begin(); iter != graph.getAdjList().end(); iter++)
    {
        string nodes = "(";
        for (const auto& edge : iter->second)
        {
            nodes += edge + " ";
        }
        nodes += ")";
        cout << iter->first << " --> " << nodes << endl;
    }

    cout << "------------------------------------------------------" << endl;
};

int main()
{
    setlocale(LC_ALL, "rus");

    Edge<int> edge{1, 5};
    
    vector<Edge<int>> edges = 
    {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };
   
    Graph<int> graphInt{ edges };
    printGraph(graphInt);

    graphInt.addEdge(edge);
    printGraph(graphInt);

    graphInt.deleteEdge(edge);
    printGraph(graphInt);

    graphInt.deleteNode(edge.st);
    printGraph(graphInt);

    /*--------------------------------------------------------------------------------------------------------*/
    Edge<string> edge1{ "1", "5" };

    vector<Edge<string>> edges1 =
    {
        {"0", "1"}, {"1", "2"}, {"2", "0"}, {"2", "1"}, {"3", "2"}, {"4", "5"}, {"5", "4"}
    };

    Graph<string> graphString{ edges1 };
    printGraph(graphString);

    graphString.addEdge(edge1);
    printGraph(graphString);

    graphString.deleteEdge(edge1);
    printGraph(graphString);

    graphString.deleteNode(edge1.st);
    printGraph(graphString);
    return 0;
}