double calculateSalary(int hours_worked, double hourly_wage) {
  double total_salary;
  if (hours_worked <= 40) {
    total_salary = hourly_wage * hours_worked;
  } else if (hours_worked > 40 && hours_worked <= 65) {
    total_salary = 
        (hourly_wage * 40) + (hours_worked - 40) * (hourly_wage * 1.5);
  } else if (hours_worked > 65) {
    total_salary = (hourly_wage * 40) + (hourly_wage * 1.5) * 25 + 
                   (hours_worked - 65) * hourly_wage * 2;
  }
  return total_salary;
}

