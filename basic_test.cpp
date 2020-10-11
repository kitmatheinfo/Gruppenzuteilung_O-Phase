#include "implementation.h"

int main() {
  Input input;
  input.groups.emplace_back("First Contact", "FC Team Gecko", CourseType::Any, DegreeType::Any);
  input.groups.emplace_back("Team Gecko", "FC Team Gecko", CourseType::Any, DegreeType::Any);
  input.groups.emplace_back("Mathe", "Project Pi", CourseType::Mathe, DegreeType::Any);
  input.groups.emplace_back("Master", "Second Contact", CourseType::Any, DegreeType::Master);
  input.students.emplace_back("Ersti 1", CourseType::Info, DegreeType::Bachelor, false);
  input.ratings.emplace_back(std::vector<Rating> { Rating(4), Rating(3), Rating(2), Rating(1) });
  input.students.emplace_back("Ersti 2", CourseType::Info, DegreeType::Bachelor, false);
  input.ratings.emplace_back(std::vector<Rating> { Rating(1), Rating(2), Rating(3), Rating(4) });
  input.students.emplace_back("Ersti 3", CourseType::Info, DegreeType::Bachelor, false);
  input.ratings.emplace_back(std::vector<Rating> { Rating(3), Rating(3), Rating(4), Rating(4) });
  input.students.emplace_back("Ersti 4", CourseType::Info, DegreeType::Bachelor, false);
  input.ratings.emplace_back(std::vector<Rating> { Rating(2), Rating(1), Rating(1), Rating(1) });
  input.students.emplace_back("Mathe 1", CourseType::Mathe, DegreeType::Bachelor, false);
  input.ratings.emplace_back(std::vector<Rating> { Rating(1), Rating(1), Rating(4), Rating(1) });
  input.students.emplace_back("Mathe 2", CourseType::Mathe, DegreeType::Bachelor, false);
  input.ratings.emplace_back(std::vector<Rating> { Rating(1), Rating(2), Rating(3), Rating(4) });
  input.students.emplace_back("Mathe 3", CourseType::Mathe, DegreeType::Bachelor, false);
  input.ratings.emplace_back(std::vector<Rating> { Rating(4), Rating(3), Rating(2), Rating(3) });
  input.students.emplace_back("Master", CourseType::Info, DegreeType::Master, false);
  input.ratings.emplace_back(std::vector<Rating> { Rating(1), Rating(2), Rating(3), Rating(4) });
  input.students.emplace_back("Lerngruppenteilnehmer 1", CourseType::Any, DegreeType::Any, false);
  input.ratings.emplace_back(std::vector<Rating> { Rating(3), Rating(2), Rating(1), Rating(1) });
  input.teams.emplace_back("Lerngruppe A", std::vector<StudentID> { 8 });

  State s(input, 3);
  auto assignment = calculateAssignment(s);
  applyAssignment(s, assignment);
  printCurrentAssignment(s);

  std::cout << "Disable group \"First Contact\" and assign \"Ersti 1\" to \"Master\"."
            << std::endl << std::endl;

  s.disableGroup(0);
  s.resetWithCapacity(4);
  s.assignParticipant(1, 3);
  assignment = calculateAssignment(s);
  applyAssignment(s, assignment);
  printCurrentAssignment(s);

  input.students.emplace_back("Lerngruppenteilnehmer 2", CourseType::Any, DegreeType::Any, false);
  input.ratings.emplace_back(std::vector<Rating> { Rating(3), Rating(2), Rating(1), Rating(1) });
  input.students.emplace_back("Lerngruppenteilnehmer 3", CourseType::Any, DegreeType::Any, false);
  input.ratings.emplace_back(std::vector<Rating> { Rating(3), Rating(2), Rating(1), Rating(1) });
  input.students.emplace_back("Lerngruppenteilnehmer 4", CourseType::Any, DegreeType::Any, false);
  input.ratings.emplace_back(std::vector<Rating> { Rating(3), Rating(2), Rating(1), Rating(1) });
  input.teams[0].members.push_back(9);
  input.teams[0].members.push_back(10);
  input.teams[0].members.push_back(11);

  s = State(input);
  assignTeamsAndStudents(s, 4);
  printCurrentAssignment(s);

  s = State(input);
  assignWithMinimumNumberPerGroup(s, 2, 5);
  printCurrentAssignment(s);

  s = State(input);
  assignWithMinimumNumberPerGroup(s, 3, 6);
  printCurrentAssignment(s);
}