#pragma once

#include <string>
#include <stdexcept>
#include <memory>

#include "date.h"

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum class LogicalOperation {
	And,
	Or
};

template<class C1, class C2> 
bool UseCmp(const C1& lhs, const C2& rhs, const Comparison& cmp);

class Node {
public:
	virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class DateComparisonNode : public Node {
public:
	bool Evaluate(const Date& date, const std::string& event) const override;

	DateComparisonNode(const Comparison& cmp, const Date& date) :
		node_cmp(cmp), 
		node_date(date)
	{}

private:
	Comparison node_cmp;
	Date node_date;
};

class EventComparisonNode : public Node {
public:
	bool Evaluate(const Date& date, const std::string& event) const override;

	EventComparisonNode(const Comparison& cmp, const std::string& event) :
		node_cmp(cmp),
		node_event(event)
	{}

private:
	Comparison node_cmp;
	std::string node_event;
};

class LogicalOperationNode : public Node {
public:
	bool Evaluate(const Date& date, const std::string& event) const override;

	LogicalOperationNode(const LogicalOperation& log_op, 
											 const std::shared_ptr<Node>& left, const std::shared_ptr<Node>& right) :
		node_operation(log_op),
		node_left(node_left), 
		node_right(node_right)
	{}

private:
	LogicalOperation node_operation;
	std::shared_ptr<Node> node_left,
									 			node_right;	
};

class EmptyNode : public Node {
public:
	bool Evaluate(const Date& date, const std::string& event) const override;
};