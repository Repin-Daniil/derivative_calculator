#include "cos.h"

namespace math {

std::string Cos::GetInfix(int previous_priority) {
  return "cos(" + argument_->GetInfix(0) + ")";
}

std::string Cos::GetRPN() {
  return argument_->GetRPN() + " cos";
}

std::shared_ptr<Expression> Cos::GetDerivative() {
  return std::make_shared<UnaryMinus>(
      std::make_shared<Multiplication>(std::make_shared<Sin>(argument_), argument_->GetDerivative()));
}
double Cos::GetNumericResult(const std::unordered_map<char, double>& variable_to_value) {
  return std::cos(argument_->GetNumericResult(variable_to_value));
}

}  // namespace math
