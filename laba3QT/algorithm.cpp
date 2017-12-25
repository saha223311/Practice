#include "algorithm.h"

std::string algorithm::Execute(std::string aLine) {
  std::string error = this->CheckData(aLine);
  //
  if (error != "done"){
    return error;
  }
 //
  line_ = aLine;
  result_ = "";
  int length = line_.length();
  std::vector<int> palin[4000];
  int dp[4001], next[4000];
  //
  for (int i = 0; i < length; ++i) {
    int pos1 = i, pos2 = i;
    //
    while (pos1 >= 0 && pos2 < length && line_[pos1] == line_[pos2]) {
      palin[pos1].push_back(pos2);
      --pos1; ++pos2;
    }
    //
    pos1 = i; pos2 = i + 1;
    while (pos1 >= 0 && pos2 < length && line_[pos1] == line_[pos2]) {
      palin[pos1].push_back(pos2);
      --pos1; ++pos2;
    }
  }
  //
  dp[length] = 0;
  for (int i = length - 1; i >= 0; --i) {
    dp[i] = length - i;
    next[i] = i + 1;
    //
    for (int j = palin[i].size() - 1; j >= 0; --j) {
      if (dp[i] > 1 + dp[palin[i][j] + 1]) {
      dp[i] = 1 + dp[palin[i][j] + 1];
      next[i] = palin[i][j] + 1;
      }
    }
  }
  //
  n_ = dp[0];
  int pos = 0;
  while (pos != length) {
    if (pos != 0) result_ += " ";
    for (int i = pos; i < next[pos]; ++i){
        result_ += line_[i];
    }
    pos = next[pos];
  }
  //
  return result_;
}

std::string algorithm::CheckData(std::string aLine){
  if (aLine.length() > 4000){
    return "error1";
  }
  //
  if (aLine.empty()){
    return "error2";
  }
  //
  for (int i = 0; i < aLine.length(); i++){
    if (aLine[i] < 97 || aLine[i] > 122){
      return "error3";
    }
  }
  //
  return "done";
}

