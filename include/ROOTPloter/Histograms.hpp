#pragma once
#include "ROOTPloter/BinType.hpp"
#include "ROOTPloter/Plot.hpp"

namespace ROOTPloter
{
  // TH1
  class TH1 final : public BinsType, public Plot
  {
  public:
    TH1()=default;
    explicit constexpr TH1(const BinsType& bin_type) : BinsType(bin_type) {};
  };
  inline const constexpr class TH1& TH1C{TH1(CharBins)}; 
  inline const constexpr class TH1& TH1S{TH1(ShortBins)};
  inline const constexpr class TH1& TH1I{TH1(IntBins)};
  inline const constexpr class TH1& TH1L{TH1(LongLongBins)};
  inline const constexpr class TH1& TH1F{TH1(FloatBins)};
  inline const constexpr class TH1& TH1D{TH1(DoubleBins)};

  // TH2
  class TH2 final : public BinsType, public Plot
  {
  public:
    TH2()=delete;
    explicit constexpr TH2(const BinsType& bin_type) : BinsType(bin_type) {};
  };
  inline const constexpr class TH2& TH2C{TH2(CharBins)}; 
  inline const constexpr class TH2& TH2S{TH2(ShortBins)};
  inline const constexpr class TH2& TH2I{TH2(IntBins)};
  inline const constexpr class TH2& TH2L{TH2(LongLongBins)};
  inline const constexpr class TH2& TH2F{TH2(FloatBins)};
  inline const constexpr class TH2& TH2D{TH2(DoubleBins)};

  // TH3
  class TH3 final : public BinsType, public Plot
  {
  public:
    TH3()=delete;
    explicit constexpr TH3(const BinsType& bin_type) : BinsType(bin_type) {};
  };
  inline const constexpr class TH3& TH3C{TH3(CharBins)}; 
  inline const constexpr class TH3& TH3S{TH3(ShortBins)};
  inline const constexpr class TH3& TH3I{TH3(IntBins)};
  inline const constexpr class TH3& TH3L{TH3(LongLongBins)};
  inline const constexpr class TH3& TH3F{TH3(FloatBins)};
  inline const constexpr class TH3& TH3D{TH3(DoubleBins)};

  // THn
  class THn final : public BinsType, public Plot
  {
  public:
    THn()=delete;
    explicit constexpr THn(const BinsType& bin_type) : BinsType(bin_type) {};
  };
  inline const constexpr class THn& THnC{THn(CharBins)}; 
  inline const constexpr class THn& THnS{THn(ShortBins)};
  inline const constexpr class THn& THnI{THn(IntBins)};
  inline const constexpr class THn& THnL{THn(LongLongBins)};
  inline const constexpr class THn& THnF{THn(FloatBins)};
  inline const constexpr class THn& THnD{THn(DoubleBins)};

  // THnSparse
  class THnSparse final : public BinsType, public Plot
  {
  public:
    THnSparse()=delete;
    explicit constexpr THnSparse(const BinsType& bin_type) : BinsType(bin_type) {};
  };
  inline const constexpr class THnSparse& THnSparseC{THnSparse(CharBins)}; 
  inline const constexpr class THnSparse& THnSparseS{THnSparse(ShortBins)};
  inline const constexpr class THnSparse& THnSparseI{THnSparse(IntBins)};
  inline const constexpr class THnSparse& THnSparseL{THnSparse(LongLongBins)};
  inline const constexpr class THnSparse& THnSparseF{THnSparse(FloatBins)};
  inline const constexpr class THnSparse& THnSparseD{THnSparse(DoubleBins)};

  class TProfile final : public Plot {};
  inline const constexpr class TProfile   TProfile{};
  class TProfile2D final : public Plot {};
  inline const constexpr class TProfile2D TProfile2D{};
  class TProfile3D final: public Plot  {};
  inline const constexpr class TProfile3D TProfile3D{};

  //FIXME Maybe discriminate TH1 and TH2
  class THStack final : public Plot {};
  inline const constexpr class THStack THStack{};

}