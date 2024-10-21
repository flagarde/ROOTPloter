#include "ROOTPloter/ROOTPloter.hpp"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include <cmath>
#include <memory>
#include <iostream>
#include <functional>
#include <TGClient.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TRandom.h>
#include <TGButton.h>
#include <TGFrame.h>
#include <TRootEmbeddedCanvas.h>
#include <spdlog/logger.h>


#if defined(USE_SPDLOG)
  #include "spdlog/spdlog.h"
  #include "spdlog/sinks/stdout_color_sinks.h"
  #define trace(...) log()->trace(__VA_ARGS__)
  #define debug(...) log()->debug(__VA_ARGS__)
  #define info(...)  log()->info(__VA_ARGS__)
  #define warn(...)  log()->warn(__VA_ARGS__)
  #define error(...) log()->error(__VA_ARGS__)
  #define critical(...) log()->critical(__VA_ARGS__)
  #define create_logger(logger) logger
#else
  #define trace(message)
  #define debug(message)
  #define info(message)
  #define warn(message)
  #define error(message)
  #define critical(message)
  #define create_logger(logger)
#endif


namespace PlotType {
  inline const constexpr std::size_t TH1{0};
  inline const constexpr std::size_t TH2{1};
}

//////////////// MACROS TO SIMPLIFY THE CODE //////////////////////
#define fill_container(type,name) std::get<type>(m_container)[name]
#define access(type,name) std::get<type>(m_container).at(name)

std::size_t ROOTPloter::ROOTPloter::m_id{0};

ROOTPloter::ROOTPloter::~ROOTPloter()
{
  m_canvas.clear();
  std::get<0>(m_container).clear();
  std::get<1>(m_container).clear();
  delete m_logger;
}

ROOTPloter::ROOTPloter::ROOTPloter(const source_location& source_loc)
{
  m_logger=new spdlog::logger(fmt::format("ROOTPloter:{}",m_id),std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
  if(source_loc.line()!=0)info(fmt::format("created in function: {}, file: {}, line: {}",source_loc.function_name(),source_loc.file_name(),source_loc.line()));
  m_name=std::to_string(m_id);
  ++m_id;
}

ROOTPloter::ROOTPloter::ROOTPloter(const std::string_view name,const source_location& source_loc)
{
  m_logger=new spdlog::logger(fmt::format("ROOTPloter:{}",name),std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
  if(source_loc.line()!=0)info(fmt::format("created in function: {}, file: {}, line: {}",source_loc.function_name(),source_loc.file_name(),source_loc.line()));
  m_name=name;
  ++m_id;
}


void ROOTPloter::ROOTPloter::createTH1(const TH1& th1,const std::string_view name,const std::string_view title,const std::size_t& xbins,const double& xlow,const double& xup)
{
  const std::string_view real_name= this->name()+":"+name.data();
  switch(th1.type())
  {
    case BinsType::Type::Char:
    {
      fill_container(PlotType::TH1,name.data())=UniqueTH1Ptr(new ::TH1C(real_name.data(),title.data(),xbins,xlow,xup), [this](::TObject* obj){this->TObjectDeleter(obj);});
      break;
    }
    case BinsType::Type::Short:
    {
      fill_container(PlotType::TH1,name.data())=UniqueTH1Ptr(new ::TH1S(real_name.data(),title.data(),xbins,xlow,xup), [this](::TObject* obj){this->TObjectDeleter(obj);});
      break;
    }
    case BinsType::Type::Int:
    {
      fill_container(PlotType::TH1,name.data())=UniqueTH1Ptr(new ::TH1I(real_name.data(),title.data(),xbins,xlow,xup), [this](::TObject* obj){this->TObjectDeleter(obj);});
      break;
    }
    case BinsType::Type::LongLong:
    {
      fill_container(PlotType::TH1,name.data())=UniqueTH1Ptr(new ::TH1L(real_name.data(),title.data(),xbins,xlow,xup), [this](::TObject* obj){this->TObjectDeleter(obj);});
      break;
    }
    case BinsType::Type::Float:
    {
      fill_container(PlotType::TH1,name.data())=UniqueTH1Ptr(new ::TH1F(real_name.data(),title.data(),xbins,xlow,xup), [this](::TObject* obj){this->TObjectDeleter(obj);});
      break;
    }
    case BinsType::Type::Double:
    {
      fill_container(PlotType::TH1,name.data())=UniqueTH1Ptr(new ::TH1D(real_name.data(),title.data(),xbins,xlow,xup), [this](::TObject* obj){this->TObjectDeleter(obj);});
      break;
    }
  }
  warn("Creating a {} named \"{}\" ({}) with {} xbins [{},{}[",
       access(PlotType::TH1,name.data())->ClassName(),
       access(PlotType::TH1,name.data())->GetName(),
       access(PlotType::TH1,name.data())->GetTitle(),
       access(PlotType::TH1,name.data())->GetNbinsX(),
       access(PlotType::TH1,name.data())->GetXaxis()->GetXmin(),
       access(PlotType::TH1,name.data())->GetXaxis()->GetXmax());
}

void ROOTPloter::ROOTPloter::createTH2(const TH2& th2,const std::string_view name,const std::string_view title,const std::size_t& xbins,const double& xlow,const double& xup,const std::size_t& ybins,const double& ylow,const double& yup)
{
  const std::string_view real_name= this->name()+":"+name.data();
  switch(th2.type())
  {
    case BinsType::Type::Char:
    {
      fill_container(PlotType::TH2,name.data())=UniqueTH2Ptr(new ::TH2C(real_name.data(),title.data(),xbins,xlow,xup,ybins,ylow,yup), [this](::TObject* obj){this->TObjectDeleter(obj);});
      break;
    }
    case BinsType::Type::Short:
    {
      fill_container(PlotType::TH2,name.data())=UniqueTH2Ptr(new ::TH2S(real_name.data(),title.data(),xbins,xlow,xup,ybins,ylow,yup), [this](::TObject* obj){this->TObjectDeleter(obj);});
      break;
    }
    case BinsType::Type::Int:
    {
      fill_container(PlotType::TH2,name.data())=UniqueTH2Ptr(new ::TH2I(real_name.data(),title.data(),xbins,xlow,xup,ybins,ylow,yup), [this](::TObject* obj){this->TObjectDeleter(obj);});
      break;
    }
    case BinsType::Type::LongLong:
    {
      fill_container(PlotType::TH2,name.data())=UniqueTH2Ptr(new ::TH2L(real_name.data(),title.data(),xbins,xlow,xup,ybins,ylow,yup), [this](::TObject* obj){this->TObjectDeleter(obj);});
      break;
    }
    case BinsType::Type::Float:
    {
      fill_container(PlotType::TH2,name.data())=UniqueTH2Ptr(new ::TH2F(real_name.data(),title.data(),xbins,xlow,xup,ybins,ylow,yup), [this](::TObject* obj){this->TObjectDeleter(obj);});
      break;
    }
    case BinsType::Type::Double:
    {
      fill_container(PlotType::TH2,name.data())=UniqueTH2Ptr(new ::TH2D(real_name.data(),title.data(),xbins,xlow,xup,ybins,ylow,yup), [this](::TObject* obj){this->TObjectDeleter(obj);});
      break;
    }
  }
  warn("Creating a {} named \"{}\" ({}) with {} xbins [{},{}[, {} ybins [{},{}[",
       access(PlotType::TH2,name.data())->ClassName(),
       access(PlotType::TH2,name.data())->GetName(),
       access(PlotType::TH2,name.data())->GetTitle(),
       access(PlotType::TH2,name.data())->GetNbinsX(),
       access(PlotType::TH2,name.data())->GetXaxis()->GetXmin(),
       access(PlotType::TH2,name.data())->GetXaxis()->GetXmax(),
       access(PlotType::TH2,name.data())->GetNbinsY(),
       access(PlotType::TH2,name.data())->GetYaxis()->GetXmin(),
       access(PlotType::TH2,name.data())->GetYaxis()->GetXmax()
       );
}


void ROOTPloter::ROOTPloter::TObjectDeleter(TObject* obj) noexcept
{
  if(obj)
  {
    this->warn("Deleting {} \"{}\" [title:{}]",obj->ClassName(),obj->GetName(),obj->GetTitle());
    obj->~TObject();
  }
  else error("Trying to delete a nullptr");
};

void ROOTPloter::ROOTPloter::createTCanvas(std::string_view name, std::string_view title)
{
  m_canvas.emplace(m_canvas.end(),new TCanvas(name.data(),title.data()), [this](TObject* obj){this->TObjectDeleter(obj);});
}

void ROOTPloter::ROOTPloter::drawAll()
{
  for(TH1Container::const_iterator it=std::get<0>(m_container).begin(); it!=std::get<0>(m_container).end();++it)
  {
    createTCanvas(it->second->GetName(),it->second->GetTitle());
    m_canvas.back()->cd();
    it->second->Draw();
  }
  for(TH2Container::const_iterator it=std::get<1>(m_container).begin(); it!=std::get<1>(m_container).end();++it)
  {
    createTCanvas(it->second->GetName(),it->second->GetTitle());
    m_canvas.back()->cd();
    it->second->Draw();
  }
}
