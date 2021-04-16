#include "node.h"

using namespace std;

template<class C1, class C2> 
bool UseCmp(const C1& lhs, const C2& rhs, const Comparison& cmp) {
	switch(cmp) {
		case Comparison::Less:
			return lhs < rhs;

		case Comparison::LessOrEqual:
			return lhs <= rhs;

		case Comparison::Greater:
			return lhs > rhs;

		case Comparison::GreaterOrEqual:
			return lhs >= rhs;

		case Comparison::Equal:
			return lhs == rhs;

		case Comparison::NotEqual:
			return lhs != rhs;

		default:
			throw runtime_error("Undeclarated cmp");
	}
}

bool DateComparisonNode::Evaluate(const Date& date, const std::string& event) const {
	return UseCmp(node_date, date, node_cmp);
}
 
bool EventComparisonNode::Evaluate(const Date& date, const std::string& event) const {
	return UseCmp(node_event, event, node_cmp);
}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event) const {
	if (node_left == nullptr && node_right == nullptr)
		return true;

	if (node_right == nullptr)
		return node_left->Evaluate(date, event);

	if (node_left == nullptr)
		return node_right->Evaluate(date, event);

	if (node_operation == LogicalOperation::And)
		return node_left->Evaluate(date, event) && 
					 node_right->Evaluate(date, event);

	return node_left->Evaluate(date, event) ||
					 node_right->Evaluate(date, event);
}	

bool EmptyNode::Evaluate(const Date& date, const std::string& event) const {
	return true;
}