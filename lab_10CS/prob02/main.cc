#include <iostream>
#include <memory>

#include "network.h"
#include "phone.h"

int main() {
  Network csuf_network;
  std::shared_ptr<Phone> phone1 = std::make_shared<Phone>("Anna");
  std::shared_ptr<Phone> phone2 = std::make_shared<Phone>("Raf");
  std::shared_ptr<Phone> phone3 = std::make_shared<Phone>("JC");

   csuf_network.AddPhone(phone1);
   csuf_network.AddPhone(phone2);
   csuf_network.AddPhone(phone3);

  csuf_network.SendMessage(phone1->AuthorMessage("Sup"),"Raf");
  csuf_network.SendMessage(phone2->AuthorMessage("Lol"),"Anna");
  std::vector<std::string> jcs_class {"Anna", "Raf"};
  csuf_network.SendMessage(phone3->AuthorMessage("Hi class!"), jcs_class);
 
  csuf_network.SendMessage(phone1->AuthorMessage("Hi Prof!") , "JC");
  csuf_network.SendMessage(phone2->AuthorMessage("help how do C++"), "JC");

  std::cout << "Printing messages sent to Anna:\n" ;
  phone1->PrintMessages();
  std::cout << "\n";
  std::cout << "Printing messages sent to Raf:\n";
  phone2->PrintMessages();
  std::cout << "\n";
  std::cout << "Printing messages sent to JC:\n";
  phone3->PrintMessages();
}