#ifndef FAST_JSON_H
#define FAST_JSON_H
#include "fast/model.h"
#include <string>

namespace fast {

std::string to_json(Model& obj);
void from_json(Model* obj);

}

#endif // FAST_JSON_H
