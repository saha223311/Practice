#include <iostream>
#include <string>

class algorithm {
public:
  algorithm(int aCountOfString, int aCountOfSymbol) 
    : countOfString_(aCountOfString), countOfSymbol_(aCountOfSymbol) {}
  //
  void SetNewWord(std::string aWord) {
	if (currentWord_ + aWord.length() + (currentWord_ > 0 ? 1 : 0) <= countOfSymbol_) {
	  currentWord_ += aWord.length() + (currentWord_ > 0 ? 1 : 0);
	}
    else {
      ++currentString_;
      currentWord_ = aWord.length();
	}
  }
  //
  int GetResult() {
    return currentString_ / countOfString_ + ((currentString_ % countOfString_) > 0 ? 1 : 0);
  }
  //
private:
  int countOfString_;
  int countOfSymbol_;
  //
  int currentString_ = 1;
  int currentWord_ = 0;
};

void main() {
  int countOfString, countOfSymbol, numberOfWord;
  std::string currentWord;
  std::cin >> countOfString >> countOfSymbol >> numberOfWord;
  //
  algorithm alg(countOfString, countOfSymbol);
  //
  for (int i = 0; i < numberOfWord; i++) {
    std::cin >> currentWord;
    alg.SetNewWord(currentWord);
  }
  //
  std::cout << alg.GetResult();
}