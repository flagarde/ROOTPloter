#pragma once
#include<cstdint>
#include<string>

namespace ROOTPloter
{
  /**
   * @brief Bin type defined by ROOT for Histograms
   * 
   */
  class BinsType
  {
  public:
    BinsType() noexcept = default;
    enum class Type : std::uint8_t
    {
      Void,
      Char,
      Short,
      Int,
      LongLong,
      Float,
      Double,
    };
    explicit constexpr BinsType(const Type& type ) noexcept : m_Type(type) {}
    const Type& type() const noexcept { return m_Type; }
    const std::string str() const
    {
      switch(m_Type)
      {
        case Type::Void: return "";
        case Type::Char: return "C";
        case Type::Short: return "S";
        case Type::Int: return "I";
        case Type::LongLong: return "L";
        case Type::Float: return "F";
        case Type::Double: return "D";
        default: return "";
      }
    }
  private:
    BinsType::Type m_Type{Type::Void};
  };
  inline const constexpr BinsType CharBins(BinsType::Type::Char);
  inline const constexpr BinsType ShortBins(BinsType::Type::Short);
  inline const constexpr BinsType IntBins(BinsType::Type::Int);
  inline const constexpr BinsType LongLongBins(BinsType::Type::LongLong);
  inline const constexpr BinsType FloatBins(BinsType::Type::Float);
  inline const constexpr BinsType DoubleBins(BinsType::Type::Double);
  inline const constexpr BinsType VoidBins(BinsType::Type::Void);

}