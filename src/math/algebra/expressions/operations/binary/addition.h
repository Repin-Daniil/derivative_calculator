#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

#include "constants_storage.h"
#include "math/algebra/expressions/operations/binary_operation.h"

namespace math {

class Addition final : public BinaryOperation {
 public:
  Addition(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
      : BinaryOperation(std::move(left), std::move(right)) {
  }

  std::string GetInfix(int previous_priority) override;
  std::string GetRPN(const std::unordered_map<char, double>& variable_to_value) override;
  std::shared_ptr<Expression> GetDerivative() override;

 private:
 public:
  double GetNumericResult(const std::unordered_map<char, double>& variable_to_value) override;

 private:
  int priority_ = constants::operations_to_priority.at(constants::Operations::ADDITION);
};

}  // namespace math
