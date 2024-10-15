#ifndef FAST_ARCHIVE_SQL_H
#define FAST_ARCHIVE_SQL_H

#include "fast/archive.h"

namespace fast {

class SqlArchive : public Archive {
 private:
  std::unordered_map<std::string,
                     std::variant<int64_t*, double*, std::string*, bool*,
                                  Archivable*, std::vector<Archivable>*>>
      map;

  std::unordered_map<std::string, std::string> result_data;

 public:
  void load_data(std::unordered_map<std::string, std::string> result_data);

  // overrides
  void add(std::string name, int64_t* data) override;
  void add(std::string name, double* data) override;
  void add(std::string name, std::string* data) override;
  void add(std::string name, bool* data) override;
  void add(std::string name, Archivable* data) override;
  void add(std::string name, std::vector<int64_t>* data) override;
  void add(std::string name, std::vector<double>* data) override;
  void add(std::string name, std::vector<std::string>* data) override;
  void add(std::string name, std::vector<bool>* data) override;
  void add(std::string name, std::vector<Archivable>* data) override;
  void deserialise() override;
  void serialise() override;
};

} // namespace fast

#endif // FAST_ARCHIVE_SQL_H
