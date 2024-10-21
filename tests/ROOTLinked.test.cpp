#include "TGraph.h"
#include "TH1.h"
#include "TApplication.h"
#include "TCanvas.h"

int main()
{
  TApplication app("My Application",nullptr,nullptr);
  TCanvas* canvas = new TCanvas("MyTCanvas","My TCanvas");
  canvas->Divide(2,1);
  TH1F* th1f = new TH1F("MyTH1F","My TH1F",1,0,1);
  canvas->cd(1);
  th1f->Draw();
  canvas->cd(2);
  TGraph* graph = new TGraph(1);
  graph->Draw();
  app.Run();
}