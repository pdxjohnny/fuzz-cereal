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

int main()
{
    /*
    {
        Minimal m = {"minimal"};
        Normal  n = {"normal"};

        std::ofstream os("data.xml");
        cereal::BinaryOutputArchive oar(os);
        oar( CEREAL_NVP(m), CEREAL_NVP(n) );
    }
    */

    {
        Minimal m;
        Normal  n;

        // std::ifstream is("data.xml");
        // cereal::BinaryInputArchive iar(is);
        cereal::BinaryInputArchive iar(std::cin);
        iar(m, n);

        cereal::JSONOutputArchive oar(std::cout);
        oar( CEREAL_NVP(m), CEREAL_NVP(n) );
    }
}

