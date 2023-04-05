#pragma once
#include <vector>
#include <map>
#include <string>
#include <iterator>

using namespace std;

template <typename T>
struct Edge {
	T st, fin;
};

template <typename T>
class Graph
{
public:
    Graph(vector<Edge<T>>& edges);

    Graph() = default;

    void addEdge(vector<Edge<T>>& newAdges);

    Edge<T>& addEdge(Edge<T>& newAdge);

    Edge<T>& deleteEdge(Edge<T>& edge);

    T deleteNode(T node);

    map<T, vector<T>> &getAdjList();

private:
    void printMessage(string message);

    map<T, vector<T>> adjList;
};


// IMPLENETATION

template<typename T>
Graph<T>::Graph(vector<Edge<T>>& edges)
{
    for (const auto& edge : edges)
    {
        if (this->getAdjList().count(edge.st))
        {
            adjList[edge.st].push_back(edge.fin);
        }
        else
        {
            adjList[edge.st] = { edge.fin };
        }
    }
}

template<typename T>
void Graph<T>::addEdge(vector<Edge<T>>& newAdges)
{
    for (const auto& edge : newAdges)
    {
        this.addEdge(edge);
    }
};

template<typename T>
Edge<T>& Graph<T>::addEdge(Edge<T>& newAdge)
{
    if (this->getAdjList().count(newAdge.st))
    {
        this->adjList[newAdge.st].push_back(newAdge.fin);
    }
    else
    {
        this->adjList[newAdge.st] = { newAdge.fin };
    }

    printMessage("Ребро добавлено!");

    return newAdge;
};

template<typename T>
Edge<T>& Graph<T>::deleteEdge(Edge<T>& edge)
{
    if (this->getAdjList().count(edge.st))
    {
        vector<T> curVector{ this->adjList[edge.st] };

        curVector.erase(find(curVector.begin(), curVector.end(), edge.fin));

        this->adjList[edge.st] = curVector;
    }
    else
    {
        printMessage("Направление отсутсвут или было удалено ранее!");
    }

    printMessage("Направление удалено!");

    return edge;
};

template<typename T>
T Graph<T>::deleteNode(T node) {
    if (this->getAdjList().count(node))
    {
        this->adjList.erase(node);
    }
    else
    {
        printMessage("Узел отсутсвут или было удалено ранее!");
    }

    printMessage("Ребро удалено!");

    return node;
}

template<typename T>
map<T, vector<T>>& Graph<T>::getAdjList()
{
    return this->adjList;
};

template<typename T>
void Graph<T>::printMessage(string message)
{
    cout << "------------------------------------------------------" << endl;
    cout << message << endl;
    cout << "------------------------------------------------------" << endl;
}
