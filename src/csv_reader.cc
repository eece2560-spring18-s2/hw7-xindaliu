#include "csv_reader.h"

#include <iostream>

namespace algdb {

CsvReader::~CsvReader() {
  if (file_.is_open()) file_.close();
}

void CsvReader::OpenFile(const char *filename) {
  if (file_.is_open()) file_.close();
  file_.open(filename, std::ifstream::in);
  NextEntry(); // Skip the header
  return ;
}

bool CsvReader::NextEntry() {
  if (!file_.good()) {
    return false;
  }
  std::getline(file_, line_);
  if (line_ == "") return false;
  return true;
}

std::string CsvReader::NextCell() {
  size_t pos = 0;
  bool in_quote = false;

  while(true) {
    char r = line_[pos];
    if (r == '"') {
      in_quote = !in_quote;
    } else if (r == ',') {
      if (!in_quote) break;
    }
    pos += 1;
  }

  std::string token = line_.substr(0, pos);
  line_.erase(0, pos + 1);
  token = token.substr(1, token.length() - 2);
  return token;
}

}
