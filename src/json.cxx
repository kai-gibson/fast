#include "fast/json.h"
#include "fast/archives/json.h"

namespace fast {

std::string to_json(Model& obj) {
  JsonOArchive oar;
  obj.load_metadata(oar);

  return oar.str();
}

void from_json(Model* obj) {
  JsonIArchive iar;
  obj->load_metadata(iar);
}

}
