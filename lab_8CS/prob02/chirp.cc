#include "chirp.h"
#include <string>
Chirp::Chirp() {
  message_ = "";
  likes_ = 0;
}
Chirp::Chirp(std::string message) {
  message_ = message;
  likes_ = 0;
}
Chirp::Chirp(std::string message, int likes) {
  message_ = message;
  likes_ = likes;
}
std::string Chirp::GetMessage() const { return message_; }
int Chirp::GetLikes() const { return likes_; }
void Chirp::SetMessage(std::string message) { message_ = message; }
void Chirp::SetLikes(int likes) { likes_ = likes; }
void Chirp::AddLike() { likes_ += 1; }
void Chirp::AddLike(int likes) { likes_ += likes; }