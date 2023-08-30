// you have a business with several offices , you want to lease phone lines to connect them up with each other and the phone company
// charges different amounts of money to connect different pairs of cities. You want a set of lines that connects all your offices with a minimum total cost
// solve problem by suggesting appropriate data structure
// graph => minimum spanning tree

#include <iostream>
#include <climits>
using namespace std;

class Graph
{

    int **matrix;
    int max_ver = 0;
    string *officeList;
    static int index;

public:
    Graph(int max_vertices)
    {

        matrix = new int *[max_vertices];
        for (int i = 0; i < max_vertices; i++)
        {
            matrix[i] = new int[max_vertices];
        }
        for (int i = 0; i < max_vertices; i++)
        {
            for (int j = 0; j < max_vertices; j++)
            {
                matrix[i][j] = 0;
            }
        }
        max_ver = max_vertices;
        officeList = new string[max_ver];
    }
    ~Graph()
    {

        for (int i = 0; i < max_ver; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    void insertOffice(string name)
    {
        if (index < max_ver)
        {
            officeList[index++] = name;
        }
        else
        {
            cout << "No more offices can be added" << endl;
        }
    }
    int refValuefromName(string name)
    {
        for (int i = 0; i < max_ver; i++)
        {
            if (officeList[i] == name)
            {
                return i;
            }
        }
        return -1;
    }

    void addLine(string name1, string name2, int weight)
    {
        int index1 = refValuefromName(name1);
        int index2 = refValuefromName(name2);
        if (index1 == -1 || index2 == -1)
        {
            if (index1 == -1)
            {
                cout << "No office named " << name1 << " found" << endl;
                return;
            }
            cout << "No office named " << name2 << " found" << endl;
        }
        matrix[index1][index2] = weight;
        matrix[index2][index1] = weight;
    }

    int minKey(int key[], int mstSet[])
    {
        int min = INT_MAX, min_index;
        for (int i = 0; i < max_ver; i++)
        {
            if (mstSet[i] == 0 && key[i] < min)
            {
                min = key[i];
                min_index = i;
            }
        }
        return min_index;
    }

    void PRIMS()
    {
        int parent[max_ver] = {0};
        int key[max_ver] = {0};
        int mstSet[max_ver] = {0};

        for (int i = 0; i < max_ver; i++)
        {
            key[i] = INT_MAX;
        }
        key[0] = 0;
        parent[0] = -1;
        for (int i = 0; i < max_ver - 1; i++)
        {
            int u = minKey(key, mstSet);
            mstSet[u] = 1;
            for (int v = 0; v < max_ver; v++)
            {

                if (matrix[u][v] && mstSet[v] == 0 && matrix[u][v] < key[v])
                {
                    parent[v] = u;
                    key[v] = matrix[u][v];
                }
            }
        }
        printMST(parent);
    }

    void printMST(int parent[])
    {
        cout << "Adjecency Matrix : " << endl;
        for (int i = 0; i < max_ver; i++)
        {
            cout << officeList[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < max_ver; i++)
        {
            for (int j = 0; j < max_ver; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << endl;
        cout << "Minimum Spanning Tree : " << endl;
        cout << "Line  \tCost" << endl;
        int tc = 0;
        for (int i = 1; i < max_ver; i++)
        {
            cout << officeList[parent[i]] << " - " << officeList[i] << "\t" << matrix[i][parent[i]] << endl;
            tc += matrix[i][parent[i]];
        }
        cout << "Total Cost : " << tc << endl;
    }
};
int Graph::index = 0;

int main()
{
    int vertexnum = 0;
    cout<<"Enter the number of vertexes in the graph: ";
    cin>>vertexnum;
    Graph g(vertexnum);
    for (int i=0;i<vertexnum;i++)
    {
        string vertex;
        cout<<"Enter vertex no "<<i<<" : ";
        cin>>vertex;
        g.insertOffice(vertex);
    }
    
    int choice = 0;
    while(choice!=-1)
    {
        cout<<"\n\nMENU\n\n1. Add a phone line.\n2. Execute PRIMS\nEnter -1 to exit the program\n\nEnter your choice from the menu: ";
        cin>>choice;

        switch(choice)
        {

            case 1:
            {
                string A,B;
                int weight;
                cout<<"Enter one end of the connection: ";
                cin>>A;
                cout<<"Enter the other end of the connection: ";
                cin>>B;
                cout<<"Enter the weight of the connection: ";
                cin>>weight;
                g.addLine(A,B,weight);
                cout<<"Line Added!";
                break;
            }

            case 2:
            {
                g.PRIMS();
                break;
            }

            case -1:
            {
                break;
            }
            default:
            {
                cout<<"Please enter the correct value from the MENU!\n\n";
                break;
            }
        }
    }
    cout<<"\nThank you!";
    return 0;
}

// A is the phone line company /root
    /*
    The graph
            B        7       E
        1       8        11      10
    A       4        D       3       G
        5       6        9       12
            C        2      F
    */

/*
SAMPLE TESTCASE
s
7
A
B
C
D
E
F
G
1
A
B
1
1
A
C
5
1
B
C
4
1
B
D
8
1
C
D
6
1
B
E
7
1
F
E
3
1
F
G
12
1
E
G
10
2
1
D
F
9
1
C
F
2
1
D
F
3
2
-1
*/
