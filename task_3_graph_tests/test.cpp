#include "pch.h"
#include <vector>
#include <string>
#include "../task3_graph/graph.h"

using namespace std;

TEST(Method1, Graph) {
    
    Edge<int> edge{ 1, 5 };
    
    vector<int> fin = { 5 };

    Graph<int> graphInt{};

    graphInt.addEdge(edge);

    EXPECT_EQ(graphInt.getAdjList()[edge.st], fin);
    EXPECT_TRUE(true);
}

TEST(Method2, Graph) {
    Edge<string> edge{ "1", "5" };

    vector<string> fin = { "5" };

    Graph<string> graphInt{};

    graphInt.addEdge(edge);

    EXPECT_EQ(graphInt.getAdjList()[edge.st], fin);
    EXPECT_TRUE(true);
}

TEST(Method3, Graph) {
    Edge<string> edge{ "1", "5" };

    vector<string> fin = { "5" };

    Graph<string> graphInt{};

    graphInt.addEdge(edge);

    EXPECT_EQ(graphInt.deleteEdge(edge).st, edge.st);
    EXPECT_TRUE(true);
}

TEST(Method4, Graph) {
    Edge<int> edge{ 1, 5 };

    vector<int> fin = { 5 };

    Graph<int> graphInt{};

    graphInt.addEdge(edge);

    EXPECT_EQ(graphInt.deleteEdge(edge).st, edge.st);
    EXPECT_TRUE(true);
}