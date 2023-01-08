#include <memory>
#include <string>

class Train {
 public:
  Train(int passenger_count, int seat_count,
        std::shared_ptr<Train> next_carriage)
      : passenger_count_(passenger_count),
        seat_count_(seat_count),
        next_carriage_(next_carriage) {}

  int GetPassengerCount() const {
    return passenger_count_;
  }
  int GetSeatCount() const {
    return seat_count_;
  }
  std::shared_ptr<Train> GetNextCarriage() const {
    return next_carriage_;
  }
  int TotalTrainPassengers() {
    if (next_carriage_ == nullptr)
      return passenger_count_;
    else
      return passenger_count_ + next_carriage_->TotalTrainPassengers();
  }
  int MaxCarriagePassengers() {
    if (next_carriage_ == nullptr) {
      return passenger_count_;
    } else {
      int max_carriage_passengers = next_carriage_->MaxCarriagePassengers();
      if (passenger_count_ > max_carriage_passengers)
        return passenger_count_;
      else
        return max_carriage_passengers;
    }
  }
  bool IsTrainFull() {
    bool is_train_full_ = (passenger_count_ == seat_count_);
    if (next_carriage_ == nullptr) {
      return is_train_full_;
    } else {
      if (is_train_full_) {
        return next_carriage_->IsTrainFull();
      } else {
        return false;
      }
    }
  }
  void AddCarriageToEnd(std::shared_ptr<Train> add_carriage_to_end) {
    if (next_carriage_ == nullptr) {
      next_carriage_ = add_carriage_to_end;
    } else {
      next_carriage_->AddCarriageToEnd(add_carriage_to_end);
    }
  }

 private:
  int passenger_count_;
  int seat_count_;
  std::shared_ptr<Train> next_carriage_;
};
