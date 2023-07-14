#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#pragma warning (disable: 4996)
using namespace std;


//function to display graph
void display(bool** A, int number_vertices)
{
	cout << " Displaying graph \n ";
	for (int i = 0; i < number_vertices; i++)
		for (int j = 0; j <= i; j++)
		{
			cout << endl << "Edge between " << i << " and " << j << " : ";
			cout << A[i][j] << endl;
		}
}

void adj_matrix(int vertices_number) {
	bool** A = new bool* [vertices_number];
	for (int k = 0; k < vertices_number; k++)
		A[k] = new bool[vertices_number];

	for (int i = 0; i < vertices_number; i++)
		for (int j = 0; j < vertices_number; j++)
			A[i][j] = 0;

	while (true) {
		int mat_choice, v1, v2, edges_count = 0;

		cout << endl;
		cout << "Choose an operation: " << endl;
		cout << "1- Find number of edges and number of indegree and outdegree " << endl
			<< "2- Find edge between two vertices" << endl
			<< "3- Add edge" << endl
			<< "4- Display graph" << endl;

		cin >> mat_choice;

		switch (mat_choice) {

		case 1:

			for (int i = 0; i < vertices_number; i++)
				for (int j = 0; j <= i; j++)
					if (A[i][j] == 1)
						edges_count++;

			cout << endl << "the number of edge is: " << edges_count;
			cout << endl << "the number of indegree and outdegree is: " << edges_count;
			cout << endl << "*********************************************" << endl;
			break;

		case 2:

			cout << "Enter a number of first vertix to find if there is an edge or not: ";
			cin >> v1;
			cout << "Enter a number of second vertix to find if there is an edge or not: ";
			cin >> v2;

			if (v1 <= vertices_number && v2 <= vertices_number)
			{
				if (A[v1][v2])
					cout << "\nThere is a connection between " << v1 << " & " << v2;
				else
					cout << "\nThere is no connection!";
			}

			cout << endl << "*********************************************";
			break;

		case 3:

			cout << "Enter a number of first vertix: ";
			cin >> v1;
			cout << "Enter a number of second vertix: ";
			cin >> v2;

			if (v1 <= vertices_number && v2 <= vertices_number)
			{
				A[v1][v2] = 1;
				A[v2][v1] = 1;
			}

			cout << endl << "*********************************************";
			break;

		case 4:

			display(A, vertices_number);
			cout << endl << "*********************************************";
			break;

		default:

			cout << "Wrong choice .. Please try again!" << endl;
			break;
		}
	}
}

void adj_list(int vertices_number) {
	vector<int>* list = new vector<int>[vertices_number];

	while (true) {
		int list_choice, v1, v2, edges_count = 0;

		cout << endl;
		cout << "Choose an operation: " << endl;
		cout << "1- Find number of edges and number of indegree and outdegree" << endl
			<< "2- Find edge between two vertices" << endl
			<< "3- Add edge " << endl
			<< "4- Display graph" << endl;

		cin >> list_choice;

		switch (list_choice) {

		case 1:

			for (int i = 0; i < vertices_number; i++)
				for (auto j : list[i])
					edges_count++;

			cout << endl << "the number of edge is: " << edges_count / 2;
			cout << endl << "the number of indegree and outdegree is: " << edges_count;
			cout << endl << "*********************************************" << endl;
			break;

		case 2:

			cout << "Enter a number of first vertix to find if there is an edge or not: ";
			cin >> v1;
			cout << "Enter a number of second vertix to find if there is an edge or not: ";
			cin >> v2;

			if (v1 <= vertices_number && v2 <= vertices_number)
			{
				bool flag = false;
				for (auto k : list[v1])
					if (k == v2)
					{
						flag = true;
						break;
					}

				if (flag)
					cout << "\nThere is a connection between " << v1 << " & " << v2;
				else
					cout << "\nThere is no connection between " << v1 << " & " << v2;
			}

			cout << endl << "*********************************************";
			break;

		case 3:

			cout << "Enter a number of first vertix: ";
			cin >> v1;
			cout << "Enter a number of second vertix: ";
			cin >> v2;

			if (v1 <= vertices_number && v2 <= vertices_number)
			{
				list[v1].push_back(v2);
				list[v2].push_back(v1);
			}

			cout << endl << "*********************************************";
			break;

		case 4:

			for (int q = 0; q < vertices_number; q++) {
				cout << "\n Vertex "
					<< q << ":";
				for (auto i : list[q])
					cout << "-> " << i;
				cout << endl;
			}

			cout << endl << "*********************************************";
			break;

		default:

			cout << "Wrong choice .. Please try again!" << endl;
			break;
		}
	}
}

int main() {

	while (true) {
		cout << endl;
		cout << "List of tasks" << endl
			<< "1- Adjacency Matrix" << endl
			<< "2- Adjacency List" << endl
			<< "3- exit" << endl
			<< "*********************************************" << endl;

		int choice;
		cout << "Choose the graph representation: ";
		cin >> choice;

		switch (choice) {
		case 1:
			int number_vertices;
			cout << endl << "Please number of vertices in the graph: ";
			cin >> number_vertices;
			adj_matrix(number_vertices);
			break;

		case 2:
			int vert_num;
			cout << endl << "Please number of vertices in the graph: ";
			cin >> vert_num;
			adj_list(vert_num);
			break;

		case 3:
			exit(0);
			break;

		default:
			cout << "Wrong choice .. Please try again";
			cout << endl;
			break;
		}
	}
}