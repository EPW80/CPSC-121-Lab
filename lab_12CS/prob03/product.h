#include <memory>
#include <string>

class Product {
 public:
  // Constructor
  Product(std::string name, double price, std::shared_ptr<Product> right,
          std::shared_ptr<Product> left)
      : name_(name), price_(price), right_(right), left_(left) {}

  // Accessor functions for the name and price
  const std::string &Name() const {
    return name_;
  }
  double Price() const {
    return price_;
  }

  // Recursive function to find the price of a product
  double FindPrice(std::string name) {
    if (name_ == name) {
      return price_;
    } else if (right_ == nullptr && left_ == nullptr) {
      return -1;
    } else {
      double _right = right_->FindPrice(name);
      double _left = left_->FindPrice(name);
      // If the product found in either right or left subtree, return price
      if (_right >= 0 || _left >= 0) {
        return std::max(_right, _left);
      }
      // Otherwise, return -1 (product not found)
      else {
        return -1;
      }
    }
  }

 private:
  std::string name_;
  double price_;
  std::shared_ptr<Product> right_;
  std::shared_ptr<Product> left_;
};
