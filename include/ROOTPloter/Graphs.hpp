#pragma once
#include "ROOTPloter/Plot.hpp"

namespace ROOTPloter
{
  class TGraph final: public Plot  {};
  inline const constexpr class TGraph   TGraph{};

  class TGraph2D final: public Plot {};
  inline const constexpr class TGraph2D TGraph2D{};

  class TGraph2DAsymmErrors final: public Plot {};
  inline const constexpr class TGraph2DAsymmErrors TGraph2DAsymmErrors{};

  class TGraph2DErrors final: public Plot {};
  inline const constexpr class TGraph2DErrors   TGraph2DErrors{};

  class TGraphAsymmErrors final: public Plot {};
  inline const constexpr class TGraphAsymmErrors TGraphAsymmErrors{};

  class TGraphBentErrors final: public Plot {};
  inline const constexpr class TGraphBentErrors   TGraphBentErrors{};

  class TGraphDelaunay final: public Plot {};
  inline const constexpr class TGraphDelaunay   TGraphDelaunay{};

  class TGraphDelaunay2D final: public Plot {};
  inline const constexpr class TGraphDelaunay2D   TGraphDelaunay2D{};

  class TGraphErrors final: public Plot {};
  inline const constexpr class TGraphErrors TGraphErrors{};

  class TGraphMultiErrors final: public Plot {};
  inline const constexpr class TGraphMultiErrors TGraphMultiErrors{};

  class TGraphTime final: public Plot {};
  inline const constexpr class TGraphTime TGraphTime{};

  class TMultiGraph final: public Plot {};
  inline const constexpr class TGraphErrors TMultiGraph{};

  class TPolyMarker final: public Plot {};
  inline const constexpr class TGraphErrors TPolyMarker{};

  class TGraphPolar final: public Plot {};
  inline const constexpr class TGraphPolar TGraphPolar{};

  class TGraphQQ final: public Plot {};
  inline const constexpr class TGraphQQ   TGraphQQ{};

  class TScater final: public Plot {};
  inline const constexpr class TScater   TScater{};

}