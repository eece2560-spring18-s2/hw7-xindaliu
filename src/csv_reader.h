#include <string>
#include <fstream>

#ifndef CSV_READER_H_
#define CSV_READER_H_

namespace algdb {

/**
 * CsvReader is responsible for reading CSV files
 */
class CsvReader {
  std::ifstream file_;
  std::string line_;

 public:

 /**
  * Destructor. It closes the file, if there is an open file.
  */
 ~CsvReader();

  /**
   * OpenFile opens a new file. If there is already an open file, close it
   * before opening the new file.
   */
  void OpenFile(const char *filename);

  /**
   * NextEntry moves the line that is being parsed to the next line. If there
   * is no more line to parse, this function returns false;
   */
  bool NextEntry();

  /**
   * NextCell returns the content of current cell and moves to the next cell.
   */
  std::string NextCell();
};

}

#endif