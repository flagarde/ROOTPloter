#include "ROOTPloter/ROOTPloter.hpp"
#include "TApplication.h"
#include "TCanvas.h"
#include "TROOT.h"

int main()
{
  TApplication app("My Application",nullptr,nullptr);
  app.ExitOnException(TApplication::EExitOnException::kExit);
  ROOTPloter::ROOTPloter ploter;
  ROOTPloter::ROOTPloter ploter2("Mama Mia!");
  ROOTPloter::ROOTPloter ploter3("Aie Caramba!");
  std::string name{"DDDD"};
  std::size_t ll{0};
  double min{10};
  double max{20};
  ploter.create(ROOTPloter::TH1C,"TH1C","Big !",1,-10.325,10000.5256);
  ploter.create(ROOTPloter::TH1L,"TH1L","small ",10,0.0001,0.0002);
  ploter.create(ROOTPloter::TH1D,name,"My TH1D",1,min,50);
  ploter.create(ROOTPloter::TGraph,"rfff4","FF",ll,0.2,0.5);

  ploter.create(ROOTPloter::TH2C,"T1","Big !",1,-10.325,10000.5256,15,0,63);
  ploter.create(ROOTPloter::TH2L,"TH","small ",10,0.0001,0.0002,20,36,58);
  ploter.create(ROOTPloter::TH2D,"LKL","My TH1D",1,min,50,290,6.235,7.98);
  ploter.drawAll();



  ploter2.create(ROOTPloter::TH1C,"TH1C","My TH1C ggg",100,1,50);
  ploter2.create(ROOTPloter::TH1S,"TH1S","My TH1S from ",10,0,10);
  ploter2.create(ROOTPloter::TH1D,"TH1D","My TH1D ff",1,0.1,0.5);
  ploter2.create(ROOTPloter::TGraph,"rfff4","FF",1,0.2,0.5);

  app.Run(true);
}
