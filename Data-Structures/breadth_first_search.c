#include <stdio.h>
#include <stdbool.h>

#define MAX 5 // Maximum number of vertices in the graph

// Queue structure for BFS
int queue[MAX];
int front = 0;
int rear = -1;
int queueItemCount = 0;

int adjMatrix[MAX][MAX]; // Adjacency matrix
char vertices[MAX];      // List of vertices
bool visited[MAX];       // Visited flag for each vertex

// Function to insert an element into the queue
void enqueue(int data)
{
    queue[++rear] = data;
    queueItemCount++;
}

// Function to remove an element from the queue
int dequeue()
{
    queueItemCount--;
    return queue[front++];
}

// Function to check if the queue is empty
bool isQueueEmpty()
{
    return queueItemCount == 0;
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

// Function to perform BFS traversal
void BreadthFirstSearch()
{
    // Mark the first vertex as visited and enqueue it
    visited[0] = true;
    printf("%c ", vertices[0]);
    enqueue(0);

    while (!isQueueEmpty())
    {
        int tempVertex = dequeue();

        // Get all adjacent unvisited vertices, mark them visited and enqueue them
        int unvisitedVertex;
        while ((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1)
        {
            visited[unvisitedVertex] = true;
            printf("%c ", vertices[unvisitedVertex]);
            enqueue(unvisitedVertex);
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

    // Perform BFS traversal
    printf("\nBreadth First Search: ");
    BreadthFirstSearch();

    return 0;
}