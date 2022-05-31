//
// Created by thebi on 16.05.2022.
//

#ifndef BMSTU_OOP_4TH_SEM_EDGE_H
#define BMSTU_OOP_4TH_SEM_EDGE_H

#include <memory>
class Edge
{
public:
	Edge();
	Edge(const size_t idxPointA, const size_t idxPointB);
	Edge(const Edge &edge);
	Edge& operator=(const Edge &edge);
	Edge(const Edge &&edge);
	Edge& operator=(const Edge &&edge);

    size_t getFirst();
    size_t getSecond();
    void setFirst(const size_t first);
    void setSecond(const size_t second);

	~Edge() = default;
private:
    size_t idxPointA, idxPointB;
};


#endif //BMSTU_OOP_4TH_SEM_EDGE_H
