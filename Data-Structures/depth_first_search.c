#include <stdio.h>
#include <stdbool.h>

#define MAX 5 // Maximum number of vertices in the graph

// Stack structure for DFS
int stack[MAX];
int top = -1;

int adjMatrix[MAX][MAX]; // Adjacency matrix
char vertices[MAX];      // List of vertices
bool visited[MAX];       // Visited flag for each vertex

// Function to push an element onto the stack
void push(int data)
{
    stack[++top] = data;
}

// Function to pop an element from the stack
int pop()
{
    return stack[top--];
}

// Function to check if the stack is empty
bool isStackEmpty()
{
    return top == -1;
}

// Function to add a vertex to the graph
void addVertex(char label)
{
    static int vertexCount = 0;
    vertices[vertexCount++] = label;
}

// Function to add an edge between two vertices
void addEdge(int start, int end)
{
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1; // Since the graph is undirected
}

// Function to get the unvisited adjacent vertex
int getAdjUnvisitedVertex(int vertexIndex)
{
    for (int i = 0; i < MAX; i++)
    {
        if (adjMatrix[vertexIndex][i] == 1 && !visited[i])
        {
            return i;
        }
    }
    return -1;
}

// Function to perform DFS traversal
void DepthFirstSearch()
{
    // Mark the first vertex as visited and push it onto the stack
    visited[0] = true;
    printf("%c ", vertices[0]);
    push(0);

    while (!isStackEmpty())
    {
        int unvisitedVertex = getAdjUnvisitedVertex(stack[top]);

        // If there is an unvisited adjacent vertex, visit it and push it onto the stack
        if (unvisitedVertex != -1)
        {
            visited[unvisitedVertex] = true;
            printf("%c ", vertices[unvisitedVertex]);
            push(unvisitedVertex);
        }
        // If no adjacent unvisited vertex, pop from the stack
        else
        {
            pop();
        }
    }
}

int main()
{
    // Initialize adjacency matrix to 0
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    // Add vertices
    addVertex('S'); // 0
    addVertex('A'); // 1
    addVertex('B'); // 2
    addVertex('C'); // 3
    addVertex('D'); // 4

    // Add edges
    addEdge(0, 1); // S - A
    addEdge(0, 2); // S - B
    addEdge(0, 3); // S - C
    addEdge(1, 4); // A - D
    addEdge(2, 4); // B - D
    addEdge(3, 4); // C - D

    // Perform DFS traversal
    printf("\nDepth First Search: ");
    DepthFirstSearch();

    return 0;
}