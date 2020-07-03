#pragma once
#include "MultiGraph.h"
#include "CondensedMultiGraph.h"
#include "ProducerPathBasedMerger.h"


class DirectedAcyclicMultiGraph
{
	CondensedMultiGraph* C;
	int nh;
	vector<vector<int>> nodes;
	vector<int> capacities;
	vector<multimap<int, int>> directed;
	vector<bool> major;
	vector<multimap<int, int>> reversedEdges;
	vector<map<int, vector<int>>> collapsedNodes;//from-to, vector of collapsed vertices
	//Get the topological order of the nodes of the DAG
	vector<int> TopologicalOrder();
	vector<bool> GetSn(vector<int> order, int n);
	bool ExistProducerPathBasedMerger(vector<int> _order, vector<bool> Sn, int n, int u, vector<int>& path, int& capacity);
	//This function 
	void CollapseNonMajorNodesPaths();
public:
	DirectedAcyclicMultiGraph() {}
	DirectedAcyclicMultiGraph(const DirectedAcyclicMultiGraph&);
	DirectedAcyclicMultiGraph(CondensedMultiGraph* _C);
	bool TerminalNodesCapacityLessThanAllInEdges();
	bool ExistAPathLeadingToNH(CondensedMultiGraph* _C);
	bool ExistAProducerMerger(CondensedMultiGraph* _C);
	vector<CondensedMultiGraph> PickATerminalNodeAndCollapseFeasiblePaths();
};

