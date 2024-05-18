#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <variant>

#include "number_node.h"
#include "symcpp/abstract-syntax-tree/node.h"
#include "symcpp/constants_storage.h"
#include "symcpp/symbol.h"

namespace symcpp::math {

class Constant final : public TreeNode {
 public:
  explicit Constant(const Symbol& symbol) : symbol_(symbol) {
  }

  bool IsContainVariable(const Symbol& variable) override;
  constants::Expressions GetType() override;

  std::string GetInfix(int previous_priority) override;
  std::string GetRPN() override;

  std::unique_ptr<TreeNode> Evaluate() override;
  std::unique_ptr<TreeNode> GetDerivative(const Symbol& d) override;
  std::unique_ptr<TreeNode> Substitute(
      const std::unordered_map<Symbol, std::unique_ptr<TreeNode>, SymbolHash>& variable_to_value) override;

  std::unique_ptr<TreeNode> Simplify() override;
  std::unique_ptr<TreeNode> Clone() override;

 private:
  const Symbol symbol_;
};

}  // namespace symcpp::math
