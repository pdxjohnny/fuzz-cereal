#include <cereal/types/string.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>
#include <fstream>
#include <iostream>

struct Minimal
{
  std::string myData;

  template <class Archive>
  std::string save_minimal( Archive const & ) const
  { return myData; }

  template <class Archive>
  void load_minimal( Archive const &, std::string const & value )
  { myData = value; }
};

struct Normal
{
  std::string myData;

  template <class Archive>
  void serialize( Archive & ar )
  { ar( myData ); }
};

int main(int argc, char ** argv) {
    Minimal m;
    Normal  n;

    if (argc == 2) {
        std::ifstream is(argv[1]);
        cereal::BinaryInputArchive iar(is);
        iar(m, n);
    } else {
        cereal::BinaryInputArchive iar(std::cin);
        iar(m, n);
    }
}

