#pragma once

#include <memory>
#include <string>
#include <utility>
#include "addition.h"
#include "math/algebra/expressions/operations/binary-operation.h"

namespace math {

class Multiplication final : public BinaryOperation {
 public:
  Multiplication(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
      : BinaryOperation(std::move(left), std::move(right)) {
  }

  std::string GetString() override;
  std::shared_ptr<Expression> GetDerivative() override;
};

}  // namespace math