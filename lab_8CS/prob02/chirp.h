#include <string>

class Chirp
{
private:
  std::string message_;
  int likes_;

public:
  Chirp();
  Chirp(std::string message);
  Chirp(std::string message, int likes);
  std::string GetMessage() const;
  int GetLikes() const;
  void SetMessage(std::string message);
  void SetLikes(int likes);
  void AddLike();
  void AddLike(int likes);
};