#ifndef BASE_H
#define BASE_H


namespace fast {
// forward declare archive since Archivable interface relies on it
class Archive;

// interface that makes a type serialisable
class Model {
public:
   virtual void load_metadata(Archive& arc) = 0;
};

} // namespace fast


#endif // BASE_H
