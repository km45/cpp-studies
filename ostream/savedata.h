#include <bitset>

union SaveData {
  std::byte reserved[256];

  struct Content {
    int level;
    int hp;
    int mp;
    std::bitset<32> flags;
  } content;

  static_assert(sizeof(content) <= sizeof(reserved),
                "FixedLengthBinary content size is must be less than or equal "
                "to reserved size.");

  SaveData() : reserved() {}
  ~SaveData() = default;
};

template <typename CharT, typename Traits>
std::basic_ostream<CharT, Traits>& operator<<(
    std::basic_ostream<CharT, Traits>& os, const SaveData& data) {
  os << "level:" << data.content.level << ", "
     << "hp: " << data.content.hp << ", "
     << "mp: " << data.content.mp << ", "
     << "flags: " << data.content.flags;
  return os;
}
