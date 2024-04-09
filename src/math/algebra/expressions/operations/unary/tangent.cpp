#include "tangent.h"

namespace math {

std::string Tangent::GetInfix(int previous_priority) {
  bool brackets_required = previous_priority >= priority_;
  return "tan(" + argument_->GetInfix(0) + ")";
}

std::string Tangent::GetRPN() {
  return argument_->GetRPN() + " tan";
}

std::shared_ptr<Expression> Tangent::GetDerivative() {
  return std::make_shared<Division>(
      argument_->GetDerivative(),
      std::make_shared<Exponentiation>(std::make_shared<Cos>(argument_), std::make_shared<Number>(2)));
}

}  // namespace math