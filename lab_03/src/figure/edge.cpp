//
// Created by thebi on 16.05.2022.
//

#include "edge.h"
Edge::Edge()
{}

Edge::Edge(const size_t idxPointA, const size_t idxPointB)
{
	this->idxPointA = idxPointA;
	this->idxPointB = idxPointB;
}

Edge::Edge(const Edge &edge)
{
	this->idxPointA = edge.idxPointA;
	this->idxPointB = edge.idxPointB;
}

Edge::Edge(const Edge &&edge) : Edge(edge)
{
	edge.~Edge();
}

Edge &Edge::operator=(const Edge &edge)
{
    this->idxPointA = edge.idxPointA;
    this->idxPointB = edge.idxPointB;

    return *this;
}

Edge &Edge::operator=(const Edge &&edge)
{
    this->idxPointA = edge.idxPointA;
    this->idxPointB = edge.idxPointB;

    edge.~Edge();
    return *this;
}

size_t Edge::getFirst()
{
    return this->idxPointA;
}

size_t Edge::getSecond()
{
    return this->idxPointB;
}

void Edge::setFirst(const size_t first)
{
    this->idxPointA = first;
}

void Edge::setSecond(const size_t second)
{
    this->idxPointB = second;
}