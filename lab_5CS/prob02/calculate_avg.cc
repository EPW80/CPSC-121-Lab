#include <vector>

double CalculateAverage(const std::vector<double> &student_grades) {
  if (student_grades.size() == 0)
    return 0.0;
  double total = 0;
  for (int i = 0; i < student_grades.size(); i++)
    total += student_grades[i];
  return total / student_grades.size();
}
